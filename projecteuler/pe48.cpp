/*************************************************************************
    > File Name: pe48.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月25日 星期五 14时51分06秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const long long mod = 10000000000l;

//快速幂会溢出（2^64-1只有10的19次即使是unsigned也不够（
//long long speedpow(long long x, int a){
//    long long ans = 1;
//    while(a){
//        if(a & 1)
//            ans = ans * x % mod;
//        x = x*x % mod;
//        a >>= 1;
//    }
//    return ans;
//}

long long naivepow(long long x, int a){
    long long ans = 1;
    for(int i = 0; i < a; i++)
        ans = ans*x % mod;
    return ans;
}

int main(){
    long long ans = 0;
    for(long long i = 1; i <= 1000; i++)
        ans = (ans+naivepow(i,i))%mod;
    printf("%lld\n", ans);
    return 0;
}

