#include <stdio.h>
#include <limits.h>

void IfStatement1() {
	int num1 = 10;
	if (num1 == 10) {
		printf("10입니다.\n");
	}

}

void IfStatement2() {
	int num1 = 5;
	if (num1 == 10);	// if문 여기서 종료
	{
		printf("10입니다.\n");
	}
}

void IfStatement3() {
	int num1 = 10;
	if (num1 == 10)
		printf("10입니다.\n");
}

void IfStatement4() {
	int num1 = 5;

	if (num1 == 10)
		printf("if 조건문\n");
	printf("10입니다.\n");

	num1 = 10;
	if (num1 == 10) {
		printf("if 조건문\n");
		printf("10입니다.\n");
	}
}

void IfStatement5() {
	float num1 = 0.1f;
	char c1 = 'a';
	if (num1 == 0.1f)
		printf("0.1입니다.\n");
	if (c1 == 'a')
		printf("a입니다.\n");
	if (c1 == 97)
		printf("a입니다.\n");
}

void IfStatement6() {
	int num1;
	scanf_s("%d", &num1);

	if (num1 == 10) {
		printf("10입니다.\n");
	}

	if (num1 == 20) {
		printf("20입니다.\n");
	}
}

void IfStatementTest() {
	char c1 = 'k';

	if (c1 == 'k') {
		printf("k입니다.\n");
	}

}

void UseElse1() {
	int num1 = 5;
	if (num1 == 10) {
		printf("10입니다.\n");
	}
	else {
		printf("10이 아닙니다.\n");
	}
}

void UseElse2() {
	int num1 = 10;
	if (num1 == 10) {
		printf("10입니다.\n");
	}
	else;
	{
		printf("10이 아닙니다.\n");
	}
}

void UseElse3() {
	int num1 = 10;
	if (num1 == 10) {
		printf("if 조건문 \n");
		printf("10입니다.\n");
	}
	else {
		printf("else\n");
		printf("10이 아닙니다.\n");
	}
}

void UseElse4() {
	int num1 = 10;
	if (num1 == 10) {
		printf("if 조건문 \n");
		printf("10입니다.\n");
	}
	else
		printf("else\n");
	printf("10이 아닙니다.\n");
}

void UseElse5() {
	if (2)
		printf("참\n");
	else
		printf("거짓\n");
}

void UseElse6() {
	if (0)
		printf("참\n");
	else
		printf("거짓\n");
}

void UseElse7() {
	int num1 = 5;
	if (num1 = 10) {
		printf("10입니다.\n");
	}

	printf("%d\n", num1);
}

void LogicalOperator() {
	int num1 = 10;
	int num2 = 20;

	if (num1 == 10 && num2 == 20)
		printf("참\n");
	else
		printf("거짓\n");
}

void DoubleIfStatement() {
	int num1 = 10;
	int num2 = 20;

	if (num1 == 10) {
		if (num2 == 20) {
			printf("참\n");
		}
		else {
			printf("거짓\n");
		}
	}
	else {
		printf("거짓\n");
	}
}

void UseElseTest1() {
	unsigned long long num1 = 0;
	if (num1)
		printf("참\n");
	else
		printf("거짓\n");
}

void UseElseTest2() {
	int writtenTest = 78;
	int toeic = 870;
	if (writtenTest > 80 && toeic > 850) {
		printf("합격\n");
	}
	else {
		printf("불합격\n");
	}
}

void UseElseIf1() {
	int num1 = 20;
	if (num1 == 10)
		printf("10입니다.\n");
	else if(num1 == 20)
		printf("20입니다.\n");
}

void UseElseIf2() {
	int num1 = 30;
	if (num1 == 10)
		printf("10입니다.\n");
	else if (num1 == 20)
		printf("20입니다.\n");
	else
		printf("10도 20도 아닙니다.\n");
}


void UseElseIfTest() {
	char c1 = 'c';
	if (c1 == 'a')
		printf("a\n");
	else if (c1 == 'b')
		printf("b\n");
	else if (c1 == 'c')
		printf("c\n");
	else if (c1 == 'd')
		printf("d\n");
	else
		printf("x\n");
}

void SwitchCase1() {
	int num1;
	scanf_s("%d", &num1);
	switch (num1) {
	case 1:
		printf("1입니다.\n");
		break;
	case 2:
		printf("2입니다.\n");
		break;
	default :
		printf("default\n");
		break;
	}
}

void SwitchCase2() {
	int num1;
	scanf_s("%d", &num1);
	switch (num1) {
	case 1:
		printf("1입니다.\n");
	case 2:
		printf("2입니다.\n");
	default:
		printf("default\n");
	}
}

void SwitchCase3() {
	int num1;
	scanf_s("%d", &num1);
	switch (num1) {
	case 1:
	case 2:
		printf("1 또는 2입니다.\n");
		break;
	case 3:
	case 4:
		printf("3 또는 4입니다.\n");
		break;
	default:
		printf("default\n");
	}
}

