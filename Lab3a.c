#include<stdio.h>
int min(int a,int b){
    return (a<b)?a:b;
 }
void floyd(int a[10][10],int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}
int main(){
    printf("Ashwin Kumar \n1AY23CS043\n");
    int a[10][10],n,i,j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Entered adjacency matix is : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    floyd(a,n);
    printf("All pair shortest path matrix is:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d \t ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
