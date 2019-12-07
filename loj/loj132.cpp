/*************************************************************************
    > File Name: loj132.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月26日 星期二 21时26分26秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000005;

long long t1[maxn], t2[maxn];

inline int lowbit(int x){
    return x&(-x);
}

inline void init(int n){
    register int pa = 0, ca;
    for(int i = 1; i <= n; i++){
        scanf("%d", &ca);
        pa = ca-pa;
        t1[i] += pa;
        t2[i] += 1ll*i*pa;
        pa = i+lowbit(i);
        if(pa <= n){
            t1[pa] += t1[i];
            t2[pa] += t2[i];
        }
        pa = ca;
    }
}

inline void add(int x, long long val, int n, long long t[]){
    while(x <= n){
        t[x] += val;
        x += lowbit(x);
    }
}

inline void addlr(int l, int r, int val, int n){
    add(l, val, n, t1);
    add(r+1, -val, n, t1);
    add(l, 1ll*val*l, n, t2);
    add(r+1, -1ll*val*(r+1), n, t2);
}

inline long long getsum(int x, long long t[]){
    long long ans = 0;
    while(x){
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

inline long long getlrsum(int l, int r){
    return (r+1)*getsum(r, t1)-getsum(r, t2)-l*getsum(l-1, t1)+getsum(l-1, t2);
}

int main(){
    int n, q;
    int cc, cl, cr, cx;
    scanf("%d%d", &n, &q);
    init(n);
    while(q--){
        scanf("%d%d%d", &cc, &cl, &cr);
        if(cc == 1){
            scanf("%d", &cx);
            addlr(cl, cr, cx, n);
        }else
            printf("%lld\n", getlrsum(cl, cr));
    }
    return 0;
}

