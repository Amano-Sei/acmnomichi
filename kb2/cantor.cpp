/*************************************************************************
    > File Name: cantor.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月08日 星期四 19时01分55秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;
bool book[maxn];

int cantor(int *num, int n){
    int ans = 0, fr = 1, cf = 1;
    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        for(int j = i+1; j < n; j++)
            if(num[i] > num[j])
                cnt++;
        ans += cnt*fr;
        fr *= cf++;
    }
    return ans;
}

void decantor(int *num, int n, int cnnum){
    memset(book, 0, sizeof(book));
    int fr = 1;
    for(int i = 2; i <= n; i++)
        fr*=i;
    for(int i = 0; i < n; i++){
        num[i] = cnnum/(fr /= (n-i))+1;
        cnnum %= fr;
        for(int j = 1; j <= num[i]; j++)
            if(book[j])
                num[i]++;
        book[num[i]] = true;
    }
}

int main(){
	return 0;
}

