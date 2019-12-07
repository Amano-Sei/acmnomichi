/*************************************************************************
    > File Name: 2698.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 15时44分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    long long n, m, pren = 1;
    long long ans = 1;
    scanf("%lld%lld", &n, &m);
    for(int j = 0; j < 2; j++){
        for(int i = pren+1; i <= n; i++){
            if(ans >= m)
                break;
            ans *= i;
        }
        pren = n;
        n = ans;
        if(ans >= m)
            break;
    }
    if(n >= m)
        printf("0\n");
    else{
        for(int i = pren+1; i <= n; i++){
            ans = ans * i % m;
            if(ans == 0)
                break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
