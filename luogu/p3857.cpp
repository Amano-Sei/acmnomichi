/*************************************************************************
    > File Name: p3857.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月25日 星期一 22时01分45秒
 ************************************************************************/

#include <cstdio>

const int mod = 2008;

char s[55];
long long d[50];
int tot;

int spow(int x, int n){
    int ans = 1;
    while(n){
        if(n&1)
            ans = ans*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return ans;
}

void insert(long long x){
    for(int i = 49; i >= 0; i--)
        if(x & (1ll<<i)){
            if(d[i])
                x ^= d[i];
            else{
                d[i] = x;
                tot++;
                return;
            }
        }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%s", s);
        register long long tmp = 0;
        for(int i = 0; i < n; i++){
            tmp <<= 1;
            if(s[i] == 'O')
                tmp |= 1;
        }
        insert(tmp);
    }
    printf("%d\n", spow(2, tot));
}

