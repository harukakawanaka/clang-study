#include <stdio.h>
#include <time.h>

void PrintLevel(int level) {
    printf("現在のスピードレベルは%dです。\n", level);
    fflush(stdout);
}

int Level0Question() {
    printf("整数の1〜9を入力してください: \n");
    fflush(stdout);
    int n;
    scanf("%d", &n);
    if (0 < n && n < 10) {
        printf("正解\n");
        fflush(stdout);
        return 1;
    } else {
        printf("違うよ\n");
        fflush(stdout);
        return 0;
    }
}

int Question(int level) {
    if (level == 0) {
        return Level0Question();
    } else {
        return 0;
    }
}

int UserContinue() {
    printf("続けますか？[Y/n]\n");
    fflush(stdout);
    char answer = 'Y';
    scanf("%c", &answer);
    fflush(stdout);
    if (answer == 'Y') {
        return 1;
    } else if (answer == 'n') {
        return 0;
    } else {
        return 9;
    }
}

int main(){
    int debug = 1;
    int answer_continue = 1;
    while(answer_continue == 1) {
        answer_continue = UserContinue();
        if (answer_continue == 9) {
            printf("不正な入力を検知したため終了します。");
        } else {
            time_t start, end;
            int currentSpeedLevel = 0;
            start = time(NULL);
            int answer = Question(currentSpeedLevel);
            end = time(NULL);
            int time = (int)(end-start);
            if (debug == 1) {
                printf("デバッグモードON\n");
                PrintLevel(currentSpeedLevel);
                printf("time = %d[秒]\n", time);
                double calc = (double)(currentSpeedLevel + answer)/time;
                printf("calc = %g\n", calc);
            }

            if ((double)(currentSpeedLevel + answer)/time > 0.9) {
                currentSpeedLevel++;
            }
            PrintLevel(currentSpeedLevel);
        }
    }

    return 0;
}