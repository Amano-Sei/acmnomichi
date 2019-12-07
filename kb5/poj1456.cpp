/*************************************************************************
    > File Name: poj1456.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月09日 星期六 21时40分38秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10005;

pair<int, int> alls[maxn];

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}

int main(){
    int n, ci, ans;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d%d", &alls[i].first, &alls[i].second);
        sort(alls, &alls[n], cmp);
        int maxd = alls[0].second;
        priority_queue<int> q;
        ans = ci = 0;
        for(int i = maxd; i > 0; i--){
            while(ci < n && alls[ci].second == i)
                q.push(alls[ci++].first);
            if(!q.empty()){
                ans += q.top();
                q.pop();
            }else{
                if(ci < n)
                    i = alls[ci].second+1;
                else
                    break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

