/*************************************************************************
    > File Name: poj2236.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月30日 星期三 19时08分29秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1005;

int x[maxn], y[maxn];
char s[2];

int pre[maxn], cnt[maxn];

int stk[maxn], tot;

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    int n, d; 
    int cp, cq;
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x[i], &y[i]);
        pre[i] = -1;
        cnt[i] = 1;
    }
        
    d *= d;
    while(scanf("%s", s) != -1){
        switch(s[0]){
            case 'O':
                scanf("%d", &cp);
                stk[tot++] = cp;
                for(int i = 0; i < tot-1; i++){
                    cq = stk[i];
                    if((x[cq]-x[cp])*(x[cq]-x[cp])+(y[cq]-y[cp])*(y[cq]-y[cp]) <= d){
                        cq = getpre(cq);
                        if(cp != cq)
                            pre[cq] = cp;
                    }
                }
                break;
            case 'S':
                scanf("%d%d", &cp, &cq);
                cp = getpre(cp);
                cq = getpre(cq);
                printf("%s", cp==cq?"SUCCESS\n":"FAIL\n");
                break;
        }
    }
    return 0;
}

