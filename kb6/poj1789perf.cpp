/*************************************************************************
    > File Name: poj1789perf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 16时36分10秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2005;

char tcode[maxn][8];
int rt[maxn], lt[maxn];
char lowc[maxn];

int prim(int n){
    int ans = 0;
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        rt[i] = i+1;
        lt[i] = i-1;
        lowc[i] = 8;
    }
    int p = 0;
    for(int i = 1; i < n; i++){
        register char minc = 8;
        register int tp = -1;
        for(int j = rt[0]; j < n; j = rt[j]){
            register char td = ((tcode[p][0] != tcode[j][0])+(tcode[p][1] != tcode[j][1]))+((tcode[p][2] != tcode[j][2])+(tcode[p][3] != tcode[j][3]))+((tcode[p][4] != tcode[j][4])+(tcode[p][5] != tcode[j][5]))+(tcode[p][6] != tcode[j][6]);
            if(lowc[j] > td)
                lowc[j] = td;
            else
                td = lowc[j];
            if(td < minc){
                minc = td;
                tp = j;
            }
        }
        p = tp;
        lt[rt[p]] = lt[p];
        rt[lt[p]] = rt[p];
        ans += minc;
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++)
            scanf("%s", tcode[i]);
        printf("The highest possible quality is 1/%d.\n", prim(n));
    }
    return 0;
}

