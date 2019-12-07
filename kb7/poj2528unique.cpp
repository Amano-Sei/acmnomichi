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

//用折半查找进行映射会比直接用数组要快...有点意外，或许是因为缓存吧
//另一方面，map频繁clear会t...这个算是意料中吧（

struct node{
    bool covered;
    int l, r;
}st[maxn<<3];

int cl[maxn], cr[maxn];
int num[maxn<<1], tot;
//map<int, int> num2i;

void built(int x, int l, int r){
    st[x] = { false, l, r };
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

inline int num2i(int x){
    int l = 1, r = tot;
    while(l < r){
        register int m = (l+r)>>1;
        if(num[m] < x)
            l = m+1;
        else if(num[m] > x)
            r = m-1;
        else
            return m;
    }
    return l;
}

int main(){
    int t, n, ans;
    scanf("%d", &t);
    while(t--){
        ans = tot = 0;
        //num2i.clear();
        //加上clear会t...
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &cl[i], &cr[i]);
            num[++tot] = cl[i];
            num[++tot] = cr[i]+1;
        }
        sort(&num[1], &num[tot+1]);
        tot = unique(&num[1], &num[tot+1])-&num[1];
        //for(int i = 0; i < tot; i++)
        //    num2i[num[i]] = i+1;
        built(1, 1, tot);
        for(int i = n-1; i >= 0; i--)
            //if(update(1, num2i[cl[i]], num2i[cr[i]+1]))
            if(update(1, num2i(cl[i]), num2i(cr[i]+1)))
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}

