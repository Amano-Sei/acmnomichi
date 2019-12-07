/*************************************************************************
    > File Name: poj2236.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月30日 星期三 19时08分29秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1005;

struct Edge{
    int v, next;
}edge[maxn*maxn];

int head[maxn], tot;
int x[maxn], y[maxn];
char s[2];

inline void push(int u, int v){
    edge[tot] = { v, head[u] };
    head[u] = tot++;
}

int pre[maxn], cnt[maxn];
bool book[maxn];

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
        pre[i] = head[i] = -1;
        cnt[i] = 1;
    }
        
    d *= d;
    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++)
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= d){
                push(i, j);
                push(j, i);
            }
    while(scanf("%s", s) != -1){
        switch(s[0]){
            case 'O':
                scanf("%d", &cp);
                book[cp] = true;
                for(int i = head[cp]; i != -1; i = edge[i].next){
                    cq = edge[i].v;
                    if(book[cq]){
                        cp = getpre(cp);
                        cq = getpre(cq);
                        if(cp != cq){
                            if(cnt[cp] < cnt[cq])
                                pre[cp] = cq;
                            else{
                                pre[cq] = cp;
                                if(cnt[cp] == cnt[cq])
                                    cnt[cp]++;
                            }
                        }
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

