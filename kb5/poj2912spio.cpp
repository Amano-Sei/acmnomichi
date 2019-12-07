/*************************************************************************
    > File Name: poj2912spio.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月16日 星期六 18时02分57秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 505;
const int maxm = 2005;

int pre[maxn][maxn], w[maxn][maxn];
int sk[maxn];
bool book[maxn];
int tot;
int cu[maxm], cv[maxm], cw[maxm];
char buf[1280000];
int bufi, buflen;

inline void init(){
    memset(pre, -1, sizeof(pre));
    memset(w, 0, sizeof(w));
    tot = 0;
    memset(book, 0, sizeof(book));
}

int getpre(int x, int ci){
    if(pre[ci][x] == -1)
        return x;
    int tx = getpre(pre[ci][x], ci);
    w[ci][x] = (w[ci][x]+w[ci][pre[ci][x]])%3;
    return pre[ci][x] = tx;
}

inline int nxtchar(){
    if(bufi == buflen){
        bufi = 0;
        buflen = fread(buf, 1, sizeof(buf)-1, stdin);
    }
    if(bufi == buflen)
        exit(0);
    return buf[bufi++];
}

inline int getnum(int ci){
    char cc;
    do{
        cc = nxtchar();
    }while(cc < '0' || cc > '9');
    int ans = 0;
    do{
        ans = ans*10+cc-'0';
        cc = nxtchar();
    }while(cc >= '0' && cc <= '9');
    while(ci){
        if(cc == '='){
            cw[ci] = 0;
            break;
        }else if(cc == '>'){
            cw[ci] = 1;
            break;
        }else if(cc == '<'){
            cw[ci] = 2;
            break;
        }
        cc = nxtchar();
    }
    return ans;
}

int main(){
    int n, m, ans, anslen, lessans;
    while(true){
        n = getnum(0);
        m = getnum(0);
        init();
        anslen = ans = -1;
        lessans = 2;
        for(int i = 1; i <= m; i++){
            cu[i] = getnum(i);
            cv[i] = getnum(0);
            if(lessans > 0){
                if(tot == 0){
                    int tu = getpre(cu[i], n);
                    int tv = getpre(cv[i], n);
                    int tw = (w[n][cu[i]]+cw[i]-w[n][cv[i]])%3;
                    if(tu != tv){
                        pre[n][tv] = tu;
                        w[n][tv] = tw;
                    }else if(tw){
                        for(int j = 0; j < n; j++)
                            if(getpre(j, n) == tu)
                                sk[tot++] = j;
                        lessans = tot;
                        for(int j = 0; j < tot; j++)
                            for(int k = 1; k <= i; k++){
                                if(cu[k] == sk[j] || cv[k] == sk[j])
                                    continue;
                                int tu = getpre(cu[k], j);
                                int tv = getpre(cv[k], j);
                                int tw = (w[j][cu[k]]+cw[k]-w[j][cv[k]]+3)%3;
                                if(tu != tv){
                                    pre[j][tv] = tu;
                                    w[j][tv] = tw;
                                }else if(tw){
                                    book[j] = true;
                                    lessans--;
                                    break;
                                }
                            }
                    }
                }else{
                    for(int j = 0; j < tot; j++)
                        if(!book[j] && cu[i] != sk[j] && cv[i] != sk[j]){
                            int tu = getpre(cu[i], j);
                            int tv = getpre(cv[i], j);
                            int tw = (w[j][cu[i]]+cw[i]-w[j][cv[i]])%3;
                            if(tu != tv){
                                pre[j][tv] = tu;
                                w[j][tv] = tw;
                            }else if(tw){
                                book[j] = true;
                                lessans--;
                                anslen = i;
                            }
                        }
                }
            }
        }
        if(n == 1)
            puts("Player 0 can be determined to be the judge after 0 lines");
        else if(lessans == 0)
            puts("Impossible");
        else if(lessans > 1)
            puts("Can not determine");
        else{
            for(int i = 0; i < tot; i++)
                if(!book[i])
                    ans = sk[i];
            printf("Player %d can be determined to be the judge after %d lines\n", ans, anslen);
        }
    }
    return 0;
}

