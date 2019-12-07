/*************************************************************************
    > File Name: poj3279better.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 17时02分37秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 15;
unsigned int pad[maxn], ans[maxn], cans[maxn];
int cnt, mincnt;
int m, n;
int main(){
    unsigned int tmp, ntmp;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
        scanf("%u", &tmp);
        for(int j = 1; j < n; j++){
            scanf("%u", &ntmp);
            tmp = (tmp<<1)|ntmp;
        }
        pad[i] = tmp;
    }
    ntmp = (1<<n)-1; 
    mincnt = m*n+1;
    for(cans[0] = 0; cans[0] <= ntmp; cans[0]++){
        for(int i = 1; i < m; i++){
            cans[i] = (pad[i-1] ^ cans[i-1] ^ (cans[i-1]<<1) ^ (cans[i-1] >> 1)) & ntmp;
            if(i > 1)
                cans[i] ^= cans[i-2];
        }
        tmp = (pad[m-1] ^ cans[m-1] ^ (cans[m-1] << 1) ^ (cans[m-1] >> 1)) & ntmp;
        if(m > 1)
            tmp ^= cans[m-2];
        if(!tmp){
            cnt = 0;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    if((cans[i] >> j) & 1)
                        cnt++;
            if(cnt < mincnt){
                memcpy(ans, cans, sizeof(ans));
                mincnt = cnt;
            }
        }
    }
    if(mincnt < m*n+1)
        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--)
                printf("%u ", (ans[i] >> j) & 1);
            putchar('\n');
        }
    else
        printf("IMPOSSIBLE\n");
	return 0;
}

