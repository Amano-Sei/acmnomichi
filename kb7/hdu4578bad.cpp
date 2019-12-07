/*************************************************************************
    > File Name: hdu4578.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月04日 星期三 20时20分17秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const long long mod = 10007;

struct node{
    int l, r;
    long long sum[3];
    long long addlz;
    long long mullz;
    long long changelz;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { l, r, 0, 0, 0, 0, 1, 0 };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

inline void push_down(int);
inline void push_down_change(int);
inline void push_down_mul(int);
inline void push_down_add(int);

inline void push_down_change(int x){
    if(st[x].changelz){
        push_down(x<<1);
        push_down((x<<1)|1);
        st[x<<1].changelz = st[(x<<1)|1].changelz = st[x].changelz;
        st[x<<1].sum[0] = (st[x<<1].r-st[x<<1].l+1)*st[x].changelz%mod;
        st[x<<1].sum[1] = st[x<<1].sum[0]*st[x].changelz%mod;
        st[x<<1].sum[2] = st[x<<1].sum[1]*st[x].changelz%mod;
        st[(x<<1)|1].sum[0] = (st[(x<<1)|1].r-st[(x<<1)|1].l+1)*st[x].changelz%mod;
        st[(x<<1)|1].sum[1] = st[(x<<1)|1].sum[0]*st[x].changelz%mod;
        st[(x<<1)|1].sum[2] = st[(x<<1)|1].sum[1]*st[x].changelz%mod;
        st[x].changelz = 0;
    }
}
inline void push_down_mul(int x){
    if(st[x].mullz != 1){
        push_down(x<<1);
        push_down((x<<1)|1);
        st[x<<1].mullz = st[(x<<1)|1].mullz = st[x].mullz;
        st[x<<1].sum[0] *= st[x].mullz;
        st[x<<1].sum[0] %= mod;
        st[x<<1].sum[1] *= st[x].mullz*st[x].mullz%mod;
        st[x<<1].sum[1] %= mod;
        st[x<<1].sum[2] *= st[x].mullz*st[x].mullz%mod*st[x].mullz%mod;
        st[x<<1].sum[2] %= mod;
        st[(x<<1)|1].sum[0] *= st[x].mullz;
        st[(x<<1)|1].sum[0] %= mod;
        st[(x<<1)|1].sum[1] *= st[x].mullz*st[x].mullz%mod;
        st[(x<<1)|1].sum[1] %= mod;
        st[(x<<1)|1].sum[2] *= st[x].mullz*st[x].mullz%mod*st[x].mullz%mod;
        st[(x<<1)|1].sum[2] %= mod;
        st[x].mullz = 1;
    }
}
inline void push_down_add(int x){
    if(st[x].addlz){
        push_down(x<<1);
        push_down((x<<1)|1);
        register long long addlz2 = st[x].addlz * st[x].addlz % mod;
        register long long addlz3 = addlz2 * st[x].addlz % mod;
        st[x<<1].addlz += st[x].addlz;
        st[x<<1].addlz %= mod;
        st[(x<<1)|1].addlz += st[x].addlz;
        st[(x<<1)|1].addlz %= mod;
        st[x<<1].sum[2] = st[x<<1].sum[2]+3*(st[x<<1].sum[1]*st[x].addlz%mod+st[x<<1].sum[0]*addlz2%mod)%mod+addlz3*(st[x<<1].r-st[x<<1].l+1)%mod;
        st[x<<1].sum[2] %= mod;
        st[x<<1].sum[1] += 2*st[x<<1].sum[0]*st[x].addlz%mod+(st[x<<1].r-st[x<<1].l+1)*addlz2%mod;
        st[x<<1].sum[1] %= mod;
        st[x<<1].sum[0] = st[x<<1].sum[0]+(st[x<<1].r-st[x<<1].l+1)*st[x].addlz%mod;
        st[x<<1].sum[0] %= mod;
        st[(x<<1)|1].sum[2] += 3*(st[(x<<1)|1].sum[1]*st[x].addlz+st[(x<<1)|1].sum[0]*addlz2)+addlz3*(st[(x<<1)|1].r-st[(x<<1)|1].l+1);
        st[(x<<1)|1].sum[1] += 2*st[(x<<1)|1].sum[0]*st[x].addlz+(st[(x<<1)|1].r-st[(x<<1)|1].l+1)*addlz2;
        st[(x<<1)|1].sum[0] += (st[(x<<1)|1].r-st[(x<<1)|1].l+1)*st[x].addlz;
        st[x].addlz = 0;
    }
}

inline void push_down(int x){
    if(st[x].l == st[x].r)
        return;
    push_down_change(x);
    push_down_add(x);
    push_down_mul(x);
}

inline void push_up(int x){
    st[x].sum[0] = (st[x<<1].sum[0]+st[(x<<1)|1].sum[0])%mod;
    st[x].sum[1] = (st[x<<1].sum[1]+st[(x<<1)|1].sum[1])%mod;
    st[x].sum[2] = (st[x<<1].sum[2]+st[(x<<1)|1].sum[2])%mod;
}

void add(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        if(l != r){
            push_down_change(x);
            push_down_mul(x);
        }
        register long long val2 = val*val%mod;
        register long long val3 = val2*val%mod;
        st[x].addlz += val;
        st[x].sum[2] = st[x].sum[2]+3*(st[x].sum[1]*val%mod+st[x].sum[0]*val2%mod)%mod+val3*(st[x].r-st[x].l+1)%mod;
        st[x].sum[2] %= mod;
        st[x].sum[1] = st[x].sum[1]+2*st[x].sum[0]*val%mod+(st[x].r-st[x].l+1)*val2%mod;
        st[x].sum[1] %= mod;
        st[x].sum[0] += (st[x].r-st[x].l+1)*st[x].addlz%mod;
        st[x].sum[0] %= mod;
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

void mul(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        if(l != r){
            push_down_change(x);
            push_down_add(x);
        }
        st[x].mullz *= val;
        st[x].sum[2] = st[x].sum[2]*val%mod*val%mod*val%mod;
        st[x].sum[1] = st[x].sum[1]*val%mod*val%mod;
        st[x].sum[0] = st[x].sum[0]*val%mod;
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

void change(int x, int l, int r, long long val){
    if(l <= st[x].l && st[x].r <= r){
        st[x].changelz = val;
        st[x].sum[0] = val*(st[x].r-st[x].l+1)%mod;
        st[x].sum[1] = st[x].sum[0]*val%mod;
        st[x].sum[2] = st[x].sum[1]*val%mod;
        return;
    }
    push_down(x);
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        change(x<<1, l, r, val);
    else if(m < l)
        change((x<<1)|1, l, r, val);
    else
        change(x<<1, l, m, val), change((x<<1)|1, m+1, r, val);
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
        return (query(x<<1, l, m, p)+query((x<<1)|1, m+1, r, p))%mod;
}

int main(){
    int n, m;
    int co, cx, cy, cz;
    while(scanf("%d%d", &n, &m) != EOF && n){
        built(1, 1, n);
        while(m--){
            scanf("%d%d%d%d", &co, &cx, &cy, &cz);
            switch(co){
                case 1:
                    add(1, cx, cy, cz);
                    break;
                case 2:
                    mul(1, cx, cy, cz);
                    break;
                case 3:
                    change(1, cx, cy, cz);
                    break;
                case 4:
                    printf("%lld\n", query(1, cx, cy, cz-1)%mod);
                    break;
            }
        }
    }
    return 0;
}

