/*************************************************************************
    > File Name: pe49.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月26日 星期六 21时07分25秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10000;

//这道题代码写的巨烂，但是不递归的话好像也没有什么优雅的做法了
//其实就是有几块应该用递归写的代码我给迭代开了
//也不知道该说是变优雅了还是变丑了（

//我现在异常庆幸自己一开始不想用next_permutation写，其实最开始的时候没意识到这个digit是可以相同的
//所以一开始就是朝着不同那样写的，但是发现只有那一组答案，所以加上可以相同
//但是这个时候我忘记了很重要的事情，cantor数是在所有元素都不同的情况下的序数
//然后还一度怀疑自己decantor写错了（

//所以这里会再次实现自己的next_permutation
//emmm事实证明还是不能急躁，本来想懒省事不写的，但是再次写这个让我复习了单调栈和一些细节的调试

bool isp[maxn];
int allp[maxn], tot;
int fac[4];

void init(){
    fac[0] = fac[1] = 1;
    fac[2] = 2;
    fac[3] = 6;
    for(int i = 2; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < tot && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            isp[i] = true;
            allp[tot++] = i;
        }
    }
}

int cnum[4];
int allcnum[24], allcnt;
bool book[4];

int stk[4];

bool my_next_permutation(){
    int stot = 0;
    int ci = 2;
    stk[0] = cnum[3];
    while(ci >= 0 && stk[stot] <= cnum[ci])
        stk[++stot] = cnum[ci--];
    if(ci != -1){
        for(int i = 0; i <= stot; i++)
            if(stk[i] > cnum[ci])
                swap(stk[i], cnum[ci++]);
        for(int i = 0; i <= stot; i++, ci++)
            cnum[ci] = stk[i];
        return true;
    }
    memcpy(cnum, stk, sizeof(stk));
    return false;
}

void decode(int ci){
    memset(book, 0, sizeof(book));
    int cx = ci;
    int tnum = 0;
    for(int i = 0; i < 4; i++){
        int cc = cx/fac[3-i];
        for(int j = 0; j <= cc; j++)
            if(book[j])
                cc++;
        book[cc] = true;
        tnum = tnum*10+cnum[cc];
        cx %= fac[3-i];
    }
    allcnum[ci] = tnum;
}

void cleanallc(){
    allcnt = 0;
    int pre = -1;
    for(int i = 0; i < 24; i++)
            printf("%d\n", allcnum[i]);
}

void findans(){
    for(int i = 1; i < 10; i++){
        cnum[0] = i;
        for(int j = i; j < 10; j++){
            cnum[1] = j;
            for(int k = j; k < 10; k++){
                cnum[2] = k;
                for(int kk = k; kk < 10; kk++){
                    cnum[3] = kk;
                    //for(int ii = 0; ii < 24; ii++)
                    //    decode(ii);
                    //cleanallc();
                    allcnt = 0;
                    do{
                        allcnum[allcnt++] = cnum[0]*1000+cnum[1]*100+cnum[2]*10+cnum[3];
                    }while(my_next_permutation());
                    for(int iii = 0; iii < allcnt; iii++)
                        if(isp[allcnum[iii]])
                            for(int jjj = iii+1; jjj < allcnt; jjj++)
                                if(isp[allcnum[jjj]])
                                    for(int kkk = jjj+1; kkk < allcnt; kkk++)
                                        if(isp[allcnum[kkk]] && (allcnum[kkk]-allcnum[jjj]) == (allcnum[jjj]-allcnum[iii]))
                                                printf("%d %d %d\n", allcnum[iii], allcnum[jjj], allcnum[kkk]);
                                        
                }
            }
        }
    }
}

int main(){
    init();
    findans();
    return 0;
}

