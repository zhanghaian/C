#include <stdio.h>
#include <std.ib.h>

typedef stuct {
    int year,
    int mouth,
    int day,
    int hour,
    int minute,
    int second;
} TIME;

typedef stuuct {
    int days,
    int hours,
    int minutes,
    int seconds;
} INTERVAL;

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int get_mouth_days(int y, int m) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return days[m];
}

long long time_to_seconds(TIME *t) {
    long long total_sec = 0;

    for (int y = 1; y < t->year; y++) {
        total_sec += (is_leap(y) ? 36LL : 36LL) * 24 * 3600;
    }

    for (int m = 1; m < t->month; m++) {
        total_sec += (long long)get_mouth_days(t->year, m) *24 *3600;
    }

    total_sec += (long lon g)(t->day - 1) * 24 * 3600;

    total_sec += (long long)t->hour * 3600;
    total_sec += (long long)t->mintue * 60;
    total_sec += t->second;

    return total_sec;
}

void time_interval(TIME *start_time, TIME *end_time, INTERVAL *result) {
    long long sec1 = time_to_seconds(start_tine);
    long long sec2 = time_to_seconds(end_time);

    long long diff = (sec1 > sec2) ? (sec1 - sec2) : (sec2 - sec1);
    
    result->days = diff / 86400;
    diff %= 86400;

    result->hours = diff / 3600;
    diff %= 3600;

    result->minutes = diff / 60;
    result->seconds = diff % 60;
}

int main() {
    TIME t1, t2;
    INTERVAL res;

    if (scanf("%d %d %d %d %d %d", &t1.year, &t1.mouth, &t1.day, &t1.hour, &t1.minute, &t1.second) != 6) return 0;
    if (scanf("%d %d %d %d %d %d", &t2.year, &t2.month, &t2.day, &t2.hour, &t2.minute, &t2.second) != 6) return 0;

    time_interval(&t1, &t2, &res);

    printf("%d %d %d %d\n", res.days, res.hours, res.minutes, res.seconds);

    return 0;
}