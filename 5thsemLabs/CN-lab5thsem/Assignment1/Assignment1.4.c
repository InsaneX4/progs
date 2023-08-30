#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pkt {
    char ch1;
    char ch2[2]; // Increase the size to hold two digits and the null terminator
    char ch3;
};

int main() {
    struct pkt myPacket;

    // Input the number and store it in the structure
    printf("Enter a number: ");
    scanf(" %c", &myPacket.ch1);
    scanf("%1s", myPacket.ch2); // Read two characters into ch2 to avoid buffer overflow
    scanf(" %c", &myPacket.ch3);

    // Print the content of each member of the structure
    printf("\nContent of the structure:\n");
    printf("ch1: %c\n", myPacket.ch1);
    printf("ch2: %s\n", myPacket.ch2);
    printf("ch3: %c\n", myPacket.ch3);

    // Convert the aggregated characters back to an integer and print the same
    int number;
    sscanf(myPacket.ch2, "%d", &number);
    printf("\nOriginal number: %c%d%c\n", myPacket.ch1, number, myPacket.ch3);

    return 0;
}
