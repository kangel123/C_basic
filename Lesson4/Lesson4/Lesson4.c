#include <stdio.h>
#include <limits.h>

void IfStatement1() {
	int num1 = 10;
	if (num1 == 10) {
		printf("10�Դϴ�.\n");
	}

}

void IfStatement2() {
	int num1 = 5;
	if (num1 == 10);	// if�� ���⼭ ����
	{
		printf("10�Դϴ�.\n");
	}
}

void IfStatement3() {
	int num1 = 10;
	if (num1 == 10)
		printf("10�Դϴ�.\n");
}

void IfStatement4() {
	int num1 = 5;

	if (num1 == 10)
		printf("if ���ǹ�\n");
	printf("10�Դϴ�.\n");

	num1 = 10;
	if (num1 == 10) {
		printf("if ���ǹ�\n");
		printf("10�Դϴ�.\n");
	}
}

void IfStatement5() {
	float num1 = 0.1f;
	char c1 = 'a';
	if (num1 == 0.1f)
		printf("0.1�Դϴ�.\n");
	if (c1 == 'a')
		printf("a�Դϴ�.\n");
	if (c1 == 97)
		printf("a�Դϴ�.\n");
}

void IfStatement6() {
	int num1;
	scanf_s("%d", &num1);

	if (num1 == 10) {
		printf("10�Դϴ�.\n");
	}

	if (num1 == 20) {
		printf("20�Դϴ�.\n");
	}
}

void IfStatementTest() {
	char c1 = 'k';

	if (c1 == 'k') {
		printf("k�Դϴ�.\n");
	}

}

void UseElse1() {
	int num1 = 5;
	if (num1 == 10) {
		printf("10�Դϴ�.\n");
	}
	else {
		printf("10�� �ƴմϴ�.\n");
	}
}

void UseElse2() {
	int num1 = 10;
	if (num1 == 10) {
		printf("10�Դϴ�.\n");
	}
	else;
	{
		printf("10�� �ƴմϴ�.\n");
	}
}

void UseElse3() {
	int num1 = 10;
	if (num1 == 10) {
		printf("if ���ǹ� \n");
		printf("10�Դϴ�.\n");
	}
	else {
		printf("else\n");
		printf("10�� �ƴմϴ�.\n");
	}
}

void UseElse4() {
	int num1 = 10;
	if (num1 == 10) {
		printf("if ���ǹ� \n");
		printf("10�Դϴ�.\n");
	}
	else
		printf("else\n");
	printf("10�� �ƴմϴ�.\n");
}

void UseElse5() {
	if (2)
		printf("��\n");
	else
		printf("����\n");
}

void UseElse6() {
	if (0)
		printf("��\n");
	else
		printf("����\n");
}

void UseElse7() {
	int num1 = 5;
	if (num1 = 10) {
		printf("10�Դϴ�.\n");
	}

	printf("%d\n", num1);
}

void LogicalOperator() {
	int num1 = 10;
	int num2 = 20;

	if (num1 == 10 && num2 == 20)
		printf("��\n");
	else
		printf("����\n");
}

void DoubleIfStatement() {
	int num1 = 10;
	int num2 = 20;

	if (num1 == 10) {
		if (num2 == 20) {
			printf("��\n");
		}
		else {
			printf("����\n");
		}
	}
	else {
		printf("����\n");
	}
}

void UseElseTest1() {
	unsigned long long num1 = 0;
	if (num1)
		printf("��\n");
	else
		printf("����\n");
}

void UseElseTest2() {
	int writtenTest = 78;
	int toeic = 870;
	if (writtenTest > 80 && toeic > 850) {
		printf("�հ�\n");
	}
	else {
		printf("���հ�\n");
	}
}

void UseElseIf1() {
	int num1 = 20;
	if (num1 == 10)
		printf("10�Դϴ�.\n");
	else if(num1 == 20)
		printf("20�Դϴ�.\n");
}

void UseElseIf2() {
	int num1 = 30;
	if (num1 == 10)
		printf("10�Դϴ�.\n");
	else if (num1 == 20)
		printf("20�Դϴ�.\n");
	else
		printf("10�� 20�� �ƴմϴ�.\n");
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
		printf("1�Դϴ�.\n");
		break;
	case 2:
		printf("2�Դϴ�.\n");
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
		printf("1�Դϴ�.\n");
	case 2:
		printf("2�Դϴ�.\n");
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
		printf("1 �Ǵ� 2�Դϴ�.\n");
		break;
	case 3:
	case 4:
		printf("3 �Ǵ� 4�Դϴ�.\n");
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
		printf("a�Դϴ�.\n");
		break;
	case 'b':
		printf("b�Դϴ�.\n");
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
	printf("���� �Է� : ");
	scanf_s("%d", &num);
	if (num % 2) {
		printf("Ȧ���Դϴ�\n");
	}
	else {
		printf("¦���Դϴ�\n");
	}
}

void Test2() {
	int numA, numB, numMax = INT_MIN;
	printf("���� A �Է� : ");
	scanf_s("%d", &numA);
	printf("���� B �Է� : ");
	scanf_s("%d", &numB);

	if (numA > numB) {
		numMax = numA;
	}
	else {
		numMax = numB;
	}
	printf("ū ���ڴ� %d�Դϴ�\n", numMax);
}

void Test3() {
	// for�� ���
	char alpabet[5] = { 'A','B','C','D','E' };
	int numMax2 = INT_MIN;
	int numMin2 = INT_MAX;
	for (int i = 0;i < 5;i++) {
		int number;
		printf("���� %c �Է� : ", alpabet[i]);
		scanf_s("%d", &number);
		if (number > numMax2)
			numMax2 = number;
		if (number < numMin2)
			numMin2 = number;
	}
	printf("�ִ밪�� %d�Դϴ�\n", numMax2);
	printf("�������� %d�Դϴ�\n", numMin2);
	
	/*	
	int numA, numB, numC, numD, numE, numMax, numMin;
	printf("���� A �Է� : ");
	scanf_s("%d", &numA);
	printf("���� B �Է� : ");
	scanf_s("%d", &numB);
	printf("���� C �Է� : ");
	scanf_s("%d", &numC);
	printf("���� D �Է� : ");
	scanf_s("%d", &numD);
	printf("���� E �Է� : ");
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

	printf("�ִ밪�� %d�Դϴ�\n", numMax);
	printf("�������� %d�Դϴ�\n", numMin);
	*/
}

void Test4() {
	int year;
	printf("���ϴ� �⵵�� �Է��ϼ��� : ");
	scanf_s("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("�����Դϴ�\n");
	}
	else {
		printf("������ �ƴմϴ�\n");
	}
}

void Test5() {
	int year, leapYear = 0;
	printf("���ϴ� �⵵�� �Է��ϼ��� : ");
	scanf_s("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		leapYear = 29;
	}
	else {
		leapYear = 28;
	}

	// for�� ���
	printf("%d���� ������ �����ϴ�.\n", year);
	int dates[12] = { 31,leapYear,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0;i < 12;i++) {
		printf("%d�� : %d��\n", i+1, dates[i]);
	}

	/*
	printf("%d���� ������ �����ϴ�.\n", year);
	printf("1�� : 31��\n");
	printf("2�� : %d��\n", leapYear);
	printf("3�� : 31��\n");
	printf("4�� : 30��\n");
	printf("5�� : 31��\n");
	printf("6�� : 30��\n");
	printf("7�� : 31��\n");
	printf("8�� : 31��\n");
	printf("9�� : 30��\n");
	printf("10�� : 31��\n");
	printf("11�� : 30��\n");
	printf("12�� : 31��\n");
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