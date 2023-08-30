#include <stdio.h>

int isLittleEndian() {
    unsigned int num = 1;
    char *byte = (char *)&num;
    return (*byte == 1);
}

int convertEndian(int num) {
    int convertedNum = 0;
    char *src = (char *)&num;
    char *dest = (char *)&convertedNum;
    int size = sizeof(int);

    if (isLittleEndian()) {
        // Convert Little Endian to Big Endian
        for (int i = 0; i < size; i++) {
            dest[i] = src[size - 1 - i];
        }
    } else {
        // Convert Big Endian to Little Endian
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
    }

    return convertedNum;
}

int main() {
    int inputNumber;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    // Check the endianness
    if (isLittleEndian()) {
        printf("\nThe host machine is Little Endian.\n");
    } else {
        printf("\nThe host machine is Big Endian.\n");
    }

    // Print the content of each byte location
    printf("\nContent of each byte location:\n");
    char *bytePtr = (char *)&inputNumber;
    for (int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: 0x%02X\n", i + 1, bytePtr[i]);
    }

    // Convert the Endianness
    int convertedNumber = convertEndian(inputNumber);

    // Print the converted number and its content
    printf("\nConverted number: %d\n", convertedNumber);
    bytePtr = (char *)&convertedNumber;
    printf("Content of each byte location after conversion:\n");
    for (int i = 0; i < sizeof(int); i++) {
        printf("Byte %d: 0x%02X\n", i + 1, bytePtr[i]);
    }

    return 0;
}
