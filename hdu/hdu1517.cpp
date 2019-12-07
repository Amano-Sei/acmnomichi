/*************************************************************************
    > File Name: hdu1517.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月12日 星期一 04时10分24秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    long long n, tmp;
    while(scanf("%lld", &n) != EOF){
        tmp = 1;
        while(tmp*18 < n)
            tmp *= 18;
        printf("%s wins.\n", tmp*9<n?"Ollie":"Stan");
    }
	return 0;
}

