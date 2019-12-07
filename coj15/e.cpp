/*************************************************************************
    > File Name: e.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月23日 星期六 20时57分08秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 2e5+5;

struct node{
    vector<int> sk;
    int l, r;
}st[maxn<<2];

void built(int l, int r, int x){
    st[x].l = l;
    st[x].r = r;
    if(l == r)
        return;
    int m = (l+r)>>1;
    built(l, m, x<<1);
    built(m+1, r, (x<<1)|1);
}

void neopush(vector<int> &tv, int v){
    if(v < 0 && !tv.empty() && *tv.rbegin() > 0)
        tv.pop_back();
    else
        tv.push_back(v);
}

void down(int x){
    for(int i = 0; i < st[x].sk.size(); i++){
        neopush(st[x<<1].sk, st[x].sk[i]);
        neopush(st[(x<<1)|1].sk, st[x].sk[i]);
    }
    st[x].sk.clear();
}

void push(int l, int r, int x, int v){
    if(st[x].l >= l && st[x].r <= r){
        st[x].sk.push_back(v);
        return;
    }
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(m >= l)
        push(l, m, x<<1, v);
    if(m < r)
        push(m+1, r, (x<<1)|1, v);
}

void pop(int l, int r, int x){
    if(st[x].l >= l && st[x].r <= r){
        neopush(st[x].sk, -1);
        return;
    }
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(m >= l)
        pop(l, m, x<<1);
    if(m < r)
        pop(m+1, r, (x<<1)|1);
}

int find(int x, int id, int pos){
    if(st[x].l == st[x].r){
        return st[x].sk[st[x].sk.size()-pos];
    }
    down(x);
    int m = (st[x].l+st[x].r)>>1;
    if(id <= m)
        return find(x<<1, id, pos);
    else
        return find((x<<1)|1, id, pos);
}
    

int main(){
    int n, q;
    char s[8];
    int cl, cr, cp;
    scanf("%d%d", &n, &q);
    built(1, n, 1);
    while(q--){
        scanf("%s", s);
        if(s[1] == 'u'){
            scanf("%d%d%d", &cl, &cr, &cp);
            push(cl, cr, 1, cp);
        }else{
            scanf("%d%d", &cl, &cr);
            if(s[0] == 'p')
                pop(cl, cr, 1);
            else
                printf("%d\n", find(1, cl, cr));
        }
    }
    return 0;
}

