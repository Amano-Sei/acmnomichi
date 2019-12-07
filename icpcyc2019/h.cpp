/*************************************************************************
    > File Name: h.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月31日 星期六 17时02分56秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int gt[maxn];

struct monster{
    long long t, atk;
    monster(){}
    monster(int hp, long long atk):t(gt[hp]),atk(atk){}
} allm[maxn];
long long at[maxn];

void init(){
    int pre = 0, cans = 0;
    gt[1] = 1;
    for(int i = 1; i < maxn; i++){
        pre = cans;
        cans += i;
        for(int j = pre+1; j <= cans && j < maxn; j++)
            gt[j] = i;
        if(cans >= maxn)
            break;
    }
}

bool cmp(const monster &a, const monster &b){
    long long la = a.t*b.atk, ra = b.t*a.atk;
    return la < ra || la==ra && a.t>b.t;
}

int main(){
    init();
    int t, n;
    long long mhp, matk, ans;
    scanf("%d", &t);
    for(int caset = 1; caset <= t; caset++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld", &mhp, &matk);
            allm[i]=monster(mhp, matk);
        }
        sort(allm+1, allm+n+1, cmp);
        for(int i = 1; i <= n; i++)
            at[i] = at[i-1]+allm[i].t;
        ans = 0;
        for(int i = 1; i <= n; i++)
            ans += at[i]*allm[i].atk;
        printf("Case #%d: %lld\n", caset, ans);
    }
	return 0;
}

