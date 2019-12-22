/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月22日 星期日 21时11分19秒
 ************************************************************************/

#include <cstdio>

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", a*b/gcd(a,b));
    return 0;
}

