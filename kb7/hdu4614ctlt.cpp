/*************************************************************************
    > File Name: hdu4614ctlt.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月10日 星期二 22时38分01秒
 ************************************************************************/

#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 50005;

map<int, bool>::iterator split(map<int, bool> &ctlt, int x){
    register map<int, bool>::iterator it = ctlt.lower_bound(x);
    if(it->first != x){
        it--;
        return ctlt.insert(it, { x, it->second });
    }
    return it;
}

int main(){
    int t, n, m;
    int op, ca, cb;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        map<int, bool> ctlt;
        ctlt[0] = false;
        ctlt[n] = false;
        while(m--){
            scanf("%d%d%d", &op, &ca, &cb);
            if(op == 1){
                register auto it = split(ctlt, ca);
                register int st = -1, ep;
                while(cb > 0 && it->first != n){
                    while(it->second)
                        ctlt.erase(it++);
                    if(it->first != n){
                        register int realin = next(it)->first-it->first;
                        if(st == -1)
                            st = it->first;

                        if(realin <= cb){
                            cb -= realin;
                            ep = it->first+realin-1;
                            ctlt.erase(it++);
                        }else{
                            ep = it->first+cb-1;
                            ctlt.insert(it, { it->first+cb, false });
                            ctlt.erase(it);
                            break;
                        }
                    }
                }
                it = ctlt.upper_bound(ca);
                it--;
                if(!it->second)
                    ctlt.insert(it, { ca, true });
                if(st != -1)
                    printf("%d %d\n", st, ep);
                else
                    puts("Can not put any one.");
            }else{
                cb++;
                register auto lt = split(ctlt, ca);
                register auto rt = split(ctlt, cb);
                register int ans = 0;
                rt--;
                while(true){
                    if(rt->second)
                        ans += cb-rt->first;
                    cb = rt->first;
                    if(rt == lt)
                        break;
                    else
                        ctlt.erase(rt--);
                }
                lt = split(ctlt, ca);
                lt->second = false;
                printf("%d\n", ans);
            }
        }
        putchar('\n');
    }
    return 0;
}

