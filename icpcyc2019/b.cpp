/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月31日 星期六 14时11分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 55;
double x[maxn], y[maxn];
double cx, cy;
int n;

double get_a(double x1, double y1, double x2, double y2, double x3, double y3){
    double ans = atan2(x1-x3, y1-y3)-atan2(x2-x3, y2-y3);
    if(ans > M_PI)
        ans -= 2*M_PI;
    if(ans <-M_PI)
        ans += 2*M_PI;
    return M_PI - abs(ans);
}

double getdis(double x1, double y1, double x2, double y2){
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx+dy*dy);
}

int nxti(int ci){
    return (ci+1)%n;
}

double getans(){
    double ans = 0.0;
    int ci[3] = {0, 1, 2};
    for(int i = 0; i < n; i++){
        ans += getdis(cx, cy, x[ci[1]], y[ci[1]])*get_a(x[ci[0]], y[ci[0]], x[ci[2]], y[ci[2]], x[ci[1]], y[ci[1]])+1e-6;
        for(int j = 0; j < 3; j++)
            ci[j] = nxti(ci[j]);
    }
    return ans;
}

int main(){
    int t, tx, ty;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &tx, &ty);
            x[i] = tx;
            y[i] = ty;
        }
        scanf("%d%d", &tx, &ty);
        cx = tx;
        cy = ty;
        printf("Case #%d: %.3lf\n", caset, getans());
    }
	return 0;
}

