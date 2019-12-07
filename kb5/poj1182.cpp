/*************************************************************************
    > File Name: poj1182.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月06日 星期三 19时10分34秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//写kb带你飞第一题的时候死活不明白性能界限是在printf上的教训告诉我
//这次的性能界限是在快速读上（
//然而事实真的如此，不知不觉间就忘记了本来最重要的东西...
//我不会再这样了（虽然还是会尝试冲榜

//来总结下这道题吧，作为遇到的第二道带权并查集的题，听说这道题是经典中的经典
//目前来看带权并查集保存的都是自己相对于自己当前pre的属性
//也正是借助这一点，使我们避免了大量的修改（就像我最初的双向链表那样
//其实我一开始有想过保存相对一点的距离什么的，但是我对并查集的嗅觉还是太差了
//保存相对于pre也就是当前根的权，使得我们更新根的权时，不需要更新根的子节点们
//因为他的子节点在被修改或查询前始终挂在这个根上
//在我们查询被挂在别的根上的根的子节点时候，会顺便把他的子节点挂到新根上
//借助原根相对新根的权和自己相对原根的权，计算出相对于新根的权

//以上应该是带权并查集的基本思想

//接下来看这道题，三种动物(因为每次都有三种可能性，所以也有三倍空间的把三种可能性都保存下来的做法)
//a吃b，b吃c，c吃a，所以用0表示同类，+1表示自己吃的类，+1+1就是自己吃的吃的类即吃自己的类，+1+1+1就是自己
//借助+1我们可以发现所有的属性都可以被+1分解，并且+1表示的属性会模3循环
//类似的-1可以用相似的方法证明合理性
//所以我们可以用0,1,2三个数表示三种相对于根的属性，剩下的就是按照带权并查集的思想的细节了

const int maxn = 50005;

int pre[maxn];
int w[maxn];
int cnt[maxn];

inline void init(){
    //memset(pre, -1, sizeof(pre));
    //memset(w, 0, sizeof(w));
}

int getpre(int x){
    //if(pre[x] == -1)
    if(pre[x] == 0)
        return x;
    int tx = getpre(pre[x]);
    w[x] = (w[x]+w[pre[x]])%3;
    return pre[x] = tx;
}

int main(){
    int n, k, co, cx, cy;
    int ans = 0;
    scanf("%d%d", &n, &k);
    //init();
    while(k--){
        scanf("%d%d%d", &co, &cx, &cy);
        if(cx > n || cy > n || co==2&&cx==cy){
            ans++;
            continue;
        }
        int tx = getpre(cx);
        int ty = getpre(cy);
        if(tx != ty){
            if(cnt[tx] < cnt[ty]){
                pre[tx] = ty;
                w[tx] = (w[cy]-w[cx]-co+4)%3;
            }else{
                if(cnt[tx] == cnt[ty])
                    cnt[tx]++;
                pre[ty] = tx;
                w[ty] = (w[cx]+co-w[cy]+2)%3;
            }
        }else if((w[cx]+co-1)%3 != w[cy])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}

