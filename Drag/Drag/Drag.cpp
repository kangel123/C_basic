#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// wallpaper_len�� �迭 wallpaper�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(size_t) * 4);

    return answer;
}

int main() {
    const char* wallpaper[3] = { ".#...", "..#..", "...#." };
    size_t wallpaper_len = strlen(wallpaper * wallpaper);

    int* result = (int*)malloc(sizeof(size_t) * wallpaper_len);
    result = solution(wallpaper, wallpaper_len);

    return 0;
}