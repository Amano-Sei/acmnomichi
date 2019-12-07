/*************************************************************************
    > File Name: a.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月31日 星期六 13时00分38秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned ans;
int s[5000005];
int top;
map<int, int> ma;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void PUSH(int x, int ti){
    s[top++] = x;
    if(ma.count(x) == 0)
        ma[x] = 1;
    else
        ma[x]++;
    ans ^= ti*(ma.rbegin()->first);
}
void POP(int ti){
    if(top){
        map<int, int>::iterator it = ma.find(s[--top]);
        if(it->second == 1)
            ma.erase(it);
        else
            it->second--;
        if(!ma.empty())
            ans ^= ti*(ma.rbegin()->first);
    }
}

void gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for(int i = 1; i <= n; i++){
        if(rng61() % (p+q) < p)
            PUSH(rng61() % m + 1, i);
        else
            POP(i);
    }
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int i = 1; i <= tt; i++){
        ans = 0;
        top = 0;
        ma = map<int, int>();
        gen();
        printf("Case #%d: %d\n", i, ans);
    }
	return 0;
}

