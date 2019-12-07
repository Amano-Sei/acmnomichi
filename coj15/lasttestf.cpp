/*************************************************************************
    > File Name: lastf.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 16时53分06秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200005;

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

int getorians(int &minans, int &maxans){
    int l, r;
    maxans = n;
    for(int i = 1; i <= n; i++)
        if(a[i] < a[i-1] && maxans >= i)
            maxans = i-1;
    l = 0;
    r = maxans;
    while(l <= r){
        int m = ((l+r)>>1);
        if(check(m))
            r = m-1;
        else
            l = m+1;
    }
    if(l > maxans)
        minans = maxans = -1;
    else
        minans = l;
}


void getneoans(int &minans, int &maxans){
    minans = maxans = n;
    for(int i = 1; i <= n; i++)
        if(maxans >= i && a[i] < a[i-1])
            maxans = i-1;
    for(int cc = n, cmax = n; minans > 0; minans--)
        if(a[minans] == cc)
            cc--;
        else if(a[minans] > cmax)
            break;
        else
            cmax = a[minans];
    if(minans > maxans)
        minans = maxans = -1;
}

int main(){
    int neominans, neomaxans;
    int oriminans, orimaxans;
    n = 10;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    do{
        getorians(oriminans, orimaxans);
        getneoans(neominans, neomaxans);
        if(oriminans != neominans || orimaxans != neomaxans){
            for(int i = 1; i <= n; i++)
                printf("%5d", a[i]);
            putchar('\n');
            printf("%d %d %d %d\n", oriminans, orimaxans, neominans, neomaxans);
        }
    }while(next_permutation(&a[1], &a[n+1]));
    printf("done\n");
    return 0;
}

