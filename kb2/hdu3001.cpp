/*************************************************************************
    > File Name: hdu3001.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月03日 星期二 23时02分24秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
    int v, w;
    edge(){}
    edge(int v, int w):v(v), w(w){}
};
int book[11];
int ans;
vector<edge> v[11];
int n;
void dfs(int cx, int cfee, int cnt){
    if(cfee >= ans)
        return;
    if(cnt == n){
        ans = min(ans, cfee);
        return;
    }
    for(int i = 0; i < v[cx].size(); i++){
        int cv = v[cx][i].v;
        if(!book[cv]){
            book[cv]++;
            dfs(cv, cfee+v[cx][i].w, cnt+1);
            book[cv]--;
        }else if(book[cv] == 1 && v[cv].size() > 2){
            book[cv]++;
            dfs(cv, cfee+v[cx][i].w, cnt);
            book[cv]--;
        }
    }
}

int main(){
    int m, u, tv, w;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++)
            v[i].clear();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &tv, &w);
            v[u].push_back(edge(tv, w));
            v[tv].push_back(edge(u, w));
        }
        ans = 0x3fffffff;
        for(int i = 1; i <= n; i++){
            book[i] = 1;
            dfs(i, 0, 1);
            book[i] = 0;
        }
        if(ans != 0x3fffffff)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
	return 0;
}

