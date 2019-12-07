/*************************************************************************
    > File Name: poj1847.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月29日 星期日 17时10分07秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int n;
int dis[maxn][maxn];
bool book[maxn];
int d[maxn];

void dijkstra(int s, int e){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    for(int i = 1; i < n; i++){
        int u = -1;
        int mindis = inf;
        for(int j = 1; j <= n; j++)
            if(!book[j] && d[j] < mindis){
                mindis = d[j];
                u = j;
            }
        if(u == -1 || u == e)
            return;
        book[u] = true;
        for(int j = 1; j <= n; j++)
            if(!book[j] && d[j]>d[u]+dis[u][j])
                d[j] = d[u]+dis[u][j];
    }
}

int main(){
    memset(dis, 0x3f, sizeof(dis));
    int a, b, cv, cc;
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 1; i <= n; i++){
        scanf("%d", &cc);
        for(int j = 0; j < cc; j++){
            scanf("%d", &cv);
            if(j == 0)
                dis[i][cv] = 0;
            else
                dis[i][cv] = 1;
        }
    }
    dijkstra(a, b);
    printf("%d\n", (d[b]==inf?-1:d[b]));
    return 0;
}

