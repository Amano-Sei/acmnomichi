/*************************************************************************
    > File Name: pe21.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月28日 星期六 22时53分49秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int d[1000001];
int maxx;

int getd(int x){
    maxx = max(x, maxx);
    if(d[x] == 0)
        for(int i = 1; i < x; i++)
            if(x%i == 0)
                d[x] += i;
    return d[x];
}

int main(){
    int ans = 0;
    for(int i = 1; i < 10000; i++)
        if(getd(getd(i)) == i && i != getd(i))
            ans += i;
    printf("%d\n", ans);

    return 0;
}

