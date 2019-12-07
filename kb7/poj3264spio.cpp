/*************************************************************************
    > File Name: poj3264.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月29日 星期五 17时50分40秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50005;
const int inf = 0x3f3f3f3f;

const int maxlen = 3000000;

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

struct node{
    int l, r;
    int cmin, cmax;
}st[maxn<<4];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        //scanf("%d", &st[x].cmin);
        //st[x].cmax = st[x].cmin;
        st[x].cmax = st[x].cmin = read();
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].cmin = min(st[x<<1].cmin, st[(x<<1)|1].cmin);
    st[x].cmax = max(st[x<<1].cmax, st[(x<<1)|1].cmax);
}

void query(int x, int l, int r, int &tmin, int &tmax){
    if(l <= st[x].l && st[x].r <= r){
        tmin = min(tmin, st[x].cmin);
        tmax = max(tmax, st[x].cmax);
        return;
    }
    int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        query(x<<1, l, r, tmin, tmax);
    else if(l > m)
        query((x<<1)|1, l, r, tmin, tmax);
    else
        query(x<<1, l, m, tmin, tmax), query((x<<1)|1, m+1, r, tmin, tmax);
}

int main(){
    fread(buf, 1, maxlen, stdin);
    int n = read(), q = read();
    built(1, 1, n);
    int cl, cr, cmin, cmax;
    while(q--){
        //scanf("%d%d", &cl, &cr);
        cl = read(); cr = read();
        cmin = inf;
        cmax = 0;
        query(1, cl, cr, cmin, cmax);
        //printf("%d\n", cmax-cmin);
        //oi += sprintf(&outbuf[oi], "%d\n", cmax-cmin);
        out(cmax-cmin);
    }
    puts(outbuf);
    return 0;
}

