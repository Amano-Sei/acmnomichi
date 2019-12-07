/*************************************************************************
    > File Name: zoj1610.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月28日 星期四 23时47分41秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//起初选择了逆攻...
//真的是zuo QAQ

//这道题如果因为在zoj上就跳过去的话真的太可惜了...
//这道题虽然是真正的区间染色，但是较上道题来说
//这道题的最小单位的区间可以被视为点来规避用区间建树
//会出现之前那种问题是离散化导致的，但是这里因为没有离散化所以完全不用担心那个问题

//一开始选择了逆攻法，虽然不是不行，但是又不好写又没有像上题那样的优势
//上题只需要记录种数，这题需要统计段数
//所以不能简单地只记录一个是否被完全覆盖

//然后感觉距离我想要学的扫描边更近了呢（

//昨天一天没有写题，看了辣鸡课本...然后瞬间状态差一档...

const int maxn = 8005;

struct node{
    int val, l, r;
}st[16384];

int ans[maxn];

void built(int x, int l, int r){
    st[x] = { -2, l, r };
    if(l+1 == r)
        return;
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m, r);
}

inline void push_down(int x){
    st[x<<1].val = st[x].val;
    st[(x<<1)|1].val = st[x].val;
    //st[x].val = -1;
}

void update(int x, int l, int r, int val){
    //if(st[x].val >= 0)
    //    return;
    //if(st[x].val == -2 && l <= st[x].l && st[x].r <= r){
    //    st[x].val = val;
    //    return;
    //}
    //if(st[x].val == val)
    //    return;
    if(l <= st[x].l && st[x].r <= r){
        st[x].val = val;
        return;
    }
    if(st[x].val >= 0)
        push_down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(l >= m)
        update((x<<1)|1, l, r, val);
    else if(r <= m)
        update(x<<1, l, r, val);
    else
        update(x<<1, l, m, val), update((x<<1)|1, m, r, val);

    if(st[x<<1].val == st[(x<<1)|1].val)
        st[x].val = st[x<<1].val;
    else
        st[x].val = -1;
}

void lastcheck(int x, int &cc){
    if(st[x].val != -1){
        if(st[x].val != cc){
            cc = st[x].val;
            if(st[x].val >= 0)
                ans[st[x].val]++;
        }
        return;
    }
    int m = (st[x].l+st[x].r)>>1;
    lastcheck(x<<1, cc);
    lastcheck((x<<1)|1, cc);
} 

int main(){
    int n, cc;
    int tl, tr, tc;
    while(scanf("%d", &n) != EOF){
        built(1, 0, 8000);
        memset(ans, 0, sizeof(ans));
        {
            //for(int i = 0; i < n; i++){
            while(n--){
                scanf("%d%d%d", &tl, &tr, &tc);
                update(1, tl, tr, tc);
                //maxc = max(maxc, tc);
            }
        }
        cc = -2;
        lastcheck(1, cc);
        for(int i = 0; i <= 8000; i++)
            if(ans[i])
                printf("%d %d\n", i, ans[i]);
        putchar('\n');
    }
    return 0;
}

