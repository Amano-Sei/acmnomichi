/*************************************************************************
    > File Name: e.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 22时50分19秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 200005;

struct node{
    int dp[5][5];
    void init(){
        memset(dp, 0x3f, sizeof(dp));
    }
    node operator + (const node &a) const {
        node ans;
        ans.init();
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                for(int k = 0; k < 5; k++)
                    ans.dp[i][j] = min(ans.dp[i][j], dp[i][k]+a.dp[k][j]);
        return ans;
    }
}stree[4*maxn], cans;
char s[maxn];

void build(int l, int r, int root){
    if(l==r){
        stree[root].init();
        for(int i = 0; i < 5; i++)
            stree[root].dp[i][i] = 0;
        switch(s[l]){
            case '2':
                stree[root].dp[0][0] = 1;
                stree[root].dp[0][1] = 0;
                break;
            case '0':
                stree[root].dp[1][1] = 1;
                stree[root].dp[1][2] = 0;
                break;
            case '1':
                stree[root].dp[2][2] = 1;
                stree[root].dp[2][3] = 0;
                break;
            case '7':
                stree[root].dp[3][3] = 1;
                stree[root].dp[3][4] = 0;
                break;
            case '6':
                stree[root].dp[3][3] = 1;
                stree[root].dp[4][4] = 1;
                break;
        }
        return;
    }
    int m = (l+r)>>1;
    build(l, m, root<<1);
    build(m+1, r, root<<1|1);
    stree[root] = stree[root<<1]+stree[root<<1|1];
    return;
}

void query(int l, int r, int root, int ql, int qr){
    if(ql <= l && r <= qr){
        cans = cans+stree[root];
        return;
    }
    int m = (l+r) >> 1;
    if(qr <= m)
        query(l, m, root<<1, ql, qr);
    else if(ql > m)
        query(m+1, r, root<<1|1, ql, qr);
    else{
        query(l, m, root<<1, ql, m);
        query(m+1, r, root<<1|1, m+1, qr);
    }
}

int main(){
    int n, q, ql, qr;
    scanf("%d%d%s", &n, &q, &s[1]);
    build(1, n, 1);
    while(q--){
        scanf("%d%d", &ql, &qr);
        cans.init();
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
