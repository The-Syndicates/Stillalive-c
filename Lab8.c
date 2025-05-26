#include<stdio.h>
#include<time.h>
int c=0;
int x[10], w[10], d;
void subset(int cs, int k, int r){
    int i;
    x[k]=1;
    if(cs+w[k]==d){
        c++;
        printf("\nSolution %d is { ",c);
        for(i=0;i<=k;i++){
            if(x[i]==1){
                printf("%d ",w[i]);
            }
        }
        printf("}\n");
    }
    else if((cs+w[k]+w[k+1])<=d){
        subset(cs+w[k], k+1, r-w[k]);
    }
    if((cs+r-w[k])>=d&&(cs+w[k+1])<=d){
        x[k]=0;
        subset(cs, k+1, r-w[k]);
    }
}
int main(){
    clock_t start,end;
	double ftime;
    printf("Atul Raj USN- 1AY23CS045");
    int n, i,sum=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements in increasing order: ");
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the positive target sum: ");
    scanf("%d",&d);
    for(i=0;i<n;i++){
        sum+=w[i];
    }
    printf("Sum = %d\n",sum);
    if(sum<d||w[0]>d){
        printf("No solution exists.\n");
        return 0;
    }
    start=clock();
    subset(0,0,sum);
    end=clock();
    ftime=((double) end-start)/CLOCKS_PER_SEC;
    printf("\nTime Taken for %d inputs  = %f",n,ftime);
    if(c==0)
    printf("No solution possible.\n");
    return 0;
}