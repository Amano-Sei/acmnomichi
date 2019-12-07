/*************************************************************************
    > File Name: 2697.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月28日 星期日 15时59分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int desu[5][5];
int cur[5];
bool book[5];
int cmax, cans, ccmax, maxi;
int rmax;

void myswap(int i){
    for(int j = 0; j < 5; j++)
        swap(desu[i][j], cur[j]);
}

void getcmax(int c){
    if(c == 5){
//        printf("%d\n", cans);
        cmax = max(cmax, cans);
        return;
    }
    for(int i = 0; i < 5; i++)
        if(!book[i]){
            book[i] = true;
            cans += desu[c][i];
            getcmax(c+1);
            cans -= desu[c][i];
            book[i] = false;
        }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 5; i++)
        for(int j = 0 ; j < 5; j++)
            scanf("%d", &desu[i][j]);
    getcmax(0);
    rmax = cmax;
    for(int i = 5; i < n; i++){
        ccmax = cmax = 0;
        for(int j = 0; j < 5; j++)
            scanf("%d", &cur[j]);
        for(int j = 0; j < 5; j++){
            memset(book, 0, sizeof(book));
            myswap(j);
            getcmax(0);
            if(cmax>ccmax){
                ccmax = cmax;
                maxi = j;
            }
            myswap(j);
        }
        if(ccmax > rmax){
            rmax = ccmax;
            myswap(maxi);
        }
    }
    printf("%d\n", rmax);
    return 0;
}
