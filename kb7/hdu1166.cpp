/*************************************************************************
    > File Name: hdu1166.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 18时24分09秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 50005;

//线段树模板题...虽然我木得模板...

struct node{
    int val, l, r;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        scanf("%d", &st[x].val);
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
}

void add(int x, int id, int val){
    st[x].val += val;
    if(st[x].l == st[x].r)
        return;
    int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        add(x<<1, id, val);
    else
        add((x<<1)|1, id, val);
}

int query(int x, int l, int r){
    if(l <= st[x].l && r >= st[x].r)
        return st[x].val;
    int m = (st[x].l+st[x].r)>>1;
    //int ans = 0;
    //if(l <= m)
    //    ans += query(x<<1, l, r);
    //if(r > m)
    //    ans += query((x<<1)|1, l, r);
    //return ans;
    if(l > m)
        return query((x<<1)|1, l, r);
    else if(r <= m)
        return query(x<<1, l, r);
    else
        return query(x<<1, l, m)+query((x<<1)|1, m+1, r);
}

int main(){
    int t, n, ci, cj;
    char op[16];
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        printf("Case %d:\n", caset);
        scanf("%d", &n);
        built(1, 1, n);
        while(scanf("%s", op) != EOF && op[0] != 'E'){
            scanf("%d%d", &ci, &cj);
            switch(op[0]){
                case 'S':
                    cj = -cj;
                case 'A':
                    add(1, ci, cj);
                    break;
                case 'Q':
                    printf("%d\n", query(1, ci, cj));
                    break;
            }
        }
    }
    return 0;
}

