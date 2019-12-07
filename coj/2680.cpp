/*************************************************************************
    > File Name: 2680.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 15时25分01秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, k, ans = 0;
    long long pre = 3e9, cur;
    scanf("%d%d", &n, &k);
    while(n--){
        scanf("%lld", &cur);
        if(abs(cur-pre) < k){
            ans++;
            pre = 3e9;
        }else
            pre = cur;
    }
    printf("%d\n", ans);
    return 0;
}

