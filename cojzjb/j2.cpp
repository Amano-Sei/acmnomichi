/*************************************************************************
    > File Name: j2.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 20时32分17秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

int n, q;
long long a[16], b[16], c[16];

bool done(int x){
    register int ans = 0;
    for(int i = 0; i < q; i++)
        if((1<<i)&x)
            ans++;
    return ans == n;
}

void printanscost(int x){
    int cnt = 0;
    register long long cost = 0, ca = 0;
    for(int i = 0; i < q; i++){
        if(x&(1<<i)){
            cnt++;
            cost += max(a[cnt]-ca, b[cnt]);
        }
        ca += c[cnt];
        printf("%d %lld %lld\n", i+1, cost, ca);
    }
}
long long getcost(int x){
    int cnt = 0;
    register long long cost = 0, ca = 0;
    for(int i = 0; i < q; i++){
        if(x&(1<<i)){
            cnt++;
            cost += max(a[cnt]-ca, b[cnt]);
        }
        ca += c[cnt];
    }
    return cost;
}

int main(){
    while(scanf("%d%d", &n, &q) != EOF){
        int ansi = 0;
        register long long ta, ans = 0x3f3f3f3f3f3f3f3fll;
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &ta);
            c[i] += ta;
            c[i] = max(c[i], c[i-1]);
        }
        for(int i = 0; i < (1<<q); i++)
            if(done(i)){
                if(ans > getcost(i))
                    ansi = i;
                ans = min(ans, getcost(i));
            }
        printanscost(ansi);
        printf("%x\n", ansi);
        printf("why....\n");
        printanscost(0x1ffd);
        printf("%lld\n", ans);
    }
    return 0;
}

