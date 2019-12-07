#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
 
string c="ACGT";
int n,depth; 
int t,k,maxn,pos[10];//pos数组记录每个字符串已经拼到第几个了
int mycnt; 
struct node{
	string s;
	int len;
}a[10];
 
int get()//获得剩余序列未拼接的最长的一个长度
{
	int ans = 0;
	for(int i=0;i<n;i++)
	 ans = max(ans,a[i].len-pos[i]);
	return ans;
}
int dfs(int step)
{
    mycnt++;
    if(mycnt % 1000000 == 0)
        printf("%dm has done...\n", mycnt/1000000);
	if(step+get()>depth) return 0;//如果预计的步数超过了最大值，就取消搜索
	if(!get()) return 1;//如果已经全部拼完，就退出
	int temp[10];//此数组记录pos数组的值，相当于完成vis的操作
	for(int i=0;i<n;i++)
	 temp[i] = pos[i];
	for(int i=0;i<4;i++)
	{
		bool flag = 0;
		for(int j=0;j<n;j++)
		{
			if(a[j].s[pos[j]]==c[i])//如果有的拼接，记录一下，第j个序列pos+1
			{
				flag = 1;
				pos[j]++;	
			}
		}
		if(flag) 
		{
			if(dfs(step+1))//如果拼接过，就继续往下搜索
			 return 1;
			for(int i=0;i<n;i++)//复原
			 pos[i] = temp[i];
		}
	}
	return 0;
}
 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		depth = 0;
		maxn = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i].s;
			a[i].len = a[i].s.length();		
			maxn = max(maxn,a[i].len);
			pos[i] = 0;
		}
		depth = maxn;//这步不能忘！初始深度为最长的一个序列的长度
		while(1)
		{
            printf("start with %d depth...\n", depth);
			if(dfs(0)) break;
			depth++;
		}
		cout<<depth<<endl;
	}
	return 0;
}
