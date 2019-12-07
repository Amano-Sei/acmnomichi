/*************************************************************************
    > File Name: p3812.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 21时01分10秒
 ************************************************************************/

#include <cstdio>

long long b[51];

void insert(long long x){
    for(int i = 50; i >= 0; i--)
        if(x & (1ll<<i)){
            if(b[i])
                x ^= b[i];
            else{
                b[i] = x;
                break;
            }
        }
}

long long getmax(){
    long long ans = 0;
    for(int i = 50; i >= 0; i--)
        if((ans^b[i]) > ans)
            ans ^= b[i];
    return ans;
    //我哭了...这个优先级QAQ位运算的优先级...老血喷出...
}

int main(){
    int n;
    long long cnum;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &cnum);
        insert(cnum);
    }
    printf("%lld\n", getmax());
    return 0;
}

