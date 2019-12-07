/*************************************************************************
    > File Name: poj2349.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 19时28分11秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define POW2(x) ({int _x = (x); _x*=_x;})

using namespace std;

const int maxn = 505;
const int inf = 0x3f3f3f3f;

int x[maxn], y[maxn];
//int lt[maxn], rt[maxn];
int lowc[maxn];
bool book[maxn];

inline int prim(int n, int cnt){
    //rt[0] = 1;
    //for(int i = 1; i < n; i++){
    //    lt[i] = i-1;
    //    rt[i] = i+1;
    //    lowc[i] = inf;
    //}
    memset(lowc, 0x3f, sizeof(lowc));
    memset(book, 0, sizeof(book));
    int p = 0;
    for(int i = 1; i < n; i++){
        register int tp = -1;
        register int minc = inf;
        //for(int j = rt[0]; j < n; j = rt[j]){
        for(int j = 1; j < n; j++){
            if(book[j])
                continue;
            register int td = POW2(x[p]-x[j])+POW2(y[p]-y[j]);
            if(lowc[j] > td)
                lowc[j] = td;
            else
                td = lowc[j];
            if(td < minc){
                tp = j;
                minc = td;
            }
        }
        book[tp] = true;
        //rt[lt[tp]] = rt[tp];
        //lt[rt[tp]] = lt[tp];
        p = tp;
    }
    sort(&lowc[1], &lowc[n]);
    return lowc[cnt];
}

int main(){
    int t, s, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &s, &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &x[i], &y[i]);
        printf("%.2f\n", sqrt(prim(n, n-max(1, s))));
    }

    return 0;
}

