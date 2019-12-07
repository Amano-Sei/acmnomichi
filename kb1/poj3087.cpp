/*************************************************************************
    > File Name: poj3087.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月07日 星期三 00时16分43秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 405;

char os[maxn], ts[maxn], cs[2][maxn];

int main(){
    int t, c, ans;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d", &c);
        scanf("%s%s%s", os, &os[c], ts);
        printf("%d ", cas);
        ans = 0;
        memset(cs[1], 0, sizeof(cs[1]));
        strcpy(cs[ans], os);
        while(true){
            if(ans > 0 && !strcmp(cs[ans&1], os)){
                printf("-1\n");
                break;
            }
            for(int i = 0; i < c; i++){
                cs[!(ans&1)][i*2] = cs[ans&1][c+i];
                cs[!(ans&1)][i*2+1] = cs[ans&1][i];
            }
            ans++;
            if(!strcmp(cs[ans&1], ts)){
                printf("%d\n", ans);
                break;
            }
        }
    }
	return 0;
}

