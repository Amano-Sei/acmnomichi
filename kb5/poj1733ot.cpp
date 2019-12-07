/*************************************************************************
    > File Name: poj1733ot.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月11日 星期一 22时00分17秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 10010;

map<int, int> numtoi;
int tot;

int pre[maxn];
bool w[maxn];

int getnum(int x){
    map<int, int>::iterator it = numtoi.find(x);
    if(it != numtoi.end())
        return it->second;
    return numtoi[x] = ++tot;
    //if(numtoi.count(x) == 0)
    //    numtoi[x] = ++tot;
    //return numtoi[x];
}

int getpre(int x){
    if(pre[x] == 0)
        return x;
    int tx = getpre(pre[x]);
    w[x] ^= w[pre[x]];
    return pre[x]=tx;
}

int main(){
    int n, m;
    int cu, cv;
    char cs[16];
    scanf("%d%d", &n, &m);
    int ans = m;
    for(int i = 0; i < m; i++){
        scanf("%d%d%s", &cu, &cv, cs);
        if(ans < m)
            continue;
        cu = getnum(cu);
        cv = getnum(cv+1);
        int tu = getpre(cu);
        int tv = getpre(cv);
        bool tmp = w[cu]^w[cv]^(cs[0]=='o');
        if(tu == tv){
            if(tmp)
                ans = i;
        }else{
            pre[tv] = tu;
            w[tv] = tmp;
        }
        //if(tu != tv){
        //    pre[tv] = tu;
        //    w[tv] = tmp;
        //}else if(tmp){
        //    ans = i;
        //}
    }
    printf("%d\n", ans);
    return 0;
}

