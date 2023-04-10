#include <stdio.h>

void Literal1() {
	printf("%d\n", 10);
	printf("%f\n", 0.1f);
	printf("%c\n", 'a');
	printf("%s\n", "Hello, world!");
}


void Literal2() {
	printf("%f\n", 0.1f);
	printf("%f\n", 0.1F);
	printf("%f\n", 1.0e-5f);
	printf("%f\n", 1.0E-5F);
}


void ConstTest1() {	
	// const : 변수 앞에 붙이면 값을 변경하지 못하도록 하며, 해당 변수를 상수로 취급
	// const 사용o
	const int con1 = 1;
	const float con2 = 0.1f;
	const char con3 = 'a';
	printf("%d %f %c\n", con1, con2, con3);

//	con1 = 2; 에러 걸림
//	printf("%d", con1);

	// const 사용x
	int con4 = 3;
	printf("%d\n", con4);
	con4 = 4;
	printf("%d\n", con4);
}


void UnsignedLiteralTest() {
	printf("%ld\n", -10L);
	printf("%lld\n", -123456789012346789);
	printf("%lld\n", -123456789012346789LL);

	printf("%u\n", 10U);
	printf("%lu\n", 1234567890UL);	// U : unsinged


	printf("%lu\n", 10UL);
	printf("%llu\n", 1234567890123456789ULL);
}

void LiteralSuffix1() {
	printf("0%lo\n", 017L);
	printf("0%lo\n", 017UL);
	printf("0x%lX\n", 0x7FFFFFL);
	printf("0x%lX\n", 0xFFFFFFFFUL);
}

void LiteralSuffix2() {
	printf("%f\n", 0.1f);
	printf("%f\n", 0.1F);
	printf("%f\n", 0.1);
	printf("%Lf\n", 0.1l);
	printf("%Lf\n", 0.1L);

	printf("%f\n", 1.0e-5f);
	printf("%f\n", 1.0e-5F);
	printf("%f\n", 1.0e-5);
	printf("%Lf\n", 1.0e-5l);
	printf("%Lf\n", 1.0e-5L);
}

void LiteralTest3() {
	printf("H%cllo, %s %d %Le\n", 'e', "world!", 8, 4.9e-302);
}

void ConstTest2() {
	const long long con1 = 10ULL;
	const float con2 = 3.2;
	const char con3 = 't';
	printf("%llu %f %c\n", con1, con2, con3);

}

void UseScanf1() {
	int num1;

	printf("정수를 입력하세요 : ");
	scanf_s("%d", &num1);
	printf("%d\n", num1);
}

void UseScanf2() {
	int num1, num2;

	printf("정수를 두 개 입력하세요 : ");
	scanf_s("%d %d", &num1, &num2);
	printf("%d %d\n", num1, num2);
}

void UseScanf3() {
	float num1;

	printf("실수를 입력하세요 : ");
	scanf_s("%f", &num1);
	printf("%f\n", num1);
}

void UseScanf4() {
	double num1;
	printf("double형을 입력하세요 : ");
	scanf_s("%lf", &num1);
	printf("%lf\n", num1);

	long double num2;
	printf("long double형을 입력하세요 : ");
	scanf_s("%Lf", &num2);
	printf("%Lf\n", num2);
}

void UseScanf5() {
	char c1;

	printf("문자를 입력하세요: ");
	scanf_s("%c", &c1);

	printf("%c\n", c1);
}

void UseGetchar() {
	printf("문자를 입력하세요: ");
	char c1 = getchar();

	printf("%c\n", c1);
	printf("%c\n", c1);
}

void UsePutchar() {
	char c1 = 'a';

	putchar(c1);
}


void UseScanf6() {
	int num1;
	int num2;
	int num3;

	printf("정수 세 개를 입력하세요:");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	printf("%d\n%d\n%d\n", num1, num2, num3);
}

void AdditionAndSubtraction1() {
	int num1;
	int num2;

	num1 = 1 + 2;
	num2 = 1 - 2;
	printf("%d\n", num1);
	printf("%d\n", num2);
}

void AdditionAndSubtraction2() {
	float num1;
	float num2;

	num1 = 1.0f + 0.456789f;
	num2 = 1.0f - 0.456789f;
	printf("%f\n", num1);
	printf("%f\n", num2);
}

void AdditionAndSubtraction3() {
	int num1 = 1;
	int num2 = 1;

	num1 = num1 + 2;
	num2 = num2 - 2;
	printf("%d\n", num1);
	printf("%d\n", num2);
}

void AdditionAndSubtraction4() {
	int num1 = 1;
	int num2 = 1;

	num1 += 2;
	num2 -= 2;
	printf("%d\n", num1);
	printf("%d\n", num2);
}

void AdditionAndSubtraction5() {
	int num1 = 1;
	printf("%d\n", num1);
	num1++;
	printf("%d\n", num1);
}

void AdditionAndSubtractionTest() {
	int num1;
	int num2 =5;

	num1 = 10 - num2;
	num1 += 95;
	printf("%d\n", num1);

}

