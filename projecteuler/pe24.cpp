/*************************************************************************
    > File Name: pe24.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月01日 星期二 23时21分48秒
 ************************************************************************/

//decantor是本来就知道的拿来复习的，在init中用了一个类似next_permutation来写的，具体内容留待明天在详细修正
//开始因为垃圾室友以及自己脑子确实有点混，写了个常数高达100+的next，然而这是一个类似单调队列的东西，而且不需要head，性能一下子就提上来了

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000005;

int pe[maxn][10];
bool book[maxn];
int fac[10];
int q[10], tail;

void init(){
    fac[0] = 1;
    for(int i = 1; i < 10; i++){
        fac[i] = i*fac[i-1];
        pe[0][i] = i;
    }

    for(int i = 1; i < 1000000; i++){
        memcpy(pe[i], pe[i-1], sizeof(pe[i]));
        tail = 0;
        for(int j = 9; j >= 0; j--){
            if(tail>0 && pe[i][j] < q[tail-1]){
                for(int k = 0; k < tail; k++)
                    if(q[k] > pe[i][j]){
                        swap(q[k], pe[i][j]);
                        break;
                    }
                for(int k = 0; k < tail; k++)
                    pe[i][j+k+1] = q[k];
                break;
            }
            q[tail++] = pe[i][j];
        //memset(book, 0, sizeof(book));
        //int cmax = -1;
        //for(int j = 9; j >= 0; j--){
        //    book[pe[i][j]] = true;
        //    if(pe[i][j] < cmax){
        //        for(int k = 0; k < 10; k++)
        //            if(book[k] && k > pe[i][j]){
        //                pe[i][j] = k;
        //                book[k] = false;
        //                break;
        //            }
        //        for(int jj = j+1; jj < 10; jj++)
        //            for(int k = 0; k < 10; k++)
        //                if(book[k]){
        //                    pe[i][jj] = k;
        //                    book[k] = false;
        //                    break;
        //                }
        //        break;
        //    }
        //    cmax = pe[i][j];
        }
    }
}

int fordec[10];

void decantor(int cx){
    memset(book, 0, sizeof(book));
    for(int i = 0; i < 10; i++){
        int ci = cx/fac[9-i];
        cx %= fac[9-i];
        for(int cii = 0; cii <= ci; cii++)
            if(book[cii])
                ci++;
        fordec[i] = ci;
        book[ci] = true;
    }
}

int main(){
    init();
    decantor(999999);
    for(int i = 0; i < 10; i++)
        printf("%d", fordec[i]);
    putchar('\n');
    for(int i = 0; i < 10; i++)
        printf("%d", pe[999999][i]);

    return 0;
}

