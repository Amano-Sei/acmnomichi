/*************************************************************************
    > File Name: pe5.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月17日 星期二 22时58分29秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    long long p[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    long long ans = 1, ci;
    for(int i = 0; i < 8; i++){
        ci = p[i];
        while(p[i]*ci <= 20)
            ci *= p[i];
        ans *= ci;
    }
    printf("%lld\n", ans);
	return 0;
}

