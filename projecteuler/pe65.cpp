/*************************************************************************
    > File Name: pe65.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月11日 星期一 14时21分07秒
 ************************************************************************/

#include <cstdio>

//简单分析下分数的计算过程就是上一个数的分子变成分母，新分子是原分母+这个位置上的加数×原分子
//会溢出，所以用一个简单的大数模板

int a[101][100];

int getans(){
    a[99][0] = a[99][1] = a[100][0] = a[100][1] = 1;
    for(int ci = 98; ci >= 0; ci--){
    //int cbase = 9;
    //a[cbase][1] = 1;
    //a[cbase][0] = a[cbase+1][0] = a[cbase+1][1] = 1;
    //for(int ci = cbase-1; ci >= 0; ci--){
        int ck;
        if(ci % 3 == 2)
            ck = (ci/3+1)*2;
        else if(ci != 0)
            ck = 1;
        else
            ck = 2;
        int prelen = a[ci+1][0];
        int cc = 0;
        for(int i = 1; i <= prelen; i++){
            cc += a[ci+1][i]*ck+a[ci+2][i];
            a[ci][i] = cc%10;
            cc /= 10;
        }
        while(cc){
            a[ci][++prelen] = cc%10;
            cc /= 10;
        }
        a[ci][0] = prelen;
        for(int i = prelen; i > 0; i--)
            printf("%d", a[ci][i]);
        printf(" / ");
        for(int i = a[ci+1][0]; i > 0; i--)
            printf("%d", a[ci+1][i]);
        printf(" %d\n", ci);
    }
    int ans = 0;
    for(int i = a[0][0]; i > 0; i--)
        ans += a[0][i];
    return ans;
}

int main(){
    printf("%d\n", getans());
    return 0;
}

