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

const int maxn = 99;
const int inf = 0x3f3f3f3f;

struct node{
    int v, len;
    bool operator < (const node &a) const{
        return len > a.len;
    }
};

int cost[maxn][maxn];
bool book[maxn];

int prim(int n){
    int ans = 0;
    int p, minc;
    priority_queue<node> q;
    memset(book, 0, sizeof(book));
    for(int i = 1; i < n; i++)
        q.push({ i, cost[0][i] });
    for(int i = 1; i < n; i++){
        node cur;
        do{
            cur = q.top();
            q.pop();
        }while(!q.empty() && book[cur.v]);
        if(book[cur.v] && q.empty())
            return -1;
        book[cur.v] = true;
        ans += cur.len;
        for(int j = 1; j < n; j++)
            if(!book[j])
                q.push({ j, cost[cur.v][j] });
    }
    return ans;
}

int main(){
    int n, m;
    int cu, cv, cw;
    while(scanf("%d", &n) != EOF && n){
        m = n*(n-1)/2;
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            cu--;cv--;
            cost[cu][cv] = cost[cv][cu] = cw;
        }
        printf("%d\n", prim(n));
    }
    return 0;
}

