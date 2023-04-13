#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// ������ ����
const int LESS_BABY_PRICE = 0, GREATER_BABY_PRICE = 15000,
ADULT_DAY_PRICE = 59000, ADULT_NIGHT_PRICE = 47000,
TEEN_DAY_PRICE = 52000, TEEN_NIGHT_PRICE = 41000,
CHILD_DAY_PRICE = 46000, CHILD_NIGHT_PRICE = 35000,
OLD_PRICE = 15000;

// �ֹε�Ϲ�ȣ �м�
const long long int FULL_DIGIT = 10000000000000,	// 14�ڸ�
FULL_DIGIT_MIN = 1000000000,	// 10�ڸ�
SEVEN_DIGIT = 1000000;
const int TWO_DIGIT = 100, ONE_DIGIT = 10,
OLD_GENERATION = 1900, NEW_GENERATION = 2000,
KOREAN_MALE_OLD = 1, KOREAN_FEMALE_OLD = 2, KOREAN_MALE_NEW = 3, KOREAN_FEMALE_NEW = 4,
FOREIGN_MALE_OLD = 5, FOREIGN_FEMALE_OLD = 6, FOREIGN_MALE_NEW = 7, FOREIGN_FEMALE_NEW = 8,
BEFORE_BIRTH = 2, AFTER_BIRTH = 1;

// ���̿� ���� ����
const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

// ���̿� ���� �׷�
const int LESS_BABY = 1, GREATER_BABY = 2, CHILD = 3, TEEN = 4, ADULT = 5, OLD = 6;

// ������
const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
MULTICHILD_DISCOUNT_RATE = 0.5,
PREGNANT_DISCOUNT_RATE = 0.7;

// �ִ� �ֹ���
const int MAX_COUNT = 100, MIN_COUNT = 1;


int inputTicketSelect() {
	int ticket;
	do {
		printf("������ �����ϼ���.\n");
		printf("1. �ְ���\n");
		printf("2. �߰���\n");
		scanf("%d", &ticket);
	} while (ticket < 1 || ticket >2);
	return ticket;
}

long long int inputCustomerIDNumber() {
	long long int  customerIDNumber;
	// �����κ� Ȯ�κκ� ���߿� �߰�!!!
	do {
		printf("�ֹι�ȣ�� �Է��ϼ���.\n");
		scanf("%lld", &customerIDNumber);
	} while (customerIDNumber >= FULL_DIGIT || customerIDNumber < FULL_DIGIT_MIN);
	return customerIDNumber;
}


int inputOrderCount() {
	int  orderCount = 1;
	do {
		printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 100��).\n");
		scanf("%d", &orderCount);
	} while (orderCount < MIN_COUNT || orderCount > MAX_COUNT);

	return orderCount;
}

int inputDiscountSelect() {
	int  discountSelect;
	do {
		printf("�������� �����ϼ���.\n");
		printf("1. ����(���� ���� �ڵ�ó��)\n");
		printf("2. �����\n");
		printf("3. ����������\n");
		printf("4. ���ڳ�\n");
		printf("5. �ӻ��\n");
		scanf("%d", &discountSelect);

	} while (discountSelect < 1 || discountSelect > 5);
	return discountSelect;
}



void inputData(int* ticketSelect, long long int* customerIDNumber, int* orderCount, int* discountSelect) {
	*ticketSelect = inputTicketSelect();
	*customerIDNumber = inputCustomerIDNumber();
	*orderCount = inputOrderCount();
	*discountSelect = inputDiscountSelect();
}

int calcAge(long long int customerIDNumber) {
	struct tm* t;
	time_t now = time(NULL);
	t = localtime(&now);

	int age = 0;
	int customerYear = 0;
	int gender = (int)((customerIDNumber / SEVEN_DIGIT) % ONE_DIGIT);
	switch (gender) {
	case KOREAN_MALE_OLD:
	case KOREAN_FEMALE_OLD:
	case FOREIGN_MALE_OLD:
	case FOREIGN_FEMALE_OLD: customerYear = (int)(OLD_GENERATION + customerIDNumber / (FULL_DIGIT_MIN * TWO_DIGIT)); break;
	case KOREAN_MALE_NEW:
	case KOREAN_FEMALE_NEW:
	case FOREIGN_MALE_NEW:
	case FOREIGN_FEMALE_NEW: customerYear = (int)(NEW_GENERATION + customerIDNumber / (FULL_DIGIT_MIN * TWO_DIGIT)); break;
	default: break;
	}

	int currentYear = OLD_GENERATION + t->tm_year;
	age = currentYear - customerYear + 1;	// �ѱ��� ����
	int birth = (int)((customerIDNumber % (FULL_DIGIT_MIN * TWO_DIGIT)) / (SEVEN_DIGIT * ONE_DIGIT));
	if (birth > (t->tm_mon + 1) * 100 + t->tm_mday) {
		age -= BEFORE_BIRTH;
	}
	else {
		age -= AFTER_BIRTH;
	}
	return age;
}

