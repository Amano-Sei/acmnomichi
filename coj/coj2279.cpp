/*************************************************************************
    > File Name: coj2279.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月14日 星期日 18时39分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int pre[maxn];

int main(){
    int n, a, b, t;
    scanf("%d", &n);
    long long ans = n*(n-1)*(2*n-1)/6;
    for(int i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        t = i-pre[a]-1;
        pre[a] = i;
        ans -= t*(t+1)/2;
        t = i-pre[b]-1;
        pre[b] = i;
        ans -= t*(t+1)/2;
    }
    for(int i = 1; i <= n; i++)
        ans -= (n-1-pre[i])*(n-pre[i])/2;
    printf("%lld\n", ans);

    return 0;
}

