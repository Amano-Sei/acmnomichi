/*************************************************************************
    > File Name: pe1.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月14日 星期六 22时07分47秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int ans = 0;
    for(int i = 1; i < 1000; i++)
        if(i % 3 == 0 || i % 5 == 0)
            ans += i;
    printf("%d\n", ans);
	return 0;
}