void SwitchCase4() {
	char c1;
	scanf_s("%c", &c1);
	switch (c1) {
	case 'a':
		printf("a입니다.\n");
		break;
	case 'b':
		printf("b입니다.\n");
		break;
	default:
		printf("default\n");
		break;
	}
}

void SwitchCaseTest() {
	int c1 = 0;
	scanf_s("%d", &c1);

	switch (c1) {
	case 2:
		printf("2\n");
		break;
	case 4:
		printf("4\n");
		break;
	case 8:
		printf("8\n");
		break;
	default:
		printf("default\n");
		break;
	}
}

void Test1() {
	int num;
	printf("숫자 입력 : ");
	scanf_s("%d", &num);
	if (num % 2) {
		printf("홀수입니다\n");
	}
	else {
		printf("짝수입니다\n");
	}
}

void Test2() {
	int numA, numB, numMax = INT_MIN;
	printf("숫자 A 입력 : ");
	scanf_s("%d", &numA);
	printf("숫자 B 입력 : ");
	scanf_s("%d", &numB);

	if (numA > numB) {
		numMax = numA;
	}
	else {
		numMax = numB;
	}
	printf("큰 숫자는 %d입니다\n", numMax);
}

void Test3() {
	// for문 사용
	char alpabet[5] = { 'A','B','C','D','E' };
	int numMax2 = INT_MIN;
	int numMin2 = INT_MAX;
	for (int i = 0;i < 5;i++) {
		int number;
		printf("숫자 %c 입력 : ", alpabet[i]);
		scanf_s("%d", &number);
		if (number > numMax2)
			numMax2 = number;
		if (number < numMin2)
			numMin2 = number;
	}
	printf("최대값은 %d입니다\n", numMax2);
	printf("최저값은 %d입니다\n", numMin2);
	
	/*	
	int numA, numB, numC, numD, numE, numMax, numMin;
	printf("숫자 A 입력 : ");
	scanf_s("%d", &numA);
	printf("숫자 B 입력 : ");
	scanf_s("%d", &numB);
	printf("숫자 C 입력 : ");
	scanf_s("%d", &numC);
	printf("숫자 D 입력 : ");
	scanf_s("%d", &numD);
	printf("숫자 E 입력 : ");
	scanf_s("%d", &numE);

	numMax = numA;
	if (numMax < numB) {
		numMax = numB;
	}
	if (numMax < numC) {
		numMax = numC;
	}
	if (numMax < numD) {
		numMax = numD;
	}
	if (numMax < numE) {
		numMax = numE;
	}

	numMin = numA;
	if (numMin > numB) {
		numMin = numB;
	}
	if (numMin > numC) {
		numMin = numC;
	}
	if (numMin > numD) {
		numMin = numD;
	}
	if (numMin > numE) {
		numMin = numE;
	}

	printf("최대값은 %d입니다\n", numMax);
	printf("최저값은 %d입니다\n", numMin);
	*/
}

void Test4() {
	int year;
	printf("원하는 년도를 입력하세요 : ");
	scanf_s("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("윤년입니다\n");
	}
	else {
		printf("윤년이 아닙니다\n");
	}
}

void Test5() {
	int year, leapYear = 0;
	printf("원하는 년도를 입력하세요 : ");
	scanf_s("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		leapYear = 29;
	}
	else {
		leapYear = 28;
	}

	// for문 사용
	printf("%d년은 다음과 같습니다.\n", year);
	int dates[12] = { 31,leapYear,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0;i < 12;i++) {
		printf("%d월 : %d일\n", i+1, dates[i]);
	}

	/*
	printf("%d년은 다음과 같습니다.\n", year);
	printf("1월 : 31일\n");
	printf("2월 : %d일\n", leapYear);
	printf("3월 : 31일\n");
	printf("4월 : 30일\n");
	printf("5월 : 31일\n");
	printf("6월 : 30일\n");
	printf("7월 : 31일\n");
	printf("8월 : 31일\n");
	printf("9월 : 30일\n");
	printf("10월 : 31일\n");
	printf("11월 : 30일\n");
	printf("12월 : 31일\n");
	*/
}


int main() {
//	IfStatement1();
//	IfStatement2();
//	IfStatement3();
//	IfStatement4();
//	IfStatement5();
//	IfStatement6();
//	IfStatementTest();

//	UseElse1();
//	UseElse2();
//	UseElse3();
//	UseElse4();
//	UseElse5();
//	UseElse6();
//	UseElse7();
//	LogicalOperator();
//	DoubleIfStatement();
//	UseElseTest1();
//	UseElseTest2();

//	UseElseIf1();
//	UseElseIf2();
//	UseElseIfTest();

//	SwitchCase1();
//	SwitchCase2();
//	SwitchCase3();
//	SwitchCase4();
//	SwitchCaseTest();

	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}