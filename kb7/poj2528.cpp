/*************************************************************************
    > File Name: poj2528.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 10时21分55秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//我一开始的离散化方法是错误的...
//因为这里是长度，应该是区间，如果最终缩为一个点树就有可能出现只要覆盖区间内部所有的离散点就错误地以为被完全覆盖了...
//所以需要离散化的地方的线段树必须使用真正的区间线段树

//可以看到bin神的代码都是有问题的...
//和我一开始一样的错误...
//不过bin神的做法非常有意思
//是离线的做法，虽然我离散化的时候也离线了，但是和在线是一样的思想，所以来敲一遍bin神做法

const int maxn = 10005;

struct node{
    int val, l, r;
}st[maxn<<3];

vector<int> num;
map<int, int> num2i;

bool book[maxn];
int cnt;
int cl[maxn], cr[maxn];

inline void init(){
    memset(book, 0, sizeof(book));
    cnt = 0;
    num.clear();
    num2i.clear();
}

void built(int x, int l, int r){
    st[x].l = l;
    st[x].r = r;
    st[x].val = -1;
    if(l+1 == r)
        return;
    int m = (l+r)>>1;
    built(x<<1, l, m);
    built((x<<1)|1, m, r);
}

inline void push_down(int x){
    if(st[x].val > 0)
        st[x<<1].val = st[(x<<1)|1].val = st[x].val;
}

void update(int x, int l, int r, int val){
    if(l <= st[x].l && st[x].r <= r){
        st[x].val = val;
        return;
    }
    push_down(x);
    st[x].val = 0;
    int m = (st[x].l+st[x].r)>>1;
    if(r <= m)
        update(x<<1, l, r, val);
    else if(l >= m)
        update((x<<1)|1, l, r, val);
    else
        update(x<<1, l, m, val), update((x<<1)|1, m, r, val);
}

void lastcheck(int x){
    if(st[x].val){
        if(st[x].val > 0 && !book[st[x].val]){
            book[st[x].val] = true;
            cnt++;
        }
        return;
    }
    lastcheck(x<<1);
    lastcheck((x<<1)|1);
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &cl[i], &cr[i]);
            num.push_back(cl[i]);
            num.push_back(cr[i]+1);
        }
        sort(num.begin(), num.end());
        num.resize(distance(num.begin(), unique(num.begin(), num.end())));
        for(int i = 0; i < num.size(); i++)
            num2i[num[i]] = i+1;
        built(1, 1, num.size());
        for(int i = 1; i <= n; i++)
            update(1, num2i[cl[i]], num2i[cr[i]+1], i);
        lastcheck(1);
        printf("%d\n", cnt);
    }

    return 0;
}

