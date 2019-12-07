/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月08日 星期五 20时29分19秒
 ************************************************************************/

//自闭了（不会写.jpg

//↑自闭了还浪费时间？你是不是需要一个打击？？？
//（我错了（（（

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2005;
const int mod = 20050321;

int pow2[maxn];

inline void init(int m){
    pow2[0] = 1;
    for(int i = 1; i < m; i++)
        pow2[i] = (pow2[i-1]<<1)%mod;
}

int w[maxn];

int main(){
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    init(m);
    w[n] = 1;
    int cans = 1;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &l, &r);
        cans = (cans<<1)%mod;
        for(int j = 1; j < l-1; j++)
            w[j] = (w[j]<<1)%mod;
        if(l-1 > 0){
            cans = (cans-w[l-1]+pow2[i]+mod)%mod;
            w[l-1] = (w[l-1]+pow2[i])%mod;
        }
        for(int j = l; j < r; j++)
            cans = (cans-w[j]+mod)%mod;
        cans = (cans-w[r]+pow2[i]+mod)%mod;
        w[r] = (w[r]+pow2[i])%mod;
        for(int j = r+1; j <= n; j++)
            w[j] = (w[j]<<1)%mod;
        printf("%d\n", cans);
    }
    return 0;
}

