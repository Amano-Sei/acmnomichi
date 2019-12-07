/*************************************************************************
    > File Name: hdu1272.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月16日 星期六 19时40分15秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//难得有一道中文题，还是中文水题
//结果首先我没读全题，其次题本身还玩文字游戏...

const int maxn = 100005;

int pre[maxn];
bool book[maxn];

int getpre(int x){
    if(pre[x] == -1)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    bool ans;
    int cu, cv;
    int ccount;
    while(scanf("%d%d", &cu, &cv) != EOF && cu > -1){
        if(cu == 0){
            puts("Yes");
            continue;
        }
        memset(pre, -1, sizeof(pre));
        memset(book, 0, sizeof(book));
        book[cu] = book[cv] = true;
        ccount = 1;
        ans = true;
        pre[cv] = cu;
        while(scanf("%d%d", &cu, &cv) != EOF && cu > 0){
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
            if(tu != tv){
                ccount--;
                pre[tv] = tu;
            }else
                ans = false;
        }
        if(ans && ccount == 1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

