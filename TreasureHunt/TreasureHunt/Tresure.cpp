#include <stdio.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define MAX_ROW_SIZE 50
#define MAX_COLUMN_SIZE 50

int getArraySize(int range, int map[]) {
    int size = 0;

    for (int i = 0; i < range && map[size] != 0; i++, size++);

    return size;
}

void createArraysOfSameSize(int minRowSize, int maxRowSize, int map[], int mapSize) {

    for (int row = minRowSize; row < maxRowSize; row++) {
        if (row >= mapSize) {
            map[row] = 0;
        }
    }
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

void findBlock(int maxRowSize, int maxColumnSize, int map1[], int map2[]) {
    char decryptedMap[MAX_ROW_SIZE][MAX_COLUMN_SIZE];

    for (int row = 0; row < maxRowSize; row++) {
        int line = map1[row] | map2[row];
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

int main() {

    int map1[5] = { 9,20,28,18,11 };
    int map2[6] = { 30,1,21,17,28 };

    int rowSize1 = getArraySize(sizeof(map1) / sizeof(int), map1);
    int rowSize2 = getArraySize(sizeof(map2) / sizeof(int), map2);

    int maxRowSize = MAX(rowSize1, rowSize2);
    int minRowSize = MIN(rowSize1, rowSize2);

    createArraysOfSameSize(minRowSize, maxRowSize, map1, rowSize1);
    createArraysOfSameSize(minRowSize, maxRowSize, map2, rowSize2);

    int maxColumnSize = compareMaxColumnSize(rowSize1, map1, rowSize2, map2);

    findBlock(maxRowSize, maxColumnSize, map1, map2);


	int map3[8] = { 46,33,33,22,31,50,10,20};
	int map4[6] = { 27,56,19,14,14,10 };

	int rowSize3 = getArraySize(sizeof(map3) / sizeof(int), map3);
	int rowSize4 = getArraySize(sizeof(map4) / sizeof(int), map4);

	maxRowSize = MAX(rowSize3, rowSize4);
	minRowSize = MIN(rowSize3, rowSize4);

    createArraysOfSameSize(minRowSize, maxRowSize, map3, rowSize3);
    createArraysOfSameSize(minRowSize, maxRowSize, map4, rowSize4);

	maxColumnSize = compareMaxColumnSize(rowSize3, map3, rowSize4, map4);

	findBlock(maxRowSize, maxColumnSize, map3, map4);

	return 0;
}
