#include <stdio.h>

int main() {
	int existingMoney, choiceCurrency, exchangedMoney, remainderMoney;
	float exchangeRate = 1;

	printf("환전을 원하는 금액을 입력하세요 (원화) : ");
	scanf_s("%d", &existingMoney);

	do {
		printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
		scanf_s("%d", &choiceCurrency);
	} while (choiceCurrency < 1 || choiceCurrency>5);

	switch (choiceCurrency) {
	case 1:
		exchangeRate = 1318.90;
		break;
	case 2:
		exchangeRate = 999.36;
		break;
	case 3:
		exchangeRate = 1438.79;
		break;
	case 4:
		exchangeRate = 191.61;
		break;
	case 5:
		exchangeRate = 1638.73;
		break;
	}

	printf("기준 환율 : %.2f\n", exchangeRate);
	exchangedMoney = (int)(existingMoney / exchangeRate);
	remainderMoney = existingMoney - exchangedMoney * exchangeRate;
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

	return 0;
}