/*************************************************************************
    > File Name: pe63.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月09日 星期六 21时16分49秒
 ************************************************************************/

#include <cstdio>

int num[100][100];

int findans(){
    int ans = 9;
    for(int ci = 1; ci < 10 ; ci++){
        num[1][0] = 1;
        num[1][1] = ci;
        for(int i = 2; ; i++){
            int prelen = num[i-1][0];
            int cc = 0;
            for(int j = 1; j <= prelen; j++){
                cc = cc+ci*num[i-1][j];
                num[i][j] = cc%10;
                cc /= 10;
            }
            if(cc == 0)
                break;
            printf("%d %d\n", ci, i);
            ans++;
            num[i][++prelen] = cc;
            num[i][0] = prelen;
        }
    }
    return ans;
}

int main(){
    printf("%d\n", findans());

    return 0;
}

