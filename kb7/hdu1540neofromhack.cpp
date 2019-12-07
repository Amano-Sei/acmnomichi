/*************************************************************************
    > File Name: hdu1540neofromhack.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月04日 星期一 12时55分31秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 50005;

//这里的做法是源自hack得到的正确(因为不服气所以这么说)结论
//任意一点所在的连续区间必然可以被某一个非叶节点的左孩子的rr和右孩子的ll所包括
//如果这个连续区间跨越了当前节点的m，那么自然上述就是所求
//否则该连续区间就会在一侧的线段树中，只使用了那一侧线段树中的区间
//循环会终止，并且保证若有答案即输出，而最终的0可以证明若是0即是正确的
//虽然这个证明有点不能接受，但是他似乎是正确的证明方法（（（

//这道题搞了两天了...
//我不想再看了（（（虽然这么说表示我很浮躁...

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

//int query(int x, int id){
//    if(st[x].l == st[x].r)
//        return 0;
//    register int m = (st[x].l+st[x].r)>>1;
//    if(m-st[x<<1].rr < id && id <= m+st[(x<<1)|1].ll)
//        return st[x<<1].rr+st[(x<<1)|1].ll;
//    if(id <= m)
//        return query(x<<1, id);
//    else
//        return query((x<<1)|1, id);
//}

inline int query(int x, int id){
    while(st[x].l != st[x].r){
        register int m = (st[x].l+st[x].r)>>1;
        if(m-st[x<<1].rr < id && id <= m+st[(x<<1)|1].ll)
            return st[x<<1].rr+st[(x<<1)|1].ll;
        x = (x<<1)|(id>m);
    }
    return 0;
    //发觉没有必要递归，就改成循环了...但是他居然变慢了...
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

