/*************************************************************************
    > File Name: poj3468.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月26日 星期二 22时24分47秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;

//什么最后一道题没写完积极跑回来...
//没写完跑回来还不是你菜（（（

//因为优雅版对于理解没有帮助，所以接下来会使用不优雅版的
//顺便bin神的代码好惨，跑到了3985ms...

struct node{
    long long val;
    long long lz;
    int l, r;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        scanf("%lld", &st[x].val);
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
}

inline void down(int x){
    if(st[x].lz){
        st[x<<1].lz += st[x].lz;
        st[x<<1].val += st[x].lz*(st[x<<1].r-st[x<<1].l+1);
        st[(x<<1)|1].lz += st[x].lz;
        st[(x<<1)|1].val += st[x].lz*(st[(x<<1)|1].r-st[(x<<1)|1].l+1);
        st[x].lz = 0;
    }
}

void add(int x, int l, int r, long long val){
    st[x].val += val*(r-l+1);
    if(l <= st[x].l && st[x].r <= r){
        st[x].lz += val;
        //st[x].val += val*(st[x].r-st[x].l+1);
        return;
    }
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(l > m)
        add((x<<1)|1, l, r, val);
    else if(r <= m)
        add(x<<1, l, r, val);
    else
        add(x<<1, l, m, val), add((x<<1)|1, m+1, r, val);
    //if(l <= m)
    //    add(x<<1, l, r, val);
    //if(r > m)
    //    add((x<<1)|1, l, r, val);
    //st[x].val = st[x<<1].val+st[(x<<1)|1].val;
}

long long query(int x, int l, int r){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].val;
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r);
    else if(m < l)
        return query((x<<1)|1, l, r);
    else
        return query(x<<1, l, m)+query((x<<1)|1, m+1, r);
}

int main(){
    int n, q;
    int ca, cb, cc;
    char op[12];
    scanf("%d%d", &n, &q);
    built(1, 1, n);
    while(q--){
        scanf("%s%d%d", op, &ca, &cb);
        if(op[0] == 'C'){
            scanf("%d", &cc);
            add(1, ca, cb, cc);
        }else
            printf("%lld\n", query(1, ca, cb));
    }
    return 0;
}

