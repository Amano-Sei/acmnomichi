/*************************************************************************
    > File Name: ieeedouble.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月04日 星期一 19时42分14秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

int bits[3000][4000];

void init(){
    bits[1][0] = 1;
    bits[1][1] = 5;
    for(int i = 2; i < 3000; i++){
        int prelen = bits[i-1][0];
        int cc = 0;
        for(int j = 1; j <= prelen; j++){
            cc = cc+bits[i-1][j];
            bits[i][j] = cc/2;
            cc = cc%2*10;
        }
        while(cc){
            bits[i][++prelen] = cc/2;
            cc = cc%2*10;
        }
        bits[i][0] = prelen;
        //printf("%d 0.", i);
        //for(int j = 1; j <= prelen; j++)
        //    printf("%d", bits[i][j]);
        //putchar('\n');
        //getchar();
    }
}

int ans[4000];

int main(){
    init();
    unsigned long long cx = 0x3b6c00003b6d;
    //unsigned long long cx = 1;

    int tlen = bits[1074][0];
    for(int i = 0; i < 48; i++)
        if((cx >> i) & 1){
            int cc = 0;
            for(int j = tlen; j >= 1; j--){
                cc += ans[j]+bits[1074-i][j];
                ans[j] = cc%10;
                cc /= 10;
            }
        }

    printf("0.");
    for(int i = 1; i <= tlen; i++)
        printf("%d", ans[i]);

    return 0;
}

