#include <bits/stdc++.h>
 
using namespace std;
 
const int N=1e5+5;
const int MAX=2147483647;
typedef long long LL;
 
struct node{        //��ͼ���ֻ���һ����
    int from;
    int to;
    int value;
    int next;
}edge[2*N];
int head[N];
 
LL dis[N];
int visited[N];
 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >vis;    //���ȶ���
 
int main()
{
    int n,m,s;
    int cnt=0;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) dis[i]=MAX;
    for(int i=1;i<=m;i++)
    {
        cnt++;
        scanf("%d%d%d",&edge[cnt].from,&edge[cnt].to,&edge[cnt].value);
        edge[cnt].next=head[edge[cnt].from];
        head[edge[cnt].from]=cnt;
    }
 
 
    dis[s]=0;
    vis.push(make_pair(0,s));    //����ĳ�����͸õ�
                                 //make_pair��c++�Դ��Ķ�Ԫ�鶨�巽ʽ,����ͨ��first��second���ʵ�һ����
				//�ڶ���Ԫ��(С�����Ե�һ��ֵ����)
 
    while(!vis.empty())        //�ж����е��Ƿ񶼲��ҹ�һ��
    {
        int start=vis.top().second;    //���ȶ��ж��׼���С��Ԫ��
        vis.pop();
 
        if(visited[start]==1) continue;    //����õ���ҹ�������
        visited[start]=1;
 
        for(int i=head[start];i!=0;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[start]+edge[i].value)
            {
                dis[edge[i].to]=dis[start]+edge[i].value;
                vis.push(make_pair(dis[edge[i].to],edge[i].to));     
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==n) printf("%d\n",dis[i]);
        else printf("%d ",dis[i]);
    }
}

