/*************************************************************************
    > File Name: hdu1233.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 16时06分03秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100;
const int inf = 0x3f3f3f3f;

//这个着实算不上优化，因为进堆的复杂度是n^2...所以没有意义呢(

struct node{
    int v, w;
    bool operator < (const node &a) const{
        return w > a.w;
    }
};

bool book[maxn];
vector<node> edges[maxn];

int prim(int n){
    int ans = 0;
    priority_queue<node> q;
    memset(book, 0, sizeof(book));
    q.push({ 1, 0 });
    while(!q.empty()){
        node cur = q.top();
        register int u = cur.v;
        q.pop();
        if(book[u])
            continue;
        book[u] = true;
        ans += cur.w;
        for(int i = 0; i < edges[u].size(); i++){
            register int tv = edges[u][i].v;
            if(book[tv])
                continue;
            q.push({ tv, edges[u][i].w });
        }
    }
    return ans;
}

int main(){
    int n, m;
    int cu, cv, cw;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 1; i <= n; i++)
            edges[i].clear();
        m = n*(n-1)/2;
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            edges[cu].push_back({cv, cw});
            edges[cv].push_back({cu, cw});
        }
        printf("%d\n", prim(n));
    }
    return 0;
}

