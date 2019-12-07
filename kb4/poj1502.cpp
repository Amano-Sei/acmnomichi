/*************************************************************************
    > File Name: poj1502.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月24日 星期二 23时09分46秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int dis[maxn][maxn];
int n;
int d[maxn];
bool book[maxn];
void dijkstra(){
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        int mindis = inf;
        for(int j = 1; j <= n; j++)
            if(!book[j] && d[j] < mindis){
                mindis = d[j];
                u = j;
            }
        //if(u == -1)
        //    return;
        book[u] = true;
        for(int j = 1; j <= n; j++)
            if(!book[j] && d[j] > d[u]+dis[u][j])
                d[j] = d[u]+dis[u][j];
    }
}

char clen[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++){
            scanf("%s", clen);
            if(clen[0] == 'x')
                dis[i][j] = dis[j][i] = inf;
            else{
                for(int k = 0; clen[k]; k++)
                    dis[i][j] = dis[i][j]*10 + clen[k]-'0';
                dis[j][i] = dis[i][j];
            }
        }
    dijkstra();
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, d[i]);
    printf("%d\n", ans);
    return 0;
}

