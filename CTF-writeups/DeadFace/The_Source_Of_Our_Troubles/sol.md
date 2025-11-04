# very beginner challs

# will only writeup the hard ones
```
Flag from database backup vulnerability (deadface{b4ckup_f1l3s_sh0uld_b3_s3cur3d}): - red herring
```


```

Method: Navigated to a misconfigured backup directory (/backup/) exposed on the web server. Downloaded and reviewed a .sql database backup file which contained sensitive information, including flags and plaintext credentials.

Flag from hidden announcement (deadface{h1dd3n_4nn0unc3m3nts_r3v34l_s3cr3ts}):

Method: Used SQL injection via the search API endpoints to reveal “hidden” announcements that are not accessible through the regular UI. Specifically manipulated the search.php endpoint parameters to include is_hidden=1, exposing hidden database records that contained a flag.

Flag from classified research compromise (deadface{cl4ss1f13d_r3s34rch_unh4ck4bl3}):

Method: Performed SQL injection on the research API endpoint to enumerate and access classified research projects, which are not visible through normal navigation. This revealed details and the flag in records marked as classified in the database.

Flag for privileged user (IDOR/hidden admin) (deadface{1ns3cur3_d1r3ct_0bj3ct_r3f3r3nc3}):

Method: Exploited an Insecure Direct Object Reference (IDOR) vulnerability by directly manipulating URLs and user IDs in the admin interface (admin.php?view_user=16). This allowed viewing hidden users (such as backup_admin) that are not listed in the default admin UI, exposing their details and the flag.

