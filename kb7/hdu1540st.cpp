/*************************************************************************
    > File Name: hdu1540st.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月02日 星期一 12时04分50秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 50005;

//自己瞎写的线段树连续区间，准备去看看dalao们怎么写
//先写下自己的感想
//首先这道题多组数据他不说...然后一个村庄可以被多次破坏，而且每次破坏都要入栈
//我的更新做法是计算区间内的破坏村庄数，所以多次破坏多次修复不加标志的话自然会崩
//来写一个不需要标志的更新（

struct node{
    int val;
    int l, r;
}st[maxn<<2];

int sk[maxn], tot;
bool dbook[maxn];
bool book[maxn];

void built(int x, int l, int r){
    st[x] = { 0, l, r };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

void update(int x, int id, int val){
    st[x].val += val;
    if(id == st[x].l && id == st[x].r)
        return;
    register int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        update(x<<1, id, val);
    else
        update((x<<1)|1, id, val);
}

void lastquery(int x, int id, int &ans){
    if(st[x].val == 0){
        book[st[x].l] = true;
        book[st[x].r] = true;
        ans += st[x].r-st[x].l+1;
        if(!book[st[x].l-1])
            lastquery(1, st[x].l-1, ans);
        if(!book[st[x].r+1])
            lastquery(1, st[x].r+1, ans);
        book[st[x].l] = false;
        book[st[x].r] = false;
        return;
    }
    if(st[x].l == st[x].r)
        return;
    int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        lastquery(x<<1, id, ans);
    else
        lastquery((x<<1)|1, id, ans);
    if(x == 1)
        book[id] = false;
}

int main(){
    int n, m, cx, ans;
    char op[16];
    book[0] = true;

    while(scanf("%d%d", &n, &m) != EOF){
        memset(dbook, 0, sizeof(dbook));
        built(1, 0, n+1);
        tot = 0;
        book[n+1] = true;
        update(1, 0, 1);
        update(1, n+1, 1);
        while(m--){
            scanf("%s", op);
            if(op[0] == 'R'){
                if(dbook[sk[tot-1]]){
                    update(1, sk[--tot], -1);
                    dbook[sk[tot]] = false;
                }
            }else{
                scanf("%d", &cx);
                if(op[0] == 'Q'){
                    if(dbook[cx])
                        puts("0");
                    else{
                        ans = 0;
                        lastquery(1, cx, ans);
                        printf("%d\n", ans);
                    }
                }else{
                    if(!dbook[cx])
                        update(1, cx, 1);
                    sk[tot++] = cx;
                    dbook[cx] = true;
                }
            }
        }
        book[n+1] = false;
    }
    return 0;
}

