/*************************************************************************
    > File Name: poj2912.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月16日 星期六 10时52分07秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

//起初一直wa...发觉网上写法都是枚举（不爽，遂好好想了下
//我最开始的做法是建立在一个错误的基础上的，如果出现了矛盾数据，就说明裁判在当前的两人之中
//但是事实上并不是说明裁判在两者之中，而是在两者所在的并查集中的所有点中
//（因为可能存在只要不连并查集中的其他的点就可以不让矛盾发生

//于是建立在上述事实上，可以枚举更少的点，写个双向链表可能会更快一点
//准备掏出快速读，挑战一下榜单（
//现实是读明显不是性能的主要瓶颈，所以调整成双向链表看看
//然而双向链表也没有变快（

using namespace std;

const int maxn = 505;
const int maxm = 2005;

int pre[maxn][maxn], w[maxn][maxn];
int lt[maxn], rt[maxn];
bool book[maxn];
int cu[maxm], cv[maxm], cw[maxm];
char buf[128];

inline void insert(int x, int n){
    rt[x] = rt[n];
    lt[x] = n;
    lt[rt[x]] = x;
    rt[n] = x;
}

inline void del(int x){
    lt[rt[x]] = lt[x];
    rt[lt[x]] = rt[x];
}

inline void init(int n){
    memset(pre, -1, sizeof(pre));
    memset(w, 0, sizeof(w));
    memset(book, 0, sizeof(book));
    lt[n] = rt[n] = n;
}

int getpre(int x, int ci){
    if(pre[ci][x] == -1)
        return x;
    int tx = getpre(pre[ci][x], ci);
    w[ci][x] = (w[ci][x]+w[ci][pre[ci][x]])%3;
    return pre[ci][x] = tx;
}

inline char *getnum(int &a, char *s){
    int ans = 0;
    int i;
    for(i = 0; !(s[i]>='0'&&s[i]<='9'); i++);
    while(s[i]>='0'&&s[i]<='9')
        ans = ans*10+s[i++]-'0';
    a = ans;
    while(s[i] == ' ')
        i++;
    return &s[i];
}

int main(){
    int n, m, anslen, lessans;
    while(scanf("%d%d", &n, &m) != EOF){
        init(n);
        lessans = 2;
        for(int i = 1; i <= m; i++){
            //scanf("%s", buf);
            //do{
            //    fgets(buf, sizeof(buf), stdin);
            //}while(strlen(buf) <= 3);
            scanf("%d%c%d", &cu[i], buf, &cv[i]);
            if(lessans > 0){
                //char *ts = getnum(cu[i], buf);
                //cw[i] = ((*ts=='=')?0:((*ts=='>')?1:2));
                //getnum(cv[i], ts+1);
                cw[i] = ((buf[0]=='=')?0:((buf[0]=='>')?1:2));
                if(rt[n] == n){
                    int tu = getpre(cu[i], n);
                    int tv = getpre(cv[i], n);
                    int tw = (w[n][cu[i]]+cw[i]-w[n][cv[i]])%3;
                    if(tu != tv){
                        pre[n][tv] = tu;
                        w[n][tv] = tw;
                    }else if(tw){
                        lessans = 0;
                        for(int j = 0; j < n; j++)
                            if(getpre(j, n) == tu){
                                insert(j, n);
                                lessans++;
                            }
                        for(int j = rt[n]; j < n ; j = rt[j])
                            for(int k = 1; k <= i; k++){
                                if(cu[k] == j || cv[k] == j)
                                    continue;
                                int tu = getpre(cu[k], j);
                                int tv = getpre(cv[k], j);
                                int tw = (w[j][cu[k]]+cw[k]-w[j][cv[k]]+3)%3;
                                if(tu != tv){
                                    pre[j][tv] = tu;
                                    w[j][tv] = tw;
                                }else if(tw){
                                    del(j);
                                    lessans--;
                                    break;
                                }
                            }
                    }
                }else{
                    for(int j = rt[n]; j < n; j = rt[j])
                        if(cu[i] != j && cv[i] != j){
                            int tu = getpre(cu[i], j);
                            int tv = getpre(cv[i], j);
                            int tw = (w[j][cu[i]]+cw[i]-w[j][cv[i]])%3;
                            if(tu != tv){
                                pre[j][tv] = tu;
                                w[j][tv] = tw;
                            }else if(tw){
                                del(j);
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
            printf("Player %d can be determined to be the judge after %d lines\n", rt[n], anslen);
        }
    }
    return 0;
}

