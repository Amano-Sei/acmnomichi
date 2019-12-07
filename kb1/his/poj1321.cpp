/*************************************************************************
    > File Name: poj1321.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月05日 星期五 18时58分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 10;

char pad[maxn][maxn];
bool book[maxn];
int cnt, n, k;

void dfs(int x, int c){
	if(c == k){
		cnt++;
		return;
	}
	for(int i = x+1; i <= n-k+c+1; i++)
		for(int j = 1; j <= n; j++)
			if(pad[i][j] == '#' && !book[j]){
				book[j] = 1;
				dfs(i, c+1);
				book[j] = 0;
			}
}

int main(){
	while(scanf("%d%d", &n, &k) != -1 && n != -1){
		for(int i = 1; i <= n; i++)
			scanf("%s", &pad[i][1]);
		cnt = 0;
		dfs(0, 0);
		printf("%d\n", cnt);
	}

	return 0;
}

