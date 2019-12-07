/*************************************************************************
    > File Name: poj1789.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 16时36分10秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;
const int inf = 0x3f3f3f3f;

char tcode[maxn][8];

//int cost[maxn][maxn];
//int lowc[maxn];
//bool book[maxn];
int rt[maxn], lt[maxn];
char cost[maxn][maxn];
char lowc[maxn];

int prim(int n){
    int ans = 0;
    //memset(book, 0, sizeof(book));
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        lowc[i] = cost[0][i];
        rt[i] = i+1;
        lt[i] = i-1;
    }
    for(int i = 1; i < n; i++){
        register int minc = inf;
        register int p = -1;
        //int pp = -2;
        //for(int j = 1; j < n; j++)
        //    if(!book[j] && lowc[j] < minc){
        //for(int j = rt[0], prej = 0; j < n; prej = j, j = rt[j])
        for(int j = rt[0]; j < n; j = rt[j])
            if(lowc[j] < minc){
                minc = lowc[j];
                p = j;
                //pp = prej;
            }
        //book[p] = true;
        //rt[pp] = rt[p];
        lt[rt[p]] = lt[p];
        rt[lt[p]] = rt[p];
        ans += minc;
        //for(int j = 1; j < n; j++)
            //if(!book[j] && lowc[j] > cost[p][j])
        for(int j = rt[0]; j < n; j = rt[j])
            if(lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%s", tcode[i]);
            for(int j = 0; j < i; j++){
                //register int tcnt = 0;
                //for(int k = 0; k < 7; k++)
                //    if(tcode[i][k] != tcode[j][k])
                //        tcnt++;
                //cost[i][j] = cost[j][i] = tcnt;
                cost[i][j] = cost[j][i] = ((tcode[i][0] != tcode[j][0])+(tcode[i][1] != tcode[j][1]))+((tcode[i][2] != tcode[j][2])+(tcode[i][3] != tcode[j][3]))+((tcode[i][4] != tcode[j][4])+(tcode[i][5] != tcode[j][5]))+(tcode[i][6] != tcode[j][6]);
            }
        }
        printf("The highest possible quality is 1/%d.\n", prim(n));
    }
    return 0;
}

