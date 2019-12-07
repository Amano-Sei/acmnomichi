/*************************************************************************
    > File Name: tswitch.c
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月03日 星期二 22时45分32秒
 ************************************************************************/

#include<stdio.h>

void tswitch(int x, int y, int *d){
    while(y > 0){
        switch(x){
            case 1:
                *d = 10;
                return;
        }
    }
    return;
}

