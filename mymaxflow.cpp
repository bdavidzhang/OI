#include<bits/stdc++.h>
#define N 209
#define M 20009
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
const int inf=0x3f3f3f3f;
int n,m,s,t,hd[N],tot,now[N],d[N],nV;
long long maxf;
struct edge{int t,w,nxt;} es[M<<1];
void adde(int u,int v,int w){es[++tot]=(edge){v,w,hd[u]},hd[u]=tot;es[++tot]=(edge){u,0,hd[v]},hd[v]=tot;}
bool bfs(){
	fill(d+1,d+nV+1,0);
	copy(hd+1,hd+nV+1,now+1);
	queue<int>q;q.push(s);d[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=hd[u],v;i;i=es[i].nxt)if(!d[v=es[i].t]&&es[i].w){
			d[v]=d[u]+1;q.push(v);
			if(v==t)return 1;
		}
	}
	return 0;
}
int dinic(int u,int f){
	if(u==t)return f;
	int r=f;
	for(int i=now[u],v;i&&r;i=es[i].nxt)if(d[v=es[i].t]==d[u]+1&&es[now[u]=i].w){
		int k=dinic(v,min(r,es[i].w));
		if(!k)d[v]=0;
		es[i].w-=k,es[i^1].w+=k;r-=k;
	}
	return f-r;
}
int main(){
	cin>>nV>>m>>s>>t;tot=1;rep(i,1,m){int u,v,w;scanf("%d %d %d",&u,&v,&w);adde(u,v,w);}while(bfs())maxf+=dinic(s,inf);cout<<maxf<<endl;
	return 0;
}