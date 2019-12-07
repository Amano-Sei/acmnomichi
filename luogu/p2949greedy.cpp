/*************************************************************************
    > File Name: p2949greedy.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月20日 星期三 22时09分13秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 1000005;

priority_queue<long long, vector<long long>, greater<long long> > q;

struct job{
    int d, p;
}jobs[maxn];

bool cmp(const job &a, const job &b){
    return a.d < b.d;
}

int main(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++)
        scanf("%d%d", &jobs[i].d, &jobs[i].p);
    sort(jobs, &jobs[n], cmp);

    for(int i = 0; i < n; i++)
        if(jobs[i].d == q.size()){
            if(jobs[i].p > q.top()){
                ans += jobs[i].p-q.top();
                q.pop();
                q.push(jobs[i].p);
            }
        }else{
            ans += jobs[i].p;
            q.push(jobs[i].p);
        }
    printf("%lld\n", ans);
    return 0;
}

