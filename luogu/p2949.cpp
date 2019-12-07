/*************************************************************************
    > File Name: p2949.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月20日 星期三 21时20分10秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1000005;

struct Job{
    int p, dl, ci;
}jobs[maxn];

bool cmp(const Job &a, const Job &b){
    return a.p > b.p;
}

map<int, int> pre;

int getpre(int x){
    if(pre.count(x) == 0)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    long long ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &jobs[i].dl, &jobs[i].p);
        jobs[i].ci = i;
    }
    sort(jobs, &jobs[n], cmp);
    for(int i = 0; i < n; i++){
        int t = getpre(jobs[i].dl);
        if(t > 0){
            pre[t] = t-1;
            ans += jobs[i].p;
        }
    }
    printf("%lld\n", ans);

    return 0;
}

