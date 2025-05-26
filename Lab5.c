#include <stdio.h> 
#include <stdlib.h>
#define MAX_VERTEX 100
int adj[MAX_VERTEX][MAX_VERTEX];
int stack[MAX_VERTEX];
int visited[MAX_VERTEX];
int top=-1;
void dfs(int v)
{	int i;
	visited[v] = 1;
	for (i = 0; i < MAX_VERTEX; i++)
	{
		if (adj[v][i] && !visited[i])
		{
			dfs(i);
		}
	}
	stack[++top] = v; 
}
void topologicalSort(int V)
{	int i;
	for (i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
	printf("Topological Sort Order: \n"); 
	while (top != -1)
	{
		printf("%d ", stack[top--]);
	}
}
void main()
{
    printf("ADITYA KUMAR \n1AY23CS012\n");
	int n,i,j;
	printf("Enter the number of vertices: "); 
	scanf("%d", &n);
	printf("Enter the adjacency matrix: \n"); 
	for (i = 0; i < n; i++)
		for(j=0;j<n;j++)
			scanf("%d", &adj[i][j]); 
	topologicalSort(n);
}