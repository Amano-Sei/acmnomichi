/*************************************************************************
    > File Name: pe16.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月24日 星期二 22时40分30秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int cnum[1001][1000];

void init(){
    cnum[0][0] = 1;
    cnum[0][1] = 1;
    for(int i = 1; i <= 1000; i++){
        int cc = 0;
        cnum[i][0] = cnum[i-1][0];
        for(int j = 1; j <= cnum[i][0]; j++){
            cnum[i][j] = cnum[i-1][j]*2+cc;
            cc = cnum[i][j]/10;
            cnum[i][j] %= 10;
        }
        while(cc){
            cnum[i][++cnum[i][0]] = cc%10;
            cc /= 10;
        }
    }
}

int main(){
    init();
    int ans = 0;
    for(int i = 1; i <= cnum[1000][0]; i++)
        ans += cnum[1000][i];
    printf("%d\n", ans);
    return 0;
}

