/*************************************************************************
    > File Name: crans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月09日 星期一 00时05分51秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200005;
const int inf = 0x3f3f3f3f;

char s[maxn];

struct node{
    int dp[5][5];
    node(){
        memset(dp, 0x3f, sizeof(dp));
    }
    node(int x){
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < 5; i++)
            dp[i][i] = 0;
        switch(s[x]){
            case '9':
                dp[4][4] = 1;
                dp[3][4] = 0;
                break;
            case '8':
                dp[4][4] = 1;
                dp[3][3] = 1;
                break;
            case '1':
                dp[2][2] = 1;
                dp[2][3] = 0;
                break;
            case '0':
                dp[1][1] = 1;
                dp[1][2] = 0;
                break;
            case '2':
                dp[0][0] = 1;
                dp[0][1] = 0;
        }
    }
    node operator + (const node &a) const{
        node ans = node();
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                for(int k = 0; k < 5; k++)
                    ans.dp[i][j] = min(ans.dp[i][j], dp[i][k]+a.dp[k][j]);
        return ans;
    }
}stree[4*maxn], cans;

void build(int l, int r, int root){
    if(l==r){
        stree[root] = node(l);
        return;
    }
    int m = (l+r)>>1;
    build(m+1, r, root<<1|1);
    build(l, m, root<<1);
    stree[root] = stree[root<<1|1]+stree[root<<1];
}

void query(int l, int r, int root, int ql, int qr){
    if(ql <= l && r <= qr){
        cans = cans+stree[root];
        return;
    }
    int m = (l+r)>>1;
    if(ql > m)
        query(m+1, r, root<<1|1, ql, qr);
    else if(qr <= m)
        query(l, m, root<<1, ql, qr);
    else{
        query(m+1, r, root<<1|1, m+1, qr);
        query(l, m, root<<1, ql, m);
    }
}

int main(){
    int n, q, ql, qr;
    scanf("%d%d%s", &n, &q, &s[1]);
    build(1, n, 1);
    while(q--){
        scanf("%d%d", &ql, &qr);
        cans = node();
        for(int i = 0; i < 5; i++)
            cans.dp[i][i] = 0;
        query(1, n, 1, ql, qr);
        if(cans.dp[0][4] != inf)
            printf("%d\n", cans.dp[0][4]);
        else
            printf("-1\n");
    }
	return 0;
}

