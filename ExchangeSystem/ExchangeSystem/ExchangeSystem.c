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
	
	printf("50000�� : %d\n", paperMoney50000);
	printf("10000�� : %d\n", paperMoney10000);
	printf("5000�� : %d\n", paperMoney5000);
	printf("1000�� : %d\n", paperMoney1000);
	printf("500�� : %d\n", paperMoney500);
	printf("100�� : %d\n", paperMoney100);
	printf("50�� : %d\n", paperMoney50);
	printf("10�� : %d\n", paperMoney10);
}

int main() {
	const float EXCHANGE_RATE[5] = { 1318.90, 999.36, 1438.79, 191.61, 1638.73};
	int existingMoney, choiceCurrency, exchangedMoney, remainderMoney;


	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ��� (��ȭ) : ");
	scanf_s("%d", &existingMoney);

	do {
		printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
		scanf_s("%d", &choiceCurrency);
	} while (choiceCurrency < 1 || choiceCurrency > 5);
	choiceCurrency--;

	printf("���� ȯ�� : %.2f\n", EXCHANGE_RATE[choiceCurrency]);
	exchangedMoney = (int)(existingMoney / EXCHANGE_RATE[choiceCurrency]);
	remainderMoney = existingMoney - exchangedMoney * EXCHANGE_RATE[choiceCurrency];
	remainderMoney = remainderMoney - remainderMoney % 10;

	printf("ȯ�� ���\n");
	switch (choiceCurrency) {
	case 1:
		printf("�޷� : %d�޷�\n", exchangedMoney);
		break;
	case 2:
		printf("�� : %d��\n", exchangedMoney);
		break;
	case 3:
		printf("���� : %d����\n", exchangedMoney);
		break;
	case 4:
		printf("���� : %d����\n", exchangedMoney);
		break;
	case 5:
		printf("�Ŀ�� : %d�Ŀ��\n", exchangedMoney);
		break;
	}
	printf("�Ž����� : %d��\n", (remainderMoney));

	ShowChange(remainderMoney);

	return 0;
}