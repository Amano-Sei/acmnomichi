/*************************************************************************
    > File Name: poj1321.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月05日 星期一 01时07分01秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10;

int n, k;
int cnt;
char paddesu[maxn][maxn];
bool book[maxn];

void dfs(int c, int row){
    if(c == k){
        cnt++;
        return;
    }
    for(int i = row; i < n-(k-c)+1; i++)
        for(int j = 0; j < n; j++)
            if(paddesu[i][j] == '#' && !book[j]){
                book[j] = true;
                dfs(c+1, i+1);
                book[j] = false;
            }
}

int main(){
    while(scanf("%d%d", &n, &k) != EOF && n != -1){
        for(int i = 0; i < n; i++)
            scanf("%s", paddesu[i]);
//        memset(book, 0, sizeof(book));
        cnt = 0;
        dfs(0, 0);
        printf("%d\n", cnt);
    }
	return 0;
}

