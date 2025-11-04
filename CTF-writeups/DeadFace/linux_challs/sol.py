
"""
recon_playbook.py

Safe, read-only recon automation for CTF-style host inspection.

What it does (read-only):
 - Lists user homes and a target home (default: /home/gh0st404)
 - Lists files in ~/tools and prints script heads
 - Greps for keywords (deadface, flag{, gh0st, hostbusters, subrecon) across specified paths
 - Finds recent files (mtime)
 - Finds small text files (likely flags)
 - Shows dotfiles and bash history for a user (if readable)
 - Shows crontabs, /etc/crontab, /var/www and web roots
 - Shows processes and listening ports via netstat (if available)
 - Finds SUID binaries
 - Records `id` and `sudo -l` output (if allowed)
 - Writes everything to a timestamped report in current directory

Usage:
    python3 recon_playbook.py               # run with defaults (target /home/gh0st404)
    python3 recon_playbook.py --target /home/username --verbose

Designed to be safe: **read-only**. Does not modify the system.
"""

import argparse
import subprocess
import shlex
import sys
from datetime import datetime
from pathlib import Path

KEYWORDS = ['deadface', 'flag{', 'gh0st', 'hostbusters', 'subrecon']

def run(cmd, timeout=30):
    """Run a shell command and return (exitcode, stdout, stderr)."""
    try:
        completed = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=timeout)
        return completed.returncode, completed.stdout.strip(), completed.stderr.strip()
    except subprocess.TimeoutExpired:
        return 124, '', 'TIMEOUT'

def safe_write(report_file, title, content):
    report_file.write(f"\n\n=== {title} ===\n")
    report_file.write(content if content else "[no output]\n")

def header(report_file, text):
    report_file.write("\n" + "="*80 + "\n")
    report_file.write(text + "\n")
    report_file.write("="*80 + "\n")

def run_quiet(cmd):
    return run(cmd)

def grep_keywords(paths, keywords, max_lines=300):
    pats = "\\|".join([shlex.quote(k) for k in keywords])
    # build a grep command that avoids noisy dirs
    cmd = f"grep -RIn --exclude-dir={{proc,sys,dev,node_modules,.git}} -E '{pats}' {' '.join(map(shlex.quote, paths))} 2>/dev/null | head -n {max_lines}"
    return run(cmd)

