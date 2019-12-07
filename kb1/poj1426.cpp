/*************************************************************************
    > File Name: poj1426.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 19时10分17秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ans[201][101];
bool book[201];

void dfs(int ci, int cn, int n){
    if(cn == 0 && ci != 1){
        book[n] = true;
        ans[n][0] = ci-1;
        return;
    }
    if(ci > 19)
        return;
    for(int i = (ci==1)?1:0; i < 10; i++){
        int tmp = i*n+cn;
        if(tmp%10 == 1 || tmp%10 == 0){
            ans[n][ci] = tmp%10;
            dfs(ci+1, tmp/10, n);
        }
        if(book[n])
            return;
    }
}

int main(){
    //int n;
    freopen("poj1426cheat.cpp", "w", stdout);
//    while(scanf("%d", &n)!=-1 && n > 0){
    for(int n = 1; n <= 200; n++){
//        printf("%d==",n);
        if(!book[n])
            dfs(1, 0, n);
        for(int i = ans[n][0]; i > 0; i--)
            printf("%d", ans[n][i]);
    //    printf("==%d", ans[n][0]);
    //    putchar('\n');
        printf(",\n");
    }
	return 0;
}

