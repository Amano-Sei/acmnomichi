/*************************************************************************
    > File Name: pe30.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月07日 星期一 21时15分32秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int allpow[10];

void init(){
    for(int i = 0; i < 10; i++){
        allpow[i] = i;
        for(int j = 0; j < 4; j++)
            allpow[i] *= i;
    }
}

int ans;
int cnum[6];
int csum;

void dfs(int ci){
    if(ci == 6){
        int tsum = csum;
        for(int i = 0; i < 6; i++){
            if(tsum%10 != cnum[i])
                return;
            tsum /= 10;
        }
        printf("%d\n", csum);
        ans += csum;
        return;
    }
    for(int i = 0; i < 10; i++){
        cnum[ci] = i;
        csum += allpow[i];
        dfs(ci+1);
        csum -= allpow[i];
    }
}

int main(){
    init();
    dfs(0);
    printf("%d\n", ans);

    return 0;
}

