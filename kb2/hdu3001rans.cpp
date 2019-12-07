/*************************************************************************
    > File Name: hdu3001rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月04日 星期三 14时05分30秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;

int tb[11];
int dp[59050][10];
int b[59050][10];
bool isa[59050][11];
int f[10][10];
vector<pair<int, int> > edge[10];

void init(){
    tb[0] = 1;
    for(int i = 1; i <= 10; i++)
        tb[i] = tb[i-1]*3;
    for(int i = 0; i < tb[10]; i++){
        isa[i][0] = true;
        for(int j = 0; j < 10; j++)
            isa[i][j+1] = (b[i][j] = i/tb[j]%3) && isa[i][j];
    }
}

int main(){
    init();
    int n, m, u, v, w, ans;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(f, 0x3f, sizeof(f));
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; i++)
            edge[i].clear();
        ans = inf;
        while(m--){
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            f[u][v] = f[v][u] = min(f[u][v], w);
        }
        for(int i = 0; i < n; i++){
            dp[tb[i]][i] = 0;
            for(int j = 0; j < n; j++)
                if(f[i][j] != inf)
                    edge[i].push_back({j, f[i][j]});
        }
        for(int i = 1; i < tb[n]; i++)
            for(int j = 0; j < n; j++)
                if(dp[i][j] != inf){
                    if(isa[i][n])
                        ans = min(ans, dp[i][j]);
                    for(int k = 0; k < edge[j].size(); k++){
                        v = edge[j][k].first;
                        if(b[i][v] < 2)
                            dp[i+tb[v]][v] = min(dp[i+tb[v]][v], dp[i][j]+edge[j][k].second);
                    }
                }
        printf("%d\n", ans==inf ? -1 : ans);
    }
	return 0;
}

