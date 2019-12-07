/*************************************************************************
    > File Name: zoj1586.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 15时45分24秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

int ap[maxn];
int cost[maxn][maxn];
int lowc[maxn];
bool book[maxn];

int prim(int n){
    memset(book, 0, sizeof(book));
    int ans = 0;
    for(int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for(int i = 1; i < n; i++){
        int minc = inf;
        int p = -1;
        for(int j = 1; j < n; j++)
            if(!book[j] && minc > lowc[j]){
                minc = lowc[j];
                p = j;
            }
        ans += minc;
        book[p] = true;
        for(int j = 1; j < n; j++)
            if(!book[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &ap[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &cost[i][j]);
                cost[i][j] += ap[i]+ap[j];
            }
        printf("%d\n", prim(n));
    }

    return 0;
}

