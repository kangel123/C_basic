#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// 권종별 가격
const int LESS_BABY_PRICE = 0, GREATER_BABY_PRICE = 15000,
ADULT_DAY_PRICE = 59000, ADULT_NIGHT_PRICE = 47000,
TEEN_DAY_PRICE = 52000, TEEN_NIGHT_PRICE = 41000,
CHILD_DAY_PRICE = 46000, CHILD_NIGHT_PRICE = 35000,
OLD_PRICE = 15000;

// 주민등록번호 분석
const long long int FULL_DIGIT = 10000000000000,	// 14자리
FULL_DIGIT_MIN = 1000000000,	// 10자리
SEVEN_DIGIT = 1000000;
const int TWO_DIGIT = 100, ONE_DIGIT = 10,
OLD_GENERATION = 1900, NEW_GENERATION = 2000,
KOREAN_MALE_OLD = 1, KOREAN_FEMALE_OLD = 2, KOREAN_MALE_NEW = 3, KOREAN_FEMALE_NEW = 4,
FOREIGN_MALE_OLD = 5, FOREIGN_FEMALE_OLD = 6, FOREIGN_MALE_NEW = 7, FOREIGN_FEMALE_NEW = 8,
BEFORE_BIRTH = 2, AFTER_BIRTH = 1;

// 나이에 따른 범위
const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19,
MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

// 나이에 따른 그룹
const int LESS_BABY = 1, GREATER_BABY = 2, CHILD = 3, TEEN = 4, ADULT = 5, OLD = 6;

// 할인율
const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
MULTICHILD_DISCOUNT_RATE = 0.5,
PREGNANT_DISCOUNT_RATE = 0.7;

// 최대 주문량
const int MAX_COUNT = 100, MIN_COUNT = 1;


int inputTicketSelect() {
	int ticket;
	do {
		printf("권종을 선택하세요.\n");
		printf("1. 주간권\n");
		printf("2. 야간권\n");
		scanf("%d", &ticket);
	} while (ticket < 1 || ticket >2);
	return ticket;
}

long long int inputCustomerIDNumber() {
	long long int  customerIDNumber;
	// 성별부분 확인부분 나중에 추가!!!
	do {
		printf("주민번호를 입력하세요.\n");
		scanf("%lld", &customerIDNumber);
	} while (customerIDNumber >= FULL_DIGIT || customerIDNumber < FULL_DIGIT_MIN);
	return customerIDNumber;
}


int inputOrderCount() {
	int  orderCount = 1;
	do {
		printf("몇개를 주문하시겠습니까? (최대 100개).\n");
		scanf("%d", &orderCount);
	} while (orderCount < MIN_COUNT || orderCount > MAX_COUNT);

	return orderCount;
}

int inputDiscountSelect() {
	int  discountSelect;
	do {
		printf("우대사항을 선택하세요.\n");
		printf("1. 없음(나이 우대는 자동처리)\n");
		printf("2. 장애인\n");
		printf("3. 국가유공자\n");
		printf("4. 다자녀\n");
		printf("5. 임산부\n");
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
	age = currentYear - customerYear + 1;	// 한국식 나이
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
	printf("가격은 %d 원 입니다.\n", priceResult);
	printf("감사합니다.\n\n");
}

void orderPrint(int totalPrice, int* position, int(*orderList)[5]) {

	printf("================================= 롯데월드 =================================\n");
	for (int i = 0;i < *position;i++) {
		switch (orderList[i][0]) {
		case 1: printf("| 주간권 |"); break;
		case 2: printf("| 야간권 |"); break;
		default: break;
		}

		switch (calAgeGroup(orderList[i][1])) {
		case OLD: printf("%17s  X", " 경로"); break;
		case ADULT:printf("%17s  X", " 대인"); break;
		case TEEN:printf("%17s  X", " 청소년"); break;
		case CHILD:printf("%17s  X", " 소인"); break;
		case GREATER_BABY:printf("%17s  X", " 12개월 이상 유아"); break;
		case LESS_BABY:printf("%17s  X", " 12개월 미만 유아"); break;
		default:  break;
		}

		printf(" %5d ", orderList[i][2]);
		printf("| %10d원 ", orderList[i][3]);

		switch (orderList[i][4]) {
		case 1: printf("| %20s |\n", "*우대적용 없음"); break;
		case 2: printf("| %20s |\n", "*장애인 우대적용"); break;
		case 3: printf("| %20s |\n", "*국가유공자 우대적용"); break;
		case 4: printf("| %20s |\n", "*다자녀 우대적용"); break;
		case 5: printf("| %20s |\n", "*임산부 우대적용"); break;
		default: break;
		}
	}
	printf("\n입장료 총액은 %d원 입니다.\n", totalPrice);
	printf("============================================================================\n");
}

int orderContinue() {
	int  continueSelect;
	do {
		printf("계속 발권 하시겠습니까?\n");
		printf("1. 티켓 발권\n");
		printf("2. 종료\n");
		scanf("%d", &continueSelect);

	} while (continueSelect < 1 || continueSelect > 2);
	return continueSelect;
}


bool orderFilePrint(int totalPrice, int* position, int(*orderList)[5], int* filePosition) {
	FILE* fp;

	fp = fopen("report.csv", "r");
	if (fp == NULL) { // 파일이 없는 경우
		fp = fopen("report.csv", "w");
		if (fp == NULL) {
			printf("파일을 열 수 없습니다.");
			return false;
		}
		fprintf(fp, "날짜,권종,연령구분,수량,가격,우대사항\n");
		fclose(fp);
		fp = fopen("report.csv", "a");
	}
	else { // 파일이 있는 경우
		fclose(fp);
		fp = fopen("report.csv", "a");
	}
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		return false;
	}

	struct tm* t;
	time_t now = time(NULL);
	t = localtime(&now);


	fprintf(fp, "%d,", ((t->tm_year + OLD_GENERATION) * 10000) + ((t->tm_mon + 1) * 100) + (t->tm_mday));
	switch (orderList[*position - 1][0]) {
	case 1: fprintf(fp, "주간권,"); break;
	case 2: fprintf(fp, "야간권,"); break;
	default: break;
	}
	switch (calAgeGroup(orderList[*position - 1][1])) {
	case OLD: fprintf(fp, "경로,"); break;
	case ADULT:fprintf(fp, "대인,"); break;
	case TEEN:fprintf(fp, "청소년,"); break;
	case CHILD:fprintf(fp, "소인,"); break;
	case GREATER_BABY:fprintf(fp, "12개월 이상 유아,"); break;
	case LESS_BABY:fprintf(fp, "12개월 미만 유아,"); break;
	default:  break;
	}
	fprintf(fp, "%d,", orderList[*position - 1][2]);
	fprintf(fp, "%d,", orderList[*position - 1][3]);

	switch (orderList[*position - 1][4]) {
	case 1: fprintf(fp, "없음\n"); break;
	case 2: fprintf(fp, "장애인\n"); break;
	case 3: fprintf(fp, "국가유공자\n"); break;
	case 4: fprintf(fp, "다자녀\n"); break;
	case 5: fprintf(fp, "임산부\n"); break;
	default: break;
	}

	fclose(fp);

	return true;
}

void errorMessagePrint() {
	printf("에러가 발생하였습니다.\n");
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
		printf("티켓 발권을 종료합니다. 감사합니다.\n\n");
		orderPrint(totalPrice, &position, orderList);

		printf("계속 진행(1:새로운 주문, 2: 프로그램 종료) : ");
		scanf("%d", &isExit);
		position = 0;
		totalPrice = 0;
	} while (isExit == 1);

	return 0;
}