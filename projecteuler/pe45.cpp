/*************************************************************************
    > File Name: pe45.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月22日 星期二 23时24分56秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

void getans(){
    int ti = 286, pi = 166, hi = 144;
    int ct, cp, ch;
    while(true){
        ch = 1LL*hi*(2*hi-1);
        while((cp=1LL*pi*(3*pi-1)/2) < ch)
            pi++;
        while((ct=1LL*ti*(ti+1)/2) < ch)
            ti++;
        if(ch == ct && ch == cp){
            printf("%d %d %d %d\n", ch, ti, pi, hi);
            return;
        }
        hi++;
    }
}

int main(){
    getans();
    return 0;
}

