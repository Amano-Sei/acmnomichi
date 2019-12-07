/*************************************************************************
    > File Name: 001.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 13时00分02秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int minzero(unsigned long long c){
    int ans = 0;
    while((c>>ans)&1 == 0)
        ans++;
    return 1<<ans;
}

int main(){
    int t;
    unsigned long long a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%llu%llu", &a, &b);
        printf("%llu\n", (a&b)?(a&b):min(minzero(a), minzero(b)));
    }
	return 0;
}

