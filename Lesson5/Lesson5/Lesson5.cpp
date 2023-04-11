#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

void comparisonOperator() {
	int num1 = 10;

	printf("%d\n", num1 == 10);
	printf("%d\n", num1 != 5);
	printf("%d\n", num1 > 10);
	printf("%d\n", num1 < 10);
	printf("%d\n", num1 >= 10);
	printf("%d\n", num1 <= 10);
}

void ternaryOperator() {
	int result;
	int data;
	data = 10;
	result = data > 5 ? 100 : 200;
	printf("%d\n", result);
}

void ternaryOperatorTest() {
	float num1 = 1.2f;
	float num2 = 1.2f;

	printf("%f\n", num1 > 2.0f ? 3.0f : 4.0f);
}

void useBooleanTest() {
	bool b1 = true;
	bool b2 = false;
	
	if (b1 && !b2)
		printf("참\n");
	else
		printf("거짓\n");
	printf("%s\n", b2 || !b1 ? "참" : "거짓");

}

void bracketTest() {
	int num1 = 1;
	int num2 = 1;
	int num3;

	num3 = (2 * 1) << num1 + 2 >> num2;
	printf("%d\n", num3);
}

void multiplicationTables1() {
	for (int i = 1;i < 10;i++) {
		printf("====%d단====\n", i);
		for (int j = 1;j < 10;j++) {
			printf("%d X %d = %d\n", i, j, i * j);
		}
	}
}

void multiplicationTables2() {
	int startDan, endDan, line;

	printf("몇 단부터 몇 단까지 출력? ");
	scanf("%d %d", &startDan, &endDan);

	printf("한 줄에 몇개? ");
	scanf("%d", &line);

	for (int dan = startDan; dan <= endDan; dan += line) {		
		for (int num = 1; num <= 9; num++) {
			for (int k = 0; k < line && (dan + k) <= endDan; k++) {				
				printf("%d X %d = %d\t", (dan + k), num, (dan + k) * num);
			}
			printf("\n");
		}
		printf("\n");
	}
}


int main() {
//	comparisonOperator();
//	ternaryOperator();
//	ternaryOperatorTest();
//	useBooleanTest();
//	bracketTest();
//	multiplicationTables1();
	multiplicationTables2();

	return 0;
}