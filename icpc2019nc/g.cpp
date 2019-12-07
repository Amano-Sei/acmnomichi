/*************************************************************************
    > File Name: g.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 13时04分44秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n==1)
            printf("18000\n");
        else
            printf("0\n");
    }
	return 0;
}

