#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main() {

	int height, width;
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	

	printf("���� ũ�� : ");
	scanf("%d", &height);
	printf("���� ũ�� : ");
	scanf("%d", &width);


	// �����Ҵ�
	int** numbers;
	numbers = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++) {
		numbers[i] = (int*)malloc(sizeof(int) * width);
	}

	
	for (int row = 0;row < height;row++) {
		for (int column = 0;column < width;column++) {
			numbers[row][column] = 0;
		}
	}

	int count = 1, directionMovement = 0;
	int row = 0, column = 0;
	while (count <= height * width) {
		numbers[row][column] = count;

		int nextRow = row + direction[directionMovement][0];
		int nextColumn = column + direction[directionMovement][1];
		if (0 > nextRow || nextRow >= height || 0 > nextColumn || nextColumn >= width || numbers[nextRow][nextColumn] != 0) {

			directionMovement = (directionMovement + 1) % 4;
			nextRow = row + direction[directionMovement][0];
			nextColumn = column + direction[directionMovement][1];
		}
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