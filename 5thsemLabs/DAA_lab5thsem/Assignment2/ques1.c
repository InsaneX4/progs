#include <stdio.h>
#include <stdlib.h>

int binaryno(int decimal_num){
    
    if (decimal_num == 0) {
        return 0;
    } else {
        return (decimal_num % 2) + 10 * binaryno(decimal_num / 2);
    }

}

int main(){

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int decimal_num;


    if(input == NULL || output == NULL){
        printf("Error opening");
        exit(0);
        
    }
    // Read  contents of input file

        while (fscanf(input, "%d", &decimal_num) != EOF) {
        int binary_representation = binaryno(decimal_num);
        fprintf(output, "%d\n", binary_representation);
    }   
    //printf("\n Contents of input file %d", output);
    fclose(input);
    fclose(output);


    return 0;
}