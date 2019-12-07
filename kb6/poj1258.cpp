/*************************************************************************
    > File Name: poj1258.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月22日 星期五 10时59分56秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 105;
const int inf = 0x3f3f3f3f;

int cost[maxn][maxn];
int lowc[maxn];
bool book[maxn];

int prim(int n){
    int ans = 0;
    memset(lowc, 0x3f, sizeof(lowc));
    memset(book, 0, sizeof(book));
    int p = 0;
    for(int i = 1; i < n; i++){
        register int tp = -1;
        register int minc = inf;
        for(int j = 1; j < n; j++)
            if(!book[j]){
                if(lowc[j] > cost[p][j])
                    lowc[j] = cost[p][j];
                if(lowc[j] < minc){
                    tp = j;
                    minc = lowc[j];
                }
            }
        ans += minc;
        book[tp] = true;
        p = tp;
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &cost[i][j]);
        printf("%d\n", prim(n));
    }
    return 0;
}

