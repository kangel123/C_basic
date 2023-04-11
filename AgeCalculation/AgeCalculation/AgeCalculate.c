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

    // 주민등록번호 유효성 검사
    if (strlen(residentRegistrationNumber) != 14) {
        printf("주민등록번호의 형식이 올바르지 않습니다.\n");
        return -1;
    }

    // 주민등록번호의 형식을 검사하여 올바르지 않은 경우 에러 처리
    for (int i = 0; i < 14; i++) {
        if (i == 6) continue; // '-'는 스킵
        if (residentRegistrationNumber[i] < '0' || residentRegistrationNumber[i] > '9') {
            printf("주민등록번호의 형식이 올바르지 않습니다.\n");
            return -1;
        }
    }

    sscanf(residentRegistrationNumber, "%6d", &birthDate); // 생년월일 추출

    // 성별에 따른 출생년도 계산
    char gender = residentRegistrationNumber[7];
    if (gender == '1' || gender == '2' || gender == '5' || gender == '6') {
        yearOfBirth = birthDate / 10000 + 1900;
    }
    else if (gender == '3' || gender == '4' || gender == '7' || gender == '8') {
        yearOfBirth = birthDate / 10000 + 2000;
    }
    else {
        printf("주민번호 뒷자리의 첫 번째 숫자를 잘못 입력하였습니다.\n");
        return -1; // 예외 처리: 잘못된 숫자 입력
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

    printf("주민등록번호를 입력하세요: ");
    scanf("%s", residentRegistrationNumber);

    int age = findAge(residentRegistrationNumber);
    if (age >= 0) {
        printf("만 나이로 %d살입니다.\n", age);
    }
    else {
        printf("주민등록번호 처리 중 에러가 발생하였습니다.\n");
        return 1; // 에러 코드 1 반환
    }

    return 0;
}
