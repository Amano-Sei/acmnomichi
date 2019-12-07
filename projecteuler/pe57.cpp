/*************************************************************************
    > File Name: pe57.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月03日 星期日 13时41分02秒
 ************************************************************************/

#include <cstdio>

//直到这道题才意识到自己之前代码有一个致命的问题
//然后终于在这里修正了（
//真是给自己读过csapp丢人（

int num[1000][500];
int den[1000][500];

int getans(){
    int ans = 0;
    num[0][0] = den[0][0] = 1;
    num[0][1] = 3;
    den[0][1] = 2;
    for(int i = 1; i < 1000; i++){
        int prelen = num[i-1][0];
        int cc = 0;
        for(int j = 1; j <= prelen; j++){
            cc += num[i-1][j]+den[i-1][j];
            den[i][j] = cc % 10;
            cc /= 10;
        }
        while(cc){
            den[i][++prelen] = cc%10;
            cc /= 10;
        }
        den[i][0] = prelen;
        for(int j = prelen; j >= 1; j--)
            printf("%d", den[i][j]);
        for(int j = 1; j <= prelen; j++){
            cc += den[i][j]+den[i-1][j];
            num[i][j] = cc % 10;
            cc /= 10;
        }
        if(cc)
            ans++;
        while(cc){
            num[i][++prelen] = cc%10;
            cc /= 10;
        }
        num[i][0] = prelen;
        putchar('\n');
        for(int j = prelen; j >= 1; j--)
            printf("%d", num[i][j]);
        putchar('\n');
        putchar('\n');
        if(i == 999)
            printf("%d\n", prelen);
    }
    return ans;
}

int main(){
    printf("%d\n", getans());

    return 0;
}

