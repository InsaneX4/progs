#include<stdio.h>
#include<stdlib.h>
 
int partition(int arr[], int low, int high)
{
 
    int pivot = arr[high];
 
 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
 
        if (arr[j] < pivot) {
 
 
            i++;
            int temp=arr[i];
            arr[i]= arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
 
        int pi = partition(arr, low, high);
 
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
 
 
 
int partition_dec(int arr[], int low, int high)
{
 
    int pivot = arr[high];
 
 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
 
        if (arr[j] > pivot) {
 
 
            i++;
            int temp=arr[i];
            arr[i]= arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    // swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
void quickSort_dec(int arr[], int low, int high)
{
    if (low < high) {
 
 
        int pi = partition_dec(arr, low, high);
 
 
        quickSort_dec(arr, low, pi - 1);
        quickSort_dec(arr, pi + 1, high);
    }
}
 
 
 
int main(){
 
 
 
FILE *INPUT,*OUTPUT;
INPUT=fopen("inAsce.dat","r");
if(INPUT==NULL){
perror("There is some problem in Reading the File \n");
exit(0);
}
 
OUTPUT=fopen("outInsAsce.dat","w");
if(OUTPUT==NULL){
perror("There is some problem in Displaying Results to the FIle \n");
exit(0);
}
 
int choice;
printf("Enter User Choice \n");
int arr[500],count=0;
int no;
 
while (fscanf(INPUT, "%d", &no) == 1) {
        arr[count++]=no;
    }
scanf("%d",&choice);
 
 
switch(choice){
	case 1:{
		// perform_insetion_sort_descending(arr,count);
		int n=count;
		int high=count-1;
		quickSort(arr,0,high);
		break;
 
	}
	case 2:{
 
		int n=count;
		int high=count-1;
		quickSort_dec(arr,0,high);
		break;
	}
	case 3:{
		// show_random_data(arr,count);
		break;
	}
	case 4:{
		perror("Error in the program \n");
		break;
	}
}
 
for(int i=0;i<count;i++){
	fprintf(OUTPUT, "%d ",arr[i]);
}
 
 
return 0;
}