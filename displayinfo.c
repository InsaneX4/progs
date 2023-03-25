#include<stdio.h>
#include<string.h>

struct student{
    char name[50];
    int roll;
    float marks;
};

int main(){
    struct student S1[5];
    for(int i=0;i<5;i++){
    printf("Enter the name of the student: ");
    scanf("%s",&S1[i].name);
    printf("Enter the rollno.: ");
    scanf("%f",&S1[i].marks);
    printf("Enter the marks: ");
    scanf("%d",&S1[i].roll);

    }
    for(int k=0;k<5;k++){
    printf("Display information: \n");
    printf("Name:  %s\n",S1[k].name);
    printf("Roll numeber:  %d\n",S1[k].roll);
    printf("Marks: %f\n",S1[k].marks);
    }
    return 0;
}