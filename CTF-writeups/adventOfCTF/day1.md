# Day 1 ( crypto )

we are given start.txt : 
```
00110101 00111001 00110011 00110011 00110100 01100101 00110110 01100010 00110110 00110101 00110011 00110001 00110110 00110011 00110111 01100001 00110110 00110010 00110100 00110111 00110100 01100100 00110111 00110111 00110110 00110010 00110101 00110100 00110100 01100101 00110110 00110110 00110100 01100110 00110100 00110111 00110100 00110110 00110100 00110100 00110101 00110011 00110011 00110001 00110011 00111000 00110011 00110011 00110100 01100100 00110100 00110110 00110011 00111001 00110110 00111000 00110101 01100001 00110100 00111000 00110101 00111001 00110111 01100001 00110101 00110100 00110110 01100001 00110110 00110100 00110110 00110110 00110100 01100100 00110110 01100001 00110100 00110001 00110111 00111001 00110100 01100101 00110101 00111000 00110011 00110000 00110011 01100100
```

- very beginner challenge this is just binary so instead of using cyber chef lets just practise my scripting in cpp.


- sol script : 
```cpp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int letter[8];
    int count = 0;
    ifstream binary("start.txt");
    string line;
    char c;
    while(binary >> c) { 
        line+=c;
    }

    // cout<<line;
    // cout<<line[0];
    //cout<<"line lenght :"<<line.size();
    int i=0;
    int l[8];
    
    while(line[i]!='\0')
    {   int sum=0;
        for(int j=0;j<8;j++){
            l[j]=line[i]-'0';
            i++;
        }
        
        int k=0;
        for(int j=7;j>=0;j--){
            //cout<<l[j]<<endl;
            sum += l[j]*(pow(2,k++));
            
        }
        char fin = sum;
        cout<<fin;
    }

    return 0;
}
```

which gives this output : 

`59334e6b6531637a62474d7762544e664f474644533138334d4639685a48597a546a64664d6a41794e58303d`

- this is hex output and if we convert to raw bytes.

- wrote a function to convert from hex to bytes : 


```cpp
char from_hex(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'a' && c <= 'f') return c - 'a' + 10;
    if(c >= 'A' && c <= 'F') return c - 'A' + 10;
    
}

string hex_decode(const string &hex) {
   

    string out;
    out.reserve(hex.size() / 2);

    for (size_t i = 0; i < hex.size(); i += 2) {
        unsigned char hi = from_hex(hex[i]);
        unsigned char lo = from_hex(hex[i+1]);
        out.push_back((hi << 4) | lo);
    }
    return out;
}
```

which gives base64 : `Y3Nke1czbGMwbTNfOGFDS183MF9hZHYzTjdfMjAyNX0=`

- i didnt bother writing cpp for conversion from base64 since building the lookp table is kinda boring.
  
which on conversion to plain text we get : 

flag : `csd{W3lc0m3_8aCK_70_adv3N7_2025}`

