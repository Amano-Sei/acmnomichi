/*************************************************************************
    > File Name: hdu4578int.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月06日 星期三 10时38分17秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int mod = 10007;

struct node{
    int l, r;
    int sum[3];
    int addlz;
    int mullz;
    int chlz;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { l, r, 0, 0, 0, 0, 1, -1 };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

inline void push_down_add(int x);

inline void chswitch(int x, int chlz){
    st[x].chlz = chlz;
    st[x].addlz = 0;
    st[x].mullz = 1;
    register int xc = st[x].r-st[x].l+1;
    st[x].sum[0] = (chlz*xc)%mod;
    st[x].sum[1] = (chlz*st[x].sum[0])%mod;
    st[x].sum[2] = (chlz*st[x].sum[1])%mod;
}

inline void push_down_ch(int x){
    register int chlz = st[x].chlz;
    if(chlz >= 0){
        st[x].chlz = -1;
        chswitch(x<<1, chlz);
        chswitch((x<<1)|1, chlz);
    }
}

inline void mulswitch(int x, int mullz, int mullz2, int mullz3){
    if(st[x].l < st[x].r){
        if(st[x].chlz >= 0)
            st[x].chlz = (st[x].chlz*mullz)%mod;
        else{
            push_down_add(x);
            st[x].mullz = (st[x].mullz*mullz)%mod; 
        }
    }
    st[x].sum[0] = (st[x].sum[0] * mullz) % mod;
    st[x].sum[1] = (st[x].sum[1] * mullz2) % mod;
    st[x].sum[2] = (st[x].sum[2] * mullz3) % mod;
}
inline void push_down_mul(int x){
    register int mullz = st[x].mullz;
    if(mullz != 1){
        st[x].mullz = 1;
        register int mullz2 = (mullz*mullz)%mod;
        register int mullz3 = (mullz*mullz2)%mod;
        mulswitch(x<<1, mullz, mullz2, mullz3);
        mulswitch((x<<1)|1, mullz, mullz2, mullz3);
    }
}

inline void addswitch(int x, long long addlz, long long addlz2, long long addlz3){
    if(st[x].l < st[x].r){
        if(st[x].chlz >= 0)
            st[x].chlz = (st[x].chlz+addlz)%mod;
        else{
            push_down_mul(x);
            st[x].addlz = (st[x].addlz+addlz)%mod;
        }
    }
    register long long xc = st[x].r-st[x].l+1;
    st[x].sum[2] = (st[x].sum[2]+3*st[x].sum[1]*addlz+3*st[x].sum[0]*addlz2+xc*addlz3)%mod;
    st[x].sum[1] = (st[x].sum[1]+2*st[x].sum[0]*addlz+xc*addlz2)%mod;
    st[x].sum[0] = (st[x].sum[0]+addlz*xc)%mod;
}

inline void push_down_add(int x){
    register long long addlz = st[x].addlz;
    if(addlz){
        st[x].addlz = 0;
        register long long addlz2 = (addlz*addlz)%mod;
        register long long addlz3 = (addlz2*addlz)%mod;
        addswitch(x<<1, addlz, addlz2, addlz3);
        addswitch((x<<1)|1, addlz, addlz2, addlz3);
    }
}

inline void push_down(int x){
    push_down_ch(x);
    push_down_mul(x);
    push_down_add(x);
}

inline void push_up(int x){
    register int lc = x<<1;
    register int rc = lc|1;
    st[x].sum[0] = (st[lc].sum[0]+st[rc].sum[0])%mod;
    st[x].sum[1] = (st[lc].sum[1]+st[rc].sum[1])%mod;
    st[x].sum[2] = (st[lc].sum[2]+st[rc].sum[2])%mod;
}

void add(int x, int l, int r, int val){
    if(l <= st[x].l && st[x].r <= r){
        register int val2 = (val*val)%mod;
        register int val3 = (val2*val)%mod;
        addswitch(x, val, val2, val3);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        add(x<<1, l, r, val);
    else if(m < l)
        add((x<<1)|1, l, r, val);
    else
        add(x<<1, l, m, val), add((x<<1)|1, m+1, r, val);
    push_up(x);
}

void mul(int x, int l, int r, int val){
    if(l <= st[x].l && st[x].r <= r){
        register int val2 = (val*val)%mod;
        register int val3 = (val2*val)%mod;
        mulswitch(x, val, val2, val3);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        mul(x<<1, l, r, val);
    else if(m < l)
        mul((x<<1)|1, l, r, val);
    else
        mul(x<<1, l, m, val), mul((x<<1)|1, m+1, r, val);
    push_up(x);
}

void ch(int x, int l, int r, int val){
    if(l <= st[x].l && st[x].r <= r){
        chswitch(x, val);
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        ch(x<<1, l, r, val);
    else if(m < l)
        ch((x<<1)|1, l, r, val);
    else
        ch(x<<1, l, m, val), ch((x<<1)|1, m+1, r, val);
    push_up(x);
}

int query(int x, int l, int r, int p){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].sum[p];
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r, p);
    else if(m < l)
        return query((x<<1)|1, l, r, p);
    else
        return query(x<<1, l, m, p)+query((x<<1)|1, m+1, r, p);
}

int main(){
    int n, m;
    int co, cx, cy, cz;
    static void *rt[4] = { &&foradd, &&formul, &&forch, &&forquery };
    while(scanf("%d%d", &n, &m) != EOF && n){
        if(m-- == 0)
            continue;
        built(1, 1, n);
        myloop:
            scanf("%d%d%d%d", &co, &cx, &cy, &cz);
            goto *rt[co-1];
        foradd:
            add(1, cx, cy, cz);
            if(m-- == 0)
                continue;
            goto myloop;
        formul:
            mul(1, cx, cy, cz);
            if(m-- == 0)
                continue;
            goto myloop;
        forch:
            ch(1, cx, cy, cz);
            if(m-- == 0)
                continue;
            goto myloop;
        forquery:
            printf("%d\n", query(1, cx, cy, cz-1)%mod);
            if(m-- == 0)
                continue;
            goto myloop;
    }
    return 0;
}

