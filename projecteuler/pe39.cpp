/*************************************************************************
    > File Name: pe39.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月17日 星期四 15时36分18秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//因为project euler维护，所以从正式开始每天一道开始第一次没写
//所以今天要写两道...

int ans, maxi;

void checkperi(int cp){
    int cans = 0;
    int ci;
    for(int i = 1; i <= cp/3; i++){
        ci = i*i;
        for(int j = cp/2-i+1; j <= (cp-i)/2; j++)
            if(ci + j*j == (cp-i-j)*(cp-i-j)){
                if(cp == 840)
                    printf("%d %d %d\n", i, j, cp-i-j);
                cans++;
            }
    }
    if(cans > ans){
        maxi = cp;
        ans = cans;
    }
}

void bettercheck(int cp){
    int cans = 0, cc, tp;
    for(int i =  1; i <= cp/3; i++){
        cc = i*i;
        tp = cp-i;
        if(cc % tp != 0)
            continue;
        cc = tp-cc/tp;
        if(cc % 2 != 0)
            continue;
        cans++;
    }
    if(cans > ans){
        maxi = cp;
        ans = cans;
    }
}

int main(){
    for(int i = 3; i <= 1000; i++)
        //checkperi(i);
        bettercheck(i);
    printf("%d %d\n", maxi, ans);
    return 0;
}

