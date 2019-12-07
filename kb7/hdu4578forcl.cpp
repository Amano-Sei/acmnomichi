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

//为了确认是否是因为快速读产生的差距，我决定用c++交下，但是我的代码有一个gnu拓展

const int maxn = 100005;
const int mod = 10007;

int st[maxn<<2];

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
    int n, m;
    int co, cx, cy, cz;
    while(scanf("%d%d", &n, &m) != EOF && n){
        st[1] = 0;
        while(m--){
            scanf("%d%d%d%d", &co, &cx, &cy, &cz);
            switch(co){
                case 1:
                    add(1, 1, n, cx, cy, cz);
                    break;
                case 2:
                    mul(1, 1, n, cx, cy, cz);
                    break;
                case 3:
                    ch(1, 1, n, cx, cy, cz);
                    break;
                case 4:
                    printf("%d\n", query(1, 1, n, cx, cy, cz)%mod);
            }
        }
    }
    return 0;
}

