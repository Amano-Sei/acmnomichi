/*************************************************************************
    > File Name: pe20.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月27日 星期五 22时39分27秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int fac[101][200];

void init(){
    fac[1][0] = 1;
    fac[1][1] = 1;
    for(int i = 2; i <= 100; i++){
        int cc = 0;
        fac[i][0] = fac[i-1][0];
        for(int j = 1; j <= fac[i][0]; j++){
            fac[i][j] = fac[i-1][j]*i+cc;
            cc = fac[i][j]/10;
            fac[i][j] %= 10;
        }
        while(cc){
            fac[i][++fac[i][0]] = cc%10;
            cc /= 10;
        }
    }
}

int main(){
    init();
    int ans = 0;
    for(int i = fac[100][0]; i > 0; i--){
        printf("%d", fac[100][i]);
        ans += fac[100][i];
    }
    printf("\n%d\n%d\n", ans, fac[100][0]);

    return 0;
}

