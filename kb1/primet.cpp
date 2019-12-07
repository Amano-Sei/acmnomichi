/*************************************************************************
    > File Name: primet.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 18时59分13秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

//const int maxn = 1000000050;
const int maxn = 1000050;

vector<long long> allp;

int main(){
    //freopen("primedesu", "w", stdout);
    bool book;
    allp.push_back(2);
    for(long long i = 3; i < maxn; i++){
        book = true;
        for(long long j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i%allp[j] == 0){
                book = false;
                break;
            }
        if(book)
            allp.push_back(i);
    }
    for(int i = 0; i < allp.size(); i++)
        printf("%d\n", allp[i]);
    printf("%d\n", allp.size());
	return 0;
}

