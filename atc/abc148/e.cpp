/*************************************************************************
    > File Name: e.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月22日 星期日 21时19分59秒
 ************************************************************************/

#include <cstdio>

int main(){
    long long n, ans = 0, cten = 10;
    scanf("%lld", &n);
    if((n&1) == 0){
        while(cten <= n){
            ans += n/cten;
            register long long ften = 5*cten;
            while(ften <= n){
                ans += (n/ften/2 + n/ften%2);
                ften *= 5;
            }
            cten *= 10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

