/*************************************************************************
    > File Name: segtree.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月03日 星期二 09时59分55秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 10005;

struct node{
    int l, r;
}st[maxn];

void built(int x, int l, int r){
    st[x] = { l, r };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

int pre(int x){
    if(x&1)
        return x&(~1);
    return pre(x>>1);
}

int nxt(int x){
    if((x&1) == 0)
        return x|1;
    return nxt(x>>1);
}

int main(){
    built(1, 1, 100);
    for(int i = 1; i <= 400; i++){
        if(st[i].l == 0)
            continue;
        printf("now show %d:\n", i);
        register int ci = pre(i);
        while(ci){
            printf("pre==%d %d~%d\n", ci, st[ci].l, st[ci].r);
            ci = pre(ci);
        }
        printf("%d %d~%d\n", i, st[i].l, st[i].r);
        ci = nxt(i);
        while(ci != 1){
            printf("nxt==%d %d~%d\n", ci, st[ci].l, st[ci].r);
            ci = nxt(ci);
        }
        getchar();
    }
    return 0;
}

