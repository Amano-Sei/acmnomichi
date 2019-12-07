/*************************************************************************
    > File Name: hdu1540alter.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月02日 星期一 19时20分31秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 50005;

int sk[maxn], tot;

struct node{
    int ll, rr;
    int l, r;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { r-l+1, r-l+1, l, r };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

void update(int x, int id, int val){
    if(st[x].l == st[x].r){
        st[x].ll = st[x].rr = val;
        return;
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        update(x<<1, id, val);
    else
        update((x<<1)|1, id, val);

    st[x].ll = st[x<<1].ll;
    if(st[x].ll > m-st[x].l)
        st[x].ll += st[(x<<1)|1].ll;

    st[x].rr = st[(x<<1)|1].rr;
    if(st[x].rr == st[x].r-m)
        st[x].rr += st[x<<1].rr;
}

int query(int x, int id){
    if(st[x].l == st[x].r || st[x].ll == st[x].r-st[x].l+1)
        return st[x].ll;
    register int m = (st[x].l+st[x].r)>>1;
    if(id <= m){
        if(id <= m-st[x<<1].rr)
            return query(x<<1, id);
        else
            return query(x<<1, id)+query((x<<1)|1, m+1);
    }else{
        if(id > m+st[(x<<1)|1].ll)
            return query((x<<1)|1, id);
        else
            return query(x<<1, m)+query((x<<1)|1, id);
    }
}

int main(){
    int n, m, cx;
    char op[4];
    while(scanf("%d%d", &n, &m) != EOF){
        tot = 0;
        built(1, 1, n);
        while(m--){
            scanf("%s", op);
            if(op[0] == 'R')
                update(1, sk[--tot], 1);
            else{
                scanf("%d", &cx);
                if(op[0] == 'Q')
                    printf("%d\n", query(1, cx));
                else
                    update(1, sk[tot++]=cx, 0);
            }
        }
    }
    return 0;
}

