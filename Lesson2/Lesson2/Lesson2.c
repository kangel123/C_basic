#include <stdio.h>
#include <float.h>
#include <limits.h>

void IntegerVariableTest() {
	int num1 = 10, num2 = 20, num3 = 30;
	printf("%d %d %d\n", num1, num2, num3);
}

void OverflowTest() {
	unsigned char num1 = 256;
	unsigned short num2 = 65536;
	long long num3 = 9223372036854775808;

	printf("%u %u %lld\n", num1, num2, num3);
}


void SizeofTest1() {
	short num1;
	double num2;
	printf("%d\n", sizeof(num1) + sizeof(num2) + sizeof(int));
}

void MaxVariableTest() {
	char num1 = CHAR_MAX;
	short num2 = SHRT_MAX;
	int num3 = INT_MAX;
	long num4 = LONG_MAX;
	long long num5 = LLONG_MAX;
	printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
}

void ExponentialNotationTest() {
	float num1 = 1.97f;
	long double num2 = 5.5242181;
	long double num3 = 3792.8e+4;

	printf("%f %LF %f\n", num1, num2, num3);
}

void SizeofTest2() {
	double num1 = 0.4284;
	float num2 = 2.7f;

	printf("num1의 크기 : %d, num2의 크기 : %d\n", sizeof(num1), sizeof(num2));
}


void MaxAndMinTest() {
	float num1 = FLT_MAX;
	double num2 = DBL_MIN;
	long double num3 = LDBL_MAX;

	printf("%.2f\n", num1);
	printf("%e\n", num2);
	printf("%Le\n", num3);
}

void UnderflowTest() {
	float num1 = FLT_MIN;

	printf("%e\n", num1 / 16777216);
}

void EscapeCharacterTest() {
	char c1 = '\t';	// escape character

	printf("Hello");
	printf("%c", c1);
	printf("world\n");
}


void CastTest() {
	char c1 = 2;
	char c2 = 11;

	printf("%c\n", c1 + 48);	// 아스키코드의 문자0은 48이다
	printf("0x%x\n", c2);	//int값을 부호없는 16진수로 출력
}

int main() {
	IntegerVariableTest();
	OverflowTest();
	SizeofTest1();
	MaxVariableTest();
	ExponentialNotationTest();
	SizeofTest2();
	MaxAndMinTest();
	UnderflowTest();
	EscapeCharacterTest();
	CastTest();

	return 0;
}