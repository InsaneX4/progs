#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main(){

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int num1;
    int num2;


    if(input == NULL || output == NULL){
        printf("Error opening");
        exit(0);
        
    }
    // Read  contents of input file

        while (fscanf(input, "%d", &num1) != EOF && fscanf(input, "%d", &num2) != EOF) {
        int binary_representation = gcd(num1, num2);
        fprintf(output, "%d\n", binary_representation);
    }   
    //printf("\n Contents of input file %d", output);
    fclose(input);
    fclose(output);

    return 0;
}