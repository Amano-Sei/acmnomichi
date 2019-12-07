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
//来写一个~不需要标志~标志在里面的更新
//因为是从set做法顺延过来的，所以下意识地加入了0和n+1这两个点，然而这对性能不利
//可以借助边界标志来避免越界

//顺便说一下自己瞎写的做法，维护了边界标志避免重复查找

struct node{
    bool ndbook;
    int l, r;
}st[maxn<<2];

int sk[maxn], tot;
bool book[maxn];

void built(int x, int l, int r){
    st[x] = { true, l, r };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

void update(int x, int id, bool val){
    if(id == st[x].l && id == st[x].r){
        st[x].ndbook = val;
        return;
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        update(x<<1, id, val);
    else
        update((x<<1)|1, id, val);
    st[x].ndbook = val && st[x<<1].ndbook && st[(x<<1)|1].ndbook;
}

void lastquery(int x, int id, int &ans){
    if(st[x].ndbook){
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
}

int main(){
    int n, m, cx, ans;
    char op[16];
    book[0] = true;

    while(scanf("%d%d", &n, &m) != EOF){
        //built(1, 0, n+1);
        built(1, 1, n);
        tot = 0;
        book[n+1] = true;
        //update(1, 0, false);
        //update(1, n+1, false);
        while(m--){
            scanf("%s", op);
            if(op[0] == 'R')
                update(1, sk[--tot], true);
            else{
                scanf("%d", &cx);
                if(op[0] == 'Q'){
                    ans = 0;
                    lastquery(1, cx, ans);
                    printf("%d\n", ans);
                }else
                    update(1, sk[tot++]=cx, false);
            }
        }
        book[n+1] = false;
    }
    return 0;
}

