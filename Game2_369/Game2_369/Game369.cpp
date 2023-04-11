#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

const int CLAP_UNIT1 = 3;
const int CLAP_UNIT2 = 6;
const int CLAP_UNIT3 = 9;

void printClaps(int numberOfClaps) {
    for (int i = 0;i < numberOfClaps;i++) {
        printf("짝\a");
        Sleep(1000);
    }
    printf("\n");
}

int countClaps(int number) {
    int numberOfClaps = 0;
    int digit;
    while (number != 0) {
        digit = number % 10;
        if (digit == CLAP_UNIT1 || digit == CLAP_UNIT2 || digit == CLAP_UNIT3) {
            numberOfClaps++;
        }
        number /= 10;
    }
    return numberOfClaps;
}

int main() {
    int count;
    printf("숫자 몇까지 할까요? ");
    scanf("%d", &count);

    for (int number = 1; number <= count; number++) {
        int numberOfClaps = countClaps(number);
        if (numberOfClaps > 0) {
            printClaps(numberOfClaps);
        }
        else {
            printf("%d\n", number);
        }
        Sleep(1000);
    }
    return 0;
}
