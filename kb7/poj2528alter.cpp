/*************************************************************************
    > File Name: poj2528alter.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 17时31分05秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10005;
const int maxm = 10000005;

//之前自己是压着线ac的...毕竟是正攻法...
//这种后续修改的值会覆盖前面的值或者会改变前面设置的状态的东西都可以倒过来做
//一言以蔽之，这道题就是判断倒过来插是否有任何一段找到了一段没有被完全覆盖的地方
//如果有的话，就说明他在最后是露在上面的，反之则相反

//另一方面还是区间的问题，那个问题在最小单位不再是点后就不再是问题了
//可以看到延续点树的情况下，可以借助在区间中加点的方法使得其变为区间

//起先以为折半查找莫名比直接开数组快，现实是没有质变，基本上差不太多

//但是还是不知道为什么有dalao能那么快，内存那么小，或许是因为zkw线段树吧（
//等我把基础线段树解决掉之后就重新过一遍

struct node{
    bool covered;
    int l, r;
}st[maxn<<3];

int hash[maxm], tot;
int cl[maxn], cr[maxn];
int num[maxn<<1];

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    st[x].covered = false;
    if(l+1 == r)
        return;
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m, r);
}

bool update(int x, int l, int r){
    if(st[x].covered)
        return false;
    if(l <= st[x].l && st[x].r <= r){
        st[x].covered = true;
        return true;
    }
    int m = (st[x].l+st[x].r)>>1;
    bool ret;
    if(r <= m)
        ret = update(x<<1, l, r);
    else if(l >= m)
        ret = update((x<<1)|1, l, r);
    else
        ret = update(x<<1, l, m) | update((x<<1)|1, m, r);
    st[x].covered = st[x<<1].covered && st[(x<<1)|1].covered;
    return ret;
}

inline void insert(int x){
    if(hash[x] != -1){
        hash[x] = -1;
        num[++tot] = x;
    }
}

int main(){
    int t, n, ans;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        ans = tot = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &cl[i], &cr[i]);
            insert(cl[i]);
            insert(cr[i]+1);
        }
        sort(&num[1], &num[tot+1]);
        for(int i = 1; i <= tot; i++)
            hash[num[i]] = i;
        built(1, 1, tot);
        for(int i = n-1; i >= 0; i--)
            if(update(1, hash[cl[i]], hash[cr[i]+1]))
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}

