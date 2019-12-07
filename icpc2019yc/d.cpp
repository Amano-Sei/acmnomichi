/*************************************************************************
    > File Name: d.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 12时20分26秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int allnum[70], book[70];
int t, n, m, csum, tt;
bool dfs(int ci){
    
}

int main(){
    scanf("%d", &t);
    while(t--){
        csum = 0;
        memset(num, 0, sizeof(num));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &allnum[i]);
            csum += allnum[i];
        }
        for(int i = n; i <= csum; i++)
            if(csum % i == 0){
                
            }
    }
	return 0;
}

