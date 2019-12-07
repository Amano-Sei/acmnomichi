#include <stdio.h>
char pad[9][9];
int book[8];
int cnt, n, k;
void dfs(int x, int c){
	if(c == k){
		cnt++;
	}else{
		int i=x+1, j=0;
		while(i < n-k+c+1){
			j = 0;
			while(j < n){
				if(pad[i][j] == '#' && !book[j]){
					book[j] = 1;
					dfs(i, c+1);
					book[j] = 0;
				}
				j++;
			}
			i++;
		}
	}
}
int main(){
	int i;
	while(scanf("%d%d", &n, &k) != -1 && n != -1){
		i = 0;
		while(i < n)
			scanf("%s", pad[i++]);
		cnt = 0;
		dfs(-1, 0);
		printf("%d\n", cnt);
	}
	return 0;
}
