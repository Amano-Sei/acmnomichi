/*************************************************************************
    > File Name: poj3279.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 01时21分57秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 15;
bool pad[maxn][maxn];
bool book[maxn][maxn];
bool ans[maxn][maxn];
bool getans;
int minans, cans;
int m, n;

void nextbook(){
    cans = 0;
    for(int i = n-1; i>=0 && !(book[0][i]=!book[0][i]); i--);
    for(int i= 0; i < n; i++)
        if(book[0][i])
            cans++;
}

bool getifl(int i, int j){
    return i >= 0 && j >= 0 && j < n && book[i][j];
}
bool getcst(int i, int j){
    return (pad[i][j]+getifl(i-1, j)+getifl(i, j-1)+getifl(i, j+1)+book[i][j]) % 2;
}

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%u", &pad[i][j]);
    minans = m*n+1;
    while(true){
        getans = true;
        for(int i = 1; i < m; i++)
            for(int j = 0; j < n; j++)
                if(book[i][j] = getcst(i-1, j))
                    cans++;
        for(int j = 0; j < n; j++)
            if(getcst(m-1, j)){
                getans = false;
                break;
            }
        if(getans && cans < minans){
            memcpy(ans, book, sizeof(book));
            minans = cans;
        }
        nextbook();
        if(!cans)
            break;
    }
    if(minans != m*n+1)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                printf("%d%c", ans[i][j], j==n-1?'\n':' ');
    else
        printf("IMPOSSIBLE\n");
	return 0;
}

