#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int findEndDate(int year, int month) {
	const int LAST_DAY[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year) && month == 2) {
		return 29;
	}
	else {
		return LAST_DAY[month - 1];
	}
}

void printCalendar(int year, int month) {
	int date, endDay;
	struct tm t = { 0 };
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = 1;
	mktime(&t);

	date = t.tm_wday % 7;
	endDay = findEndDate(year, month);
	printf("%d", date);
	printf("\n======== %d�� %d�� ==========\n", year, month);
	printf("  ��  ��  ȭ  ��  ��  ��  ��\n");

	for (int i = 0; i < date; i++) {
		printf("    ");
	}

	for (int day = 1; day <= endDay; date++, day++) {		
		
		printf("%4d", day);
		if (date % 7 == 6) {
			printf("\n");
		}
	}
	printf("\n\n");
}

int main() {
	int year, month;

	while (true) {
		printf("�⵵ �Է� (0 �Է� �� ����): ");
		scanf("%d", &year);
		if (year == 0) {
			printf("�����մϴ�.");
			break;
		}
		printf("�� �Է�: ");
		scanf("%d", &month);

		printCalendar(year, month);
	}

	return 0;
}
