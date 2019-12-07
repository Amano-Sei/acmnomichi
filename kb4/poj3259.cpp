/*************************************************************************
    > File Name: poj3259.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月24日 星期二 14时24分30秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring> 

using namespace std;

const int maxn = 500+5;
const int maxm = 2500*2+200+maxn+5;

struct edge{
	int u, v;
	int w;
	edge(){}
	edge(int u, int v, int w):u(u), v(v), w(w){} 
} E[maxm];

int d[maxn];
int n, m, w;

bool bellman_ford(){
	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	for(int i = 0; i < n; i++){
		bool flag = true;
		for(int i = 0; i < m; i++){
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			if(d[v] > d[u]+w){
				flag = false;
				d[v] = d[u]+w;
			}
		}
		if(flag)
			return false;
	}
	for(int i = 0; i < m; i++)
		if(d[E[i].v] > d[E[i].u]+E[i].w)
			return true;
	return false;
}

int main(){
	int f;
	scanf("%d", &f);
	while(f--){
		scanf("%d%d%d", &n, &m, &w);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &E[2*i].u, &E[2*i].v, &E[2*i].w);
			E[2*i+1].u = E[2*i].v;
			E[2*i+1].v = E[2*i].u;
			E[2*i+1].w = E[2*i].w;
		}
		m *= 2;
		for(int i = m; i < m+w; i++){
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
			E[i].w = -E[i].w;
		}
		m += w;
		for(int i = m, j = 0; j < n; i++, j++){
			E[i+j].u = 0;
			E[i+j].v = j;
			E[i+j].w = 0;
		}
		m += n;
		printf("%s", bellman_ford()?"YES\n":"NO\n");
	}
	return 0;
}

