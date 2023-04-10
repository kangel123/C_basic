#include <stdio.h>

int main() {
	int existingMoney, choiceCurrency, exchangedMoney, remainderMoney;
	float exchangeRate = 1;

	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ��� (��ȭ) : ");
	scanf_s("%d", &existingMoney);

	do {
		printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
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

	printf("���� ȯ�� : %.2f\n", exchangeRate);
	exchangedMoney = (int)(existingMoney / exchangeRate);
	remainderMoney = existingMoney - exchangedMoney * exchangeRate;
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

	return 0;
}