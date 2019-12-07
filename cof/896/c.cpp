/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月06日 星期五 15时48分59秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#pragma GCC optimize(2)

using namespace std;

//貌似这道题是odt也就是珂朵莉树的起源
//虽然luogo某dalao说不是...反论是ODT是平凡技巧
//但是...这道题的出题人就是ODT啊...
//而且ODT好像是中国人诶...

//emmm这道题主要是因为hdu4578看dalao说可以用珂朵莉树，所以看了下珂朵莉的起源
//不过...这个区间第k小居然是暴力来做的...
//也太狡猾了吧！

//pow要先把base求mod一下（
//这个地方wa了好久（（（
//虽然不会有越long long界的加，但是会出现一乘方就溢出的情况

const int maxn = 100005;

inline int rnd(long long &seed){
    register int ans = seed;
    seed = (seed*7+13)%1000000007;
    return ans;
}

map<int, long long> ct;
pair<long long, int> cv[maxn];

inline long long mypow(long long base, int x, int mod){
    register long long ans = 1;
    base %= mod;
    while(true){
        if(x&1)
            ans = ans*base%mod;
        base = base*base%mod;
        if((x>>=1) == 0)
            return ans;
    }
}

int main(){
    int n, m, vmax;
    long long seed;
    scanf("%d%d%lld%d", &n, &m, &seed, &vmax);
    for(int i = 0; i < n; i++)
        ct[i] = (rnd(seed)%vmax)+1;
    ct[n] = 0;
    while(m--){
        register int op = rnd(seed)%4;
        register int l = rnd(seed)%n;
        register int r = rnd(seed)%n;
        register int tot = 0;
        if(l > r)
            swap(l, r);
        r++;
        register int x = (rnd(seed)%((op!=2)?vmax:(r-l)))+1, y;
        if(op == 3)
            y = (rnd(seed)%vmax)+1;
        register auto itl = ct.lower_bound(l);
        if(itl->first != l){
            itl--;
            ct.insert(itl, { l, itl->second });
            itl++;
        }
        register auto itr = ct.lower_bound(r);
        if(itr->first != r){
            itr--;
            ct.insert(itr, { r, itr->second });
            itr++;
        }
        //printf("%d %d %d %d", op, l, r, x);
        switch(op){
            case 0:
                while(itl != itr)
                    (itl++)->second += x;
                break;
            case 1:
                while(itl != itr)
                    ct.erase(itl++);
                ct.insert(prev(itr), { l, x });
                break;
            case 2:
                do{
                    itr--;
                    cv[tot++] = { itr->second, r - itr->first };
                    r = itr->first;
                }while(itl != itr);
                sort(cv, &cv[tot]);
                l = -1;
                r = 0;
                do{
                    r += cv[++l].second;
                }while(r < x);
                printf("%lld\n", cv[l].first);
                break;
            case 3:
                register long long ans = 0;
                do{
                    itr--;
                    ans = (ans+(r-itr->first) * mypow(itr->second, x, y))%y;
                    r = itr->first;
                }while(itr != itl);
                printf("%lld\n", ans);
                break;
        }
    }
    return 0;
}

