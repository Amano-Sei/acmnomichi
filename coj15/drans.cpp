/*************************************************************************
    > File Name: drans.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月24日 星期日 18时32分15秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

const int maxn = 505;

//dalao就是不一样QAQ
//有O(n)的排序 QAQ
//有避免memset的tt QAQ

//不过a和c可以一起检查，这是dalao所没有注意到的

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
    int cmin = 0;
    for(int i = 1; i <= n; i++)
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
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        minans = maxans = -1;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i <= n; i++)
            if(check(i)){
                if(minans == -1)
                    minans = i;
                maxans = i;
            }
        printf("%d %d\n", minans, maxans);
    }
    return 0;
}

