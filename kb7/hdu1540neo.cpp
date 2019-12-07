/*************************************************************************
    > File Name: hdu1540neo.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月02日 星期一 19时20分31秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 50005;

//看起来普通无比的连续区间
//为了做这个我证明了这种建线段树法的叶子节点都是在倒数两层的（递归）
//实现出来可以说很开心了，接下来会再写一个不这么复杂的相邻区间寻找

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

inline int lastlquery(int x){
    register int ans = 0;
    if(st[x].l != 1)
        ans = st[--x].rr;
    while(st[x].l != 1 && st[x].rr > st[x].r-st[x].l)
        ans += st[--x].rr;
    return ans;
}

inline int lastrquery(int x){
    register int ans = 0;
    if(st[x+1].l != 1)
        ans = st[++x].ll;
    while(st[x+1].l != 1 && st[x].ll > st[x].r-st[x].l)
        ans += st[++x].ll;
    return ans;
}

int query(int x, int id){
    if(st[x].l == st[x].r || st[x].ll > st[x].r-st[x].l){
        register int ans = st[x].ll;
        if(ans){
            //if(x&1){
            //    ans += lastrquery(x>>1) + st[x^1].rr;
            //    //if(st[x^1].rr > st[x^1].r-st[x^1].l)
            //    //    ans += lastlquery(x>>1);
            //    //显然自己这里之前迷糊了，如果是一侧的孩子的话那么他只需要加上另一侧的孩子这一侧的长度就足够了
            //}else{
            //    ans += lastlquery(x>>1) + st[x^1].ll;
            //    //if(st[x^1].ll > st[x^1].r-st[x^1].l)
            //    //    ans += lastrquery(x>>1);
            //}
            ans += lastlquery(x>>(!(x&1)))+lastrquery(x>>(x&1));
            //然后就获得这样如我所希望的简洁形式的答案
        }
        return ans;
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        return query(x<<1, id);
    else
        return query((x<<1)|1, id);
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

