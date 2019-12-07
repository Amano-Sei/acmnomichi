/*************************************************************************
    > File Name: hdu3974.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月04日 星期三 13时35分36秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//这道题数据异常地水，可以看到如果我们用类似并查集一样的东西每次都从叶子遍历之根的时间比线段树还短
//但是事实上无论是类并查集还是普通的dfs多叉树，这些方法在最坏的情况下会有O(TNM)的复杂度，即2.5e10，而时限是5s,参考1s1e9,需要25s的时间
//而线段树建树复杂度是O(n)，准备的dfs也是O(n)，每次操作或查询的时间是O(logn)
//所以线段树做法的复杂度是O((n+mlogn)*T)，或许并不会很快，但是5s内一定是没问题的
//所以(目前我看的)除了线段树以外的做法都不是能满足条件的题解

const int maxn = 50005;

struct Edge{
    int v, nxt;
}edge[maxn];

int head[maxn], tot;

int e2i[maxn], ci, ee2i[maxn];
bool book[maxn];

inline void init(){
    memset(head, -1, sizeof(head));
    memset(book, 0, sizeof(book));
    ci = tot = 0;
}

inline void push(int u, int v){
    book[v] = true;
    edge[tot] = { v, head[u] };
    head[u] = tot++;
}

void dfs(int u){
    e2i[u] = ++ci;
    for(int i = head[u]; i != -1; i = edge[i].nxt)
        dfs(edge[i].v);
    ee2i[u] = ci;
}

struct node{
    int l, r, c;
}st[maxn<<2];

void built(int x, int l, int r){
    st[x] = { l, r, -1 };
    if(l == r)
        return;
    register int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
}

void update(int x, int l, int r, int c){
    if(l <= st[x].l && st[x].r <= r){
        st[x].c = c;
        return;
    }
    if(st[x].c >= 0)
        st[x<<1].c = st[(x<<1)|1].c = st[x].c;
    st[x].c = -2;
    register int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        update(x<<1, l, r, c);
    else if(l > m)
        update((x<<1)|1, l, r, c);
    else
        update(x<<1, l, m, c), update((x<<1)|1, m+1, r, c);
    //if(st[x<<1].c == st[(x<<1)|1].c)
    //    st[x].c = st[x<<1].c;
    //else
    //    st[x].c = -2;
}

inline int query(int id){
    register int x = 1;
    while(st[x].l > id || id > st[x].r || st[x].c == -2)
        x = (x<<1)|(id>((st[x].l+st[x].r)>>1));
    return st[x].c;
}

int main(){
    int t, n, cu, cv;
    char op[12];
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        printf("Case #%d:\n", caset);
        scanf("%d", &n);
        init();
        built(1, 1, n);
        for(int i = 1; i < n; i++){
            scanf("%d%d", &cv, &cu);
            push(cu, cv);
        }
        for(cu = 1; book[cu]; cu++);
        dfs(cu);
        scanf("%d", &n);
        while(n--){
            scanf("%s%d", op, &cu);
            if(op[0] == 'C')
                printf("%d\n", query(e2i[cu]));
            else{
                scanf("%d", &cv);
                update(1, e2i[cu], ee2i[cu], cv);
            }
        }
    }
    return 0;
}

