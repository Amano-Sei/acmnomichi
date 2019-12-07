/*************************************************************************
    > File Name: onf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期日 11时11分11秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

//dreamoon版O(n)，可以看到~在知道结论后~还是很好得出的

const int maxn = 2e5+5;

int a[maxn], n;
int book[maxn], tt;
int b[maxn];

inline void solve(int &minans, int &maxans){
    tt++;
    for(int i = 1; i <= maxans; i++)
        book[a[i]] = tt;
    int bid = 0;
    for(int i = 1; i <= n; i++)
        if(book[i] != tt)
            b[bid++] = i;
    bid = 0;
    int cmin = a[maxans], cc = -1;
    for(int i = maxans+1; i <= n; i++)
        if(b[bid] == a[i])
            bid++;
        else if(cmin < a[i]){
            cmin = a[i];
            if(cc == -1)
                cc = cmin;
        }else{
            minans = maxans = -1;
            return;
        }
    if(maxans == n){
        minans = 0;
        return;
    }
    minans = maxans;
    register int bb = b[0];
    while(minans > 0){
        if(a[minans] == a[minans-1]+1 && a[minans] < bb)
            bb = a[minans--];
        else if(cc == -1 || cc == a[minans]+1)
            cc = a[minans--];
        else
            return;
    }
}

int main(){
    int t;
    int minans, maxans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        maxans = n;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] < a[i-1] && maxans >= i)
                maxans = i-1;
        }
        solve(minans, maxans);
        printf("%d %d\n", minans, maxans);
    }
    return 0;
}

