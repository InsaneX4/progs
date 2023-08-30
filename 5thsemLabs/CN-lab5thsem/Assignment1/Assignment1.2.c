#include<stdio.h>
#include<stdlib.h>

struct dob{
	int age;
};


struct student_info{
	int roll_no;
	char name[50];
	float CGPA;
	struct dob age;
};

int main(){
	struct student_info n1;
	n1.roll_no=10;
	gets(n1.name);
	n1.CGPA=10;
	n1.age.age=20;
	printf("RollNo. of the Student:%d \n",n1.roll_no);
	printf("Name of the Student:");
	puts(n1.name);
	printf("CGPA is %.2f \n",n1.CGPA);
	printf("DOB is %d \n",n1.age.age);
	return 0;
}
