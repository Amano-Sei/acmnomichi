/*************************************************************************
    > File Name: pe52.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月30日 星期三 09时25分40秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//啊啊啊，忘记了1/7了...明明应该一眼就看出来答案的...
//总是觉得要借助编程束缚了我么（（（

long long tens[10];

void init(){
    long long t = 1;
    for(int i = 0; i < 10; i++){
        tens[i] = t;
        t *= 10;
    }
}

int getbithash(int cnum){
    long long ans = 0;
    while(cnum){
        ans += tens[cnum%10];
        cnum /= 10;
    }
    return ans;
}

void findans(){
    for(int i = 1; ; i++){
        bool flag = true;
        long long chash = getbithash(i);
        for(int j = 2; j < 7; j++)
            if(chash != getbithash(j*i)){
                flag = false;
                break;
            }
        if(flag){
            printf("%d\n", i);
            return;
        }
    }
}

int main(){
    init();
    findans();

    return 0;
}

