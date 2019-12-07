/*************************************************************************
    > File Name: 2715.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 15时36分30秒
 ************************************************************************/

#include <iostream>
using namespace std;
int main(){
    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k > (n-1)*(m-1))
        printf("-1\n");
    else
        printf("%lld\n", n+m-2);
    return 0;
}

