#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int findAge(const char* residentRegistrationNumber) {
    int age;
    int birthDate, yearOfBirth, monthAndDayOfBirth;
    struct tm* t;
    time_t now = time(NULL);

    // �ֹε�Ϲ�ȣ ��ȿ�� �˻�
    if (strlen(residentRegistrationNumber) != 14) {
        printf("�ֹε�Ϲ�ȣ�� ������ �ùٸ��� �ʽ��ϴ�.\n");
        return -1;
    }

    // �ֹε�Ϲ�ȣ�� ������ �˻��Ͽ� �ùٸ��� ���� ��� ���� ó��
    for (int i = 0; i < 14; i++) {
        if (i == 6) continue; // '-'�� ��ŵ
        if (residentRegistrationNumber[i] < '0' || residentRegistrationNumber[i] > '9') {
            printf("�ֹε�Ϲ�ȣ�� ������ �ùٸ��� �ʽ��ϴ�.\n");
            return -1;
        }
    }

    sscanf(residentRegistrationNumber, "%6d", &birthDate); // ������� ����

    // ������ ���� ����⵵ ���
    char gender = residentRegistrationNumber[7];
    if (gender == '1' || gender == '2' || gender == '5' || gender == '6') {
        yearOfBirth = birthDate / 10000 + 1900;
    }
    else if (gender == '3' || gender == '4' || gender == '7' || gender == '8') {
        yearOfBirth = birthDate / 10000 + 2000;
    }
    else {
        printf("�ֹι�ȣ ���ڸ��� ù ��° ���ڸ� �߸� �Է��Ͽ����ϴ�.\n");
        return -1; // ���� ó��: �߸��� ���� �Է�
    }

    monthAndDayOfBirth = birthDate % 10000;
    t = localtime(&now);

    age = t->tm_year + 1900 - yearOfBirth;
    if (monthAndDayOfBirth > (t->tm_mon + 1) * 100 + t->tm_mday) {
        age -= 1;
    }

    return age;
}

int main() {
    char residentRegistrationNumber[15];

    printf("�ֹε�Ϲ�ȣ�� �Է��ϼ���: ");
    scanf("%s", residentRegistrationNumber);

    int age = findAge(residentRegistrationNumber);
    if (age >= 0) {
        printf("�� ���̷� %d���Դϴ�.\n", age);
    }
    else {
        printf("�ֹε�Ϲ�ȣ ó�� �� ������ �߻��Ͽ����ϴ�.\n");
        return 1; // ���� �ڵ� 1 ��ȯ
    }

    return 0;
}
