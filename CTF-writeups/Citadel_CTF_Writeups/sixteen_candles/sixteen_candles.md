# Sixteen Candles

300

🗼OSINT pt3: You find that the cake from the floor below was a token for citadweller whose birthday is coming up soon. There’s a plaque on a wall on this floor that says @citadwellersecrets with a play button engraved on it.

## Solution

The question description mentions a play button, along with an @ before the username, immediately hinting towards the platform being youtube.

i go to https://youtube.com/@citadwellersecrets, which is indeed a valid page.

there's a playlist named birthday playlist on the youtube channel with a single jerma video. the playlist description states:

```my birthday is coming up & you are all invited! i hope you are able to view the calendar invite from my gmail for more details on it```

and the channel description also states:

```
view the calendar invite to my birthday party for more details.
```

in the more info tab, we have an option to view the user's buisness email address by submitting a captcha. doing this yields us the email:

**citadweller@gmail.com**

as the playlist an channel description says, we have to view their calendar invite. my first thought is google calendar.

i open it and there's a search for people option where i can input emails. putting his email in there, we see an event scheduled for 7th October named "citadweller birthday" clicking on this yields the flag.

**citadel{c0ngr4tz_y0uv3_st4lk3d_m3_3n0ugh}**

