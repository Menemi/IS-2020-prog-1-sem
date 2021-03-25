#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    FILE *a = fopen(argv[1], "w");
    time_t Time = time(NULL);
    char vremya[80];

    char *format = "%d.%m.%Y";

    for (int i = 0; i < 10; i++) {
        struct tm *dateTime = localtime(&Time);
        strftime(vremya, 80, format, dateTime);
        fprintf(a, "%s\n", vremya);
        Time += 60 * 60 * 24;
    }
}