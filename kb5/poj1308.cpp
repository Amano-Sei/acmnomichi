/*************************************************************************
    > File Name: poj1308.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月16日 星期六 19时40分15秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

//没想到真的有指向自己这种数据
//一直还想着反正我内部循环就算自环也没问题，然而他是第一个出现的（

//没啥好说的（
//网上一片青黄不接的博客写的都是什么鬼（
//除了真大神以外基本上看不到自己的想法观点思路什么的（
//大部分都是你抄我我抄你，抄来抄去赚人气，真开心呢（

//连边的时候只要注意被连的点是根就可以了，并查集本来就是棵树嘛（

using namespace std;

const int maxn = 100005;

int pre[maxn];
bool book[maxn];

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    int caset = 1;
    bool ans;
    int cu, cv;
    int ccount;
    while(scanf("%d%d", &cu, &cv) != EOF && cu >= 0){
        if(cu == 0){
            printf("Case %d is a tree.\n", caset++);
            continue;
        }
        memset(pre, -1, sizeof(pre));
        memset(book, 0, sizeof(book));
        book[cu] = book[cv] = true;
        ccount = 1;
        if(cu != cv){
            ans = true;
            pre[cv] = cu;
        }else
            ans = false;
        while(scanf("%d%d", &cu, &cv) != EOF && cu > 0){
            if(!ans)
                continue;
            if(!book[cu]){
                book[cu] = true;
                ccount++;
            }
            if(!book[cv]){
                book[cv] = true;
                ccount++;
            }
            register int tu = getpre(cu);
            register int tv = getpre(cv);
            if(tu != tv && tv == cv){
                ccount--;
                pre[tv] = tu;
            }else
                ans = false;
        }
        if(ans && ccount == 1)
            printf("Case %d is a tree.\n", caset++);
        else
            printf("Case %d is not a tree.\n", caset++);
    }
    return 0;
}

