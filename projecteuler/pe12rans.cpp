/*************************************************************************
    > File Name: pe12rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月20日 星期五 14时35分12秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int getdivinum(long long num){
    int ans = 1, ccount;
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            ccount = 1;
            while(num%i == 0){
                ccount++;
                num /= i;
            }
            ans *= ccount;
        }
    }
    if(num != 1)
        ans *= 2;
    return ans;
}

int main(){
    for(long long ci = 1; ; ci++)
        if(getdivinum(ci*(ci+1)/2) > 500){
            printf("%lld\n", ci*(ci+1)/2);
            break;
        }
	return 0;
}

