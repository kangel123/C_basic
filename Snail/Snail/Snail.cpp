#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {

	int height, width;
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int count = 1, directionMovement = 0;
	int row = 0, column = 0;

	printf("행의 크기 : ");
	scanf("%d", &height);
	printf("열의 크기 : ");
	scanf("%d", &width);


	// 동적할당
	int** numbers;
	numbers = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++) {
		numbers[i] = (int*)malloc(sizeof(int) * width);
	}

	// 
	for (int row = 0;row < height;row++) {
		for (int column = 0;column < width;column++) {
			numbers[row][column] = 0;
		}
	}

	if (height > 0 && width > 0) {
		numbers[0][0] = count;
		count++;
	}
	while (count <= height * width) {

		int nextRow = row + direction[directionMovement][0];
		int nextColumn = column + direction[directionMovement][1];
		if (0 > nextRow || nextRow >= height || 0 > nextColumn || nextColumn >= width || numbers[nextRow][nextColumn] != 0) {

			directionMovement = (directionMovement + 1) % 4;
			continue;
		}
		numbers[nextRow][nextColumn] = count;
		row = nextRow;
		column = nextColumn;
		count++;
	}



	for (int row = 0;row < height;row++) {
		for (int column = 0;column < width;column++) {
			printf("%d\t", numbers[row][column]);
		}
		printf("\n");
	}

	return 0;
}