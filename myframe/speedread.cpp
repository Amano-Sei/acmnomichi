/*************************************************************************
    > File Name: speedread.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月07日 星期四 15时40分53秒
 ************************************************************************/

#include <cstdio>
#define ISNUM(x) ((x)>='0'&&(x)<='9')

int Read(){
    char c;
    while(!ISNUM(c=getchar()));
    int ans = c-'0';
    while(ISNUM(c=getchar()))
        ans = ans*10+c-'0';
    return ans;
}

char buf[1000];
int ci;

int Read2(){
    while(!ISNUM(buf[ci]))
        if(buf[ci])
            ci++;
        else{
            fgets(buf, 1000, stdin);
            ci = 0;
        }
    int ans = buf[ci++]-'0';
    while(ISNUM(buf[ci]))
        ans = ans*10+buf[ci++]-'0';
    return ans;
}

const int maxn = 1000005;

char superbuf[maxn];
int ci;

void Read3_init(){
    fread(superbuf, 1, maxn, stdin);
    ci = 0;
}

int Read3(){
    while(!(ISNUM(superbuf[ci])))
        ci++;
    int ans = superbuf[ci]-'0';
    while(ISNUM(superbuf[ci]))
        ans = ans*10+superbuf[ci++]-'0';
    return ans;
}

