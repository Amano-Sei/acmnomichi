/*************************************************************************
    > File Name: h.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 13时54分11秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const long long mod = 998244353;

struct rect{
    long long num[2][2];
    rect(){}
    rect(long long *cnum){
        memcpy(num, cnum, sizeof(num));
    }
}ami[65];

map<long long, long long> allans;

rect mul(const rect &a, const rect &b){
    rect result;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            result.num[i][j] = 0;
            for(int k = 0; k < 2; k++)
                result.num[i][j] = (a.num[i][k]*b.num[k][j]+result.num[i][j])%mod;
        }
    return result;
}

void plu(const rect &a, rect &b){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            b.num[i][j] = (b.num[i][j] + a.num[i][j]) % mod;
}

void init(){
    ami[0].num[0][0] = 3;
    ami[0].num[0][1] = 2;
    ami[0].num[1][0] = 1;
    ami[0].num[1][1] = 0;
    allans[0] = 0;
    allans[1] = 1;
    for(int i = 1; i <= 60; i++)
        ami[i] = mul(ami[i-1], ami[i-1]);
    //for(int i = 0; i < 10; i++)
    //    for(int j = 0; j < 2; j++)
    //        cout << ami[i].num[j][0] << " " << ami[i].num[j][1] << endl;
    //cout << endl;
}

int main(){
    init();
    int q;
    long long n, tn, ans = 0, cans;
    scanf("%d%lld", &q, &n);
    for(int i = 1; i <= q; i++){
        if(allans.count(n)){
            cans = allans[n];
        }else{
            rect getans;
            getans.num[0][0] = getans.num[1][1] = 1;
            getans.num[1][0] = getans.num[1][0] = 0;
            for(int j = 0; tn=((n-1)>>j); j++)
                if(tn&1)
                    getans = mul(ami[j], getans);
            allans[n] = cans = getans.num[0][0];
        }
        n = (cans*cans)^n;
        ans ^= cans;
    }
    printf("%lld\n", ans);
	return 0;
}

