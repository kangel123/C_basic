#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define MAX_ROW_SIZE 50
#define MAX_COLUMN_SIZE 50

int getArraySize(int range, int map[]) {
    int size = 0;

    for (int i = 0; i < range && map[size] != 0; i++, size++);

    return size;
}

int findMaxColumnSize(int rowSize, int map[]) {
    int maxColumSize = 0;
    int maxNumber = 0;
    for (int row = 0; row < rowSize; row++) {
        if (maxNumber < map[row]) {
            maxNumber = map[row];
        }
    }

    for (; maxNumber != 0; maxColumSize++, maxNumber /= 2);

    return maxColumSize;
}

int compareMaxColumnSize(int maxRowSize1, int map1[], int maxRowSize2, int map2[]) {
    int maxCoulmnSizeMap1 = findMaxColumnSize(maxRowSize1, map1);
    int maxCoulmnSizeMap2 = findMaxColumnSize(maxRowSize2, map2);

    return MAX(maxCoulmnSizeMap1, maxCoulmnSizeMap2);
}

void findBlock(int minRowSize, int maxRowSize, int maxColumnSize, int map1[], int map2[]) {
    char decryptedMap[MAX_ROW_SIZE][MAX_COLUMN_SIZE];

    for (int row = 0; row < maxRowSize; row++) {
        int line = 0;
        if (row < minRowSize) {
            line = map1[row] | map2[row];
        }
        else {
            line = map1[row];
        }
        for (int column = maxColumnSize - 1; column >= 0; column--) {
            int block = line % 2;
            if (block) {
                decryptedMap[row][column] = '#';
            }
            else {
                decryptedMap[row][column] = ' ';
            }
            line /= 2;
        }
        decryptedMap[row][maxColumnSize] = '\0';
    }


    printf("[");
    for (int i = 0; i < maxRowSize; i++) {
        printf("%s", decryptedMap[i]);
        if (i < maxRowSize - 1)
            printf(",");
    }

    printf("]\n");
}

void putMap(int height, int map[]) {
    for (int row = 0; row < height; row++) {
        int num;
        while (true) {
            printf("%d번째 행에 대해 숫자를 입력하시오 : ", (row + 1));
            if (scanf("%d", &num) != 1) {
                printf("숫자가 아닌 입력이 감지되었습니다. 다시 입력해주세요.\n");
                    int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }
            else if (num < 0) {
                printf("음수는 입력이 불가능합니다. 다시 입력해주세요.\n");
                continue;
            }
            break;
        }
        map[row] = num;
    }
}

// 기존 문제에서 업그레이드
int main() {
    // 배열의 크기가 맞지 않는 경우 
    int map1[5] = { 9,20,28,18,11 };
    int map2[6] = { 30,1,21,17,28 };

    int rowSize1 = getArraySize(sizeof(map1) / sizeof(int), map1);
    int rowSize2 = getArraySize(sizeof(map2) / sizeof(int), map2);

    int maxRowSize = MAX(rowSize1, rowSize2);
    int minRowSize = MIN(rowSize1, rowSize2);

    int maxColumnSize = compareMaxColumnSize(rowSize1, map1, rowSize2, map2);

    if (rowSize1 > rowSize2)
        findBlock(minRowSize, maxRowSize, maxColumnSize, map1, map2);
    else
        findBlock(minRowSize, maxRowSize, maxColumnSize, map2, map1);


    // 지도의 크기가 서로 다른 경우 
    int map3[8] = { 46,33,33,22,31,50,10,20 };
    int map4[6] = { 27,56,19,14,14,10 };

    int rowSize3 = getArraySize(sizeof(map3) / sizeof(int), map3);
    int rowSize4 = getArraySize(sizeof(map4) / sizeof(int), map4);

    maxRowSize = MAX(rowSize3, rowSize4);
    minRowSize = MIN(rowSize3, rowSize4);

    maxColumnSize = compareMaxColumnSize(rowSize3, map3, rowSize4, map4);

    if (rowSize1 > rowSize2)
        findBlock(minRowSize, maxRowSize, maxColumnSize, map1, map2);
    else
        findBlock(minRowSize, maxRowSize, maxColumnSize, map2, map1);

    // 지도 내용 입력받기 
    while (true) {
        int height1, height2;

        printf("지도1의 높이를 입력하시오(0보다 작거나 같으면 종료) : ");
        scanf("%d", &height1);
        if (height1 < 1) break;
        int* map1 = (int*)malloc(height1 * sizeof(int));
        putMap(height1, map1);

        printf("지도2의 높이를 입력하시오(0보다 작거나 같으면 종료) : ");
        scanf("%d", &height2);
        if (height2 < 1)	break;
        int* map2 = (int*)malloc(height2 * sizeof(int));
        putMap(height2, map2);

        int maxRowSize = MAX(height1, height2);
        int minRowSize = MIN(height1, height2);

        int maxColumnSize = compareMaxColumnSize(height1, map1, height2, map2);

        if (height1 > height2)
            findBlock(minRowSize, maxRowSize, maxColumnSize, map1, map2);
        else
            findBlock(minRowSize, maxRowSize, maxColumnSize, map2, map1);

    }

    printf("종료합니다.");


    return 0;
}
