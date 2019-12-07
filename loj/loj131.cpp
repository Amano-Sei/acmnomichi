/*************************************************************************
    > File Name: loj131.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月26日 星期二 21时13分54秒
 ************************************************************************/

#include <cstdio>

const int maxn = 1000005;

long long t[maxn];

inline int lowbit(int x){
    return x&(-x);
}

inline void init(int n){
    register int pt = 0, ct;
    for(int i = 1; i <= n; i++){
        scanf("%d", &ct);
        t[i] += ct-pt;
        register int j = i+lowbit(i);
        if(j <= n)
            t[j] += t[i];
        pt = ct;
    }
}

inline void add(int x, int val, int n){
    while(x <= n){
        t[x] += val;
        x += lowbit(x);
    }
}

inline void addlr(int l, int r, int val, int n){
    add(l, val, n);
    add(r+1, -val, n);
}

inline long long getsum(int x){
    long long ans = 0;
    while(x){
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int n, q;
    int cc, cl, cr, cx;
    scanf("%d%d", &n, &q);
    init(n);
    while(q--){
        scanf("%d%d", &cc, &cl);
        if(cc == 1){
            scanf("%d%d", &cr, &cx);
            addlr(cl, cr, cx, n);
        }else
            printf("%lld\n", getsum(cl));
    }
    return 0;
}

