/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月31日 星期六 16时07分12秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
double f[maxn], g[maxn];

void init(){
    f[1] = 1.0;
    f[2] = 0.5;
    for(int i = 3; i <= 50; i++){
        f[i] = 1.0;
        for(int j = 2; j < i; j++)
            f[i] += f[j];
        f[i] /= i;
    }

    g[1] = 1.0;
    g[2] = 0.75;
    for(int i = 3; i <= 50; i++){
        g[i] = 1.0;
        for(int j = 1; j< i; j++)
            g[i] += f[i];
            //g[i] += (j-1)/(double)(i-1) + (i-j)/(double)(i-1)*f[i-j+1];
        g[i] /= i;
    }
}

int main(){
    init();
    int t, n, m;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        scanf("%d%d", &n, &m);
        printf("Case #%d: %.6lf %.6lf\n", caset, f[n], g[m]);
    }
	return 0;
}

