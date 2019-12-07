/*************************************************************************
    > File Name: pe23.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月01日 星期二 00时17分36秒
 ************************************************************************/

#include <cstdio>

using namespace std;

const int maxn = 28123;

bool checkab(int x){
    int ans = 0;
    for(int i = 1; i < x; i++)
        if(x%i == 0)
            ans += i;
    return ans > x;
}

bool isab[maxn];

int main(){
    for(int i = 1; i < maxn; i++)
        isab[i] = checkab(i);
    int ans = 0;
    for(int i = 1; i < maxn; i++){
        bool flag = true;
        for(int j = 1; 2*j <= i; j++)
            if(isab[j] && isab[i-j]){
                flag = false;
                break;
            }
        if(flag)
            ans += i;
    }
    printf("%d\n", ans);

    return 0;
}

