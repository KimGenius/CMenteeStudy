//
// Created by young on 2014-07-29.
//
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define EMPTY 0

//게임들
int su();

int Ran();

int Card();

int Dice();

int Ru();

int In1();

int In2();

int In3();

int In4();

//게임 설치 목록
int Mi();

int Ra();

int Ca();

int Di();

int Ru();

int Su();

//그러하다
int main2();

int HPan();

int HHPan();

int APan();

int H2Pan();

typedef struct hero {
    short x;
    short y;
} HERO, *PHERO;

void gotoxy(int x, int y) {
    COORD Cur = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

typedef struct node {
    int x;
    int y;
    struct node *link;
} Stack;

Stack *Getnode() {
    Stack *tmp;
    tmp = (Stack *) malloc(sizeof(Stack));
    tmp->link = 0;
    return tmp;
}

void Push(Stack **top, HERO hr) {
    Stack *tmp;
    tmp = *top;

    *top = Getnode();

    (*top)->x = hr.x;
    (*top)->y = hr.y;
    (*top)->link = tmp;
}

HERO Pop(Stack **top) {
    Stack *tmp;
    HERO dt;

    if (*top == EMPTY) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("끄~읕!!! ^-^\n");
        exit(0);
    }
    tmp = *top;
    dt.x = tmp->x;
    dt.y = tmp->y;

    *top = (*top)->link;

    free(tmp);
    return dt;
}


void print_MAP(int MAP[20][20], HERO hr) {
    int i, j;
    gotoxy(0, 0);
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (MAP[i][j] == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                printf("■");
            } else if (MAP[i][j] == 1) {
                printf("  ");
            } else if (MAP[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("§");
            } else if (MAP[i][j] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("▣"); //주사위
            } else if (MAP[i][j] == 4) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("◈"); //숫자야구
            } else if (MAP[i][j] == 5) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("★"); //카드게임
            } else if (MAP[i][j] == 6) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("※"); //주사위 보드게임
            } else if (MAP[i][j] == 7) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                printf("♧"); //러시안 룰렛
            }
        }
        printf("\n");
    }
    gotoxy(hr.x, hr.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("☆");
}


int main(void) {
    HERO hr;
    HERO he;
    int a = 0, i, sum, num;
    Stack *top = EMPTY;
    int MAP[20][20] = {
            {3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {4, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {5, 1, 2, 0, 0, 1, 1, 0, 6, 6, 6, 6, 0, 0, 0, 0, 0, 1, 0, 0},
            {6, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {7, 1, 1, 0, 1, 1, 1, 3, 3, 3, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 6, 1, 1, 2},
            {0, 1, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 6, 1, 6, 0},
            {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 0, 1, 0, 3, 1, 4, 0},
            {0, 2, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 0, 1, 0, 3, 1, 4, 0},
            {0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 3, 1, 4, 0},
            {0, 1, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 3, 1, 4, 0},
            {0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 4, 4, 0, 0, 1, 0, 3, 1, 4, 0},
            {0, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 2, 2, 0, 0},
            {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 2, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 5, 2, 5, 1, 0},
            {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 2, 5, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    hr.x = 2;
    hr.y = 0;
    gotoxy(20, 15);
    main2();
    system("cls");
    srand((unsigned) time(NULL));
    menu:
    printf("===================================All Game===================================\n");
    printf("===================================MENU===================================\n");
    printf("1.게임시작!!!\n");
    printf("2.이 게임은 뭘까??\n");
    printf("3.제 작 진\n");
    printf("4.이제 그만\n");
    scanf("%d", &num);
    while (num > 4 || num < 1) {
        printf("선택할수 있는 수는 1~4뿐입니다\n다시 입력해주세요");
        scanf("%d", &num);
    }
    switch (num) {
        case 1:
            system("cls");
            while (1) {
                sum = getchar();
                if (sum == 224)
                    sum = getchar();
                a++;
                if (sum == 72) {
                    if (MAP[hr.y - 1][hr.x / 2] == 1) {
                        hr.y = hr.y - 1;
                        Push(&top, hr);
                    } else if (MAP[hr.y - 1][hr.x / 2] == 2) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        for (i = 0; i <= a; i++) {
                            gotoxy(50, i);
                            he = Pop(&top);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            printf("%d / %d", he.x, he.y);
                            Sleep(100);
                        }
                    } else if (MAP[hr.y - 1][hr.x / 2] == 3) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ran();
                    } else if (MAP[hr.y - 1][hr.x / 2] == 4) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        su();
                    } else if (MAP[hr.y - 1][hr.x / 2] == 5) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Card();
                    } else if (MAP[hr.y - 1][hr.x / 2] == 6) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Dice();
                    } else if (MAP[hr.y - 1][hr.x / 2] == 7) {
                        hr.y = hr.y - 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ru();
                    }
                } else if (sum == 80) {
                    if (MAP[hr.y + 1][hr.x / 2] == 1) {
                        hr.y = hr.y + 1;
                        Push(&top, hr);
                    } else if (MAP[hr.y + 1][hr.x / 2] == 2) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        for (i = 0; i <= a; i++) {
                            gotoxy(50, i);
                            he = Pop(&top);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            printf("%d / %d", he.x, he.y);
                            Sleep(100);
                        }
                    } else if (MAP[hr.y + 1][hr.x / 2] == 3) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ran();
                    } else if (MAP[hr.y + 1][hr.x / 2] == 4) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        su();
                    } else if (MAP[hr.y + 1][hr.x / 2] == 5) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Card();
                    } else if (MAP[hr.y + 1][hr.x / 2] == 6) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Dice();
                    } else if (MAP[hr.y + 1][hr.x / 2] == 7) {
                        hr.y = hr.y + 1;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ru();
                    }
                } else if (sum == 77) {

                    if (MAP[hr.y][(hr.x / 2) + 1] == 1) {
                        hr.x = hr.x + 2;
                        Push(&top, hr);
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 2) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        for (i = 0; i <= a; i++) {
                            gotoxy(50, i);
                            he = Pop(&top);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            printf("%d / %d", he.x, he.y);
                            Sleep(100);
                        }
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 3) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ran();
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 4) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        su();
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 5) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Card();
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 6) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Dice();
                    } else if (MAP[hr.y][(hr.x / 2) + 1] == 7) {
                        hr.x = hr.x + 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ru();
                    }
                } else if (sum == 75) {

                    if (MAP[hr.y][hr.x / 2 - 1] == 1) {
                        hr.x = hr.x - 2;
                        Push(&top, hr);
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 2) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        for (i = 0; i <= a; i++) {
                            gotoxy(50, i);
                            he = Pop(&top);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                            printf("%d / %d", he.x, he.y);
                            Sleep(100);
                        }
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 3) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ran();
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 4) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        su();
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 5) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Card();
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 6) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Dice();
                    } else if (MAP[hr.y][hr.x / 2 - 1] == 7) {
                        hr.x = hr.x - 2;
                        print_MAP(MAP, hr);
                        system("cls");
                        printf("!!!!");
                        getchar();
                        system("cls");
                        Ru();
                    }
                }
                print_MAP(MAP, hr);
            }
            break;
        case 2:
            system("cls");
            printf("이 게임은 제작자가 지금까지 만든 게임을 조합하여 만든 것으로\n미로게임을 기반한 형식입니다\n");
            printf("========================기 호 설 명========================\n");
            printf("☆은 자신의 캐릭터입니다! 방향키로 움직일수 있습니다\n");
            printf("§은 출구 입니다! 여기로 가면 게임이 끝나게 됩니다\n");
            printf("■는 벽입니다! 여기로는 갈수 없습니다\n");
            printf("▣는 주사위 게임입니다! 여기로 가면 주사위게임이 시작되며 랜덤으로 6번의 주사위를 굴려서 ai와 대전을 합니다!\n");
            printf("◈은 숫자야구 게임입니다! ai가 랜덤으로 만든 숫자를 주어진 기회안에 맞추면됩니다!\n");
            printf("★은 카드게임입니다! 이게임은 2인용 게임이며 Black과 White팀으로 나눠서 게임을 하게됩니다!\n");
            printf("※는 주사위(보드)게임입니다! 이게임은 2인용과 Ai모드로 나누어져있어서 선택해서 게임을 하게됩니다!\n");
            printf("♧은 러시안룰렛 게임입니다! 이게임은 최대4인용과 Ai모드로 나누어져있어서 선택해서 게임을 하게됩니다!\n");
            printf("===========================================================\n");
            printf("자 그럼 즐겁게 게임을 즐겨주시길 바랍니다~! ^_^");
            getchar();
            system("cls");
            goto menu;
            break;
        case 3:
            system("cls");
            printf("==============================================================================\n\t\t\t제 작 진\n==============================================================================\n");
            printf("\n\t\t\t만든이:김영재\n\n\t\t\t아이디어:정기완\n\n\t\t\t카드판별코드아이디어:배현빈\n\n\t\t\t제작시간: 총합 약 20시간50분\n\n");
            printf("==============================================================================\n");
            getchar();
            system("cls");
            goto menu;
            break;
        case 4:
            exit(0);
    }
    return 0;
}

