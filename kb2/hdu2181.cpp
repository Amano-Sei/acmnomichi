/*************************************************************************
    > File Name: hdu2181.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月11日 星期日 00时15分22秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 21;
struct node{
    int to[3];
    node(){}
    node(int *cto){
        memcpy(to, cto, sizeof(to));
    }
} nodes[maxn];

bool book[maxn];
int s[maxn];
int cnt;
int st;
void dfs(int cs, int nd){
    s[nd] = cs;
    for(int i = 0; i < 3; i++){
        if(!book[nodes[cs].to[i]]){
            book[nodes[cs].to[i]] = true;
            dfs(nodes[cs].to[i], nd+1);
            book[nodes[cs].to[i]] = false;
        }
        if(nd == 19 && nodes[cs].to[i] == st){
            printf("%d: ", ++cnt);
            for(int i = 0; i < 20; i++)
                printf(" %d", s[i]);
            printf(" %d\n", st);
            return;
        }
    }
}

int main(){
    int cto[3];
    for(int i = 1; i <= 20; i++){
        scanf("%d%d%d", &cto[0], &cto[1], &cto[2]);
        sort(cto, cto+3, less<int>());
        nodes[i] = node(cto);
    }
    while(scanf("%d", &st) != -1 && st > 0){
        cnt = 0;
        book[st] = true;
        dfs(st, 0);
        book[st] = false;
    }
	return 0;
}

