/*************************************************************************
    > File Name: poj1860.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月21日 星期六 14时11分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;

struct exc{
    int v;
    double rt, cm;
    exc(){}
    exc(int v, double rt, double cm):v(v), rt(rt), cm(cm){}
};

vector<exc> alle[maxn];
double dm[maxn];
int n;

bool bfs(int cs){
    queue<int> q;
    q.push(cs);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        double cmax = 0;
        for(int i = 0; i < alle[u].size(); i++){
            int v = alle[u][i].v;
            double ns = (dm[u]-alle[u][i].cm)*alle[u][i].rt;
            if(ns > dm[v]){
                if(v == cs)
                    return true;
                dm[v] = ns;
                q.push(v);
            }
        }
    }
    return false;
}

int main(){
    int m, cs;
    int cu, cv;
    double cr, cc;
    scanf("%d%d%d", &n, &m, &cs);
    scanf("%lf", &dm[cs]);
    while(m--){
        scanf("%d%d%lf%lf", &cu, &cv, &cr, &cc);
        alle[cu].push_back(exc(cv, cr, cc));
        scanf("%lf%lf", &cr, &cc);
        alle[cv].push_back(exc(cu, cr, cc));
    }
    printf("%s", bfs(cs)?"YES\n":"NO\n");
	return 0;
}

