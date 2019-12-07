/*************************************************************************
    > File Name: pe34.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月11日 星期五 17时43分13秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//首先显然， 这个数不会超过7位数
//我们可以看到7*9!是一个7位数，并且只有2540160
//如果这个数位数大于7，那么即使每位数都取9都不可能大于这个位数的最小值
//说的再规范一些，符合条件的n位数的最大值为n*9!，而n位数的最小值位10^(n-1)
//大减小做差求导，求得倒数零点约为6.197547344，而导数又是单调递减的
//所以由于当n为8时，最大值已经小于最小值了，而最大值的导数又小于最小值的导数
//所以无论如何这个n都不会超过7了，而为7时，最大的可能符合条件的值就是7*9!(当然这个值不可能符合条件）

int fac[10];
void init(){
    fac[0] = 1;
    for(int i = 1; i < 10; i++)
        fac[i] = fac[i-1]*i;
}

long long getans(){
    long long ans = 0;
    for(int cnum = 3; cnum <= 2540160; cnum++){
        int tnum = cnum;
        int csum = 0;
        while(tnum){
            csum += fac[tnum%10];
            tnum /= 10;
        }
        if(csum == cnum){
            printf("%d\n", cnum);
            ans += cnum;
        }
    }
    return ans;
}

int main(){
    init();
    printf("%lld\n", getans());

    return 0;
}

