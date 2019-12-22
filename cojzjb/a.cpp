/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 14时51分39秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;

long long a[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, &a[n]);
    printf("%lld\n", a[n-1]+a[n-2]+a[n-3]-a[0]-a[1]-a[2]);
    return 0;
}

