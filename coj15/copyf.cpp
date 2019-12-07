/*************************************************************************
    > File Name: copyf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月24日 星期日 22时16分40秒
 ************************************************************************/

#include <cstdio>

const int maxn = 2e5+5;

int n, a[maxn], ma, mb, mc, ha[maxn];

void solve(){
    int i, minans = -1, maxans = -1, cmin;
    for(i = 1; i <= n; i++){
        register int tmp;
        scanf("%d", &tmp);
        a[tmp] = i;
    }
    for(ma = 0; ma < n && a[ma+1] == ma+1; ma++);
    for(mc = n; mc > 1 && a[mc-1] < a[mc]; mc--);
    for(maxans = ma, cmin = 0, mb = ma+1; mb <= n; ha[++mb] = maxans){
        if(a[mb] == maxans+1)
            maxans++;
        else if(a[mb] < cmin)
            break;
        else
            cmin = a[mb];
    }
    if(mb > n)
        mb--;
    if(mc <= ma)
        minans = 0;
    else if(mb >= mc)
        minans = (ha[mb-1]==ma)?0:ha[mb-1];
    else
        minans = maxans = -1;
    printf("%d %d\n", minans, maxans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        solve();
    }
}