int calAgeGroup(int age) {

	if (age > MAX_ADULT) {
		return OLD;
	}
	else if (MIN_ADULT <= age) {
		return ADULT;
	}
	else if (MIN_TEEN <= age && age <= MAX_TEEN) {
		return TEEN;
	}
	else if (MIN_CHILD <= age && age < MAX_CHILD) {
		return CHILD;
	}
	else if (MIN_BABY <= age && age < MIN_CHILD) {
		return GREATER_BABY;
	}
	else if (0 <= age && age < MIN_BABY) {
		return LESS_BABY;
	}
	else {
		return -1;
	}

}

int calcPriceProcess(int age, int ticketSelect) {
	int ageNumber = calAgeGroup(age);
	int price = 0;
	switch (ticketSelect) {
	case 1:
		switch (ageNumber) {
		case OLD: price = OLD_PRICE; break;
		case ADULT:price = ADULT_DAY_PRICE; break;
		case TEEN:price = TEEN_DAY_PRICE; break;
		case CHILD:price = CHILD_DAY_PRICE; break;
		case GREATER_BABY:price = GREATER_BABY_PRICE; break;
		case LESS_BABY:price = LESS_BABY_PRICE; break;
		default: price = -1; break;
		}
		break;
	case 2:
		switch (ageNumber) {
		case OLD: price = OLD_PRICE;break;
		case ADULT:price = ADULT_NIGHT_PRICE;break;
		case TEEN:price = TEEN_NIGHT_PRICE;break;
		case CHILD:price = CHILD_NIGHT_PRICE;break;
		case GREATER_BABY:price = GREATER_BABY_PRICE; break;
		case LESS_BABY:price = LESS_BABY_PRICE; break;
		default: price = -1;break;
		}
		break;
	default: price = -1;break;
	}

	return price;
}

int calcDiscount(int calcPrice, int discountSelect) {
	switch (discountSelect) {
	case 1: break;
	case 2: calcPrice *= DISABLE_DISCOUNT_RATE; break;
	case 3: calcPrice *= MERIT_DISCOUNT_RATE; break;
	case 4: calcPrice *= MULTICHILD_DISCOUNT_RATE; break;
	case 5: calcPrice *= PREGNANT_DISCOUNT_RATE; break;
	default: calcPrice = -1; break;
	}
	return calcPrice;
}

int calcPriceResult(int calcPrice, int orderCount) {
	return calcPrice * orderCount;
}


int processIntegeration(long long int customerIDNumber, int ticketSelect, int discountSelect, int orderCount, int priceResult, int* age) {
	int calcPrice = 0;
	*age = calcAge(customerIDNumber);

	calcPrice = calcPriceProcess(*age, ticketSelect);
	calcPrice = calcDiscount(calcPrice, discountSelect);
	priceResult = calcPriceResult(calcPrice, orderCount);

	return priceResult;
}

void saveOrderList(int ticketSelect, int age, int orderCount, int priceResult, int discountSelect, int* position, int(*orderList)[5])
{
	orderList[*position][0] = ticketSelect;
	orderList[*position][1] = age;
	orderList[*position][2] = orderCount;
	orderList[*position][3] = priceResult;
	orderList[*position][4] = discountSelect;
	(*position)++;
}

void pricePrint(int priceResult) {
	printf("������ %d �� �Դϴ�.\n", priceResult);
	printf("�����մϴ�.\n\n");
}

void orderPrint(int totalPrice, int* position, int(*orderList)[5]) {

	printf("================================= �Ե����� =================================\n");
	for (int i = 0;i < *position;i++) {
		switch (orderList[i][0]) {
		case 1: printf("| �ְ��� |"); break;
		case 2: printf("| �߰��� |"); break;
		default: break;
		}

		switch (calAgeGroup(orderList[i][1])) {
		case OLD: printf("%17s  X", " ���"); break;
		case ADULT:printf("%17s  X", " ����"); break;
		case TEEN:printf("%17s  X", " û�ҳ�"); break;
		case CHILD:printf("%17s  X", " ����"); break;
		case GREATER_BABY:printf("%17s  X", " 12���� �̻� ����"); break;
		case LESS_BABY:printf("%17s  X", " 12���� �̸� ����"); break;
		default:  break;
		}

		printf(" %5d ", orderList[i][2]);
		printf("| %10d�� ", orderList[i][3]);

		switch (orderList[i][4]) {
		case 1: printf("| %20s |\n", "*������� ����"); break;
		case 2: printf("| %20s |\n", "*����� �������"); break;
		case 3: printf("| %20s |\n", "*���������� �������"); break;
		case 4: printf("| %20s |\n", "*���ڳ� �������"); break;
		case 5: printf("| %20s |\n", "*�ӻ�� �������"); break;
		default: break;
		}
	}
	printf("\n����� �Ѿ��� %d�� �Դϴ�.\n", totalPrice);
	printf("============================================================================\n");
}

