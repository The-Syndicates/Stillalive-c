#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int* a, int* b);
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1,j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int n) {
    int i;
	for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    clock_t start,end;
	double ftime;
	int n;
	printf("How many randome number you want to generate = ");
	scanf("%d", &n);
	int arr[n],i;
	for (i = 0; i < n; i++){
        arr[i]=rand()%n;
    }
	start=clock();
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr,0,n-1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    end=clock();
    ftime=((double) end-start)/CLOCKS_PER_SEC;
    printf("\nAtul Raj USN- 1AY23CS045");
    printf("\nTime Taken for %d inputs  = %f",n,ftime);
    return 0;
}