/*************************************************************************
    > File Name: hdu1213.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月05日 星期二 09时29分00秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1005;

int pre[maxn], cnt[maxn];
int n;

inline void init(){
    memset(pre, -1, sizeof(pre));
    memset(cnt, 0, sizeof(cnt));
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
        n--;
        if(cnt[x] < cnt[y])
            pre[x] = y;
        else{
            pre[y] = x;
            if(cnt[x] == cnt[y])
                cnt[x]++;
        }
    }
}

int main(){
    int t, m, cx, cy;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d%d", &n, &m);
        while(m--){
            scanf("%d %d", &cx, &cy);
            merge(cx, cy);
        }
        printf("%d\n", n);
    }

    return 0;
}