int orderContinue() {
	int  continueSelect;
	do {
		printf("��� �߱� �Ͻðڽ��ϱ�?\n");
		printf("1. Ƽ�� �߱�\n");
		printf("2. ����\n");
		scanf("%d", &continueSelect);

	} while (continueSelect < 1 || continueSelect > 2);
	return continueSelect;
}


bool orderFilePrint(int totalPrice, int* position, int(*orderList)[5], int* filePosition) {
	FILE* fp;

	fp = fopen("report.csv", "r");
	if (fp == NULL) { // ������ ���� ���
		fp = fopen("report.csv", "w");
		if (fp == NULL) {
			printf("������ �� �� �����ϴ�.");
			return false;
		}
		fprintf(fp, "��¥,����,���ɱ���,����,����,������\n");
		fclose(fp);
		fp = fopen("report.csv", "a");
	}
	else { // ������ �ִ� ���
		fclose(fp);
		fp = fopen("report.csv", "a");
	}
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.");
		return false;
	}

	struct tm* t;
	time_t now = time(NULL);
	t = localtime(&now);


	fprintf(fp, "%d,", ((t->tm_year + OLD_GENERATION) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday));
	switch (orderList[*position - 1][0]) {
	case 1: fprintf(fp, "�ְ���,"); break;
	case 2: fprintf(fp, "�߰���,"); break;
	default: break;
	}
	switch (calAgeGroup(orderList[*position - 1][1])) {
	case OLD: fprintf(fp, "���,"); break;
	case ADULT:fprintf(fp, "����,"); break;
	case TEEN:fprintf(fp, "û�ҳ�,"); break;
	case CHILD:fprintf(fp, "����,"); break;
	case GREATER_BABY:fprintf(fp, "12���� �̻� ����,"); break;
	case LESS_BABY:fprintf(fp, "12���� �̸� ����,"); break;
	default:  break;
	}
	fprintf(fp, "%d,", orderList[*position - 1][2]);
	fprintf(fp, "%d,", orderList[*position - 1][3]);

	switch (orderList[*position - 1][4]) {
	case 1: fprintf(fp, "����\n"); break;
	case 2: fprintf(fp, "�����\n"); break;
	case 3: fprintf(fp, "����������\n"); break;
	case 4: fprintf(fp, "���ڳ�\n"); break;
	case 5: fprintf(fp, "�ӻ��\n"); break;
	default: break;
	}

	fclose(fp);

	return true;
}

void errorMessagePrint() {
	printf("������ �߻��Ͽ����ϴ�.\n");
}

int main() {

	int totalPrice = 0;
	int position = 0;
	int filePosition = 0;
	int reportPosition = 0;
	int orderList[100][5] = { 0 };
	int isExit = 0;
	bool error=true;
	struct tm* t;
	time_t now = time(NULL);
	t = localtime(&now);

	do {
		while (1) {
			int ticketSelect, orderCount, discountSelect, age, price = 0;
			long long int customerIDNumber;
			inputData(&ticketSelect, &customerIDNumber, &orderCount, &discountSelect);

			price = processIntegeration(customerIDNumber, ticketSelect, discountSelect, orderCount, price, &age);
			pricePrint(price);
			totalPrice += price;

			saveOrderList(ticketSelect, age, orderCount, price, discountSelect, &position, orderList);

			error = orderFilePrint(totalPrice, &position, orderList, &filePosition);
			

			if (!error) {errorMessagePrint(); break; }

			int continueSelect = orderContinue();
			if (continueSelect == 2) { break; }
		}
		printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n\n");
		orderPrint(totalPrice, &position, orderList);

		printf("��� ����(1:���ο� �ֹ�, 2: ���α׷� ����) : ");
		scanf("%d", &isExit);
		position = 0;
		totalPrice = 0;
	} while (isExit == 1);

	return 0;
}