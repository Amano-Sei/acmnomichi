/*************************************************************************
    > File Name: pe7.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 13时56分59秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<long> allp;

int main(){
    allp.push_back(2);
    for(long i = 3; ; i++){
        bool flag = true;
        for(int j = 0; allp[j]*allp[j] <= i; j++)
            if(i%allp[j] == 0){
                flag = false;
                break;
            }
        if(flag)
            allp.push_back(i);
        if(allp.size() >= 10001)
            break;
    }
    printf("%lld\n", allp[10000]);            
	return 0;
}

