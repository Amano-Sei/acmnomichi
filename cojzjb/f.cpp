/*************************************************************************
    > File Name: f.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 15时59分15秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cost[52][52];

inline int c2i(char c){
    return c>0x60?(c-71):(c-65);
}

char cs[5];

int main(){
    int n, a, b;
    scanf("%s", cs);
    a = c2i(cs[0]);
    scanf("%s", cs);
    b = c2i(cs[0]);
    memset(cost, 0x3f, sizeof(cost));
    scanf("%d", &n);
    while(n--){
        scanf("%s", cs);
        cost[c2i(cs[0])][c2i(cs[3])] = 1;
    }
    for(int k = 0; k < 52; k++)
        for(int i = 0; i < 52; i++)
            for(int j = 0; j < 52; j++)
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
    if(cost[a][b] != 0x3f3f3f3f)
        printf("%d\n", cost[a][b]);
    else
        puts("-1");
    return 0;
}

