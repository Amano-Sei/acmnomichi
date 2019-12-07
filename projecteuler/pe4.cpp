/*************************************************************************
    > File Name: pe4.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月16日 星期一 23时16分07秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int bits[8];

bool ispali(int cnum){
    int len = 0;
    while(cnum){
        bits[len++] = cnum%10;
        cnum /= 10;
    }
    for(int i = 0; i<len/2; i++)
        if(bits[i] != bits[len-1-i])
            return false;
    return true;
}

int main(){
    int cans = 0;
    for(int i = 100; i <= 999; i++)
        for(int j = i; j <= 999; j++)
            if(ispali(i*j) && i*j > cans)
                cans = i*j;
    printf("%d\n", cans);
	return 0;
}

