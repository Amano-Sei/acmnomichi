/*************************************************************************
    > File Name: poj2031.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月21日 星期四 12时14分56秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define POW2(x) \
    ({ double x_ = (x);\
        x_ *= x_;})

using namespace std;

//G++的话printf没有定义%lf，所以要用%f打印
//宏里面是我第一次用，发觉好像{}似乎会返回最后一个;号前的内容
//cl似乎不支持这些东西...

const int maxn = 105;

struct Cell{
    double x, y, z, r;
}cells[maxn];

double cost[maxn][maxn];
bool book[maxn];
double lowc[maxn];

double prim(int n){
    double ans = 0;
    memset(book, 0, sizeof(book));
    for(int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for(int i = 1; i < n; i++){
        double minc = 400;
        int p = -1;
        for(int j = 1; j < n; j++)
            if(!book[j] && lowc[j] < minc){
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
    int n;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &cells[i].x, &cells[i].y, &cells[i].z, &cells[i].r);
            for(int j = 0; j < i; j++){
                double tc = sqrt(POW2(cells[i].x-cells[j].x)+POW2(cells[i].y-cells[j].y)+POW2(cells[i].z-cells[j].z)) - cells[i].r - cells[j].r;
                //double tc = sqrt((cells[i].x-cells[j].x)*(cells[i].x-cells[j].x)+(cells[i].y-cells[j].y)*(cells[i].y-cells[j].y)+(cells[i].z-cells[j].z)*(cells[i].z-cells[j].z)) - cells[i].r - cells[j].r;
                if(tc > 0)
                    cost[i][j] = cost[j][i] = tc;
                else
                    cost[i][j] = cost[j][i] = 0;
            }
        }
        printf("%.3f\n", prim(n));
    }
    return 0;
}

