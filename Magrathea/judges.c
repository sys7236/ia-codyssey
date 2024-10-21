#include <stdio.h>
#include <stdlib.h>

int main() {
    char project_name[100];
    char judges_array[5][512]; // 5명의 심사자를 위한 고정 크기 배열
    int judge_count = 5;
    int selected_judges = 4; // 선발된 심사자 수의 기본값
    char choice;
    char buffer[512];

    // 초기 입력 화면 표시
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin); // 프로젝트 이름 입력

    // 프로젝트 이름에서 줄 바꿈 문자 수동 제거
    int i = 0;
    while (project_name[i] != '\0' && project_name[i] != '\n') {
        i++;
    }
    project_name[i] = '\0'; // 문자열 끝에 NULL 문자 추가

    printf("> 심사 풀 인원: %d\n", judge_count);
    printf("> 선발 멤버 수: %d\n", selected_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_count);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 각 심사자의 정보 입력
    for (i = 0; i < judge_count; i++) {
        printf("*심사자 %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin); // 공백 및 긴 입력 처리를 위한 fgets 사용
        if (buffer[0] == '\n') {
            i--; // 입력이 비어 있으면 건너뜀
            printf("입력이 누락되었습니다. 다시 입력해주세요.\n");
            continue;
        }
        // buffer의 내용을 judges_array에 수동으로 복사
        int j = 0;
        while (buffer[j] != '\0') {
            judges_array[i][j] = buffer[j];
            j++;
        }
        judges_array[i][j] = '\0'; // 문자열 끝에 NULL 문자 추가
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀을 출력할지 여부 묻기
    printf("심사자 풀을 확인할까요? (Y/N): ");
    scanf(" %c", &choice); // Y/N 입력 받기
    if (choice == 'Y' || choice == 'y') {
        // 심사자 풀 데이터 출력
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (i = 0; i < judge_count; i++) {
            printf("[심사자 %d]\n", i + 1);

            int j = 0;
            while (judges_array[i][j] != '\0') {
                if (judges_array[i][j] == ',') {
                    printf("\n"); // 각 콤마 뒤에 줄 바꿈 추가
                } else {
                    printf("%c", judges_array[i][j]);
                }
                j++;
            }
            printf("-----------------------------------\n");
        }
    }

    return 0;
}
