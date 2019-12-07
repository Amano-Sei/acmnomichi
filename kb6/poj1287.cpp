/*************************************************************************
    > File Name: poj1287.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月20日 星期三 22时41分31秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 55;
const int inf = 0x3f3f3f3f;

int dis[maxn][maxn];
bool book[maxn];
int d[maxn];

int prim(int n){
    int ans = 0;
    for(int i = 2; i <= n; i++)
        d[i] = dis[1][i];
    book[1] = true;
    for(int i = 0; i < n-1; i++){
        int mind = inf;
        int mini = -1;
        for(int j = 2; j <= n; j++)
            if(!book[j] && d[j] < mind){
                mind = d[j];
                mini = j;
            }
        if(mini == -1)
            return -1;
        ans += mind;
        book[mini] = true;
        for(int j = 2; j <= n; j++)
            if(!book[j] && d[j] > dis[mini][j])
                d[j] = dis[mini][j];
    }
    return ans;
}

int main(){
    int p, r, cu, cv, cw;
    while(scanf("%d", &p) != EOF && p){
        memset(dis, 0x3f, sizeof(dis));
        memset(book, 0, sizeof(book));
        scanf("%d", &r);
        while(r--){
            scanf("%d%d%d", &cu, &cv, &cw);
            dis[cu][cv] = dis[cv][cu] = min(cw, dis[cu][cv]);
        }
        printf("%d\n", prim(p));
    }
}

