/*************************************************************************
    > File Name: hdu1875.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 19时20分32秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define POW2(x) ({ int _x = (x); _x *= _x; })

const int maxn = 105;

int x[maxn], y[maxn];
double lowc[maxn];
int lt[maxn], rt[maxn];

inline double calc(int p, int q){
    int ans = POW2(x[p]-x[q])+POW2(y[p]-y[q]);
    if(ans < 100 || ans > 1000000)
        return 1001.0;
    return sqrt(ans);
}

inline double prim(int n){
    double ans = 0;
    rt[0] = 1;
    for(int i = 1; i < n; i++){
        lt[i] = i-1;
        rt[i] = i+1;
        lowc[i] = 1001.0;
    }
    int p = 0;
    for(int i = 1; i < n; i++){
        register int tp = -1;
        register double minc = 1001.0;
        for(int j = rt[0]; j < n; j = rt[j]){
            register double td = calc(p, j);
            if(td < lowc[j])
                lowc[j] = td;
            else
                td = lowc[j];
            if(td < minc){
                tp = j;
                minc = td;
            }
        }
        if(tp == -1)
            return -1.0;
        ans += minc;
        lt[rt[tp]] = lt[tp];
        rt[lt[tp]] = rt[tp];
        p = tp;
    }
    return ans;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &x[i], &y[i]);
        register double tans = prim(n);
        if(tans < 0)
            puts("oh!");
        else
            printf("%.1f\n", tans*100);
    }
    return 0;
}

