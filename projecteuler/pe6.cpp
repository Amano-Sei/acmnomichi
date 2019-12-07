/*************************************************************************
    > File Name: pe6.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 13时54分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    long ans = 5050*5050;
    for(long i = 1; i<= 100; i++)
        ans -= i*i;
    printf("%lld\n", ans);
	return 0;
}

