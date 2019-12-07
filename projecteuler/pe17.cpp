/*************************************************************************
    > File Name: pe17.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月25日 星期三 23时47分48秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

using namespace std;

char s[10][100] = {"onetwothreefourfivesixseveneightnine", "eleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen", "twentythirtyfortyfiftysixtyseventyeightyninety", "hundred"};

int main(){
    int ans = (strlen(s[0])+3+strlen(s[1])+strlen(s[2])*10+8*strlen(s[0]))*10+100*strlen(s[0])+900*strlen(s[3])+99*9*3+strlen("onethousand");
    printf("%d\n", ans);

    return 0;
}

