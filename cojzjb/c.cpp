/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 16时13分34秒
 ************************************************************************/

#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

//刚学的珂朵莉树，然而一直waQAQ

const long long mod = 1e9+7;

map<long long, long long> tmaxp;

long long calcmaxp(long long x){
    for(long long i = 2; i*i <= x; i++)
        if(x % i == 0)
            return x/i;
    return 1;
}
long long getmaxp(long long x){
    register map<long long, long long>::iterator it = tmaxp.lower_bound(x);
    if(it != tmaxp.end() && it->first == x)
        return it->second;
    register long long ans = calcmaxp(x);
    tmaxp.insert(--it, { x, ans });
    return ans;
}
map<long long, long long>::iterator split(map<long long, long long> &ct, long long x){
    register auto ret = ct.lower_bound(x);
    if(ret->first == x)
        return ret;
    ret--;
    return ct.insert(ret, { x, ret->second });
}

int main(){
    int t;
    scanf("%d", &t);
    tmaxp[0] = 0;
    tmaxp[1] = 1;
    while(t--){
        long long n;
        int m;
        int op;
        long long cl, cr, cx;
        long long ans;
        long long predesu;
        map<long long, long long>::iterator lt, rt;
        scanf("%lld%d", &n, &m);
        map<long long, long long> ct;
        ct[1] = 0;
        ct[n+1] = 0;
        while(m--){
            scanf("%d%lld", &op, &cl);
            ans = 0;
            switch(op){
                case 1:
                    scanf("%lld%lld", &cr, &cx);
                    cr++;
                    lt = split(ct, cl);
                    rt = split(ct, cr);
                    rt--;
                    while(true){
                        ans = (ans+(cr - rt->first)%mod*(rt->second % mod)%mod)%mod;
                        if(lt == rt){
                            lt->second = cx;
                            break;
                        }else{
                            cr = rt->first;
                            ct.erase(rt--);
                        }
                    }
                    printf("%lld\n", ans);
                    break;
                case 2:
                    scanf("%lld", &cr);
                    cr++;
                    lt = split(ct, cl);
                    rt = split(ct, cr);
                    predesu = -1;
                    while(lt != rt){
                        lt->second = getmaxp(lt->second);
                        if(lt->second == predesu)
                            ct.erase(lt++);
                        else{
                            predesu = (lt++)->second;
                            ans = max(ans, predesu);
                        }
                    }
                    printf("%lld\n", ans);
                    break;
                case 3:
                    lt = ct.upper_bound(cl);
                    printf("%lld\n", (--lt)->second);
                    break;
            }
        }
    }
    return 0;
}

