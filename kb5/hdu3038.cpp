/*************************************************************************
    > File Name: hdu3038.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月05日 星期二 10时18分24秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 200005;
const int maxm = 40005;

//爆哭...好不容易实现了一个双向链表出来然后t了（
//这道题貌似是用带权并查集的说，虽然只看了一半别人的做法
//我就已经发觉了（双向链表好像保存了过多的信息（或者说进行了一系列不必要的操作
//所以我决定先试试看自己能不能写出来再别人的带权并查集
//写一半发觉不对啊（为什么我最后选择了双向链表就是因为这两条链的合并不只是这两个点之间的点的合并

int pre[maxn];
int lt[maxn], rt[maxn], w[maxn];

inline void init(int n){
    memset(pre, 0, sizeof(pre));
    memset(w, 0, sizeof(w));
    //memset(lt, 0x3f, sizeof(lt));
    //memset(rt, 0, sizeof(rt));
    for(int i = 1; i <= n; i++)
        lt[i] = rt[i] = i;
}

int getpre(int x){
    if(pre[x] == 0)
        return x;
    return pre[x] = getpre(pre[x]);
}

int main(){
    int n, m;
    int cx, cy, cw;
    int ans;
    while(scanf("%d%d", &n, &m) != EOF){
        init(n);
        ans = 0;
        while(m--){
            scanf("%d%d%d", &cx, &cy, &cw);
            cy++;
            int tx = getpre(cx);
            int ty = getpre(cy);
            if(tx != ty){
                while(cx > tx){
                    cx = lt[cx];
                    cw += w[cx];
                }
                while(cy > ty){
                    cy = lt[cy];
                    cw -= w[cy];
                }
                if(tx > ty){
                    swap(tx, ty);
                    cw = -cw;
                }
                pre[ty] = tx;
                while(tx < rt[tx]){
                    while(rt[tx] < ty){
                        cw -= w[tx];
                        tx = rt[tx];
                    }
                    lt[ty] = tx;
                    int tw = w[tx];
                    w[tx] = cw;
                    cw = tw-cw;
                    tx = rt[tx];
                    rt[lt[ty]] = ty;
                    swap(tx, ty);
                }
                w[tx] = cw;
                lt[ty] = tx;
                rt[tx] = ty;
            }else{
                int tsum = 0;
                while(cx < cy){
                    tsum += w[cx];
                    cx = rt[cx];
                }
                if(tsum != cw)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
}

