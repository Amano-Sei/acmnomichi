/*************************************************************************
    > File Name: pe14.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月23日 星期一 22时11分04秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

map<long long, long long> len;

long long maxlen;
long long maxx;

long long getlen(long long x){
    //printf("%lld\n", x);
    maxx = max(x, maxx);
    if(x<0)
        printf("%lld\n", x);
    if(len.count(x))
        return len[x];
    return len[x] = 1+getlen((x%2)?(3*x+1):(x/2));
}

int main(){
    int ans = 0;
    len[1] = 1;
    for(int i = 1; i <= 1000000; i++){
        if(maxlen <getlen(i)){
            maxlen = getlen(i);
            ans = i;
        }
    }
    printf("%d\n", maxlen);
    printf("%lld\n", maxx);
    printf("%lld\n", len.size());
    printf("%d\n", ans);
    return 0;
}

