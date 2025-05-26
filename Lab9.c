#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i,j;
	for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
	for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Atul Raj \n USN- 1AY23CS045");
	clock_t start,end;
	double ftime;
	int n;
	printf("How many randome number you want to generate = ");
	scanf("%d", &n);
	int arr[n],i;
	for (i = 0; i < n; i++)
	{
        arr[i]=rand()%n;
    }
    printf("Original array: ");
    printArray(arr, n);
    
	start=clock();
    selectionSort(arr, n);
    end=clock();
    
    printf("Sorted array: ");
    printArray(arr, n);
    ftime=((double) end-start)/CLOCKS_PER_SEC;
    printf("\nAtul Raj USN - 1AY23CS045");
    printf("\nTime Taken for %d inputs  = %f",n,ftime);
    return 0;
}