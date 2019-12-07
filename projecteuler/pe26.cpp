/*************************************************************************
    > File Name: pe26.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月03日 星期四 23时09分11秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int book[1000005];

int getcyc(int x){
    memset(book, 0, sizeof(book));
    int cc = 1;
    for(int i = 1; cc; i++){
        if(book[cc])
            return i-book[cc];
        book[cc] = i;
        cc *= 10;
        cc %= x;
    }
    return 0;
}

int main(){
    int ans = 0;
    int maxcyc = 0;
    for(int i = 1; i < 1000; i++)
        if(maxcyc < getcyc(i)){
            ans = i;
            maxcyc = getcyc(i);
        }
    printf("%d %d", ans, maxcyc);
    //for(int i = 1; i < 1000000; i++){
    //    if(i<=getcyc(i))
    //        printf("%d %d\n", i, getcyc(i));
    //    if(i % 100000 == 0)
    //        printf("%d done...\n", i/100000);
    //}
    //前面是傻了，不能余0的，所以自然最多只有n-1个余数
    
    return 0;
}

