#include <stdio.h>

int main()
{
    unsigned char num = 4;
    int i = sizeof(num) * 8;

    printf("Before: ");
    while (i-- > 0)
        printf("%d", (num >> i) & 1);
    printf("\n");

    i = 0;
    int size = sizeof(num) * 8; // Size in bits
    while ( i++ < size)
    {
        if (num & (1 << i))
            num &= ~(1 << i);
        else
            num |= (1 << i);
    }
    printf("After:  ");
    while (i-- > 0)
        printf("%d", (num >> i) & 1);
    printf("\n");

    return 0;
}
/*
#include <stdio.h>

int main() {
    unsigned char num = 4;

    printf("Before: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");

    int size = sizeof(num) * 8; // Size in bits
    for (int i = 0; i < size; i++) {
        if (num & (1 << i)) { // Check if the ith bit is set
            num &= ~(1 << i); // Clear the ith bit
        } else {
            num |= (1 << i); // Set the ith bit
        }
    }

    printf("After:  ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");

    return 0;
}

*/