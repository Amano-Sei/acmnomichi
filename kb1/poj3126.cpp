/*************************************************************************
    > File Name: primet.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月06日 星期二 18时59分13秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10005;

typedef struct Node{
    int c, sp;
    Node(){}
    Node(int c, int sp) : c(c), sp(sp){}
}node;

vector<int> allp;
queue<node> q;
bool isp[maxn], book[maxn];

void addp(int i){
    isp[i] = true;
    allp.push_back(i);
}

int main(){
    bool bookp;
    addp(2);
    for(int i = 3; i < maxn; i++){
        bookp = true;
        for(int j = 0; j < allp.size(); j++)
            if(i%allp[j] == 0){
                bookp = false;
                break;
            }
        if(bookp)
            addp(i);
    }
    allp.clear();
    
    int t, st, ep;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &st, &ep);
        if(st == ep){
            printf("0\n");
            continue;
        }
        memset(book, 0, sizeof(book));
        while(!q.empty())
            q.pop();
        q.push(node(st, 0));
        book[st] = true;
        bookp = false;
        node cur;
        int neonum;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            int cnum[4] = {cur.c/1000, cur.c/100%10, cur.c/10%10, cur.c%10};
            for(int i = 0; i < 4; i++){
                for(int j = i==0?1:0; j < 10; j++){
                    neonum = 0;
                    for(int k = 0; k < 4; k++)
                        neonum = neonum*10 + (i==k?j:cnum[k]);
                    if(neonum == ep){
                        printf("%d\n", cur.sp+1);
                        bookp = true;
                        break;
                    }
                    if(!book[neonum] && isp[neonum]){
                        book[neonum] = true;
                        q.push(node(neonum, cur.sp+1));
                    }
                }
                if(bookp)
                    break;
            }
            if(bookp)
                break;
        }
    }
	return 0;
}

