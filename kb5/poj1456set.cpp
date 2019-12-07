/*************************************************************************
    > File Name: poj1456set.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月10日 星期日 09时56分55秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//这道题作为并查集压缩路径的经典题目，我一开始用优先队列做了（（（
//如果就这么过去了着实是一大损失
//这道题其实和coj13的c有相似的部分（啊不，这道题就是那道题的一部分
//这里的每个节点的pre表示的是包括自己在内的前面的第一个还没用被使用的点
//如果这个点被使用了就把他连到前一个节点上即可，因为此时他和前一个节点的pre是同样的

const int maxn = 10005;

struct node{
    int p, d;
    bool operator < (const node &a) const{
        return p > a.p;
    }
}prod[maxn];

int pre[maxn];

inline void init(){
    memset(pre, -1, sizeof(pre));
}

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    int n;
    int ans;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        init();
        for(int i = 0; i < n; i++)
            scanf("%d%d", &prod[i].p, &prod[i].d);
        sort(prod, &prod[n]);
        for(int i = 0; i < n; i++){
            register int t = getpre(prod[i].d);
            if(t != 0){
                ans += prod[i].p;
                pre[t] = t-1;
            }
        }
        printf("%d\n", ans);
    }
}

