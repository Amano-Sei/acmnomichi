/*************************************************************************
    > File Name: 1008.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月23日 星期五 14时37分17秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
long long at[maxn];

int main(){
    int t, l, r;
    int n;
    long long k, ct, mint, mini, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d%lld", &n, &k);
        ans = 0;
        mint = 1e10+1;
        for(int i = 0; i < n; i++)
            scanf("%lld", &at[i]);
        sort(at, &at[n]);
        l = 0;
        r = n-1;
        ans = k;
        while(r>l){
            if(at[r] > k){
                ans += at[r];
                at[r] -= k;
                while(l < r-1 && at[r] > k){
                    at[r] -= k;
                    ans += at[l++];
                }
                if(l < r-1 && k-at[r] < k-at[l])
                    ans += at[l++]+k-at[r];
            }else{
                ans += k;
            }
            r--;
        }
        ans += at[r];
        printf("%lld\n", ans);
    }
	return 0;
}

