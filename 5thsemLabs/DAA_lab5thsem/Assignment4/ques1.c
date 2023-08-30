// Aim of the program: Write a menu driven program to sort list of array elements using Merge
// Sort technique and calculate the execution time only to sort the elements. Count the number of
// comparisons.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int h, int *comparisonCount) {
     int i = l;
    int j = m+1;
    int k = 0;
    int b[h-l+1];
    while(i <= m && j <= h){
        (*comparisonCount)++;
    if(a[i] < a[j]){
        b[k] = a[i];
        i++; 
    }else{
        b[k] = a[j];
        j++; 
    }
    k++;
    }
    while(i <= m){
        b[k] = a[i];
        i++; k++;
    }
    while(j <= h){
        b[k] = a[j];
        k++;
         j++;
    }
     for (int x = 0; x < k; x++) {  // Copy elements from b[] back to a[]
        a[l + x] = b[x];
    }
}
void merge_dec(int arr[],int low,int mid,int high,int *comparisonCount){
	int l=low,r=mid+1;
	int temp[(high-low)+1],k=0;
	while(l<=mid && r<=high){
        (*comparisonCount)++;
		if(arr[l]<arr[r]){
		temp[k++]=arr[l++];
		}else{
		temp[k++]=arr[r++];
		}
	}
 
	while(l<=mid){
		temp[k++]=arr[l++];
	}
 
	while(r<=high){
		temp[k++]=arr[r++];
	}
	for(int i=low;i<=(high);i++){
		arr[i]=temp[i-low];
	}
 
 
}
// Merge Sort function
void mergeSort(int arr[], int l, int r, int *comparisonCount) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comparisonCount);
        mergeSort(arr, m + 1, r, comparisonCount);

        merge(arr, l, m, r, comparisonCount);
    }
}
void sort_merge_descending(int arr[],int low,int high,int *comparisonCount){
	// base case
	if(low>=high)
	return;
	int mid=(low+high)/2;
	sort_merge_descending(arr,low,mid,comparisonCount);
	sort_merge_descending(arr,mid+1,high,comparisonCount);
	merge_dec(arr,low,mid,high,comparisonCount);
}

int main() {
    int choice;
    char *inputFileName, *outputFileName;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1:
                inputFileName = "inAsce.txt";
                outputFileName = "outMergeAsce.txt";
                break;
            case 2:
                inputFileName = "inDesc.txt";
                outputFileName = "outMergeDesc.txt";
                break;
            case 3:
                inputFileName = "inRand.txt";
                outputFileName = "outMergeRand.txt";
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Error opening input file.\n");
            return 1;
        }

        int n;
        printf("Enter the number of elements to be sorted: ");
        scanf("%d",&n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            fscanf(inputFile, "%d", &arr[i]);
        }

        fclose(inputFile);

        clock_t start_time = clock();
        int comparisonCount = 0;
        mergeSort(arr, 0, n - 1, &comparisonCount);
        clock_t end_time = clock();

        FILE *outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error opening output file.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
        }

        fclose(outputFile);

        double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Sorting completed and written to %s\n", outputFileName);
        printf("Number of comparisons: %d\n", comparisonCount);
        printf("Execution time: %f seconds\n", execution_time);
    }

    return 0;
}
