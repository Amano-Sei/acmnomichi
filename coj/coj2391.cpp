/*************************************************************************
    > File Name: coj2391.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月14日 星期日 20时01分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long l, r;
    while(n--){
        scanf("%lld%lld", &l, &r);
        if(l != r)
            printf("%lld %lld %lld %lld\n", r*(r-1), l, r, 1);
        else
            printf("%lld %lld %lld %lld\n", r, r, r, r);
    }
    return 0;
}

