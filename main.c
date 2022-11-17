#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

// ┏ ━ ┓ ┗ ┛ ┳ ╋ ┫ ┣ ┻ ┃ ◽ ◾ 🟩 🟥

struct Tm{
    int h0;
    int m0;
    int h1;
    int m1;
    int name;
};
typedef struct Tm T;

struct tm *mytime;
time_t t;

void print_time2(int x){
        for (int i = 1; i<=x;i++){
            printf("🟩");
        }
        for (int i = x; i<45;i++){
            printf("🟥");
        }
        printf("\r");
}

T pairs(int time){
    T p;
    switch (time) {
        case 10:
        case 11:
            p.h0 = 10;
            p.m0 = 15;
            p.h1 = 11;
            p.m1 = 50;
            p.name = 2;
            return p;
            break;
        case 12:
        case 13:
            p.h0 = 12;
            p.m0 = 00;
            p.h1 = 13;
            p.m1 = 35;
            p.name = 3;
            return p;
            break;
        case 14:
        case 15:
            p.h0 = 14;
            p.m0 = 20;
            p.h1 = 15;
            p.m1 = 55;
            p.name = 4;
            return p;
            break;
        case 16:
        case 17:
            p.h0 = 16;
            p.m0 = 05;
            p.h1 = 17;
            p.m1 = 40;
            p.name = 5;
            return p;
            break;
    }
    return p;
}

void cn_pair(int x){
    printf("Идёт %i пара\n", x);
}

void main() {
    int d=1;
    while (d==1){
        t=time(NULL);
        mytime=localtime(&t);
        int h = mytime->tm_hour;
        int m = mytime->tm_min;
        T p = (pairs(h));
        
        int time_end = fabs(p.h1-(h))*60+((p.m1-m));
        if (time_end>=50 && time_end<=95){
            cn_pair(p.name);
            print_time2(45-(time_end-50));
        }else if (time_end<=45 && time_end>0){
            cn_pair(p.name);
            print_time2(45-time_end);
        }else if (time_end<50 && time_end>45){
            printf("Перерыв");
        }else if (time_end==0){
            printf("Пара закончилась\n");
        }else{
            printf("Перерыв\nСcылка на GitHub - https://github.com/KostyaBIST221\n");
        }
        printf("\r\r\r\r\r\r");
        sleep(5);
    }

}
