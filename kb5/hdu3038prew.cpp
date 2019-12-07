/*************************************************************************
    > File Name: hdu3038prew.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月06日 星期三 18时05分22秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int pre[maxn];
int w[maxn];
//int cnt[maxn];

inline void init(int n){
    //memset(pre, -1, (n+2)*sizeof(int));
    //memset(w, 0, (n+2)*sizeof(int));
    //memset(cnt, 0, (n+2)*sizeof(int));
    for(int i = 1; i <= n+1; i++){
        pre[i] = -1;
        w[i] = 0;
        //cnt[i] = 0;
    }
}

int getpre(int x){
    if(pre[x] == -1)
        return x;
    int tx = getpre(pre[x]);
    w[x] += w[pre[x]];
    return pre[x] = tx;
}

int main(){
    int n, m;
    int cu, cv, cw;
    int ans;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        init(n);
        while(m--){
            scanf("%d%d%d", &cu, &cv, &cw);
            cv++;
            int tu = getpre(cu);
            int tv = getpre(cv);
            if(tu != tv){
                //if(cnt[tv] < cnt[tu]){
                    pre[tv] = tu;
                    w[tv] = w[cu]+cw-w[cv];
                //}else{
                //    pre[tu] = tv;
                //    w[tu] = w[cv]-cw-w[cu];
                //    if(cnt[tu] == cnt[tv])
                //        cnt[tv]++;
                //}
            }else{
                if(w[cv]-w[cu] != cw)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

