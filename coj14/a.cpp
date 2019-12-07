/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月08日 星期五 19时51分31秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

int main(){
    long long n, a, b, r;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &r);
    long long cx, cy, ans = 0;
    while(n--){
        scanf("%lld%lld", &cx, &cy);
        if((cx-a)*(cx-a)+(cy-b)*(cy-b) <= r*r)
            ans++;
    }
    printf("%lld\n", ans);
    
    return 0;
}

