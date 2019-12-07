/*************************************************************************
    > File Name: hdu4027.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月01日 星期日 18时55分57秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

//这是我最开始的想法，因为区间修改么，所以设了个nval表示下一个值
//但是这个值不能像普通的lazy tag一样简单地在O(1)的时间里维护
//当nval为负时，表示这个节点的nval需要重新计算
//特别的，当nval为-1时，表示这个节点的所有孩子节点都需要更新为nval
//而最少update时一定需要更新，如果query还可以用一个uraquery来避免更新
//但是update是需要计算新的nval的
//而计算新的nval又必须遍历到所有的下层叶子节点再层层返回
//这是一个复杂度为O(logn)的过程
//所以事实上这样搞下来写得脑壳疼也没有什么优化，并不比简单地判断若全1直接返回快（
//就结果而言，比max做法要快一点点，不过不知道为什么max函数在其他题里面效果也一般
//不过如果update不交叉的话，可能还是有效果的
//↑如果不交叉的话，为什么我们不只保存一个nval，非要在哪儿搞-1 -2呢（（（
//想了下如果只有两个状态的线段树，比如会区间取反，然后询问区间异或和的问题
//这样的话就可以简单滴保存lazy tag了（但是这和普通的线段树问题比并没有什么区别（（（

//最开始的时候我有一处忘记return导致re和结果不正确，头都debug破了都找不到QAQ
//最后一处赋值点一处赋值点地找的...这也算是debug经验了吧（

//emmm今天搜了下dalao的博客，这个可以这样暴力做的原因是因为连续开根号下取整很快就会变成1，每次开根号都会使得位数减半

const int maxn = 100005;

struct node{
    long long val;
    long long nval;
    int l, r;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        scanf("%lld", &st[x].val);
        st[x].nval = sqrt(st[x].val);
        return;
    }
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
    st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
}

void push_down(int x){
    if(st[x].nval == st[x].val)
        return;
    st[x].val = st[x].nval;
    if(st[x].l == st[x].r){
        st[x].nval = sqrt(st[x].val);
        return;
    }
    push_down(x<<1);
    push_down((x<<1)|1);
    st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
}

inline void push_up(int x){
    while(x && st[x<<1].nval >= 0 && st[(x<<1)|1].nval >= 0){
        st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
        x>>=1;
    }
}

void update(int x, int l, int r){
    if(st[x].l == st[x].r){
        st[x].val = st[x].nval;
        st[x].nval = sqrt(st[x].val);
        return;
    }
    if(st[x].nval == -1){
        push_down(x<<1);
        push_down((x<<1)|1);
        st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
        push_up(x>>1);
    }
    if(st[x].nval == st[x].val)
        return;
    if(st[x].nval >= 0 && l <= st[x].l && st[x].r <= r){
        st[x].val = st[x].nval;
        st[x].nval = -1;
        return;
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        update(x<<1, l, r);
    else if(l > m)
        update((x<<1)|1, l, r);
    else
        update(x<<1, l, m), update((x<<1)|1, m+1, r);
    st[x].val = st[x<<1].val+st[(x<<1)|1].val;
    if(st[x<<1].nval < 0 || st[(x<<1)|1].nval < 0)
        st[x].nval = -2;
    else
        st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
}

long long uraquery(int x, int l, int r){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].nval;
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return uraquery(x<<1, l, r);
    else if(l > m)
        return uraquery((x<<1)|1, l, r);
    else
        return uraquery(x<<1, l, m)+uraquery((x<<1)|1, m+1, r);
}

long long query(int x, int l, int r){
    if(l <= st[x].l && st[x].r <= r)
        return st[x].val;
    if(st[x].nval == -1){
        return uraquery(x, l, r);
        push_down(x<<1);
        push_down((x<<1)|1);
        st[x].nval = st[x<<1].nval+st[(x<<1)|1].nval;
        push_up(x>>1);
    }
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        return query(x<<1, l, r);
    else if(l > m)
        return query((x<<1)|1, l, r);
    else
        return query(x<<1, l, m)+query((x<<1)|1, m+1, r);
}

int main(){
    int n, m, ct, cx, cy, caset = 1;
    while(scanf("%d", &n) != EOF){
        printf("Case #%d:\n", caset++);
        built(1, 1, n);
        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &ct, &cx, &cy);
            if(cx > cy)
                swap(cx, cy);
            if(ct == 0)
                update(1, cx, cy);
            else
                printf("%lld\n", query(1, cx, cy));
        }
        putchar('\n');
    }
    return 0;
}

