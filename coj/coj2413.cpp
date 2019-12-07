/*************************************************************************
    > File Name: coj2413.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年07月14日 星期日 20时13分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int alldesu[5];


int main(){
    for(int i = 0; i < 4; i++){
        scanf("%d", &alldesu[i]);
        alldesu[i]--;
    }

    if((alldesu[0]+1)%4==alldesu[1] && (alldesu[1]+1)%4==alldesu[2] && (alldesu[2]+1)%4==alldesu[3])
        printf("0\n");
    else if((alldesu[1]+1)%4==alldesu[0] && (alldesu[2]+1)%4==alldesu[1] && (alldesu[3]+1)%4==alldesu[2])
        printf("2\n");
    else
        printf("1\n");
    return 0;
}

