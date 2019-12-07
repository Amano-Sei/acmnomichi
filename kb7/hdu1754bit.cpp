/*************************************************************************
    > File Name: hdu1754bit.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 21时19分31秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int a[maxn];
int n;

int mt[maxn];

inline int lowbit(int x){
    return x&(-x);
}

inline void addmax(int i, int x){
    a[i] = x;
    swap(mt[i], x);
    for(int j = 1; j < lowbit(i); j <<= 1)
        mt[i] = max(mt[i], mt[i-j]);
    if(mt[i] != x)
        for(int j = i+lowbit(i); j <= n; j += lowbit(j)){
            mt[j] = a[j];
            for(int jj = 1; jj < lowbit(j); jj <<= 1)
                mt[j] = max(mt[j], mt[j-jj]);
        }
}

int getmax(int l, int r){
    int ans = 0;
    if(l != 1)
        while(l <= r){
            ans = max(a[r--], ans);
            while(r-l+1 >= lowbit(r)){
                ans = max(mt[r], ans);
                r -= lowbit(r);
            }
        }
    else
        while(r){
            ans = max(mt[r], ans);
            r -= lowbit(r);
        }
    return ans;
}

int main(){
    int m, ca, cb;
    char cc[4];
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &ca);
            addmax(i, ca);
        }
        while(m--){
            scanf("%s%d%d", cc, &ca, &cb);
            if(cc[0] == 'Q')
                printf("%d\n", getmax(ca, cb));
            else
                addmax(ca, cb);
        }
    }
    return 0;
}

