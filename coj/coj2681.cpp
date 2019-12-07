/*************************************************************************
    > File Name: coj2681.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 14时00分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    long long t, n, k;
    long long tmp, cans, ans;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &k, &n);
        if(k == 1){
            printf("%lld\n", n-1);
            continue;
        }
        tmp = (n-1)/k*(k-1)+1;
        cans = k;
        ans = 1;
        while(true){
            if(cans > tmp){
                if((n-1)/k-(cans/k-1)/(k-1) > cans/k/k)
                    printf("%lld\n", ans*2);
                else
                    printf("%lld\n", ans*2-1);
                break;
            }else if(cans == tmp){
                printf("%lld\n", ans*2);
                break;
            } 
            cans *= k;
            ans++;
        }
    }
    return 0;
}

