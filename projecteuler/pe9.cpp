/*************************************************************************
    > File Name: pe9.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 14时16分02秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findans(){
    for(int i = 1; i <= 333; i++)
        for(int j = i; j <= 500; j++)
            if(1000000+2*i*j == 2000*i+2000*j){
                printf("%d %d %d\n", i, j, 1000-i-j);
                return i*j*(1000-i-j);
            }
}

int main(){
    printf("%d\n", findans());
	return 0;
}

