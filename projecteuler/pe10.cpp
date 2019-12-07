/*************************************************************************
    > File Name: pe10.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月18日 星期三 14时25分28秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 2000000;

vector<int> allp;

int main(){
    allp.push_back(2);
    long long ans = 2;
    for(int i = 3; i <= maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            allp.push_back(i);
            ans += i;
        }
    }
    printf("%lld\n", ans);
	return 0;
}

