/*************************************************************************
    > File Name: pe19.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月26日 星期四 22时37分24秒
 ************************************************************************/

#include <cstdio>

bool isleapyear(int cyear){
    return cyear%4==0 && cyear%100!=0 || cyear%400==0;
}

int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(){
    int ans = 0;
    int ci = 0;
    for(int i = 0; i < 12; i++)
        ci = (ci+month[isleapyear(1900)][i])%7;
    for(int i = 1901; i <= 2000; i++)
       for(int j = 0; j < 12; j++)
           ans += ((ci = (ci+month[isleapyear(i)][j])%7)==6);
    if(ci == 6)
        ans--;
    printf("%d\n", ci);
    printf("%d\n", ans);
    return 0;
}

