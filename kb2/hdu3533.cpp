/*************************************************************************
    > File Name: hdu3533.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月11日 星期日 18时04分18秒
    > Comment: 人不能经过堡垒这点着实没读出来...
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

const int maxn = 105;

struct bullet{
    int x, y;
    int cv, cd;
    bullet(){}
    bullet(int x, int y, int cv, int cd):x(x), y(y), cv(cv), cd(cd){}
};
struct lita{
    int x, y;
    int ct;
    lita(){}
    lita(int x, int y, int ct):x(x), y(y), ct(ct){}
};
struct castle{
    int x, y;
    int ct, cv, cd;
    castle(){}
    castle(int x, int y, int ct, int cv, int cd):x(x), y(y), ct(ct), cv(cv), cd(cd){}
} csts[maxn];

bool book[maxn][maxn];
bool hascas[maxn][maxn];
bool hasgone[maxn][maxn];
int step[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
int m, n, k, d;

queue<lita> q;
list<bullet> bs;

void bfs(){
    int nx, ny, nt = 0;
    while(!q.empty()){
        lita cur = q.front();
        q.pop();
        if(cur.ct == d)
            break;
        if(nt != cur.ct+1){
            nt = cur.ct+1;
            memset(hasgone, 0, sizeof(hasgone));
            memset(book, 0, sizeof(book));
            list<bullet>::iterator it = bs.begin();
            while(it != bs.end()){
                bool nodel = true;
                for(int i = 0; i < it->cv; i++){
                    it->x += step[it->cd][0];
                    it->y += step[it->cd][1];
                    if(it->x < 0 || it->y < 0 || it->x > m || it->y > n || hascas[it->x][it->y]){
                        bs.erase(it++);
                        nodel = false;
                        break;
                    }
                }
                if(nodel){
                    book[it->x][it->y] = true;
                    it++;
                }
            }
            for(int i = 0; i < k; i++)
                if(nt % csts[i].ct == 0){
                    bs.push_back(bullet(csts[i].x, csts[i].y, csts[i].cv, csts[i].cd));
                    book[csts[i].x][csts[i].y] = true;
                }
        }
        for(int i = 0; i < 5; i++){
            nx = cur.x+step[i][0];
            ny = cur.y+step[i][1];
            if(nx >= 0 && ny >= 0 && nx <= m && ny <= n && !book[nx][ny] && !hascas[nx][ny] && !hasgone[nx][ny]){
                q.push(lita(nx, ny, nt));
                hasgone[nx][ny] = true;
                if(nx == m && ny == n){
                    printf("%d\n", nt);
                    return;
                }
            }
        }
    }
    printf("Bad luck!\n");
}

int main(){
    char c[2];
    int dv;
    while(scanf("%d%d%d%d", &m, &n, &k, &d) != EOF){
        while(!q.empty())
            q.pop();
        bs.clear();
        memset(hascas, 0, sizeof(hascas));
        for(int i = 0; i < k; i++){
            scanf("%s%d%d%d%d", c, &csts[i].ct, &csts[i].cv, &csts[i].x, &csts[i].y);
            switch(c[0]){
                case 'N':
                    csts[i].cd = 0;
                    break;
                case 'S':
                    csts[i].cd = 1;
                    break;
                case 'W':
                    csts[i].cd = 2;
                    break;
                case 'E':
                    csts[i].cd = 3;
                    break;
            }
            hascas[csts[i].x][csts[i].y] = true;
            bs.push_back(bullet(csts[i].x, csts[i].y, csts[i].cv, csts[i].cd));
        }
        q.push(lita(0, 0, 0));
        bfs();
    }
	return 0;
}

