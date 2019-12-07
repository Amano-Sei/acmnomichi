/*************************************************************************
    > File Name: cseg.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月09日 星期六 14时18分06秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

//小小总结一下就是更新子节点时不要忘记反补父节点（
//任何运算都需要求余，如果有可能溢出有必要开long long

const int maxn = 10005;
const int mod = 20050321;

struct node{
    int l, r;
    long long flag;
    long long sum;
}st[maxn];

void built(int x, int l, int r){
    st[x] = { l, r, 1, 0 };
    if(l == r)
        return;
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

inline void mulpoint(int x, long long tf){
    st[x].flag = st[x].flag*tf%mod;
    st[x].sum = st[x].sum*tf%mod;
}

void down(int x){
    if(st[x].flag == 1)
        return;
    mulpoint(x<<1, st[x].flag);
    mulpoint((x<<1)|1, st[x].flag);
    st[x].flag = 1;
}

long long query(int x, int l, int r){
    if(st[x].l >= l && st[x].r <= r)
        return st[x].sum;
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(m < l)
        return query((x<<1)|1, l, r);
    else if(m >= r)
        return query(x<<1, l, r);
    else
        return (query(x<<1, l, m)+query((x<<1)|1, m+1, r))%mod;
}

void addpoint(int x, int pos, int val){
    if(st[x].l == pos && st[x].r == pos){
        st[x].sum = (st[x].sum+val)%mod;
        return;
    }
    down(x);
    st[x].sum = (st[x].sum+val)%mod;
    int m = (st[x].l+st[x].r)>>1;
    if(m < pos)
        addpoint((x<<1)|1, pos, val);
    else
        addpoint(x<<1, pos, val);
}

void mul2sco(int x, int l, int r){
    if(st[x].l >= l && st[x].r <= r){
        mulpoint(x, 2);
        return;
    }
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(m >= l)
        mul2sco(x<<1, l, r);
    if(m < r)
        mul2sco((x<<1)|1, l, r);
    st[x].sum = (st[x<<1].sum+st[(x<<1)|1].sum)%mod;
}

int main(){
    int n, m, cl, cr;
    int cpow2 = 1;
    scanf("%d%d", &n, &m);
    built(1, 1, n);
    addpoint(1, n, 1);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &cl, &cr);
        if(cl-2 > 0)
            mul2sco(1, 1, cl-2);
        if(cl-1 > 0)
            addpoint(1, cl-1, cpow2);
        if(cr < n)
            mul2sco(1, cr+1, n);
        addpoint(1, cr, cpow2);
        printf("%lld\n", query(1, 1, n));
        cpow2 = (cpow2<<1)%mod;
    }
    return 0;
}

