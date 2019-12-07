/*************************************************************************
    > File Name: loj130.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月26日 星期二 21时02分23秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 1000005;

int a[maxn];
long long t[maxn];

inline int lowbit(int x){
    return x&(-x);
}

inline void init(int n){
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        t[i] += a[i];
        register int j = i+lowbit(i);
        if(j <= n)
            t[j] += t[i];
    }
}

inline void add(int i, int x, int n){
    a[i] += x;
    while(i <= n){
        t[i] += x;
        i += lowbit(i);
    }
}

inline long long getsum(int x){
    long long ans = 0;
    while(x){
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

inline long long getlrsum(int l, int r){
    return getsum(r)-getsum(l-1);
}

int main(){
    int n, q;
    int cc, cl, cr;
    scanf("%d%d", &n, &q);
    init(n);
    while(q--){
        scanf("%d%d%d", &cc, &cl, &cr);
        if(cc == 1)
            add(cl, cr, n);
        else
            printf("%lld\n", getlrsum(cl, cr));
    }
    return 0;
}

