#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int u; /// Enter the no of subject
int n; /// Enter the no of student


//////////////////////////////////////////////////////
struct student{
   int id;
   char name[30];
   float marks;
   float total;
   float percentage;
};

 typedef struct subject{
   char subject1[30];
   struct student record[5];
} subject;
//////////////////////////////////////////////////////////

// function to print total marks and percentage of a student
/*void Part_A(subject info[]){
    for (int i=0; i<n; i++){
        float total = 0; // total marks
        for (int j=0; j<5; j++){
            total += info[i].record[j].marks;
        }
        float percentage = ((total*100)/500);
        info[i].record[i].total = total;
        info[i].record[i].percentage = percentage;
        printf("\nTotal marks for Student : ", info[i].record[i].total , " is " ,  total);
        printf("\nPercentage is : " , info[i].record[i].percentage,"\n");
    } 
}
/////////////////////////////////
// function to display details of a student with a given roll number
void Part_B(subject info[], int roll){
    bool  found = false;
    for (int i=0; i<u; i++){
      for(int j=0;j<n;j++){
        if (info[i].record[j].id == roll){
            // Display details of this student
           // DisplayDetails(info[i].record[i]);
           printf("%0.3f",info[i].record[j].marks," \n ");
            found = true;
            
        }
      }
    }
    if (found==false) printf("No match for any student with roll : %d" , roll);
}
*/
////////////////////////
int main(){
   //Enter the number of subjects
   printf("Enter the number of subjects ");
   scanf("%d",&u);
   // Enter the size of the record
   printf("Enter the size of the record: ");
   scanf("%d",&n);

   int i;
   struct subject info[n];
   //Enter the data by "the user
   for(int l=0;l<u;l++){ // runing 2 times 
      printf("Enter the name of the subject ");
      scanf("%s",info[l].subject1); // 0 // 1 //
   for(int k=0;k<n;++k){ //running 1 time //1
      printf("Enter the name of the student ");
      scanf("%s",info[l].record[k].name);  // 0 0 // 1 1 // 1 2

      printf("Enter the roll number of the student ");
      scanf("%d",&info[l].record[k].id); // 0 0 // 1 1 // 1 2

      printf("Enter the marks of the student ");
      scanf("%f",&info[l].record[k].marks); // 0 0 // 1 1 // 1 2

   }
   
   }
   /// printing the value
   printf(" Records of STUDENT :  \n");
   for(int y=0;y<u;y++){ // 2
      printf(" Subject name is: %s \n", info[y].subject1);
   for(i=0; i<n; ++i){ //1
      printf(" Rollno is: %d \n", info[y].record[i].id);
      printf(" Name is: %s \n", info[y].record[i].name);
      printf(" marks is: %0.2f\n\n",info[y].record[i].marks);
   
   }
   }
 /*
    // a. Find total marks and percentage of total n students
    Part_A(info);
    printf("----------------------------\n");
    
    // b. Display details of a student with a given roll number.
    int whichRoll;
    printf("\nWhich roll number do you want to check ? - ");
    scanf( "%d",&whichRoll);
    Part_B(info, whichRoll);
    printf("----------------------------\n");
*/
     
   return 0;
}



/*
subject -> info
           subject1 char[50]
           studennt -> record
                       id
                       name[50] 
                       marks

*/