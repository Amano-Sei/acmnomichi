/*************************************************************************
    > File Name: p3292.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 21时36分11秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//写完才发现是树链剖分...
//现在还写不了（晚点再做吧

const int maxn = 20005;

struct node{
    long long d[61];
    int l, r;
}st[maxn<<2];

void insert(long long x, long long d[]){
    for(int i = 60; i >= 0 && x; i--)
        if(x & (1ll<<i)){
            if(d[i])
                x ^= d[i];
            else{
                d[i] = x;
                return;
            }
        }
}

void merge(long long d1[], long long d2[]){
    for(int i = 60; i >= 0; i--)
        if(d1[i])
            insert(d1[i], d2);
}

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    if(l == r){
        register long long tmp;
        scanf("%lld", &tmp);
        insert(tmp, st[x].d);
        return;
    }
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m+1, r);
    memcpy(st[x].d, st[x<<1].d, sizeof(st[x].d));
    merge(st[(x<<1)|1].d, st[x].d);
}

long long ansd[61];
inline long long getmax(){
    register long long ans = 0;
    for(int i = 60; i >= 0; i--){
        register long long tans = ans^ansd[i];
        if(tans > ans)
            ans = tans;
    }
    return ans;
}

void query(int x, int l, int r){
    if(l <= st[x].l && st[x].r <= r){
        merge(st[x].d, ansd);
        return;
    }
    int m = (st[x].l+st[x].r)>>1;
    if(l <= m)
        query(x<<1, l, m);
    if(r > m)
        query((x<<1)|1, m+1, r);
}

int main(){
    int n, q;
    int cx, cy;
    scanf("%d%d", &n, &q);
    built(1, 1, n);
    while(q--){
        scanf("%d%d", &cx, &cy);
        memset(ansd, 0, sizeof(ansd));
        query(1, cx, cy);
        printf("%lld\n", getmax());
    }
    return 0;
}