int main2() {
    int i, a, y = 0;
    int mi = 0, ca = 0, di = 0, ru = 0, su = 0, D = 0;
    srand((unsigned int) time(NULL));
    printf("로딩중....");
    for (i = 0; i < 30; i++) {
        a = (rand() % 3 + 1);
        if (a == 1) {
            printf("/");
            Sleep(100);
        } else if (a == 2) {
            y = 0;
            while (y < 3) {
                printf("/");
                Sleep(100);
                y++;
            }
        } else if (a == 3) {
            y = 0;
            while (y < 5) {
                printf("/");
                Sleep(100);
                y++;
            }
        }
    }
    printf("\n로딩완료!!!\n아무키나 누르세요....");
    getchar();
    system("cls");
    return 0;
}


int su(void) {
    int i, yum, j, k, t;
    int sum[5], num[5];
    int strike, ball;
    srand((unsigned int) time(NULL));
    ball = 0;
    strike = 0;
    printf("\t==========The 2nd GameMaker==========\n");
    printf("\t=========The==Number==Baseball========\n");
    getchar();
    system("cls");
    printf("숫자 야구 게임\n1.쉬움 2.보통 3.어려움4.나갈래");
    printf("\n난이도 선택:");
    scanf("%d", &k);
    switch (k) {
        case 1:
            printf("쉬움 단계 입니다.\n이단계는 총 3개의 숫자로 이루어지며 \n기회는 자신이 정합니다.");
            printf("\n기회를 몇번 하시겠습니까?:");
            scanf("%d", &yum);
            printf("%d번의 기회가 주어졌습니다.", yum);
            sum[0] = rand() % 10;
            sum[1] = rand() % 10;
            while (sum[0] == sum[1]) {
                sum[1] = rand() % 10;
            }
            sum[2] = rand() % 10;
            while (sum[2] == sum[1] || sum[2] == sum[0]) {
                sum[2] = rand() % 10;
            }
            getchar();
            system("cls");
            printf("ai가 랜덤으로 숫자를 뽑았습니다.\n");
            for (i = 0; i < yum; i++) {
                cs1:
                printf("%d번째 도전입니다.\n3개의 숫자(0~9까지)를 입력하세요", i);
                scanf("%d", &num[0]);
                scanf("%d", &num[1]);
                scanf("%d", &num[2]);
                while (num[0] == num[1]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d", &num[0], &num[1], &num[2]);
                }
                while (num[0] == num[2] || num[1] == num[2]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d", &num[0], &num[1], &num[2]);
                }
                while ((num[0] > 9 || num[1] > 9) || num[2] > 9) {

                    printf("9보다 작은수를 입력해주세요\n다시입력");
                    scanf("%d%d%d", &num[0], &num[1], &num[2]);
                }
                for (j = 0; j < 3; j++) {
                    if (sum[j] == num[j])
                        strike++;
                    else if (sum[(j + 1) % 3] == num[j])
                        ball++;
                    else if (sum[(j + 2) % 3] == num[j])
                        ball++;
                }
                system("cls");
                printf("\t결과\n");
                printf("%dstrike %dball\n", strike, ball);
                if (strike < 3) {
                    printf("다시시도하세요...\n");
                    strike = 0;
                    ball = 0;
                    goto cs1;
                } else {
                    printf("축하드립니다. 당신은 쉬움단계를 클리어하였습니다!!!\n");
                }
                getchar();
                system("cls");
                break;
            }
            break;
        case 2:
            printf("보통 단계 입니다.\n이단계는 총 4개의 숫자로 이루어지며 \n기회는 20번 입니다.");
            sum[0] = rand() % 10;
            sum[1] = rand() % 10;
            while (sum[0] == sum[1]) {
                sum[1] = rand() % 10;
            }
            sum[2] = rand() % 10;
            while (sum[2] == sum[1] || sum[2] == sum[0]) {
                sum[2] = rand() % 10;
            }
            sum[3] = rand() % 10;
            while ((sum[0] == sum[3] || sum[1] == sum[3]) || sum[2] == sum[3]) {
                sum[3] = rand() % 10;
            }
            getchar();
            system("cls");
            printf("ai가 랜덤으로 숫자를 뽑았습니다.\n");
        cs2:
            for (i = 0; i < 20; i++) {
                printf("%d번째 도전입니다.\n4개의 숫자(0~9까지)를 입력하세요", i);
                scanf("%d", &num[0]);
                scanf("%d", &num[1]);
                scanf("%d", &num[2]);
                scanf("%d", &num[3]);
                while (num[0] == num[1]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);
                }
                while (num[0] == num[2] || num[1] == num[2]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);
                }
                while (num[0] == num[3] || (num[1] == num[3] || num[2] == num[3])) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);
                }

                while ((num[0] > 9 || num[1] > 9) || (num[2] > 9 || num[3] > 9)) {

                    printf("9보다 작은수를 입력해주세요\n다시입력");
                    scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);
                }
                for (j = 0; j < 4; j++) {
                    if (sum[j] == num[j])
                        strike++;
                    else if (sum[(j + 1) % 4] == num[j]) //0=1 1=2 2=3 3=0
                        ball++;
                    else if (sum[(j + 2) % 4] == num[j]) //0=2 1=3 2=0 3=1
                        ball++;
                    else if (sum[(j + 3) % 4] == num[j]) //0=3 1=0 2=1 3=2
                        ball++;
                }
                system("cls");
                printf("\t결과\n");
                printf("%dstrike %dball\n", strike, ball);
                if (strike < 4) {
                    printf("다시시도하세요...\n");
                    strike = 0;
                    ball = 0;
                    goto cs2;
                } else {
                    printf("축하드립니다. 당신은 보통단계를 클리어하였습니다!!!\n");

                }
                getchar();
                system("cls");
                break;
            }
            break;
        case 3:
            printf("어려움 단계 입니다.\n이단계는 총 4개의 숫자로 이루어지며 \n기회는 1번타입(rand(1~41)과 2번(25) 타입이 있습니다.");
            printf("타입을 고르세요:");
            scanf("%d", &t);
            if (t == 1) {
                yum = rand() % 41;
            } else if (t == 2) {
                yum = 25;
            }
            printf("\n당신의 기회는 %d입니다.", yum);
            sum[0] = rand() % 10;
            sum[1] = rand() % 10;
            while (sum[0] == sum[1]) {
                sum[1] = rand() % 10;
            }
            sum[2] = rand() % 10;
            while (sum[2] == sum[1] || sum[2] == sum[0]) {
                sum[2] = rand() % 10;
            }
            sum[3] = rand() % 10;
            while ((sum[0] == sum[3] || sum[1] == sum[3]) || sum[2] == sum[3]) {
                sum[3] = rand() % 10;
            }
            sum[4] = rand() % 10;
            while ((sum[0] == sum[4] || sum[1] == sum[4]) || (sum[2] == sum[4] || sum[3] == sum[4])) {
                sum[4] = rand() % 10;
            }
            getchar();
            system("cls");
            printf("ai가 랜덤으로 숫자를 뽑았습니다.\n");
        cs3:
            for (i = 0; i < yum; i++) {
                printf("%d번째 도전입니다.\n5개의 숫자(0~9까지)를 입력하세요", i);
                scanf("%d", &num[0]);
                scanf("%d", &num[1]);
                scanf("%d", &num[2]);
                scanf("%d", &num[3]);
                scanf("%d", &num[4]);
                while (num[0] == num[1]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
                }
                while (num[0] == num[2] || num[1] == num[2]) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
                }
                while (num[0] == num[3] || (num[1] == num[3] || num[2] == num[3])) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
                }
                while ((num[0] == num[4] || num[3] == num[4]) || (num[1] == num[4] || num[2] == num[4])) {
                    printf("중복은 안됩니다.\n다시입력");
                    scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
                }

                while ((num[0] > 9 || num[1] > 9) || (num[2] > 9 || num[3] > 9) || num[4] > 9) {

                    printf("9보다 작은수를 입력해주세요\n다시입력");
                    scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
                }
                for (j = 0; j < 5; j++) {
                    if (sum[j] == num[j])
                        strike++;
                    else if (sum[(j + 1) % 5] == num[j]) //0=1 1=2 2=3 3=4 4=0
                        ball++;
                    else if (sum[(j + 2) % 5] == num[j]) //0=2 1=3 2=4 3=0 4=1
                        ball++;
                    else if (sum[(j + 3) % 5] == num[j]) //0=3 1=4 2=0 3=1 4=2
                        ball++;
                    else if (sum[(j + 4) % 5] == num[j]) //0=4 1=0 2=1 3=2 4=3
                        ball++;
                }
                system("cls");
                printf("\t결과\n");
                printf("%dstrike %dball\n", strike, ball);
                if (strike < 5) {
                    printf("다시시도하세요...\n");
                    strike = 0;
                    ball = 0;
                    goto cs3;
                } else {
                    printf("축하드립니다. 당신은 어려움단계를 클리어하였습니다!!!\n");


                }
                getchar();
                system("cls");
                break;
                case 4:
                    break;
            }
            break;
    }
    return 0;
}


