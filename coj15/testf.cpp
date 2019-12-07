/*************************************************************************
    > File Name: testf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月24日 星期日 11时37分30秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 2e5+5;

int a[maxn], n;
int book[maxn], tt;
int b[maxn];

bool check(int cnt){
    tt++;
    for(int i = 1; i <= cnt; i++)
        book[a[i]] = tt;
    int bid = 0;
    b[0] = 0;
    for(int i = 1; i <= n; i++)
        if(book[i] != tt)
            b[bid++] = i;
    bid = 0;
    int cmin = a[cnt];
    for(int i = cnt+1; i <= n; i++)
        if(b[bid] == a[i])
            bid++;
        else if(cmin < a[i])
            cmin = a[i];
        else
            return false;
    return true;
}

int main(){
    int t;
    int minans, maxans;
    int l, r;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        maxans = n;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] < a[i-1] && maxans >= i)
                maxans = i-1;
        }
        if(!check(maxans))
            puts("-1 -1");
        else if(!check(maxans-1))
            printf("%d %d\n", maxans, maxans);
        else{
            for(minans = 0; a[minans+1] == minans+1; minans++);
            printf("0 %d\n", maxans);
        }
    }
    return 0;
}

