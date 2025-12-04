# day 3

this is a dns infra mapping ctf. idk much about it but i kept using dig on any domain i found and somehow got the flag.


- The DNS investigation of krampus.csd.lol began with SPF and DMARC records, where the DMARC ruf address leaked an internal subdomain: ops.krampus.csd.lol. Querying it revealed internal service endpoints via TXT, exposing three SRV records: LDAP and Kerberos pointing to dc01.krampus.csd.lol, and a metrics service pointing to beacon.krampus.csd.lol, the hidden command-and-control node. A TXT record on the beacon contained a Base64-encoded configuration string that decoded to exfil.krampus.csd.lol, the Syndicate’s exfiltration server. Querying this host revealed DKIM usage with selector syndicate, leading to the DKIM public key stored at syndicate._domainkey.krampus.csd.lol. Decoding the Base64 payload in its TXT record produced the final flag: csd{dn5_m19HT_B3_K1ND4_W0NKy}.

```
(base) ss@Satwik:~$ dig csd.lol ANY
dig csd.lol TXT
dig csd.lol MX
dig csd.lol NS
dig csd.lol SOA

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csd.lol ANY
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 63034
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csd.lol.                       IN      ANY

;; ANSWER SECTION:
csd.lol.                3600    IN      HINFO   "RFC8482" ""

;; Query time: 119 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (TCP)
;; WHEN: Thu Dec 04 16:54:45 UTC 2025
;; MSG SIZE  rcvd: 57


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 64480
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csd.lol.                       IN      TXT

;; AUTHORITY SECTION:
csd.lol.                1800    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 75 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:54:45 UTC 2025
;; MSG SIZE  rcvd: 101


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csd.lol MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 43504
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csd.lol.                       IN      MX

;; AUTHORITY SECTION:
csd.lol.                1190    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 314 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:54:45 UTC 2025
;; MSG SIZE  rcvd: 101


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csd.lol NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 56345
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csd.lol.                       IN      NS

;; ANSWER SECTION:
csd.lol.                86400   IN      NS      rajeev.ns.cloudflare.com.
csd.lol.                86400   IN      NS      harmony.ns.cloudflare.com.

;; Query time: 64 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:54:45 UTC 2025
;; MSG SIZE  rcvd: 96


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csd.lol SOA
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 18413
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csd.lol.                       IN      SOA

;; ANSWER SECTION:
csd.lol.                1800    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 21 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:54:46 UTC 2025
;; MSG SIZE  rcvd: 101

(base) ss@Satwik:~$ dig csdev.lol NSEC

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csdev.lol NSEC
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 8718
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csdev.lol.                     IN      NSEC

;; AUTHORITY SECTION:
csdev.lol.              3600    IN      SOA     dns1.p01.nsone.net. domains+netlify.netlify.com. 1759579222 43200 7200 1209600 3600

;; Query time: 108 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:55:50 UTC 2025
;; MSG SIZE  rcvd: 119

(base) ss@Satwik:~$ dig csdev.lol NSEC

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> csdev.lol NSEC
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 47407
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;csdev.lol.                     IN      NSEC

;; AUTHORITY SECTION:
csdev.lol.              3521    IN      SOA     dns1.p01.nsone.net. domains+netlify.netlify.com. 1759579222 43200 7200 1209600 3600

;; Query time: 54 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 16:57:07 UTC 2025
;; MSG SIZE  rcvd: 119

(base) ss@Satwik:~$ subfinder -d krampus.csd.lol
subfinder: command not found
(base) ss@Satwik:~$ dig +short _dmarc.krampus.csd.lol TXT | sed 's/"//g' | tr ' ' '\n' | egrep '^(rua=|ruf=|v=|p=)'
dig +short krampus.csd.lol TXT | sed 's/"//g' | tr ' ' '\n' | egrep '^(include=|ip4:|ip6:|v=)'
dig +short _spf.krampus.csd.lol TXT | sed 's/"//g' | tr ' ' '\n' | egrep '^(include=|ip4:|ip6:)'
v=DMARC1;
p=reject;
rua=mailto:dmarc@krampus.csd.lol;
ruf=mailto:forensics@ops.krampus.csd.lol;
v=spf1
ip4:203.0.113.0/24
(base) ss@Satwik:~$ dig ops.krampus.csd.lol
dig ops.krampus.csd.lol A
dig ops.krampus.csd.lol TXT
dig ops.krampus.csd.lol MX

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> ops.krampus.csd.lol
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 11177
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;ops.krampus.csd.lol.           IN      A

;; AUTHORITY SECTION:
csd.lol.                1754    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 357 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:36 UTC 2025
;; MSG SIZE  rcvd: 113


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> ops.krampus.csd.lol A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 10866
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;ops.krampus.csd.lol.           IN      A

;; Query time: 21 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:36 UTC 2025
;; MSG SIZE  rcvd: 48


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> ops.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 46049
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;ops.krampus.csd.lol.           IN      TXT

;; ANSWER SECTION:
ops.krampus.csd.lol.    300     IN      TXT     "internal-services: _ldap._tcp.krampus.csd.lol _kerberos._tcp.krampus.csd.lol _metrics._tcp.krampus.csd.lol"

;; Query time: 21 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:36 UTC 2025
;; MSG SIZE  rcvd: 167


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> ops.krampus.csd.lol MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 64215
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;ops.krampus.csd.lol.           IN      MX

;; AUTHORITY SECTION:
csd.lol.                840     IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 216 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:36 UTC 2025
;; MSG SIZE  rcvd: 113

(base) ss@Satwik:~$ dig forensics.krampus.csd.lol
dig forensics.ops.krampus.csd.lol

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> forensics.krampus.csd.lol
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 61665
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;forensics.krampus.csd.lol.     IN      A

;; AUTHORITY SECTION:
csd.lol.                814     IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 303 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:44 UTC 2025
;; MSG SIZE  rcvd: 119


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> forensics.ops.krampus.csd.lol
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 64728
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;forensics.ops.krampus.csd.lol. IN      A

;; AUTHORITY SECTION:
csd.lol.                832     IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 303 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:00:45 UTC 2025
;; MSG SIZE  rcvd: 123

(base) ss@Satwik:~$ dig _ldap._tcp.krampus.csd.lol SRV

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _ldap._tcp.krampus.csd.lol SRV
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 64060
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;_ldap._tcp.krampus.csd.lol.    IN      SRV

;; ANSWER SECTION:
_ldap._tcp.krampus.csd.lol. 300 IN      SRV     0 0 389 dc01.krampus.csd.lol.

;; Query time: 1180 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:01:41 UTC 2025
;; MSG SIZE  rcvd: 84

(base) ss@Satwik:~$ dig _ldap._tcp.krampus.csd.lol TXT

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _ldap._tcp.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 50366
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_ldap._tcp.krampus.csd.lol.    IN      TXT

;; AUTHORITY SECTION:
csd.lol.                1372    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 75 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:01:52 UTC 2025
;; MSG SIZE  rcvd: 120

(base) ss@Satwik:~$ dig _ldap._tcp.krampus.csd.lol ANY

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _ldap._tcp.krampus.csd.lol ANY
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 36022
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_ldap._tcp.krampus.csd.lol.    IN      ANY

;; ANSWER SECTION:
_ldap._tcp.krampus.csd.lol. 276 IN      SRV     0 0 389 dc01.krampus.csd.lol.

;; Query time: 10 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (TCP)
;; WHEN: Thu Dec 04 17:02:04 UTC 2025
;; MSG SIZE  rcvd: 95

(base) ss@Satwik:~$ dig _kerberos._tcp.krampus.csd.lol SRV

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _kerberos._tcp.krampus.csd.lol SRV
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 30292
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_kerberos._tcp.krampus.csd.lol.        IN      SRV

;; ANSWER SECTION:
_kerberos._tcp.krampus.csd.lol. 300 IN  SRV     0 0 88 dc01.krampus.csd.lol.

;; Query time: 32 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:02:15 UTC 2025
;; MSG SIZE  rcvd: 99

(base) ss@Satwik:~$ dig _kerberos._tcp.krampus.csd.lol TXT

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _kerberos._tcp.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 18738
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_kerberos._tcp.krampus.csd.lol.        IN      TXT

;; AUTHORITY SECTION:
csd.lol.                1757    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 108 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:02:22 UTC 2025
;; MSG SIZE  rcvd: 124

(base) ss@Satwik:~$ dig _metrics._tcp.krampus.csd.lol SRV
dig _metrics._tcp.krampus.csd.lol TXT
dig _metrics._tcp.krampus.csd.lol ANY

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _metrics._tcp.krampus.csd.lol SRV
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 65095
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_metrics._tcp.krampus.csd.lol. IN      SRV

;; ANSWER SECTION:
_metrics._tcp.krampus.csd.lol. 300 IN   SRV     0 0 443 beacon.krampus.csd.lol.

;; Query time: 194 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:02:32 UTC 2025
;; MSG SIZE  rcvd: 100


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _metrics._tcp.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 65011
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_metrics._tcp.krampus.csd.lol. IN      TXT

;; AUTHORITY SECTION:
csd.lol.                1637    IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 54 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:02:32 UTC 2025
;; MSG SIZE  rcvd: 123


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> _metrics._tcp.krampus.csd.lol ANY
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 9525
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;_metrics._tcp.krampus.csd.lol. IN      ANY

;; ANSWER SECTION:
_metrics._tcp.krampus.csd.lol. 300 IN   SRV     0 0 443 beacon.krampus.csd.lol.

;; Query time: 10 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (TCP)
;; WHEN: Thu Dec 04 17:02:32 UTC 2025
;; MSG SIZE  rcvd: 100

(base) ss@Satwik:~$ dig beacon.krampus.csd.lol A

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> beacon.krampus.csd.lol A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 23917
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;beacon.krampus.csd.lol.                IN      A

;; ANSWER SECTION:
beacon.krampus.csd.lol. 300     IN      A       203.0.113.2

;; Query time: 259 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:03:46 UTC 2025
;; MSG SIZE  rcvd: 67

(base) ss@Satwik:~$ dig beacon.krampus.csd.lol A

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> beacon.krampus.csd.lol A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 8263
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;beacon.krampus.csd.lol.                IN      A

;; ANSWER SECTION:
beacon.krampus.csd.lol. 290     IN      A       203.0.113.2

;; Query time: 86 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:03:55 UTC 2025
;; MSG SIZE  rcvd: 67

(base) ss@Satwik:~$ dig beacon.krampus.csd.lol CNAME

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> beacon.krampus.csd.lol CNAME
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 20163
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;beacon.krampus.csd.lol.                IN      CNAME

;; AUTHORITY SECTION:
csd.lol.                629     IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 54 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:04:06 UTC 2025
;; MSG SIZE  rcvd: 116

(base) ss@Satwik:~$ dig beacon.krampus.csd.lol CNAME

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> beacon.krampus.csd.lol CNAME
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 56937
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;beacon.krampus.csd.lol.                IN      CNAME

;; AUTHORITY SECTION:
csd.lol.                593     IN      SOA     harmony.ns.cloudflare.com. dns.cloudflare.com. 2390291443 10000 2400 604800 1800

;; Query time: 64 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:04:22 UTC 2025
;; MSG SIZE  rcvd: 116

(base) ss@Satwik:~$ dig beacon.krampus.csd.lol TXT +noall +answer
beacon.krampus.csd.lol. 300     IN      TXT     "config=ZXhmaWwua3JhbXB1cy5jc2QubG9s=="
(base) ss@Satwik:~$ dig exfil.krampus.csd.lol TXT
dig exfil.krampus.csd.lol A
dig exfil.krampus.csd.lol ANY

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> exfil.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 48450
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;exfil.krampus.csd.lol.         IN      TXT

;; ANSWER SECTION:
exfil.krampus.csd.lol.  300     IN      TXT     "status=active; auth=dkim; selector=syndicate"

;; Query time: 54 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:05:52 UTC 2025
;; MSG SIZE  rcvd: 107


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> exfil.krampus.csd.lol A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 20392
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;exfil.krampus.csd.lol.         IN      A

;; Query time: 249 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:05:53 UTC 2025
;; MSG SIZE  rcvd: 50


; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> exfil.krampus.csd.lol ANY
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 62575
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;exfil.krampus.csd.lol.         IN      ANY

;; ANSWER SECTION:
exfil.krampus.csd.lol.  3600    IN      HINFO   "RFC8482" ""

;; Query time: 21 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (TCP)
;; WHEN: Thu Dec 04 17:05:53 UTC 2025
;; MSG SIZE  rcvd: 71

(base) ss@Satwik:~$ dig syndicate._domainkey.krampus.csd.lol TXT

; <<>> DiG 9.18.39-0ubuntu0.24.04.2-Ubuntu <<>> syndicate._domainkey.krampus.csd.lol TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 12339
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;syndicate._domainkey.krampus.csd.lol. IN TXT

;; ANSWER SECTION:
syndicate._domainkey.krampus.csd.lol. 300 IN TXT "v=DKIM1; k=rsa; p=Y3Nke2RuNV9tMTlIVF9CM19LMU5ENF9XME5LeX0="

;; Query time: 184 msec
;; SERVER: 10.255.255.254#53(10.255.255.254) (UDP)
;; WHEN: Thu Dec 04 17:06:21 UTC 2025
;; MSG SIZE  rcvd: 136

(base) ss@Satwik:~$
```

Flag : `csd{dn5_m19HT_B3_K1ND4_W0NKy}`