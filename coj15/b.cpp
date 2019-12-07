/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 20时06分07秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

#define POW2(x) ({ long long _x = (x); _x *= _x; })

const int maxn = 2003;
const int mod = 10003;

long long dis[maxn][maxn];
long long x[maxn], y[maxn];
struct node{
    long long w;
    int cnt;
}ht[mod];
int i2ht[maxn];
int tot;

inline void insert(long long num){
    int insertp = num%mod;
    while(ht[insertp].cnt != 0 && ht[insertp].w != num)
        insertp = (insertp+1)%mod;
    if(ht[insertp].cnt == 0){
        i2ht[tot++] = insertp;
        ht[insertp].w = num;
    }
    ht[insertp].cnt++;
}

int main(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &x[i], &y[i]);
        for(int j = 0; j < i; j++)
            dis[i][j] = dis[j][i]= POW2(x[i]-x[j])+POW2(y[i]-y[j]);
    }
    for(int i = 0; i < n; i++){
        memset(ht, 0, sizeof(ht));
        tot = 0;
        for(int j = 0; j < n; j++)
            insert(dis[i][j]);
        for(int j = 0; j < tot; j++){
            register long long tmp = ht[i2ht[j]].cnt;
            if(tmp >= 3)
                ans += tmp*(tmp-1)*(tmp-2)/6;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

