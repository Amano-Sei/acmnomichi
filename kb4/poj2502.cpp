/*************************************************************************
    > File Name: poj2502.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019/9/27 9:04:12
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 205;
const double inf = 1/0.0;

struct qnode{
    int ci;
    double cost;
    qnode(){}
    qnode(int ci, double cost):ci(ci), cost(cost){}
    bool operator < (const qnode &a) const{
        return cost > a.cost;
    }
};

struct point{
    int x, y;
    int pi;
    point(){}
    point(int x, int y, int pi):x(x), y(y), pi(pi){}
};

vector<point> subline[maxn];
double dis[maxn][maxn];
double d[maxn];
bool book[maxn];
int si, n;

void dijkstra(){
    for(int i = 1; i < n; i++)
        d[i] = inf;
    //memset(book, 0, sizeof(book));
    priority_queue<qnode> q;
    d[0] = 0;
    q.push(qnode(0,0));
    while(!q.empty()){
        int u = q.top().ci;
        q.pop();
        if(book[u])
            continue;
        if(u == 1)
            return;
        book[u] = true;
        for(int i = 1; i < n; i++)
            if(!book[i] && d[i] > d[u]+dis[u][i]){
                d[i] = d[u]+dis[u][i];
                q.push(qnode(i, d[i]));
            }
    }
}

int main(){
    int cx, cy;
    scanf("%d%d", &cx, &cy);
    subline[si++].push_back(point(cx, cy, n++));
    scanf("%d%d", &cx, &cy);
    subline[si++].push_back(point(cx, cy, n++));
    while(scanf("%d%d", &cx, &cy) != EOF){
        subline[si].push_back(point(cx, cy, n++));
        while(scanf("%d%d", &cx, &cy) != EOF && cx >= 0)
            subline[si].push_back(point(cx, cy, n++));
        si++;
    }
    for(int i = 0; i < si; i++)
        for(int j = 0; j <= i; j++)
            for(int ii = 0; ii < subline[i].size(); ii++)
                for(int jj = 0; jj < subline[j].size(); jj++){
                    int u = subline[i][ii].pi;
                    int v = subline[j][jj].pi;
                    dis[u][v] = dis[v][u] = sqrt((subline[i][ii].x-subline[j][jj].x)*(subline[i][ii].x-subline[j][jj].x)+(subline[i][ii].y-subline[j][jj].y)*(subline[i][ii].y-subline[j][jj].y))/10000.0*60.0;
                }
    for(int i = 0; i < si; i++)
        for(int j = 0; j < subline[i].size()-1; j++){
                int u = subline[i][j].pi;
                int v = subline[i][j+1].pi;
                dis[u][v] = dis[v][u] = min(dis[u][v], sqrt((subline[i][j].x-subline[i][j+1].x)*(subline[i][j].x-subline[i][j+1].x)+(subline[i][j].y-subline[i][j+1].y)*(subline[i][j].y-subline[i][j+1].y))/40000.0*60.0);
        }
    dijkstra();
    printf("%d\n", (int)(d[1]+0.5));

    return 0;
}

