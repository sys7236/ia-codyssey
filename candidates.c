#include <stdio.h>
#include <string.h>

// 후보자 구조체 정의
typedef struct {
    char name[50];
    char birthdate[11];
    char gender;
    char email[50];
    char nationality[20];
    float bmi;
    char main_skill[20];
    char sub_skill[20];
    int topik_level;
    char mbti[5];
    char introduction[256];
} Candidate;

// 후보자 정보를 입력받는 함수
void input_candidate_info(Candidate *candidate) {
    printf("\n성명을 입력하세요: ");
    scanf(" %[^\n]", candidate->name);

    printf("생일(YYYY/MM/DD 형식)을 입력하세요: ");
    scanf(" %[^\n]", candidate->birthdate);

    printf("성별(여성이면 F, 남성이면 M)을 입력하세요: ");
    scanf(" %c", &candidate->gender);

    printf("메일 주소를 입력하세요: ");
    scanf(" %[^\n]", candidate->email);

    printf("국적을 입력하세요: ");
    scanf(" %[^\n]", candidate->nationality);

    printf("BMI를 입력하세요: ");
    scanf("%f", &candidate->bmi);

    printf("주 스킬을 입력하세요: ");
    scanf(" %[^\n]", candidate->main_skill);

    printf("보조 스킬을 입력하세요: ");
    scanf(" %[^\n]", candidate->sub_skill);

    printf("한국어 등급(TOPIK)을 입력하세요: ");
    scanf("%d", &candidate->topik_level);

    printf("MBTI를 입력하세요: ");
    scanf(" %[^\n]", candidate->mbti);

    printf("자기소개를 입력하세요: ");
    scanf(" %[^\n]", candidate->introduction);
}

// 후보자 정보를 출력하는 함수
void display_candidate_info(Candidate candidate) {
    char topik_level[10];
    if (candidate.topik_level == 0) {
        strcpy(topik_level, "원어민");
    } else {
        sprintf(topik_level, "%d", candidate.topik_level);
    }

    printf("\n=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI  | 주스킬 | 보조스킬 | TOPIK | MBTI \n");
    printf("=============================================================================================\n");
    printf("%-6s | %-8s | %-3c | %-20s | %-4s | %-4.1f | %-5s | %-7s | %-6s | %-4s |\n",
           candidate.name, candidate.birthdate, candidate.gender, candidate.email, 
           candidate.nationality, candidate.bmi, candidate.main_skill, 
           candidate.sub_skill, topik_level, candidate.mbti);
    printf("        -------------------------------------------------------------------------------------\n");
    printf("%-94s |\n", candidate.introduction);
    printf("---------------------------------------------------------------------------------------------\n");
}

int main() {
    Candidate candidates[2];

    // 후보자 2명의 정보를 입력받음
    for (int i = 0; i < 2; i++) {
        printf("\n%d 번째 후보자의 정보를 입력합니다.\n", i + 1);
        input_candidate_info(&candidates[i]);
    }

    // 입력된 후보자 정보를 출력
    for (int i = 0; i < 2; i++) {
        display_candidate_info(candidates[i]);
    }

    return 0;
}
