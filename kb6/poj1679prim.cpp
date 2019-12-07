/*************************************************************************
    > File Name: poj1679prim.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 15时23分08秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

//还打麻将吗...
//我错了...
//还记得think twice, code once么....
//我错了...

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int cost[maxn][maxn];
int highc[maxn][maxn];
int lowc[maxn];
int pre[maxn];
bool used[maxn][maxn];
bool book[maxn];

int prim(int n){
    int ans = 0;
    memset(used, 0, sizeof(used));
    memset(book, 0, sizeof(book));
    book[1] = true;
    //这里逃不掉这个
    for(int i = 2; i <= n; i++){
        lowc[i] = cost[1][i];
        pre[i] = 1;
    }
    for(int i = 1; i < n; i++){
        int p = -1;
        int minc = inf;
        for(int j = 2; j <= n; j++)
            if(!book[j] && minc > lowc[j]){
                minc = lowc[j];
                p = j;
            }
        if(p == -1)
            return -1;
        book[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        ans += minc;
        for(int j = 1; j <= n; j++)
            if(book[j]){
                if(j != p)
                    highc[j][p] = highc[p][j] = max(highc[j][pre[p]], minc);
            }else if(lowc[j] > cost[p][j]){
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
    }
    return ans;
}

int main(){
    int t, n, m;
    int cu, cv, cw;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(cost, 0x3f, sizeof(cost));
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            cost[cu][cv] = cost[cv][cu] = cw;
        }
        register int tans = prim(n);
        for(int i = 1; i < n && tans != -1; i++)
            for(int j = i+1; j <= n; j++)
                if(cost[i][j] != inf && !used[i][j] && cost[i][j] == highc[i][j]){
                    tans = -1;
                    break;
                }
        if(tans == -1)
            puts("Not Unique!");
        else
            printf("%d\n", tans);
    }
    return 0;
}