void MultiplicationAndDivision1() {
	int num1;
	int num2;

	num1 = 2 * 3;
	num2 = 7 / 2;

	printf("%d\n", num1);
	printf("%d\n", num2);
}

void MultiplicationAndDivision2() {
	int num1=1;
	int num2=0;
	int num3;
//	error
//	num3 = num1 / num2;
//	printf("%d\n", num3);
}

void MultiplicationAndDivision3() {
	float num1 = 1.0f;
	float num2 = 0.0f;	// 유효숫자
	float num3;
		
	num3 = num1 / num2;
	printf("%f\n", num3);
}

void MultiplicationAndDivision4() {
	int num1 = 2;
	int num2 = 7;

	num1 = num1 * 3;
	num2 = num2 / 2;

	printf("%d\n", num1);
	printf("%d\n", num2);
}

void MultiplicationAndDivision5() {
	int num1 = 2;
	int num2 = 7;

	num1 *= 3;
	num2 /= 2;

	printf("%d\n", num1);
	printf("%d\n", num2);
}

void TriangleAreaTest() {
	int base = 20;
	int height = 16;
	int area;

	area = base * height /2;

	printf("%d\n", area);

}

void Remain1() {
	printf("%d\n", 1 % 3);
	printf("%d\n", 2 % 3);
	printf("%d\n", 3 % 3);
	printf("%d\n", 4 % 3);
	printf("%d\n", 5 % 3);
	printf("%d\n", 6 % 3);
}

void RemainTest() {
	int num1 = 15;
	int num2 = 27;
	int num3 = 3;

	num1 %= num3;
	num2 %= num3;

	printf("%d\n", num1);
	printf("%d\n", num2);

}

void FourArithmeticOperations1() {
	int num1, num2;

	printf("정수를 두 개 입력하세요 : ");
	scanf_s("%d %d", &num1, &num2);
	
	printf("합:%d\n차:%d\n곱:%d\n몫:%d\n나머지:%d\n", num1 + num2, num1-num2, num1 * num2, num1 / num2, num1 % num2);
}


void FourArithmeticOperations2() {
	int numberA, numberB, numberC;

	printf("A를 입력: ");
	scanf_s("%d", &numberA);
	printf("B를 입력: ");
	scanf_s("%d", &numberB);
	printf("C를 입력: ");
	scanf_s("%d", &numberC);

	printf("A의 짝/홀 확인 : %d\n", numberA % 2);
	printf("B의 짝/홀 확인 : %d\n", numberB % 2);
	printf("C의 짝/홀 확인 : %d\n", numberC % 2);

	printf("A + B + C = %d + %d + %d = %d\n", numberA, numberB, numberC, numberA + numberB + numberC);
	printf("A + B + C = %d + %d + %d = %d\n", numberA, numberB, numberC, numberA - numberB - numberC);
	printf("A + B + C = %d + %d + %d = %d\n", numberA, numberB, numberC, numberA * numberB * numberC);
}

void DataTypeExtension1() {
	int num1 = 11;
	float num2 = 4.4f;

	printf("%f\n", num1 + num2);
	printf("%f\n", num1 - num2);
	printf("%f\n", num1 * num2);
	printf("%f\n", num1 / num2);
}

void DataTypeExtension2() {

	long long num1 = 123456789000;
	int num2 = 10;

	printf("%lld\n", num1 + num2);
	printf("%lld\n", num1 - num2);
	printf("%lld\n", num1 * num2);
	printf("%lld\n", num1 / num2);
}

void DataTypeReduction1() {
	float num1 = 11.0f;
	float num2 = 5.0f;

	int num3 = num1 / num2;

	printf("%d\n", num3);

}

void DataTypeReduction2() {
	char num1 = 28;
	int num2 = 1000000002;
	char num3 = num1 + num2;

	printf("%d\n", num3);
}

int main() {
//	Literal1();
//	Literal2();
//	ConstTest1();
//	UnsignedLiteralTest();
//	LiteralSuffix1();
//	LiteralSuffix2();
//	LiteralTest3();
//	ConstTest2();

//	UseScanf1();
//	UseScanf2();
//	UseScanf3();
//	UseScanf4();
//	UseScanf5();
//	UseGetchar();
//	UsePutchar();
//	UseScanf6();

//	AdditionAndSubtraction1();
//	AdditionAndSubtraction2();
//	AdditionAndSubtraction3();
//	AdditionAndSubtraction4();
//	AdditionAndSubtraction5();
//	AdditionAndSubtractionTest();

	MultiplicationAndDivision1();
	MultiplicationAndDivision2();
	MultiplicationAndDivision3();
	MultiplicationAndDivision4();
	MultiplicationAndDivision5();
	TriangleAreaTest();
	Remain1();
	RemainTest();
	FourArithmeticOperations1();
	FourArithmeticOperations2();

	DataTypeExtension1();
	DataTypeExtension2();
	DataTypeReduction1();
	DataTypeReduction2();

	return 0;
}