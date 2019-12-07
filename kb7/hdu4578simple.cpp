/*************************************************************************
    > File Name: hdu4578simple.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月06日 星期三 12时07分17秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//其实是在重新反思了下ch的存在，意识到其实没必要维护3个标记
//这些数本来就是一堆连续的相同数字...
//把结构体去掉有一个好处就是省去了一个不必要的初始化
//加上快速io不出意外冲榜成功
//但是可以看到袁恩的榜1应该并不是快速读，所以应该是还有什么优化吧（

const int maxn = 100005;
const int mod = 10007;

int st[maxn<<2];
char buf[maxn*10*24];
int ci;
char outbuf[maxn*60];
int oi;

inline bool isnum(char c){
    return c>='0' && c <= '9';
}
inline bool notnum(char c){
    return c<'0' || c>'9';
}

inline int read(){
    while(notnum(buf[ci]))
        ci++;
    register int ans = buf[ci++]-'0';
    while(isnum(buf[ci]))
        ans = ans*10+buf[ci++]-'0';
    return ans;
}

inline void out(int x){
    register int ti = oi;
    register int tti = oi;
    do{
        outbuf[ti++] = (x%10)+'0';
        x /= 10;
    }while(x);
    oi = ti+1;
    outbuf[ti--] = '\n';
    while(tti < ti)
        swap(outbuf[ti--], outbuf[tti++]);
}

inline void push_down(int x){
    if(st[x] >= 0)
        st[x<<1] = st[(x<<1)|1] = st[x];
}

inline void push_up(int x){
    if(st[x<<1] == st[(x<<1)|1])
        st[x] = st[x<<1];
    else
        st[x] = -1;
}

void add(int x, int L, int R, int l, int r, int val){
    if(st[x] >= 0 && l <= L && R <= r){
        st[x] = (st[x]+val)%mod;
        return;
    }
    push_down(x);
    register int M = (L+R)>>1;
    if(r <= M)
        add(x<<1, L, M, l, r, val);
    else if(M < l)
        add((x<<1)|1, M+1, R, l, r, val);
    else
        add(x<<1, L, M, l, M, val), add((x<<1)|1, M+1, R, M+1, r, val);
    push_up(x);
}

void mul(int x, int L, int R, int l, int r, int val){
    if(st[x] >= 0 && l <= L && R <= r){
        st[x] = (st[x]*val)%mod;
        return;
    }
    push_down(x);
    register int M = (L+R)>>1;
    if(r <= M)
        mul(x<<1, L, M, l, r, val);
    else if(M < l)
        mul((x<<1)|1, M+1, R, l, r, val);
    else
        mul(x<<1, L, M, l, M, val), mul((x<<1)|1, M+1, R, M+1, r, val);
    push_up(x);
}

void ch(int x, int L, int R, int l, int r, int val){
    if(l <= L && R <= r){
        st[x] = val;
        return;
    }
    push_down(x);
    register int M = (L+R)>>1;
    if(r <= M)
        ch(x<<1, L, M, l, r, val);
    else if(M < l)
        ch((x<<1)|1, M+1, R, l, r, val);
    else
        ch(x<<1, L, M, l, M, val), ch((x<<1)|1, M+1, R, M+1, r, val);
    push_up(x);
}

int query(int x, int L, int R, int l, int r, int p){
    if(st[x] >= 0 && l <= L && R <= r){
        register long long tval = st[x];
        while(--p)
            tval = tval*st[x];
        return (R-L+1)*tval%mod;
    }
    push_down(x);
    register int M = (L+R)>>1;
    if(r <= M)
        return query(x<<1, L, M, l, r, p);
    else if(M < l)
        return query((x<<1)|1, M+1, R, l, r, p);
    else
        return query(x<<1, L, M, l, M, p)+query((x<<1)|1, M+1, R, M+1, r, p);
}

int main(){
    //freopen("indesu", "r", stdin);
    //freopen("outdesu", "w", stdout);
    int n, m;
    int co, cx, cy, cz;
    static void *rt[4] = { &&foradd, &&formul, &&forch, &&forquery };
    fread(buf, 1, sizeof(buf), stdin);
    while((n = read()) != 0){
        m = read();
        st[1] = 0;
        myloop:
            co = read()-1, cx = read(), cy = read(), cz = read();
            goto *rt[co];
        foradd:
            add(1, 1, n, cx, cy, cz);
            if(--m > 0)
                goto myloop;
            continue;
        formul:
            mul(1, 1, n, cx, cy, cz);
            if(--m > 0)
                goto myloop;
            continue;
        forch:
            ch(1, 1, n, cx, cy, cz);
            if(--m > 0)
                goto myloop;
            continue;
        forquery:
            //printf("%d\n", query(1, 1, n, cx, cy, cz)%mod);
            out(query(1, 1, n, cx, cy, cz)%mod);
            if(--m > 0)
                goto myloop;
            continue;
    }
    outbuf[oi-1] = '\0';
    puts(outbuf);
    return 0;
}

