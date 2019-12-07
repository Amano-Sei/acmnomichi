/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 10时34分48秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct allp{
    int a, b;
    allp(){}
    allp(int a, int b):a(a), b(b){}
}peo[200];

struct lastg{
    int nu, a, b, w;
    lastg(){}
    lastg(int nu, int a, int b, int w):nu(nu),a(a),b(b),w(w){}
}lastgame[16];
bool cmp(const lastg &a, const lastg &b){
    return a.nu < b.nu;
}

int alla[205], allb[205], ta, tb;
int n;
int ans[2][8], curans[2][8], cans, maxans;
bool book[206];

void dfs(int ii, int sj){
    //cout << i << "  " << ii << endl;
    for(int j = sj; j < ta; j++){
        if(!book[alla[j]]){
            book[alla[j]] = true;
            cans += peo[alla[j]].a;
            curans[0][ii] = alla[j];
            if(ii == 7){
                int bi = 0;
                int tans = cans;
                for(int i = 0; i < tb && bi < 8; i++)
                    if(!book[allb[i]]){
                        tans += peo[allb[i]].b;
                        curans[1][bi++] = allb[i];
                    }
                if(tans > maxans){
                    maxans = tans;
                    memcpy(ans, curans, sizeof(ans));
                }
            }
            else
                dfs(ii+1, j+1);
            cans -= peo[alla[j]].a;
            book[alla[j]] = false;
        }
    }
}

int main(){
    int tt;
    while(scanf("%d", &n) != EOF && n){
        ta = tb = maxans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &peo[i].a, &peo[i].b);
            if(ta == 0 || ta > 0 && peo[alla[ta-1]].a == peo[i].a){
                alla[ta++] = i;
            }else{
                tt = ta;
                while(tt > 0 && peo[alla[tt-1]].a < peo[i].a){
                    alla[tt] = alla[tt-1];
                    tt--;
                }
                alla[tt] = i;
                ta++;
                for(; ta > 16 && peo[alla[ta-1]].a != peo[alla[15]].a; ta--);
            }
            if(tb == 0 || tb > 0 && peo[allb[tb-1]].b == peo[i].b){
                allb[tb++] = i;
            }else{
                tt = tb;
                while(tt > 0 && peo[allb[tt-1]].b < peo[i].b){
                    allb[tt] = allb[tt-1];
                    tt--;
                }
                allb[tt] = i;
                tb++;
                for(; tb > 16 && peo[allb[tb-1]].b != peo[allb[15]].b; tb--);
            }
        }
        //for(int i = 0 ; i < ta; i++)
        //    cout << alla[i] << " "<< peo[alla[i]].a<< " " << peo[allb[i]].b << endl;
        //cout << endl;
        //for(int i = 0 ; i < tb; i++)
        //    cout << allb[i] << " "<< peo[allb[i]].a<< " " << peo[allb[i]].b << endl;
        dfs(0, 0);
        printf("%d\n", maxans);
        for(int i = 0; i < 8; i++)
            lastgame[i] = lastg(ans[0][i]+1, peo[ans[0][i]].a, peo[ans[0][i]].b, 1);
        for(int i = 0; i < 8; i++)
            lastgame[i+8] = lastg(ans[1][i]+1, peo[ans[1][i]].a, peo[ans[1][i]].b, 2);
        sort(lastgame, lastgame+16, cmp);
        for(int i = 0; i < 16; i++)
            printf("%d %d %d %d\n", lastgame[i].nu, lastgame[i].a, lastgame[i].b, lastgame[i].w);
    }
	return 0;
}

