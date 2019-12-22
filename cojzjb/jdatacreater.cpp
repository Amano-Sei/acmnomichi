/*************************************************************************
    > File Name: jdatacreater.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年12月08日 星期日 20时41分12秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int mod = 1e9+1;
int main(){
    freopen("indesu", "w", stdout);
    for(int i = 0; i < 10000; i++){
        register int n = random()%15+1, q = random()%15+1;
        if(n > q)
            swap(n, q);
        printf("%d %d\n", n, q);
        for(int j = 0; j < n; j++){
            register int l = random()%mod;
            register int r = random()%mod;
            if(l < r)
                swap(l, r);
            if(l == r)
                l++;
            printf("%d %d ", l, r);
            printf("%d %d\n", random()%mod, random()%mod);
        }
            putchar('\n');
    }
    return 0;
}

