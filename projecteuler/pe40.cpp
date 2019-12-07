/*************************************************************************
    > File Name: pe40.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月17日 星期四 22时54分27秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int nums[1000005];
int tbits[6];
int cnt;

void init(){
    int cnum = 1;
    while(cnt < 1000000){
        int tnum = cnum;
        int cb = 0;
        while(tnum){
            tbits[cb++] = tnum%10;
            tnum /= 10;
        }
        for(int i = cb-1; i >= 0; i--)
            nums[++cnt] = tbits[i];
        cnum++;
    }
    printf("%d\n", cnt);
    printf("%d\n", cnum);
}


int main(){
    init();
    int ans = 1, ci = 1;
    for(int i = 0; i < 7; i++){
        ans *= nums[ci];
        printf("%d ", nums[ci]);
        ci *= 10;
    }
    printf("%d\n", ans);
    return 0;
}

