/*************************************************************************
    > File Name: poj2253.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月17日 星期二 14时23分11秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 205;
const int inf = 0x3f3f3f3f;

struct point{
    int x, y;
    int operator * (const point &a) const {
        return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);
    }
}P[maxn];

int d[maxn][maxn];
int n;

void floyd(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = P[i]*P[j];
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
}

int main(){
    int tcase = 0;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &P[i].x, &P[i].y);
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++tcase, sqrt(d[0][1]));
        //g++要%f输出有毒...
    }
	return 0;
}

