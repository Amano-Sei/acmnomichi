/*************************************************************************
    > File Name: poj3264rmq.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月29日 星期五 18时13分18秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 50005;
const int maxlen = 3000000;

int mm[maxn];
int dpm[maxn][16];
int dpM[maxn][16];

char buf[maxlen];
char outbuf[maxlen];
int ci, oi;

inline bool isnum(char c){
    return c >= '0' && c <= '9';
}
inline bool notnum(char c){
    return c < '0' || c > '9';
}

inline int read(){
    while(notnum(buf[ci]))
        ci++;
    register int ans = buf[ci++]-'0';
    while(isnum(buf[ci]))
        ans = ans*10+buf[ci++]-'0';
    return ans;
}

inline void out(int num){
    register int i = oi;
    do{
        outbuf[oi++] = (num%10)+'0';
        num /= 10;
    }while(num);
    for(int j = oi-1; i < j; i++, j--)
        swap(outbuf[i], outbuf[j]);
    outbuf[oi++] = '\n';
}

inline void init(int n){
    register int pt = -1;
    for(int i = 1; i <= n; i++){
        pt += ((i&(i-1))?0:1);
        mm[i] = pt;
        dpM[i][0] = dpm[i][0] = read();
    }
    register int ct;
    for(int j = 1; j <= mm[n]; j++){
        ct = 1<<(j-1);
        pt = n-(1<<j)+1;
        for(int i = 1; i <= pt; i++)
            dpm[i][j] = min(dpm[i][j-1], dpm[i+ct][j-1]), dpM[i][j] = max(dpM[i][j-1], dpM[i+ct][j-1]);
    }
}

inline int getans(int l, int r){
    register int tm = mm[r-l+1];
    r -= (1<<tm)-1;
    return max(dpM[l][tm], dpM[r][tm])-min(dpm[l][tm], dpm[r][tm]);
}

int main(){
    fread(buf, 1, maxlen, stdin);
    int n, q;
    n = read(); q = read();
    init(n);
    while(q--){
        register int cl = read(), cr = read();
        out(getans(cl, cr));
    }
    puts(outbuf);
    return 0;
}

