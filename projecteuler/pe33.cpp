/*************************************************************************
    > File Name: pe33.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月10日 星期四 19时03分49秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    for(int i = 1; i < 10; i++)
        for(int j = i+1; j < 10; j++){
            for(int k = 1; k < 10; k++){
                if(i == k || j == k)
                    continue;
                if(i*(j*10+k) == (i*10+k)*j)
                    printf("%d/%d with %d\n", i*10+k, j*10+k, k);
                if(i*(j*10+k) == (k*10+i)*j)
                    printf("%d/%d with %d\n", k*10+i, j*10+k, k);
                if(i*(k*10+j) == (i*10+k)*j)
                    printf("%d/%d with %d\n", i*10+k, k*10+j, k);
                if(i*(k*10+j) == (k*10+i)*j)
                    printf("%d/%d with %d\n", k*10+i, k*10+j, k);
            }
        }
}

