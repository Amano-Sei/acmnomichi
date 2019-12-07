/*************************************************************************
    > File Name: coj2416ct.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月14日 星期日 20时37分11秒
 ************************************************************************/

#include <iostream>
using namespace std;

int alldesu[20];
bool book[20];
long long ans;
int n;
void dfs(int ci){
    if(ci > n){
        for(int i = 1; i < n; i++)
            for(int j = i+1; j <= n; j++)
                if(alldesu[i] > alldesu[j])
                    ans += (j-i)*(alldesu[i]-alldesu[j]);
        return;
    }
    for(int i = 1; i <= n; i++)
        if(!book[i]){
            book[i] = true;
            alldesu[ci] = i;
            dfs(ci+1);
            book[i] = false;
        }
}

int main(){
    for(n = 1; n <= 16; n++){
        ans = 0;
        dfs(1);
        printf("%d\t%lld\n", n, ans);
    }
    return 0;
}


