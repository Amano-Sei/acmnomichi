/*************************************************************************
    > File Name: pe2.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月14日 星期六 22时09分56秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    long long ans = 2;
    long long p1 = 1, p2 = 2;
    while(p2 <= 4000000){
        p1 += p2;
        swap(p1, p2);
        if(p2%2 == 0)
            ans += p2;
    }
    printf("%lld\n", ans);
	return 0;
}

