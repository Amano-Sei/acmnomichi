/*************************************************************************
    > File Name: f.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月22日 星期日 22时47分59秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100005;

vector<int> edge[maxn];
int n;

int sp[maxn];
int ans;

void dfs(int u, int cf, int cr, int dep){
    if(cr == 1){
        ans = max(sp[u], ans);
        if(dep >= sp[u])
            return;
    }else
        sp[u] = dep;
    for(size_t i = 0; i < edge[u].size(); i++){
        register int cv = edge[u][i];
        if(cv != cf)
            dfs(cv, u, cr, dep+1);
    }
}

int main(){
    int cu, cv, u, v;
    scanf("%d%d%d", &n, &u, &v);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &cu, &cv);
        edge[cu].push_back(cv);
        edge[cv].push_back(cu);
    }
    dfs(v, 0, 0, 0);
    dfs(u, 0, 1, 0);
    printf("%d\n", ans-1);
    return 0;
}

