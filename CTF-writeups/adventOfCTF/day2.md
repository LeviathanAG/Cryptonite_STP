# day 2

we are given a pcap file and we have to find the username and password which allowed login. pretty easy to filter the packets in wireshark.


- since its an ftp response we can do `ftp contains log in` an sift thru the cannot log in msgs to get the flag easily or just do `ftp contains logged in` but i didnt know the ftp response so i just had to brute a lil.