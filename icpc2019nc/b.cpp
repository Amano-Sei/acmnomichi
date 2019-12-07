/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 14时39分08秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;
struct edge{
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
};

int fa[1005][1005];
int dis[1005][1005];
int v, e, s, k, c;
vector<int> allteam;
vector<edge> alle;

bool cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

int main(){
    int t, tt, tu, tv;
    while(t--){
        allteam.clear();
        alle.clear();
        memset(fa, 0x3f, sizeof(fa));
        memset(dis, 0x3f, sizeof(dis));
        scanf("%d%d%d%d%d", &v, &e, &s, &k, &c);
        for(int i = 1; i <= v; i++)
            alle[i].clear();
        for(int i = 0; i < k; i++){
            scanf("%d", &tt);
            allteam.push_back(tt);
        }
        for(int i = 0; i < k; i++){
            scanf("%d%d%d", &tu, &tv, &tt);
            fa[tu][tv] = fa[tv][tu] = min(fa[tu][tv], tt);
        }
        for(int i = 1; i <= v; i++)
            for(int j = i+1; j <= v; j++)
                if(fa[i][j] != inf)
                    alle.push_back(edge(i, j, fa[i][j]));
        sort(alle.begin(), alle.end(), cmp);
        for(int i = 0; i < alle.size(); i++){
            int cu = alle[i].u;
            int cv = alle[i].v;
            int cw = alle[i].w;
            if(dis[cu][cv] > cw)
                dis[cu][cv] = cw;

        }
    }
	return 0;
}

