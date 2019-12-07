/*************************************************************************
    > File Name: p4570.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 21时19分32秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;

//线性基的贪心和mst的kruskal好像的说

long long d[60];

struct stone{
    long long num, mag;
}stones[maxn];

bool cmp(const stone &a, const stone &b){
    return a.mag > b.mag;
}

bool insert(long long x){
    for(int i = 59; i >= 0 && x; i--)
        if(x & (1ll<<i)){
            if(d[i])
                x ^= d[i];
            else{
                d[i] = x;
                return true;
            }
        }
    return false;
}

int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld%lld", &stones[i].num, &stones[i].mag);
    sort(stones, &stones[n], cmp);
    for(int i = 0; i < n; i++)
        if(insert(stones[i].num))
            ans += stones[i].mag;
    printf("%d\n", ans);

    return 0;
}

