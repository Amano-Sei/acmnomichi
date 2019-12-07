/*************************************************************************
    > File Name: poj2421.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 15时12分29秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int cost[maxn][maxn];
int lowc[maxn];
bool book[maxn];

int prim(int n){
    int ans = 0;
    for(int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for(int i = 1; i < n; i++){
        int minc = inf;
        int p = -1;
        for(int j = 1; j < n; j++)
            if(!book[j] && lowc[j] < minc){
                minc = lowc[j];
                p = j;
            }
        ans += minc;
        book[p] = true;
        for(int j = 1; j < n; j++)
            if(!book[j] && cost[p][j] < lowc[j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

int main(){
    int n, m;
    int cu, cv;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &cu, &cv);
        cu--;cv--;
        cost[cu][cv] = cost[cv][cu] = 0;
    }
    printf("%d\n", prim(n));
    return 0;
}

