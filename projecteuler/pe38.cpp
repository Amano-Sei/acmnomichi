/*************************************************************************
    > File Name: pe38.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月15日 星期二 19时06分51秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool book[10];
int tens[9];
int ans = 0;

void init(){
    tens[0] = 1;
    for(int i = 1; i < 9; i++)
        tens[i] = tens[i-1]*10;
}
void getans(){
    for(int cnum = 9876; cnum > 0; cnum--){
        bool flag = true;
        memset(&book[1], 0, 9*sizeof(bool));
        int tnum = cnum;
        int tcnt = 0, mc;
        int cans = 0;
        for(mc = 1, tnum = cnum; flag; ++mc, tnum=cnum*mc){
            while(tnum){
                if(book[tnum%10]){
                    flag = false;
                    break;
                }
                book[tnum%10] = true;
                tcnt++;
                tnum /= 10;
            }
            cans += cnum*mc*tens[9-tcnt];
            if(tcnt == 9){
                for(int i = 1; i <= mc; i++)
                    printf("%d ", i*cnum);
                putchar('\n');
                ans = max(ans, cans);
                break;
            }
        }
    }
}

int main(){
    init();
    book[0] = true;
    getans();
    printf("%d\n", ans);
    return 0;
}

