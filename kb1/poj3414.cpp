/*************************************************************************
    > File Name: poj3414.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年08月07日 星期三 13时35分21秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10201;

char op[3][5] = {"FILL", "DROP", "POUR"};

typedef struct Node{
    int opt;
    int opa;
    int fa;
    int cc;
    Node(){}
    Node(int opt, int opa, int fa, int cc):opt(opt),opa(opa),fa(fa),cc(cc){}
}node;

int book[maxn];
node queue[maxn];
int ps[maxn], top;
int head, tail;
int a, b, c;

void print(int last){
    while(last != -1){
        ps[top++] = last;
        last = queue[last].fa;
    }
    printf("%d\n", --top);
    while(top-- != 0){
        printf("%s(%d", op[queue[ps[top]].opt], queue[ps[top]].opa);
        if(queue[ps[top]].opt == 2)
            printf(",%d", queue[ps[top]].opa^3);
        printf(")\n");
    }
}

void push(int opt, int opa, int fa, int cc){
    if(!book[cc]){
        book[cc] = true;
        queue[tail++] = node(opt, opa, fa, cc);
    }
}

void bfs(){
    int ca, cb, no, noa, na, nb, ncc;
    while(head != tail){
        node cur = queue[head];
        ca = cur.cc/101;
        cb = cur.cc%101;
        if(ca == c || cb == c){
            print(head);
            return;
        }
        if(ca){
            noa = 1;

            no = 1;
            ncc = cb;
            push(no, noa, head, ncc);

            no = 2;
            ncc = ca+cb>b?((ca+cb-b)*101+b):(ca+cb);
            push(no,noa, head, ncc);
        }

        if(cb){
            noa = 2;

            no = 1;
            ncc = ca*101;
            push(no, noa, head, ncc);

            no = 2;
            ncc = ca+cb>a?(a*101+ca+cb-a):((ca+cb)*101);
            push(no, noa, head, ncc);
        }

        no = 0;
        if(ca < a){
            noa = 1;
            ncc = a*101+cb;
            push(no, noa, head, ncc);
        }
        if(cb < b){
            noa = 2;
            ncc = ca*101+b;
            push(no, noa, head, ncc);
        }
        head++;
    }
    printf("impossible\n");
}

int main(){
    scanf("%d%d%d", &a, &b, &c);
    queue[tail++] = node(-1, -1, -1, 0);
    book[0] = true;
    bfs();
	return 0;
}

