/*************************************************************************
    > File Name: coj2681rans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 15时10分48秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    int t;
    long long n, k;
    long long tmp, cans, cnt;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &k, &n);
        if(k == 1){
            printf("%lld\n", n-1);
            continue;
        }
        cans = 1;
        tmp = 1;
        cnt = 1;
        while(tmp < n){
            cans *= k;
            tmp += cans;
            cnt++;
        }
        if(tmp == n || n-tmp+cans > cans/k)
            printf("%lld\n", 2*cnt-2);
        else
            printf("%lld\n", 2*cnt-3);
    }
}
