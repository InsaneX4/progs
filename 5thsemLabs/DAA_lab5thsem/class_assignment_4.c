#include <stdio.h>
#include <math.h>

int main()
{
int i,j,row,col;
printf("How many rows do you want?");
scanf("%d",&row);
printf("How many columns do you want?");
scanf("%d",&col);


double arr[row][col];
int brr[row][col];

for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("Enter element: ");
scanf("%lf",&arr[i][j]);
}
}


for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
brr[i][j]=round(arr[i][j]);

}
}

printf("INPUT ARRAY\n");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%lf\t",arr[i][j]);
}
printf("\n");
}

printf("OUTPUT ARRAY\n");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%d\t",brr[i][j]);
}
printf("\n");
}

}


