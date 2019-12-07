/*************************************************************************
    > File Name: poj3468ta.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 09时00分54秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define lowbit(x) ({ int _x = (x); _x & -x; })

using namespace std;

const int maxn = 100005;

//可以看到Binary Indexed Tree就是1800+ms，SegTree就是2500+ms
//因为树状数组维护两个树状数组，所以即使常数小也没有发生绝对的质变（
//但是700ms的差距还是挺大的...

long long t1[maxn], t2[maxn];

inline void init(int n){
    register long long pa = 0, ca;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &ca);
        pa = ca-pa;
        t1[i] += pa;
        t2[i] += pa*i;
        pa = i+lowbit(i);
        if(pa <= n){
            t1[pa] += t1[i];
            t2[pa] += t2[i];
        }
        pa = ca;
    }
}

inline void add(int x, int val, int n, long long t[]){
    while(x <= n){
        t[x] += val;
        x += lowbit(x);
    }
}

inline void addlr(int l, int r, int val, int n){
    add(l, val, n, t1);
    add(r+1, -val, n, t1);
    add(l, val*l, n, t2);
    add(r+1, -val*(r+1), n, t2);
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
    int ca, cb, cc;
    char op[12];
    scanf("%d%d", &n, &q);
    init(n);
    while(q--){
        scanf("%s%d%d", op, &ca, &cb);
        if(op[0] == 'C'){
            scanf("%d", &cc);
            addlr(ca, cb, cc, n);
        }else
            printf("%lld\n", getlrsum(ca, cb));
    }
    return 0;
}

