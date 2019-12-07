/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 19时59分41秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

int bn[10];

int main(){
    bn[0] = 1;
    for(int i = 1; i < 9; i++)
        bn[i] = bn[i-1]*10+1;
    int t, v, ans;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &v);
        for(int i = 8; i >= 0; i--){
            ans += v/bn[i];
            v %= bn[i];
        }
        if(ans <= 9)
            printf("%d\n", ans);
        else
            puts("Impossible");
    }
    return 0;
}

