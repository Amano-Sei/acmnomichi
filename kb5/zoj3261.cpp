/*************************************************************************
    > File Name: zoj3261.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月16日 星期六 21时09分20秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

//emmm可以说是灵光一闪也可以说是我忘了（
//"不过只要离线之后倒过来处理就可以了"，这样的思想大概不是第一次遇到了

//我想应该遇到过好多次了...能自己想起来真的太好了
//一开始处理边直接开了maxn^2的数组然后内存超了（
//bin神是用多个map，还有dalao是用一个map通过把出发点*maxn+终点
//emmm反正都大差不差了（
//意识到其实在map里信息就足够了之后我自己换了set（在看dalao博客之前自己换的

//说到这里，我还是要说...那堆说带权并查集的垃圾博客哟...
//你们知道什么是带权并查集吗...

//终于做完kb带你飞5了（
//我真的在变强么（沉思...

using namespace std;

const int maxn = 10005;
const int maxm = 20005;
const int maxq = 50005;

struct Query{
    int type, cu, cv;
}que[maxq];

int p[maxn];

struct Edge{
    int u, v;
    int nxt;
}edge[maxm];

int pre[maxn];
set<pair<int, int> > noe;

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

inline void init(){
    memset(pre, -1, sizeof(pre));
    noe.clear();
}

inline void merge(int u, int v){
    u = getpre(u);
    v = getpre(v);
    if(u != v){
        if(p[u] < p[v] || p[u] == p[v] && u > v)
            pre[u] = v;
        else
            pre[v] = u;
    }
}

int main(){
    bool hasbegin = false;
    int n, m, q;
    char s[20];
    while(scanf("%d", &n) != EOF){
        if(hasbegin)
            putchar('\n');
        hasbegin = true;
        init();
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &edge[i].u, &edge[i].v);
            if(edge[i].u > edge[i].v)
                swap(edge[i].u, edge[i].v);
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%s%d", s, &que[i].cu);
            if(s[0] == 'd'){
                que[i].type = 0;
                scanf("%d", &que[i].cv);
                if(que[i].cu > que[i].cv)
                    swap(que[i].cu, que[i].cv);
                noe.insert({que[i].cu, que[i].cv});
            }else
                que[i].type = 1;
        }
        for(int i = 0; i < m; i++){
            if(noe.count({edge[i].u, edge[i].v}))
                continue;
            merge(edge[i].u, edge[i].v);
        }
        for(int i = q-1; i >= 0; i--){
            if(que[i].type)
                que[i].cv = getpre(que[i].cu);
            else
                merge(que[i].cu, que[i].cv);
        }
        for(int i = 0; i < q; i++)
            if(que[i].type)
                printf("%d\n", (que[i].cu == que[i].cv || p[que[i].cu]==p[que[i].cv]) ? -1 : que[i].cv);
    }
}

