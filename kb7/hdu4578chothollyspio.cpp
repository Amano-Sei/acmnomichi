/*************************************************************************
    > File Name: hdu4578chothollyspio.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月07日 星期六 11时13分25秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

//15ms的差距不知道原因是什么（，不过根据Amdahl定理，是时候掏出speedio
//468ms...emmm差不多结束了吧，这道题只差看一遍bin神代码了

const int maxn = 100005;
const int mod = 10007;

char buf[maxn*10*24];
int ci;
char outbuf[maxn*60];
int oi;

inline bool isnum(char c){
    return c>='0' && c <= '9';
}
inline bool notnum(char c){
    return c<'0' || c>'9';
}

inline int read(){
    while(notnum(buf[ci]))
        ci++;
    register int ans = buf[ci++]-'0';
    while(isnum(buf[ci]))
        ans = ans*10+buf[ci++]-'0';
    return ans;
}

inline void out(int x){
    register int ti = oi;
    register int tti = oi;
    do{
        outbuf[ti++] = (x%10)+'0';
        x /= 10;
    }while(x);
    oi = ti+1;
    outbuf[ti--] = '\n';
    while(tti < ti)
        swap(outbuf[ti--], outbuf[tti++]);
}

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
    fread(buf, 1, sizeof(buf), stdin);
    while((n = read()) != 0){
        m = read();
        map<int, int> ctlt;
        ctlt[1] = 0;
        ctlt[n+1] = 0;
        myloop:
            register int op = read()-1, cx = read(), cy = read()+1, cc = read();
            register auto lt = split(cx, ctlt);
            register auto rt = split(cy, ctlt);
            goto *jt[op];
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
            out(ans);
            if(--m)
                goto myloop;
    }
    outbuf[--oi] = '\0';
    puts(outbuf);
    return 0;
}

