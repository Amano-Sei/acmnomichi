/*************************************************************************
    > File Name: hdu4578chotholly.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月07日 星期六 11时13分25秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

//加上快速读写，妥妥地可以干掉榜1了（
//emmm其实这道题因为赋值操作的存在使得某种建线段树方法可行甚至比常规方法更快就已经说明了有大量相同区间
//而chotholly树实在是太适合这种数据了
//不出意外的话原榜1就是用的chotholly树
//好好的线段树基础题，然而不按照基础来写会有更好的性能，这是一种讽刺么（

const int maxn = 100005;
const int mod = 10007;

int p[3][mod];

inline void init(){
    for(int i = 1; i < mod; i++)
        p[0][i] = i, p[1][i] = i*i%mod, p[2][i] = p[1][i]*i%mod;
}

inline map<int, int>::iterator split(int x, map<int, int> &ctlt){
    register auto ret = ctlt.lower_bound(x);
    if(ret->first != x){
        ret--;
        ret = ctlt.insert(ret, { x, ret->second });
    }
    return ret;
}

int main(){
    static void *jt[4] = { &&foradd, &&formul, &&forch, &&forquery };
    int n, m;
    init();
    while(scanf("%d%d", &n, &m) != EOF && n){
        map<int, int> ctlt;
        ctlt[1] = 0;
        ctlt[n+1] = 0;
        register int op, cx, cy, cc;
        myloop:
            scanf("%d%d%d%d", &op, &cx, &cy, &cc);
            register auto lt = split(cx, ctlt);
            register auto rt = split(++cy, ctlt);
            goto *jt[op-1];
        foradd:
            do{
                rt--;
                rt->second = (rt->second+cc)%mod;
            }while(lt != rt);
            if(--m)
                goto myloop;
            continue;
        formul:
            do{
                rt--;
                rt->second = (rt->second*cc)%mod;
            }while(lt != rt);
            if(--m)
                goto myloop;
            continue;
        forch:
            (lt++)->second = cc;
            ctlt.erase(lt, rt);
            if(--m)
                goto myloop;
            continue;
        forquery:
            register int ans = 0;
            cc--;
            do{
                rt--;
                ans = (ans+(cy-rt->first)*p[cc][rt->second])%mod;
                cy = rt->first;
            }while(lt != rt);
            printf("%d\n", ans);
            if(--m)
                goto myloop;
    }
    return 0;
}

