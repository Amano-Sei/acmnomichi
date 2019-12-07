/*************************************************************************
    > File Name: binaryindextree.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月27日 星期三 21时19分31秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10005;

int a[maxn];
int n;

int t[maxn];
int mt[maxn];

inline int lowbit(int x){
    return x&(-x);
}

inline void init(){
    for(int i = 1; i <= n; i++){
        t[i] += a[i];
        register int j = i+lowbit(i);
        if(j <= n)
            t[j] += t[i];
    }
}

inline void addmax(int i, int x){
    a[i] = x;
    swap(mt[i], x);
    for(int j = 1; j < lowbit(i); j <<= 1)
        mt[i] = max(mt[i], mt[i-j]);
    if(mt[i] != x)
        for(int j = i+lowbit(i); j <= n; j += lowbit(j)){
            mt[j] = a[j];
            for(int jj = 1; jj < lowbit(j); jj <<= 1)
                mt[j] = max(mt[j], mt[j-jj]);
        }
}

//写这个的目的主要是觉得网上的做法都不优雅，结果发觉优雅的话会错
//行吧（那还是实干比较好

//后续写出了次优雅的做法
//但是这个好像优雅的做法不能接受l为1，否则在r>1的情况下会死循环...

//所以没有优雅的树状数组最大值做法么（（（

//凡是找得到的做法都不愿意把那最后一位减下来（
//我决定去验一下自己写的板子...
int getmax(int l, int r){
    int ans = 0;
    if(l != 1)
        while(l <= r){
            ans = max(a[r--], ans);
            while(r-l+1 >= lowbit(r)){
                ans = max(mt[r], ans);
                r -= lowbit(r);
            }
        }
    else
        while(r){
            ans = max(t[r], ans);
            r -= lowbit(r);
        }
    return ans;
}