int Ran() {
    int i[6], b, sum, num, a[6], t;

    while (1) {
        printf("\t==========The First GameMaker==========\n");
        printf("\t==========The===Dice===Game==========\n");
        getchar();
        system("cls");
        sum = 0;
        num = 0;
        srand((unsigned) time(NULL));
        printf("난이도를 선택하세요...\n1. 쉬움\n2. 보통\n3. 중간\n4. 어려움\n5. 많이어려움\n6. 이걸 깨라고 만듬?\n7. 나갈래\n");
        scanf("%d", &t);
        system("cls");
        switch (t) {
            case 1:
                printf("쉬움 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6 + 1;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 4;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 2:
                printf("보통 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6 + 1;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 5;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 3:
                printf("중간 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6 + 1;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 6 + 1;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 4:
                printf("어려움 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 6 + 1;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 5:
                printf("많이 어려움 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 7 + 1;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 6:
                printf("이걸 깨라고 만듬? 난이도 입니다.\n");
                printf("당신의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    i[b] = rand() % 6;
                    printf("%d\t", i[b]);
                }
                printf("\n\n");
                sum = i[0] + i[1] + i[2] + i[3] + i[4] + i[5];

                printf("봇의 주사위는\n");
                for (b = 0; b < 6; b++) {
                    a[b] = rand() % 8 + 2;
                    printf("%d\t", a[b]);
                }
                printf("\n\n");
                num = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
                printf("당신의 합계는 %d입니다.\n", sum);
                printf("봇의 합계는 %d입니다.\n", num);
                if (sum < num) {
                    printf("패배");
                } else if (num < sum) {
                    printf("승리");
                } else {
                    printf("무승부");
                }
                getchar();
                system("cls");
                break;
            case 7:
                break;
        }
        break;
    }
    return 0;
}

int Card() {
    int q/*차례*/, bl = 5, wl = 5, ra/*rand*/, REF = 0, ATT = 0, SHI = 0, Ref = 0, Att = 0, Shi = 0;
    int b, b2, b3, s, d, f, a, z;            // b,b2,b3=Black	s,d,f=White	a,z=카드개수
    printf("\t==========The 3th GameMaker==========\n");
    printf("\t=========Black========White==========\n");
    getchar();
    system("cls");
    srand((unsigned int) time(NULL));
    while (1) {
        op:
        printf("=================MENU=================\n");
        printf("1.Black First\n");
        printf("2.While First\n");
        printf("3.게임방법\n");
        printf("4.제작진\n");
        printf("5.종료");
        scanf("%d", &q);
        st:
        system("cls");
        switch (q) {
            case 1: //블랙
                printf("Black의 차례입니다.");
                printf("\n랜덤으로 카드를 뽑습니다...");
                ra = rand() % 7 + 1;
                if (ra == 1 || ra == 3 || ra == 6) {
                    ATT++;
                    printf("공격 카드가 나왔습니다!");
                } else if (ra == 2 || ra == 4 || ra == 7) {
                    SHI++;
                    printf("방어 카드가 나왔습니다!");
                } else if (ra == 5) {
                    REF++;
                    printf("반사 카드!!!");
                }
                getchar();
                system("cls");
                printf("당신이 보유하고 있는 카드는\n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", ATT, SHI, REF);
                printf("몇개의 카드를 쓰시겠습니까?");
                scanf("%d", &a);
                while (a < 0 || a > 3) {
                    printf("다시입력하세요");
                    scanf("%d", &a);
                }
                if (a == 0) {
                    printf("카드를 뽑지않고 넘어갑니다.\n\n");
                    goto ts;
                } else if (a == 1) {
                    printf("한장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\nex)Attack을 쓰려면 1\n");
                    st1:
                    scanf("%d", &b);
                    while (b > 3 || b < 0) {
                        printf("다시 입력해주세요...");
                        scanf("%d", &b);
                    }
                    if (b == 1 && ATT > 0) {
                        printf("Attack!!!\n");
                        ATT--;
                    } else if (b == 2 && SHI > 0) {
                        printf("Shield!!!\n");
                        SHI--;
                    } else if (b == 3 && REF > 0) {
                        printf("Reflect!!!\n");
                        REF--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st1;
                    }
                } else if (a == 2) {
                    printf("두장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    st2:
                    scanf("%d%d", &b, &b2);
                    while ((b > 3 || b < 0) || (b2 > 3 || b2 < 0)) {
                        printf("다시 입력해주세요...");
                        scanf("%d%d", &b, &b2);
                    }
                    if ((b == 1 && b2 == 2) && (SHI > 0 && ATT > 0)) {
                        printf("Shield!!!\n");
                        SHI--;
                        printf("Attack!!!\n");
                        ATT--;
                    } else if ((b == 2 && b2 == 3) && (SHI > 0 && REF > 0)) {
                        printf("Shield!!!\nReflect!!!\n");
                        SHI--;
                        REF--;
                    } else if ((b == 1 && b2 == 3) && (ATT > 0 && REF > 0)) {
                        printf("Attack!!!\n");
                        ATT--;
                        printf("Reflect!!!\n");
                        REF--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st2;
                    }
                } else if ((a == 3 && ATT > 0) && (SHI > 0 && REF > 0)) {
                    printf("세장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    scanf("%d%d%d", &b, &b2, &b3);
                    printf("Attack!\nShield!\nReflect!\n");
                    ATT--;
                    SHI--;
                    REF--;
                }
            ts:
                printf("당신에게 남은 카드는 \n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", ATT, SHI, REF);
                getchar();
                system("cls");
                //White
                printf("White의 차례입니다.");
                printf("\n랜덤으로 카드를 뽑습니다...");
                ra = rand() % 7 + 1;
                if (ra == 1 || ra == 3 || ra == 6) {
                    Att++;
                    printf("공격 카드가 나왔습니다!");
                } else if (ra == 2 || ra == 4 || ra == 7) {
                    Shi++;
                    printf("방어 카드가 나왔습니다!");
                } else if (ra == 5) {
                    Ref++;
                    printf("반사 카드!!!");
                }
                getchar();
                system("cls");
                printf("당신이 보유하고 있는 카드는\n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", Att, Shi, Ref);
                printf("몇개의 카드를 쓰시겠습니까?");
                scanf("%d", &z);
                while (z < 0 || z > 3) {
                    printf("다시입력하세요");
                    scanf("%d", &z);
                }
                if (z == 0) {
                    printf("카드를 뽑지않고 넘어갑니다.\n\n");
                    goto ts1;
                }
                if (z == 1) {
                    printf("한장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...");
                    st3:
                    scanf("%d", &s);
                    while (s < 0 || s > 3) {
                        printf("다시 입력해주세요...");
                        scanf("%d", &s);
                    }
                    if (s == 1 && Att > 0) {
                        printf("Attack!!!\n");
                        Att--;
                    } else if (s == 2 && Shi > 0) {
                        printf("Shield!!!\n");
                        Shi--;
                    } else if (s == 3 && Ref > 0) {
                        printf("Reflect!!!\n");
                        Ref--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st3;
                    }
                } else if (z == 2) {
                    printf("두장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...");
                    st4:
                    scanf("%d%d", &s, &d);
                    while (s < 0 || s > 3) {
                        printf("다시 입력해주세요...");
                        scanf("%d%d", &s, &d);
                    }
                    if ((s == 1 && d == 2) && (Shi > 0 && Att > 0)) {
                        printf("Shield!!!\n");
                        Shi--;
                        printf("Attack!!!\n");
                        Att--;
                    } else if ((s == 2 && d == 3) && (Shi > 0 && Ref > 0)) {
                        printf("Shield!!!\nReflect!!!\n");
                        Shi--;
                        Ref--;
                    } else if ((s == 3 && d == 1) && (Att > 0 && Ref > 0)) {
                        printf("Attack!!!\n");
                        Att--;
                        printf("Reflect!!!\n");
                        Ref--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st4;
                    }
                } else if ((z == 3 && Att > 0) && (Shi > 0 && Ref > 0)) {
                    printf("세장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    scanf("%d%d%d", &s, &d, &f);
                    printf("Attack!\nShield!\nReflect!\n");
                    Att--;
                    Shi--;
                    Ref--;
                }
            ts1:
                printf("당신에게 남은 카드는 \n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", Att, Shi, Ref);
                getchar();
                system("cls");
                break;
            case 2:
                //White
                printf("White의 차례입니다.");
                printf("\n랜덤으로 카드를 뽑습니다...");
                ra = rand() % 7 + 1;
                if (ra == 1 || ra == 3 || ra == 6) {
                    Att++;
                    printf("공격 카드가 나왔습니다!");
                } else if (ra == 2 || ra == 4 || ra == 7) {
                    Shi++;
                    printf("방어 카드가 나왔습니다!");
                } else if (ra == 5) {
                    Ref++;
                    printf("반사 카드!!!");
                }
                getchar();
                system("cls");
                printf("당신이 보유하고 있는 카드는\n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", Att, Shi, Ref);
                printf("몇개의 카드를 쓰시겠습니까?");
                scanf("%d", &z);
                while (z < 0 || z > 3) {
                    printf("다시입력하세요");
                    scanf("%d", &z);
                }
                if (z == 0) {
                    printf("카드를 뽑지않고 넘어갑니다.\n\n");
                    goto ts2;
                }
                if (z == 1) {
                    printf("한장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...");
                    st5:
                    scanf("%d", &s);
                    while (s < 0 || s > 3) {
                        printf("다시 입력해주세요...");
                        goto st5;
                    }
                    if (s == 1 && Att > 0) {
                        printf("Attack!!!\n");
                        Att--;
                    } else if (s == 2 && Shi > 0) {
                        printf("Shield!!!\n");
                        Shi--;
                    } else if (s == 3 && Ref > 0) {
                        printf("Reflect!!!\n");
                        Ref--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st5;
                    }
                } else if (z == 2) {
                    printf("두장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...");
                    st6:
                    scanf("%d%d", &s, &d);
                    while (s < 0 || s > 3) {
                        printf("다시 입력해주세요...");
                        scanf("%d%d", &s, &d);
                    }
                    if ((s == 1 && d == 2) && (Shi > 0 && Att > 0)) {
                        printf("Shield!!!\n");
                        Shi--;
                        printf("Attack!!!\n");
                        Att--;
                    } else if ((s == 2 && d == 3) && (Shi > 0 && Ref > 0)) {
                        printf("Shield!!!\nReflect!!!\n");
                        Shi--;
                        Ref--;
                    } else if ((s == 3 && d == 1) && (Att > 0 && Ref > 0)) {
                        printf("Attack!!!\n");
                        Att--;
                        printf("Reflect!!!\n");
                        Ref--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st6;
                    }
                } else if ((z == 3 && Att > 0) && (Shi > 0 && Ref > 0)) {
                    printf("세장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    scanf("%d%d%d", &s, &d, &f);
                    printf("Attack!\nShield!\nReflect!\n");
                    Att--;
                    Shi--;
                    Ref--;
                }
            ts2:
                printf("당신에게 남은 카드는 \n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", Att, Shi, Ref);
                getchar();
                system("cls");
                // 블랙
                printf("Black의 차례입니다.");
                printf("\n랜덤으로 카드를 뽑습니다...");
                ra = rand() % 7 + 1;
                if (ra == 1 || ra == 3 || ra == 6) {
                    ATT++;
                    printf("공격 카드가 나왔습니다!");
                } else if (ra == 2 || ra == 4 || ra == 7) {
                    SHI++;
                    printf("방어 카드가 나왔습니다!");
                } else if (ra == 5) {
                    REF++;
                    printf("반사 카드!!!");
                }
                getchar();
                system("cls");
                printf("당신이 보유하고 있는 카드는\n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", ATT, SHI, REF);
                printf("몇개의 카드를 쓰시겠습니까?");
                scanf("%d", &a);
                while (a < 0 || a > 3) {
                    printf("다시입력하세요");
                    scanf("%d", &a);
                }
                if (a == 0) {
                    printf("카드를 쓰지않고 넘어갑니다.\n\n");
                    goto ts3;
                } else if (a == 1) {
                    printf("한장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\nex)Attack을 쓰려면 1\n");
                    st7:
                    scanf("%d", &b);
                    while (b > 3 || b < 0) {
                        printf("다시 입력해주세요...");
                        scanf("%d", &b);
                    }
                    if (b == 1 && ATT > 0) {
                        printf("Attack!!!\n");
                        ATT--;
                    } else if (b == 2 && SHI > 0) {
                        printf("Shield!!!\n");
                        SHI--;
                    } else if (b == 3 && REF > 0) {
                        printf("Reflect!!!\n");
                        REF--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st7;
                    }
                } else if (a == 2) {
                    printf("두장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    st8:
                    scanf("%d%d", &b, &b2);
                    while ((b > 3 || b < 0) || (b2 > 3 || b2 < 0)) {
                        printf("다시 입력해주세요...");
                        scanf("%d%d", &s, &d);
                    }
                    if ((b == 1 && b2 == 2) && (SHI > 0 && ATT > 0)) {
                        printf("Shield!!!\n");
                        SHI--;
                        printf("Attack!!!\n");
                        ATT--;
                    } else if ((b == 2 && b2 == 3) && (SHI > 0 && REF > 0)) {
                        printf("Shield!!!\nReflect!!!\n");
                        SHI--;
                        REF--;
                    } else if ((b == 1 && b2 == 3) && (ATT > 0 && REF > 0)) {
                        printf("Attack!!!\n");
                        ATT--;
                        printf("Reflect!!!\n");
                        REF--;
                    } else {
                        printf("입력하신 카드가 없습니다.\n");
                        goto st8;
                    }
                } else if ((a == 3 && ATT > 0) && (SHI > 0 && REF > 0)) {
                    printf("세장의 카드를 씁니다.\n이번엔 어떤 종류의 카드를 쓸지 골라주세요...\n");
                    scanf("%d%d%d", &b, &b2, &b3);
                    printf("Attack!\nShield!\nReflect!\n");
                    ATT--;
                    SHI--;
                    REF--;
                }
            ts3:
                printf("당신에게 남은 카드는 \n1.공격:%d개\n2.방어:%d개\n3.반사:%d개\n입니다.\n", ATT, SHI, REF);
                getchar();
                system("cls");
                break;
            case 3:
                printf("===========================\n\t게임방법\n===========================");
                printf("\n이 게임은 카드게임이며, 총 3개의 카드(공격,방어,반사)로 이루어져있습니다.\n");
                printf("팀은 Black과 White팀으로 이루어져있으며 각팀의 목숨은 5개씩 있습니다.\n");
                printf("카드를 뽑을때는 처음에는 사용할 카드의 갯수를 적어주시고(중복불가)\n");
                printf("그 다음엔 카드의 종류번호(공격:1 방어:2 반사:3)를 적어주시면 됩니다\n");
                printf("카드의 판정순서는 공격->반사->방어 순으로 됩니다.\n");
                printf("즐겁게 플레이 해주세요~!\n");
                getchar();
                system("cls");
                goto op;
                break;
            case 4:
                printf("==============================================================================\n\t\t\t제 작 진\n==============================================================================\n");
                printf("\n\t\t\t만든이:김영재\n\n\t\t\t아이디어:정기완\n\n\t\t\t카드판별코드아이디어:배현빈\n\n\t\t\t제작시간: 총합 약 12시간30분\n\n");
                printf("==============================================================================\n");
                getchar();
                system("cls");
                goto op;
                break;
            case 5:
                return 0;
                break;
        }
        if (z == 0 && a == 1) {
            if (b == 1 && (b2 == 2 && b3 == 3)) {
                printf("Black:All-out attack!!!\nWhite:아무것도 하지않음\n");
                printf("Black이 공격했습니다!\n");
                wl--;
                getchar();
            } else if (b == 1 && b2 == 2) {
                printf("Black:Attack! and Shield! \nWhite:아무것도 하지않음\n");
                printf("Black이 공격했습니다!\n");
                wl--;
                getchar();
            } else if (b == 1 && b2 == 3) {
                printf("Black:Attack! and Reflect! \nWhite:아무것도 하지않음\n");
                printf("Black이 공격했습니다!\n");
                wl--;
                getchar();
            } else if (b == 2 && b2 == 3) {
                printf("Black:Shield! and Reflect! \nWhite:아무것도 하지않음\n");
                printf("...\n");
                getchar();
            } else if (b == 1) {
                printf("Black:Attack!\nWhite:아무것도 하지 않음\n");
                printf("Black이 공격했습니다!");
                wl--;
                getchar();
            } else if (b == 2) {
                printf("Black:Shield!\nWhite:아무것도 하지 않음\n");
                printf("...\n");
                getchar();
            } else if (b == 3) {
                printf("Black:Reflect!\nWhite:아무것도 하지 않음\n");
                printf("...\n");
                getchar();
            }
        } else if (a == 0 && z == 1) {
            if ((s == 1) && (d == 2 && f == 3)) {
                printf("Black:아무것도 하지않음\nWhite:All-out attack!!!\n");
                printf("White가 공격했습니다!");
                bl--;
                getchar();
            } else if (s == 1 && d == 2) {
                printf("Black:아무것도 하지않음\nWhite:Attack! and Shield!\n");
                printf("White가 공격했습니다!");
                bl--;
                getchar();
            } else if (s == 1 && d == 3) {
                printf("Black:아무것도 하지않음\nWhite:Attack! and Reflect!\n");
                printf("White가 공격했습니다!\n");
                wl--;
                getchar();
            } else if (s == 2 && d == 3) {
                printf("Black:아무것도 하지않음\nWhite:Shield! and Reflect!\n");
                printf("...\n");
                getchar();
            } else if (s == 1) {
                printf("Black:아무것도 하지 않음\nWhite:Attack!\n");
                printf("White가 공격했습니다!");
                bl--;
                getchar();
            } else if (s == 2) {
                printf("Black:아무것도 하지 않음\nWhite:Shield!\n");
                printf("...\n");
                getchar();
            } else if (s == 3) {
                printf("Black:아무것도 하지 않음\nWhite:Reflect!\n");
                printf("...\n");
                getchar();
            }
        } else if (a < z && (a > 0 && z > 0)) {
            a = z;
            switch (a) {
                case 1:
                    if ((b == 1 && s == 1) && (d == 2 && f == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 막고 반사시켰습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if ((b == 2 && s == 1) && (d == 2 && f == 3)) {
                        printf("White는 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 White는 또 반사를 시켰습니다!\n");
                        bl = bl - 1;
                        getchar();
                    } else if ((b == 1 && s == 1) && d == 2) {
                        printf("Black은 공격을 했지만 White는 이를막고 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 2 && s == 1) && d == 2) {
                        printf("White는 공격을 했지만 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && d == 2) {
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 White는 이것을 막았습니다!\n");
                        getchar();
                    } else if ((b == 1 && s == 1) && d == 3) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        getchar();
                        bl = bl - 2;
                        getchar();
                    } else if ((b == 2 && s == 1) && d == 3) {
                        printf("White가 공격을 했지만 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && d == 3) {
                        printf("White가 공격을 했지만 Black은 이를 반사시키고 White는 또 반사시켰습니다!");
                        bl--;
                        getchar();
                    } else if ((s == 1 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if ((s == 2 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 3 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 Black은 또 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 1 && b == 1) && b2 == 2) {
                        printf("White는 공격을 했지만 Black은 이를 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 2 && b == 1) && b2 == 2) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 3 && b == 1) && b2 == 2) {
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 1 && b == 1) && b == 3) {
                        printf("White가 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl--;
                        wl--;
                        getchar();
                    } else if ((s == 2 && b == 1) && b == 3) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!");
                        getchar();
                    } else if ((s == 3 && b == 1) && b == 3) {
                        printf("Black은 공격을 했지만 White는 이를 반사시키고 Black이 또 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (b == 1 && s == 1) {
                        printf("Black:Attack!\nWhite:Attack!\n");
                        printf("서로 공격했습니다...\n");
                        wl--;
                        bl--;
                        getchar();
                    } else if (b == 1 && s == 2) {
                        printf("Black:Attack!\nWhite:Shield\n");
                        printf("Black이 공격을 했지만 White는 막았습니다!\n");
                        getchar();
                    } else if (b == 1 && s == 3) {
                        printf("Black:Attack!\nWhite:Reflect!\n");
                        printf("Black이 공격을 했지만 White는 반사시켰습니다!\n");
                        getchar();
                        bl--;
                    } else if (b == 2 && s == 1) {
                        printf("Black:Shield!\nWhite:Attack!\n");
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && s == 2) {
                        printf("Black:Shield!\nWhite:Shield!\n");
                        printf("서로 막았습니다...\n");
                        getchar();
                    } else if (b == 2 && s == 3) {
                        printf("Black:Shield!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 1) {
                        printf("Black:Reflect!\nWhite:Attack!");
                        printf("White가 공격을 했지만 Black이 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (b == 3 && s == 2) {
                        printf("Black:Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 3) {
                        printf("Black:Reflect!\nWhite:Reflect!\n");
                        printf("서로 반사시켰습니다...");
                        getchar();
                    }
                    break;
                case 2:
                    if ((b == 1 && b2 == 2) && (s == 1 && d == 2)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Shield!\n");
                        printf("서로 공격했지만 서로 막았습니다...");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 3)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Reflect!\n");
                        printf("서로 공격했지만 White는 공격을 반사시키고 Black은 공격을 막았습니다");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White가 공격했지만 Black은 반사시켰습니다.\n");
                        wl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White가 공격을 했지만 Black은 이를 반사시키고 White는 또 반사를 시켰지만 Black은 이를 막았습니다.\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 2 && d == 3)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield! and Reflect!\n");
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 반사를 막았습니다!");
                        getchar();
                    } else if ((b == 2 && b == 3) && (s == 2 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 1 && (s == 1 && d == 2)) {
                        printf("Black:Attack!\nWhite:Attack! and Shield!\n");
                        printf("Black은 공격을 했지만 White는 이를 막고 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if (b == 1 && (s == 1 && d == 3)) {
                        printf("Black:Attack!\nWhite:Attack! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if (b == 1 && (s == 2 && d == 3)) {
                        printf("Black:Attack!\nWhite:Shield! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if (s == 1 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    }
                        //***************************
                    else if (b == 2 && (s == 1 && d == 2)) {
                        printf("Black:Shield!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 1 && d == 3)) {
                        printf("Black:Shield!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 2 && d == 3)) {
                        printf("Black:Shield!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    } else if (s == 2 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    }
                        //****************************
                    else if (b == 3 && (s == 1 && d == 2)) {
                        printf("Black:Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 White는 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 3 && (s == 1 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 또 그걸 White가 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (b == 3 && (s == 2 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 또 Black이 그걸 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 3 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 Black은 그걸 막았습니다!\n");
                        getchar();
                    }
                    break;
                case 3:
                    /***************************/
                    if ((b == 1 && b2 == 2) && (b3 == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White와 Black은 서로 공격을 하고 서로 반사를 하고 서로 막았습니다!\n");
                        getchar();
                    } else if ((s == 1 && d == 2) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시켰고 공격을 했고 White는 한개의 공격을 막았습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 1 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시키고 White는 또 반사를 시키고 Black은 그걸 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 2 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("Black은 공격을 했지만 White는 이걸 반사시키고 Black은 또 반사시키고 White는 이걸 막았습니다!\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 반사시키고 공격을 했고 Black은 한개의 공격을 막았습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 1 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 또 반사시키고 White가 막고 공격을 했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 White는 또 반사시키고 Black은 그걸 막고 White는 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((s == 1 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if ((s == 2 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 3 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시켰고 Black은 또 반사를 시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if ((b == 1 && s == 1) && (d == 2 && f == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if ((b == 2 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 이를 반사시켰고 White는 이걸 또 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    }
            }
        } else if (a > z && (s > 0 && z > 0)) {
            switch (a) {
                case 1:
                    if (b == 1 && s == 1) {
                        printf("Black:Attack!\nWhite:Attack!\n");
                        printf("서로 공격했습니다...\n");
                        wl--;
                        bl--;
                        getchar();
                    } else if (b == 1 && s == 2) {
                        printf("Black:Attack!\nWhite:Shield\n");
                        printf("Black이 공격을 했지만 White는 막았습니다!\n");
                        getchar();
                    } else if (b == 1 && s == 3) {
                        printf("Black:Attack!\nWhite:Reflect!\n");
                        printf("Black이 공격을 했지만 White는 반사시켰습니다!\n");
                        getchar();
                        bl--;
                    } else if (b == 2 && s == 1) {
                        printf("Black:Shield!\nWhite:Attack!\n");
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && s == 2) {
                        printf("Black:Shield!\nWhite:Shield!\n");
                        printf("서로 막았습니다...\n");
                        getchar();
                    } else if (b == 2 && s == 3) {
                        printf("Black:Shield!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 1) {
                        printf("Black:Reflect!\nWhite:Attack!");
                        printf("White가 공격을 했지만 Black이 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (b == 3 && s == 2) {
                        printf("Black:Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 3) {
                        printf("Black:Reflect!\nWhite:Reflect!\n");
                        printf("서로 반사시켰습니다...");
                        getchar();
                    }
                    break;
                case 2:
                    if ((b == 1 && b2 == 2) && (s == 1 && d == 2)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Shield!\n");
                        printf("서로 공격했지만 서로 막았습니다...");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 3)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Reflect!\n");
                        printf("서로 공격했지만 White는 공격을 반사시키고 Black은 공격을 막았습니다");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White가 공격했지만 Black은 반사시켰습니다.\n");
                        wl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White가 공격을 했지만 Black은 이를 반사시키고 White는 또 반사를 시켰지만 Black은 이를 막았습니다.\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 2 && d == 3)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield! and Reflect!\n");
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 반사를 막았습니다!");
                        getchar();
                    } else if ((b == 2 && b == 3) && (s == 2 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 1 && (s == 1 && d == 2)) {
                        printf("Black:Attack!\nWhite:Attack! and Shield!\n");
                        printf("Black은 공격을 했지만 White는 이를 막고 공격했습니다!\n");
                        getchar();
                        bl--;
                    } else if (b == 1 && (s == 1 && d == 3)) {
                        printf("Black:Attack!\nWhite:Attack! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if (b == 1 && (s == 2 && d == 3)) {
                        printf("Black:Attack!\nWhite:Shield! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if (s == 1 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    }
                        //***************************
                    else if (b == 2 && (s == 1 && d == 2)) {
                        printf("Black:Shield!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 1 && d == 3)) {
                        printf("Black:Shield!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 2 && d == 3)) {
                        printf("Black:Shield!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    } else if (s == 2 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    }
                        //****************************
                    else if (b == 3 && (s == 1 && d == 2)) {
                        printf("Black:Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 White는 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 3 && (s == 1 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 또 그걸 White가 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (b == 3 && (s == 2 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 또 Black이 그걸 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 3 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 Black은 그걸 막았습니다!\n");
                        getchar();
                    }
                    break;
                case 3:
                    /***************************/
                    if ((b == 1 && b2 == 2) && (b3 == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White와 Black은 서로 공격을 하고 서로 반사를 하고 서로 막았습니다!\n");
                        getchar();
                    } else if ((s == 1 && d == 2) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시켰고 공격을 했고 White는 한개의 공격을 막았습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 1 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시키고 White는 또 반사를 시키고 Black은 그걸 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 2 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("Black은 공격을 했지만 White는 이걸 반사시키고 Black은 또 반사시키고 White는 이걸 막았습니다!\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 반사시키고 공격을 했고 Black은 한개의 공격을 막았습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 1 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 또 반사시키고 White가 막고 공격을 했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 White는 또 반사시키고 Black은 그걸 막고 White는 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((s == 1 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if ((s == 2 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 3 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시켰고 Black은 또 반사를 시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if ((b == 1 && s == 1) && (d == 2 && f == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if ((b == 2 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 이를 반사시켰고 White는 이걸 또 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    }
            }
        } else if (a == z) {
            switch (a) {
                case 1:
                    if (b == 1 && s == 1) {
                        printf("Black:Attack!\nWhite:Attack!\n");
                        printf("서로 공격했습니다...\n");
                        wl--;
                        bl--;
                        getchar();
                    } else if (b == 1 && s == 2) {
                        printf("Black:Attack!\nWhite:Shield\n");
                        printf("Black이 공격을 했지만 White는 막았습니다!\n");
                        getchar();
                    } else if (b == 1 && s == 3) {
                        printf("Black:Attack!\nWhite:Reflect!\n");
                        printf("Black이 공격을 했지만 White는 반사시켰습니다!\n");
                        getchar();
                        bl--;
                    } else if (b == 2 && s == 1) {
                        printf("Black:Shield!\nWhite:Attack!\n");
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && s == 2) {
                        printf("Black:Shield!\nWhite:Shield!\n");
                        printf("서로 막았습니다...\n");
                        getchar();
                    } else if (b == 2 && s == 3) {
                        printf("Black:Shield!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 1) {
                        printf("Black:Reflect!\nWhite:Attack!");
                        printf("White가 공격을 했지만 Black이 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (b == 3 && s == 2) {
                        printf("Black:Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 3 && s == 3) {
                        printf("Black:Reflect!\nWhite:Reflect!\n");
                        printf("서로 반사시켰습니다...");
                        getchar();
                    }
                    break;
                case 2:
                    if ((b == 1 && b2 == 2) && (s == 1 && d == 2)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Shield!\n");
                        printf("서로 공격했지만 서로 막았습니다...");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 3)) {
                        printf("Black:Attack! and Shield! \nWhite:Attack! and Reflect!\n");
                        printf("서로 공격했지만 White는 공격을 반사시키고 Black은 공격을 막았습니다");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White가 공격했지만 Black은 반사시켰습니다.\n");
                        wl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White가 공격을 했지만 Black은 이를 반사시키고 White는 또 반사를 시켰지만 Black은 이를 막았습니다.\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 2 && d == 3)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield! and Reflect!\n");
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 반사를 막았습니다!");
                        getchar();
                    } else if ((b == 2 && b == 3) && (s == 2 && d == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (b == 1 && (s == 1 && d == 2)) {
                        printf("Black:Attack!\nWhite:Attack! and Shield!\n");
                        printf("Black은 공격을 했지만 White는 이를 막고 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if (b == 1 && (s == 1 && d == 3)) {
                        printf("Black:Attack!\nWhite:Attack! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if (b == 1 && (s == 2 && d == 3)) {
                        printf("Black:Attack!\nWhite:Shield! and Reflect!\n");
                        printf("Black은 공격을 했지만 White는 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if (s == 1 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 1 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Attack!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    }
                        //***************************
                    else if (b == 2 && (s == 1 && d == 2)) {
                        printf("Black:Shield!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 1 && d == 3)) {
                        printf("Black:Shield!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 그것을 막았습니다!\n");
                        getchar();
                    } else if (b == 2 && (s == 2 && d == 3)) {
                        printf("Black:Shield!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    } else if (s == 2 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Shield!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 2 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Shield!\n");
                        printf("Black은 공격을 했지만 White는 그것을 막았습니다!\n");
                        getchar();
                    }
                        //****************************
                    else if (b == 3 && (s == 1 && d == 2)) {
                        printf("Black:Reflect!\nWhite:Attack! and Shield!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 White는 이를 막았습니다!\n");
                        getchar();
                    } else if (b == 3 && (s == 1 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Attack! and Reflect!\n");
                        printf("White는 공격을 했지만 Black은 이를 반사시켰고 또 그걸 White가 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    } else if (b == 3 && (s == 2 && d == 3)) {
                        printf("Black:Reflect!\nWhite:Shield! and Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 3)) {
                        printf("Black:Attack! and Reflect!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 또 Black이 그걸 반사시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if (s == 3 && (b == 2 && b2 == 3)) {
                        printf("Black:Shield! and Reflect!\nWhite:Reflect!\n");
                        printf("...?\n");
                        getchar();
                    } else if (s == 3 && (b == 1 && b2 == 2)) {
                        printf("Black:Attack! and Shield!\nWhite:Reflect!\n");
                        printf("Black은 공격을 했지만 White는 이를 반사시켰고 Black은 그걸 막았습니다!\n");
                        getchar();
                    }
                    break;
                case 3:
                    /***************************/
                    if ((b == 1 && b2 == 2) && (b3 == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White와 Black은 서로 공격을 하고 서로 반사를 하고 서로 막았습니다!\n");
                        getchar();
                    } else if ((s == 1 && d == 2) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시켰고 공격을 했고 White는 한개의 공격을 막았습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 1 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("White는 공격을 했지만 Black은 그걸 반사시키고 White는 또 반사를 시키고 Black은 그걸 막고 공격했습니다!\n");
                        wl--;
                        getchar();
                    } else if ((s == 2 && d == 3) && (b == 1 && b2 == 2) && b3 == 3) {
                        printf("Black은 공격을 했지만 White는 이걸 반사시키고 Black은 또 반사시키고 White는 이걸 막았습니다!\n");
                        getchar();
                    } else if ((b == 1 && b2 == 2) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 반사시키고 공격을 했고 Black은 한개의 공격을 막았습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 1 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 Black은 또 반사시키고 White가 막고 공격을 했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((b == 2 && b2 == 3) && (s == 1 && d == 2) && f == 3) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 White는 또 반사시키고 Black은 그걸 막고 White는 공격했습니다!\n");
                        bl--;
                        getchar();
                    } else if ((s == 1 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("White는 공격을 했지만 Black은 이를 반사시키고 공격했습니다!\n");
                        wl = wl - 2;
                        getchar();
                    } else if ((s == 2 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black은 공격을 했지만 White는 이를 막았습니다!\n");
                        getchar();
                    } else if ((s == 3 && b == 1) && (b2 == 2 && b3 == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시켰고 Black은 또 반사를 시켰습니다!\n");
                        wl--;
                        getchar();
                    } else if ((b == 1 && s == 1) && (d == 2 && f == 3)) {
                        printf("Black이 공격을 했지만 White는 이를 반사시키고 공격했습니다!\n");
                        bl = bl - 2;
                        getchar();
                    } else if ((b == 2 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 막았습니다!\n");
                        getchar();
                    } else if ((b == 3 && s == 1) && (d == 2 && f == 3)) {
                        printf("White가 공격을 했지만 Black은 이를 반사시켰고 White는 이걸 또 반사시켰습니다!\n");
                        bl--;
                        getchar();
                    }
            }
        }
        if (wl <= 0 && bl <= 0) {
            printf("DRAW!");
            getchar();
            return 0;
        } else if (wl <= 0) {
            printf("Black Win!");
            getchar();
            return 0;
        } else if (bl <= 0) {
            printf("White Win!");
            getchar();
            return 0;
        } else {
            system("cls");
            if (wl > bl)
                printf("서로 남은 목숨은 \nBlack:%d White:%d이므로 White가 이기고 있습니다!", bl, wl);
            else if (bl > wl)
                printf("서로 남은 목숨은 \nBlack:%d White:%d이므로 Black이 이기고 있습니다!", bl, wl);
            else
                printf("서로 남은 목숨은 \nBlack:%d White:%d이므로 서로 동등합니다!", bl, wl);
            getchar();
            goto st;
        }

        return 0;
    }
}


int HPan(int Hu, int Ai) {
    int y, num;
    if (Hu == 3) {
        printf("+11이득!\n");
        Hu = Hu + 11;
        getchar();
    } else if (Hu == 7) {
        printf("+17이득!\n");
        Hu = Hu + 17;
        getchar();
    } else if (Hu == 13) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트을 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            getchar();
            num = Hu;
            Hu = Ai;
            Ai = num;
        } else
            printf("텔레포트을 하지않습니다!\n");
    } else if (Hu == 29) {
        printf("함정!\n-14\n");
        Hu = Hu - 14;
        getchar();
    } else if (Hu == 31) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트를 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            num = Hu;
            Hu = Ai;
            Ai = num;
            getchar();
        } else
            printf("텔레포트를 하지않습니다!\n");
        getchar();
    } else if (Hu == 37) {
        printf("+4이득!\n");
        Hu = Hu + 4;
        getchar();
    } else if (Hu == 42) {
        printf("함정!\n-6\n");
        Hu = Hu - 6;
        getchar();
    } else if (Hu == 45) {
        printf("함정!\n-4\n");
        Hu = Hu - 4;
        getchar();
    } else if (Hu == 46) {
        printf("+1이득!\n");
        getchar();
        Hu = Hu + 1;
    } else if (Hu == 49) {
        printf("선택\n1. +1 or 2. -1\n");
        scanf("%d", &y);
        if (y == 1)
            Hu = Hu + 1;
        else
            Hu = Hu - 1;
    } else if (Hu == 50) {
        printf("함정!\n-5\n");
        Hu = Hu - 5;
        getchar();
    } else {
        printf("당신은 현재 %d자리에 있습니다!\n", Hu);
        getchar();
        return Hu;
    }
    printf("당신은 현재 %d자리에 있습니다!\n", Hu);
    getchar();
    return Hu;
}

int H2Pan(int Hu, int Hu2) {
    int y;
    if (Hu2 == 3) {
        printf("+11이득!\n");
        Hu2 = Hu2 + 11;
        getchar();
    } else if (Hu2 == 7) {
        printf("+17이득!\n");
        Hu2 = Hu2 + 17;
        getchar();
    } else if (Hu2 == 13) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트을 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            getchar();
            Hu = Hu2;
        } else
            printf("텔레포트을 하지않습니다!\n");
    } else if (Hu2 == 29) {
        printf("함정!\n-14\n");
        Hu2 = Hu2 - 14;
        getchar();
    } else if (Hu2 == 31) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트를 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            Hu = Hu2;
            getchar();
        } else
            printf("텔레포트를 하지않습니다!\n");
        getchar();
    } else if (Hu2 == 37) {
        printf("+4이득!\n");
        Hu2 = Hu2 + 4;
        getchar();
    } else if (Hu2 == 42) {
        printf("함정!\n-6\n");
        Hu2 = Hu2 - 6;
        getchar();
    } else if (Hu2 == 45) {
        printf("함정!\n-4\n");
        Hu2 = Hu2 - 4;
        getchar();
    } else if (Hu2 == 46) {
        printf("+1이득!\n");
        getchar();
        Hu2 = Hu2 + 1;
    } else if (Hu2 == 49) {
        printf("선택\n1. +1 or 2. -1\n");
        scanf("%d", &y);
        if (y == 1)
            Hu2 = Hu2 + 1;
        else
            Hu2 = Hu2 - 1;
    } else if (Hu2 == 50) {
        printf("함정!\n-5\n");
        Hu2 = Hu2 - 5;
        getchar();
    } else {
        printf("당신은 현재 %d자리에 있습니다!\n", Hu2);
        getchar();
        return Hu2;
    }
    printf("당신은 현재 %d자리에 있습니다!\n", Hu2);
    getchar();
    return Hu2;
}


int APan(int Hu, int Ai) {
    int y, num;
    if (Ai == 3) {
        printf("+11이득!\n");
        Ai = Ai + 11;
        getchar();
    } else if (Ai == 7) {
        printf("+17이득!\n");
        Ai = Ai + 17;
        getchar();
    } else if (Ai == 13) {
        if (Hu > Ai) {
            printf("Ai 텔 레 포 트 !\n");
            num = Ai;
            Ai = Hu;
            Hu = num;
        } else
            printf("Ai가 텔레포트을 하지않습니다!\n");;
    } else if (Ai == 29) {
        printf("함정!\n-14\n");
        Ai = Ai - 14;
        getchar();
    } else if (Ai == 31) {
        if (Hu > Ai) {
            printf("Ai텔 레 포 트 !\n");
            num = Ai;
            Ai = Hu;
            Hu = num;
            getchar();
        } else
            printf("Ai가 텔레포트을 하지않습니다!\n");
        getchar();
    } else if (Ai == 37) {
        printf("+4이득\n");
        Ai = Ai + 4;
        getchar();
    } else if (Ai == 42) {
        printf("함정!\n-6\n");
        Ai = Ai - 6;
        getchar();
    } else if (Ai == 45) {
        printf("함정!\n-4\n");
        Ai = Ai - 4;
        getchar();
    } else if (Ai == 46) {
        printf("+1이득!\n");
        getchar();
        Ai = Ai + 1;
    } else if (Ai == 49) {
        printf("선택\n1. +1 or 2. -1\n");
        scanf("%d", &y);
        if (y == 1)
            Ai = Ai + 1;
        else
            Ai = Ai - 1;
    } else if (Ai == 50) {
        printf("함정!\n-5\n");
        Ai = Ai - 5;
        getchar();
    } else {
        printf("Ai는 현재 %d자리에 있습니다!\n", Ai);
        getchar();
        return Ai;
    }
    printf("Ai는 현재 %d자리에 있습니다!\n", Ai);
    getchar();
    return Ai;
}


int HHPan(int Hu, int Hu2) {
    int y;
    if (Hu == 3) {
        printf("+11이득!\n");
        Hu = Hu + 11;
        getchar();
    } else if (Hu == 7) {
        printf("+17이득!\n");
        Hu = Hu + 17;
        getchar();
    } else if (Hu == 13) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트을 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            getchar();
            Hu2 = Hu;
        } else
            printf("텔레포트을 하지않습니다!\n");
    } else if (Hu == 29) {
        printf("함정!\n-14\n");
        Hu = Hu - 14;
        getchar();
    } else if (Hu == 31) {
        printf("텔레포트 찬스!\n");
        printf("텔레포트를 쓰시겠습니까?\n1. Y 2. N\n");
        scanf("%d", &y);
        if (y == 1) {
            printf("텔 레 포 트 !\n");
            Hu2 = Hu;
            getchar();
        } else
            printf("텔레포트를 하지않습니다!\n");
        getchar();
    } else if (Hu == 37) {
        printf("+4이득!\n");
        Hu = Hu + 4;
        getchar();
    } else if (Hu == 42) {
        printf("함정!\n-6\n");
        Hu = Hu - 6;
        getchar();
    } else if (Hu == 45) {
        printf("함정!\n-4\n");
        Hu = Hu - 4;
        getchar();
    } else if (Hu == 46) {
        printf("+1이득!\n");
        getchar();
        Hu = Hu + 1;
    } else if (Hu == 49) {
        printf("선택\n1. +1 or 2. -1\n");
        scanf("%d", &y);
        if (y == 1)
            Hu = Hu + 1;
        else
            Hu = Hu - 1;
    } else if (Hu == 50) {
        printf("함정!\n-5\n");
        Hu = Hu - 5;
        getchar();
    } else {
        printf("당신은 현재 %d자리에 있습니다!\n", Hu);
        getchar();
        return Hu;
    }
    printf("당신은 현재 %d자리에 있습니다!\n", Hu);
    getchar();
    return Hu;
}


int Dice() {
    int i, g, a = 0, r = 0;
    int Hu = 0, Ai = 0, Hu2 = 0;
    printf("\t==========The 4th GameMaker==========\n");
    printf("\t============Dice=====War=============\n");
    getchar();
    system("cls");
    srand((unsigned int) time(NULL));
    while (1) {
        Menu:
        printf("=================MENU=================\n");
        printf("1.AI Mode\n");
        printf("2.2P Mode\n");
        printf("3.게임방법\n");
        printf("4.제작진\n");
        printf("5.종료");
        scanf("%d", &g);
        system("cls");
        switch (g) {
            case 1:
                printf("컴퓨터와 대전합니다!\n");
                printf("순서정하는중....\n");
                for (i = 0; i < 10; i++) {
                    printf("/");
                    Sleep(200);
                }
                a = rand() % 2 + 1;
                //순서!
            go:
                if (a == 1) {
                    printf("당신의 차례입니다!\n주사위를 굴리려면 아무키나 눌러주세요!!!");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("당신이 굴린 주사위는 %d입니다!\n", r);
                    Hu = Hu + r;
                    Hu = HPan(Hu, Ai);
                    system("cls");
                    //############################################
                    printf("Ai가 주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("Ai가 굴린 주사위는 %d입니다!\n", r);
                    Ai = Ai + r;
                    Ai = APan(Hu, Ai);
                    system("cls");
                    if (Hu >= 51 && Ai >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("사람 승!\n");
                        return 0;
                    } else if (Ai >= 51) {
                        printf("Ai 승!\n");
                        return 0;
                    } else {
                        goto go;
                    }
                } else if (a == 2) {
                    go2:
                    printf("Ai가 주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("Ai가 굴린 주사위는 %d입니다!\n", r);
                    Ai = Ai + r;
                    APan(Hu, Ai);
                    system("cls");
                    //############################################
                    printf("당신의 차례입니다!\n주사위를 굴리려면 아무키나 눌러주세요!!!");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("당신이 굴린 주사위는 %d입니다!\n", r);
                    Hu = Hu + r;
                    HPan(Hu, Ai);
                    system("cls");
                    if (Hu >= 51 && Ai >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("사람 승!\n");
                        return 0;
                    } else if (Ai >= 51) {
                        printf("Ai 승!\n");
                        return 0;
                    } else {
                        goto go2;
                    }
                }
                break;
            case 2:
                printf("2P전용 모드 입니다\n");
                printf("순서정하는중....\n");
                for (i = 0; i < 10; i++) {
                    printf("/");
                    Sleep(200);
                }
                a = rand() % 2 + 1;
                //순서
                if (a == 1) {
                    go3:
                    printf("1P의 차례입니다!\n");
                    printf("주사위를 굴리려면 아무키나 눌러주세요!!!\n");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("1P가 굴린 주사위는 %d입니다!\n", r);
                    Hu = Hu + r;
                    HHPan(Hu, Hu2);
                    system("cls");
                    if (Hu >= 51 && Hu2 >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("1P 승!\n");
                        return 0;
                    } else if (Hu2 >= 51) {
                        printf("2P 승!\n");
                        return 0;
                    }
                    system("cls");
                    //####################
                    printf("2P의 차례입니다!\n");
                    printf("주사위를 굴리려면 아무키나 눌러주세요!!!\n");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("2P가 굴린 주사위는 %d입니다!\n", r);
                    Hu2 = Hu2 + r;
                    H2Pan(Hu, Hu2);
                    system("cls");
                    if (Hu >= 51 && Hu2 >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("1P 승!\n");
                        return 0;
                    } else if (Hu2 >= 51) {
                        printf("2P 승!\n");
                        return 0;
                    } else {
                        goto go3;
                    }
                } else if (a == 2) {
                    go4:
                    printf("2P의 차례입니다!\n");
                    printf("주사위를 굴리려면 아무키나 눌러주세요!!!\n");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("2P가 굴린 주사위는 %d입니다!\n", r);
                    Hu2 = Hu2 + r;
                    H2Pan(Hu, Hu2);
                    system("cls");
                    if (Hu >= 51 && Hu2 >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("1P 승!\n");
                        return 0;
                    } else if (Hu2 >= 51) {
                        printf("2P 승!\n");
                        return 0;
                    }
                    system("cls");
                    //##############################
                    printf("1P의 차례입니다!\n");
                    printf("주사위를 굴리려면 아무키나 눌러주세요!!!\n");
                    getchar();
                    system("cls");
                    printf("주사위 굴리는중...");
                    for (i = 0; i < 6; i++) {
                        printf("#");
                        Sleep(100);
                    }
                    r = rand() % 6 + 1;
                    system("cls");
                    printf("1P가 굴린 주사위는 %d입니다!\n", r);
                    Hu = Hu + r;
                    HHPan(Hu, Hu2);
                    system("cls");
                    if (Hu >= 51 && Hu2 >= 51) {
                        printf("무승부!");
                        return 0;
                    } else if (Hu >= 51) {
                        printf("1P 승!\n");
                        return 0;
                    } else if (Hu2 >= 51) {
                        printf("2P 승!\n");
                        return 0;
                    } else {
                        goto go4;
                    }
                }
                break;
            case 3:
                printf("=================================================================\n\t\t게 임 방 법\n=================================================================\n");
                printf("일단 2P모드로 할건지 Ai모드로 할건지 정해줍니다\n그런다음 랜덤으로 순서가 정해지는데 주사위를 굴려서 51까지 가는게 목적입니다\n");
                printf("단 어느 칸에 가면 특별한 이벤트가 나옵니다 \n이것이 좋은거일수도 있고 나쁜것일수도 있습니다\n");
                printf("그럼 행운을 빕니다!\n");
                printf("========================================================================\n");
                getchar();
                system("cls");
                goto Menu;
            case 4:
                printf("==============================================================================\n\t\t\t제 작 진\n==============================================================================\n");
                printf("\n\t\t\t만든이:김영재\n\n\t\t\t아이디어:김영재\n\n\t\t\t제작시간: 총합 약 2시간 30분 정도?\n\n");
                printf("==============================================================================\n");
                getchar();
                system("cls");
                goto Menu;
            case 5:
                return 0;
        }
    }
    return 0;
}

int In1() {
    int a, i, sum = 10;
    printf("\nAi와 대전합니다...\n");
    getchar();
    system("cls");
    srand((unsigned) time(NULL));
    printf("플레이어 먼저 합니다...\n");
    while (1) {
        I1:
        printf("카드를 뽑으려면 아무키나 눌러주세요..\n");
        getchar();
        system("cls");
        printf("카드 뽑는중...\n");
        for (i = 0; i < 10; i++) {
            printf("/");
            Sleep(160);
        }
        a = rand() % sum + 1;

        if (a == 1) {
            printf("Trap!\n");
            getchar();
            printf("당신이 졌습니다!\n");
            getchar();
            system("cls");
            return 0;
        }
        printf("Safe!\n");
        getchar();
        system("cls");
        sum--;
        printf("남은 카드는 %d장입니다!\n", sum);
        if (sum == 1) {
            printf("함정카드만 남아서 플레이어 승!\n");
            getchar();
            system("cls");
            return 0;
        }
        if (sum == 0)
            sum++;
        printf("Ai의 차례입니다!\n");
        printf("카드 뽑는중...\n");
        for (i = 0; i < 10; i++) {
            printf("/");
            Sleep(160);
        }
        a = rand() % sum + 1;
        if (a == 1) {
            printf("Trap!\n");
            printf("플레이어 승!\n");
            getchar();
            system("cls");
            return 0;
        } else {
            printf("Safe!\n");
            system("cls");
            sum--;
            printf("남은 카드는 %d장입니다!\n", sum);
            if (sum == 1) {
                printf("함정카드만 남아서 Ai 승!\n");
                getchar();
                system("cls");
                return 0;
            }
            if (sum == 0)
                sum++;
            goto I1;
        }
    }
    return 0;
}

int In2()// ..
{
    int a, i, sum = 10;
    srand((unsigned) time(NULL));
    printf("P1부터 시작합니다!\n");
    Il:
    printf("P1의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P2 승리!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);
    if (sum == 1) {
        printf("함정카드만 남아서 P1 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    if (sum == 0)
        sum++;
    printf("P2의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P1 승리!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);
    if (sum == 1) {
        printf("함정카드만 남아서 P2 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    if (sum == 0)
        sum++;
    goto Il;
    return 0;
}


int In3()// ...
{
    int a, i, sum = 20, P1L = 1, P2L = 1, P3L = 1;
    srand((unsigned) time(NULL));
    printf("P1부터 시작합니다!\n");
    Il:
    if (P1L <= 0)
        goto Il2;
    if (P1L == 1 && P2L == 0 && P3L == 0) {
        printf("P1 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P1의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P1 사망!\n");
        P1L--;
        getchar();
        system("cls");
        goto Il2;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P1 사망!\n");
        getchar();
        P1L--;
        system("cls");
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;

    Il2:
    if (P2L <= 0)
        goto Il3;
    if (P1L == 0 && P2L == 1 && P3L == 0) {
        printf("P2 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P2의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P2 사망!\n");
        P2L--;
        getchar();
        system("cls");
        goto Il3;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P2 사망!\n");
        getchar();
        system("cls");
        P2L--;
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    Il3:
    if (P3L <= 0)
        goto Il;
    if (P1L == 0 && P2L == 0 && P3L == 1) {
        printf("P3 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P3의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P3 사망!\n");
        P3L--;
        getchar();
        system("cls");
        goto Il;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P3 사망!\n");
        getchar();
        system("cls");
        P3L--;
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    goto Il;
    return 0;
}

int In4()// ....
{
    int a, i, sum = 24, P1L = 1, P2L = 1, P3L = 1, P4L = 1;
    srand((unsigned) time(NULL));
    printf("P1부터 시작합니다!\n");
    Il:
    if (P1L <= 0)
        goto Il2;
    if (P1L == 1 && P2L == 0 && P3L == 0 && P4L == 0) {
        printf("P1 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P1의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P1 사망!\n");
        P1L--;
        getchar();
        system("cls");
        goto Il2;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P1 사망!\n");
        getchar();
        P1L--;
        system("cls");
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    Il2:
    if (P2L <= 0)
        goto Il3;
    if (P1L == 0 && P2L == 1 && P3L == 0 && P4L == 0) {
        printf("P2 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P2의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P2 사망!\n");
        P2L--;
        getchar();
        system("cls");
        goto Il3;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P2 사망!\n");
        getchar();
        system("cls");
        P2L--;
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    Il3:
    if (P3L <= 0)
        goto Il4;
    if (P1L == 0 && P2L == 0 && P3L == 1 && P4L == 0) {
        printf("P3 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P3의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P3 사망!\n");
        P3L--;
        getchar();
        system("cls");
        goto Il4;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P3 사망!\n");
        getchar();
        system("cls");
        P3L--;
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    Il4:
    if (P4L <= 0)
        goto Il;
    if (P1L == 0 && P2L == 0 && P3L == 0 && P4L == 4) {
        printf("P4 승!\n");
        getchar();
        system("cls");
        return 0;
    }
    printf("P4의 차례입니다\n카드를 뽑으려면 아무키나 눌러주세요\n");
    getchar();
    system("cls");
    printf("카드 뽑는중...\n");
    for (i = 0; i < 10; i++) {
        printf("/");
        Sleep(160);
    }
    a = rand() % sum + 1;
    if (a == 1) {
        printf("Trap!\n");
        printf("P4 사망!\n");
        P4L--;
        getchar();
        system("cls");
        goto Il;
    }
    printf("Safe~!\n");
    getchar();
    system("cls");
    if (sum == 1) {
        printf("함정카드만 남아서 P4 사망!\n");
        getchar();
        system("cls");
        P4L--;
    }
    sum--;
    printf("남은 카드는 %d장입니다!\n", sum);

    if (sum == 0)
        sum++;
    goto Il;
    return 0;
}

int Ru() {
    int a, s;
    printf("\t==========The 5th GameMaker==========\n");
    printf("\t=========The==Russian==roulette========\n");
    getchar();
    system("cls");
    while (1) {
        Menu:
        printf("===================================\n\tMenu\n===================================\n");
        printf("1.게임시작\n");
        printf("2.게임방법\n");
        printf("3.제작진\n");
        printf("4.종료\n");
        scanf("%d", &a);
        system("cls");
        switch (a) {
            case 1:
            op:
                printf("인원을 정해주세요...(최대 4명)\n");
                scanf("%d", &s);
                if (s > 4 || s < 0) {
                    system("cls");
                    goto op;
                }
                printf("플레이 인원은 총 %d명입니다\n", s);
                if (s == 1)
                    In1();
                else if (s == 2)
                    In2();
                else if (s == 3)
                    In3();
                else if (s == 4)
                    In4();
                goto Menu;
                break;
            case 2:
                printf("=================================================\n\t게 임 방 법\n=================================================\n");
                printf("이 게임은 일단 게임시작을 누르게 되시면 인원을 선택하게 됩니다 \n최대인원은 4명입니다\n");
                printf("게임 형식은 간단합니다 일단 한명씩 랜덤으로 카드를 뽑게되고\n만약 그 카드가 함정일 경우 그사람은 죽게됩니다\n만약 모두다 살게되면 마지막 한명빼고는 다 죽게됩니다..\n");
                printf("한사람이 남을때까지 이게임은 계속되니 나갈생각하지마세요~^_^\n");
                printf("=====================================================================\n");
                getchar();
                system("cls");
                goto Menu;
                break;
            case 3:
                printf("==============================================================================\n\t\t\t제 작 진\n==============================================================================\n");
                printf("\n\t\t\t만든이:김영재\n\n\t\t\t아이디어:(이번에도 역시나)정기완\n\n\t\t\t제작시간: 총합 약 3시간 20분\n\n");
                printf("==============================================================================\n");
                getchar();
                system("cls");
                goto Menu;
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}
