#include<stdio.h>
int prims(int n, int mincost, int cost[10][10]){
	int ne=1; 
  int selected[10]={0};
  selected[0] = 1;
  int x;  
  int y; 
  printf("Edge : Weight\n");
  while (ne < n) {
    int min = 999;
    x = 0;
    y = 0;
	  int i,j;
    for ( i = 0; i < n; i++) {
      if (selected[i]) {
        for (j = 0; j < n; j++) {
          if (!selected[j] && cost[i][j]) {  
            if (min > cost[i][j]) {
              min = cost[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, cost[x][y]);
    selected[y] = 1;
    mincost=mincost+cost[x][y];
    ne++;
  }
  return mincost;
}

int main()
{
	printf("ATUL RAJ USN- 1AY23CS045\n");
	int cost[10][10];
	int i, j, mincost = 0, n;
	printf("Enter the number of nodes: "); 
	scanf("%d", &n);
	printf("Enter the cost matrix (No edge enter 999):\n"); 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	mincost = prims(n, mincost, cost);
	printf("The minimum spanning tree cost is: %d\n", mincost); 
	return 0;
}