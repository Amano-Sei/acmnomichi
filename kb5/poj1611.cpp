/*************************************************************************
    > File Name: poj1611.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月05日 星期二 09时14分35秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 30005;

int pre[maxn];
int cnt[maxn];

inline void init(int n){
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < n; i++)
        cnt[i] = 1;
}

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

inline void merge(int x, int y){
    x = getpre(x);
    y = getpre(y);
    if(x != y){
        if(cnt[x] < cnt[y]){
            pre[x] = y;
            cnt[y] += cnt[x];
        }else{
            pre[y] = x;
            cnt[x] += cnt[y];
        }
    }
}

int main(){
    int n, m, k, cu, cv;
    while(scanf("%d%d", &n, &m) != EOF && n){
        init(n);
        while(m--){
            scanf("%d %d", &k, &cu);
            while(--k){
                scanf("%d", &cv);
                merge(cu, cv);
            }
        }
        printf("%d\n", cnt[getpre(0)]);
    }
    return 0;
}