def main():
    p = argparse.ArgumentParser(description="Recon playbook (read-only).")
    p.add_argument("--target", "-t", default="/home/gh0st404", help="Target home directory to inspect")
    p.add_argument("--paths", "-p", nargs="*", default=["/home", "/opt", "/srv", "/var/www", "/tmp", "/etc"], help="Paths to grep for keywords")
    p.add_argument("--verbose", "-v", action="store_true", help="Print progress to stdout")
    p.add_argument("--no-netstat", action="store_true", help="Skip netstat (if you want to avoid it)")
    args = p.parse_args()

    timestamp = datetime.utcnow().strftime("%Y%m%d_%H%M%SZ")
    report_name = f"recon_report_{timestamp}.txt"
    report_path = Path.cwd() / report_name

    if args.verbose:
        print(f"[+] Writing report to {report_path}")

    with report_path.open("w", encoding="utf-8", errors="replace") as rpt:
        header(rpt, f"Recon Playbook Report - {timestamp} (UTC)")
        safe_write(rpt, "invocation", " ".join(sys.argv))

        # Basic identity
        rc, out, err = run("id")
        safe_write(rpt, "id", out if out else err)
        if args.verbose: print("[*] id")

        rc, out, err = run("sudo -l 2>/dev/null || true")
        safe_write(rpt, "sudo -l", out if out else (err if err else "[no sudo or no output]"))
        if args.verbose: print("[*] sudo -l")

        # List /home and target
        rc, out, err = run(f"ls -la /home 2>/dev/null || true")
        safe_write(rpt, "/home listing", out if out else err)
        if args.verbose: print("[*] listed /home")

        target = args.target
        rc, out, err = run(f"ls -la {shlex.quote(target)} 2>/dev/null || true")
        safe_write(rpt, f"{target} listing", out if out else err)
        if args.verbose: print(f"[*] listed {target}")

        # tools dir
        tools_dir = Path(target) / "tools"
        if tools_dir.exists():
            rc, out, err = run(f"ls -la {shlex.quote(str(tools_dir))} 2>/dev/null || true")
            safe_write(rpt, f"{tools_dir} listing", out if out else err)
            if args.verbose: print(f"[*] listed {tools_dir}")

            # print heads of shell scripts found
            rc, out, err = run(f"find {shlex.quote(str(tools_dir))} -maxdepth 2 -type f -iname '*.sh' -print 2>/dev/null")
            script_files = out.splitlines() if out else []
            for s in script_files:
                s = s.strip()
                if not s:
                    continue
                rc2, out2, err2 = run(f"sed -n '1,240p' {shlex.quote(s)} 2>/dev/null || true")
                safe_write(rpt, f"HEAD of {s}", out2 if out2 else err2)
                if args.verbose: print(f"[*] read head of {s}")
        else:
            safe_write(rpt, "tools directory", f"{tools_dir} does not exist or is not readable")

        # Search for keyword matches across common paths
        safe_write(rpt, "grep keywords start", f"Keywords: {', '.join(KEYWORDS)}\nPaths: {', '.join(args.paths)}")
        rc, out, err = grep_keywords(args.paths, KEYWORDS, max_lines=500)
        safe_write(rpt, "grep keywords results", out if out else (err if err else "[no matches]"))
        if args.verbose: print("[*] grep done")

        # Find recently modified files (last 3 days)
        rc, out, err = run("find / -type f -mtime -3 -ls 2>/dev/null | sort -k7 -r | head -n 200")
        safe_write(rpt, "recently modified files (mtime -3 days)", out if out else err)
        if args.verbose: print("[*] recent files search done")

        # Small text files (<10KB)
        rc, out, err = run("find / -type f -size -10k -exec file {} \\; 2>/dev/null | grep -i text | head -n 200")
        safe_write(rpt, "small text files (under 10KB, first 200)", out if out else err)
        if args.verbose: print("[*] small text files search done")

        # Look for files named like subs_* in target
        rc, out, err = run(f"find {shlex.quote(str(target))} -type f -iname 'subs_*' -print 2>/dev/null || true")
        safe_write(rpt, f"subs_* files under {target}", out if out else "[none found]")
        if args.verbose: print("[*] subs_* check done")

        # show recon_* directories
        rc, out, err = run(f"find {shlex.quote(str(target))} -maxdepth 3 -type d -iname 'recon*' -print 2>/dev/null || true")
        safe_write(rpt, f"recon* dirs under {target}", out if out else "[none found]")
        if args.verbose: print("[*] recon* dirs check done")

        # Read candidate subs files if present
        if out:
            for line in out.splitlines():
                d = line.strip()
                if not d:
                    continue
                # find subs_*.txt inside
                rc2, out2, err2 = run(f"find {shlex.quote(d)} -type f -iname 'subs_*.txt' -print 2>/dev/null || true")
                if out2:
                    for fpath in out2.splitlines():
                        rc3, out3, err3 = run(f"sed -n '1,400p' {shlex.quote(fpath)} 2>/dev/null || true")
                        safe_write(rpt, f"Content of {fpath}", out3 if out3 else err3)
                        if args.verbose: print(f"[*] read {fpath}")

        # Dotfiles & history for target
        for dot in [".bash_history", ".bashrc", ".profile", ".ssh/authorized_keys"]:
            pth = Path(target) / dot
            if pth.exists():
                rc, out, err = run(f"sed -n '1,240p' {shlex.quote(str(pth))} 2>/dev/null || true")
                safe_write(rpt, f"{pth}", out if out else err)
                if args.verbose: print(f"[*] read {pth}")

        # webroots
        rc, out, err = run("ls -la /var/www /var/www/html /srv 2>/dev/null || true")
        safe_write(rpt, "webroot listing (/var/www /var/www/html /srv)", out if out else err)
        if args.verbose: print("[*] webroots listed")

        rc, out, err = run("find /var/www /srv -type f -iname '*deadface*' -o -iname '*flag*' 2>/dev/null | head -n 200")
        safe_write(rpt, "webroot suspicious files", out if out else "[none found]")
        if args.verbose: print("[*] webroot suspicious files search done")

        # crontabs and /etc/crontab
        rc, out, err = run("cat /etc/crontab 2>/dev/null || true")
        safe_write(rpt, "/etc/crontab", out if out else err)
        if args.verbose: print("[*] /etc/crontab")

        rc, out, err = run("ls -la /etc/cron.* 2>/dev/null || true")
        safe_write(rpt, "/etc/cron.* listing", out if out else err)
        if args.verbose: print("[*] /etc/cron.*")

        # user crontabs
        rc, out, err = run("for u in $(cut -f1 -d: /etc/passwd); do echo '=== user:'$u' ==='; crontab -u $u -l 2>/dev/null || true; done")
        safe_write(rpt, "user crontabs", out if out else err)
        if args.verbose: print("[*] user crontabs")

        # processes and listening ports (if available)
        rc, out, err = run("ps aux | head -n 200")
        safe_write(rpt, "ps aux (top 200 lines)", out if out else err)
        if args.verbose: print("[*] ps aux")

        if not args.no_netstat:
            rc, out, err = run("netstat -tuln 2>/dev/null || ss -tuln 2>/dev/null || true")
            safe_write(rpt, "listening ports (netstat/ss)", out if out else err)
            if args.verbose: print("[*] netstat/ss")

        # SUID files
        rc, out, err = run("find / -perm -4000 -type f -ls 2>/dev/null | head -n 200")
        safe_write(rpt, "SUID files (first 200)", out if out else err)
        if args.verbose: print("[*] SUID scan")

        # find shell scripts, py, pl under /home and /opt
        rc, out, err = run("find /home /opt -type f \\( -iname '*.sh' -o -iname '*.py' -o -iname '*.pl' \\) 2>/dev/null | head -n 200")
        safe_write(rpt, "scripts under /home and /opt (first 200)", out if out else err)
        if args.verbose: print("[*] script search done")

        # look for flag pattern across the filesystem (this is the most direct)
        rc, out, err = run("grep -RIn --binary-files=without-match -E 'deadface\\{|flag\\{' / 2>/dev/null | head -n 500")
        safe_write(rpt, "direct grep for flag patterns (first 500 hits)", out if out else err)
        if args.verbose: print("[*] direct flag grep done")

        # last: helpful hints written to report
        safe_write(rpt, "next_steps_hint",
                   "If you see promising file paths in this report, run:\n"
                   "    sed -n '1,400p' /path/to/file\n"
                   "or\n"
                   "    strings /path/to/binary | grep -Ei 'deadface|flag'")

        header(rpt, "End of report")

    if args.verbose:
        print(f"[+] Report saved to {report_path}")
    else:
        print(f"[+] Done. Report: {report_path}")

if __name__ == "__main__":
    main()
