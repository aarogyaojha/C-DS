#include<stdio.h>
#define max 10

// int adj[][max] = {{0,1,0,1,0},{1,0,1,1,0},{0,1,0,0,1},{1,1,0,0,1},{0,0,1,1,0}};
int start=0,r,f,i;
int adj[max][max];

void bfs()
{
	int visited[max]={0};
	r=f=-1;
	int q[max];
	q[++r] = start;
	visited[start] = 1;
	while(r!=f)
	{
		start = q[++f];
		printf("%d->",start);
		for(i=0;i<max;i++)
		{
			if(adj[start][i]==1 && visited[i]==0)
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
}

void dfs(int start)
{
	int visited[max]={0};
	int stack[max];
	int top = -1,i;
	printf("%d->",start);
	visited[start] = 1;
	stack[++top] = start;
	while(top!=-1)
	{
		start = stack[top];
		for(i=0;i<max;i++)
		{
			if(adj[start][i] && visited[i]==0)
			{
				stack[++top] = i;
				printf("%d->",i);
				visited[i] = 1;
				break;
			}
		}
		if(i==max)
		{
			top--;
		}
	}
}

int main()
{
	int m,n,s;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d",&m,&n);
	printf("Enter the elements: ");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("----------BFS----------\n");
	bfs();
	printf("\n");
	printf("----------DFS----------\n");
	printf("Enter the starting vertex: ");
	scanf("%d",&s);
	dfs(s);
	printf("\n");
	return 0;
}
