#include <stdio.h>

void ShowChange(int money) {
	int paperMoney50000 = (money / 50000);
	money %= 50000;
	int paperMoney10000 = (money / 10000);
	money %= 10000;
	int paperMoney5000 = (money / 5000);
	money %= 5000;
	int paperMoney1000 = (money / 1000);
	money %= 1000;
	int paperMoney500 = (money / 500);
	money %= 500;
	int paperMoney100 = (money / 100);
	money %= 100;
	int paperMoney50 = (money / 50);
	money %= 100;
	int paperMoney10 = (money / 10);
	money %= 100;
	
	printf("50000원 : %d\n", paperMoney50000);
	printf("10000원 : %d\n", paperMoney10000);
	printf("5000원 : %d\n", paperMoney5000);
	printf("1000원 : %d\n", paperMoney1000);
	printf("500원 : %d\n", paperMoney500);
	printf("100원 : %d\n", paperMoney100);
	printf("50원 : %d\n", paperMoney50);
	printf("10원 : %d\n", paperMoney10);
}

int main() {
	const float EXCHANGE_RATE[5] = { 1318.90, 999.36, 1438.79, 191.61, 1638.73};
	int existingMoney, choiceCurrency, exchangedMoney, remainderMoney;


	printf("환전을 원하는 금액을 입력하세요 (원화) : ");
	scanf_s("%d", &existingMoney);

	do {
		printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
		scanf_s("%d", &choiceCurrency);
	} while (choiceCurrency < 1 || choiceCurrency > 5);
	choiceCurrency--;

	printf("기준 환율 : %.2f\n", EXCHANGE_RATE[choiceCurrency]);
	exchangedMoney = (int)(existingMoney / EXCHANGE_RATE[choiceCurrency]);
	remainderMoney = existingMoney - exchangedMoney * EXCHANGE_RATE[choiceCurrency];
	remainderMoney = remainderMoney - remainderMoney % 10;

	printf("환전 결과\n");
	switch (choiceCurrency) {
	case 1:
		printf("달러 : %d달러\n", exchangedMoney);
		break;
	case 2:
		printf("엔 : %d엔\n", exchangedMoney);
		break;
	case 3:
		printf("유로 : %d유로\n", exchangedMoney);
		break;
	case 4:
		printf("위안 : %d위안\n", exchangedMoney);
		break;
	case 5:
		printf("파운드 : %d파운드\n", exchangedMoney);
		break;
	}
	printf("거스름돈 : %d원\n", (remainderMoney));

	ShowChange(remainderMoney);

	return 0;
}