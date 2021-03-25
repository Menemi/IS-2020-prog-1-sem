#define _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>

int main() {
    printf("Input the angle: ");
    double angle;
    scanf("%lf", &angle);

    double z1 = cos(angle * M_PI / 180) + cos(2 * angle * M_PI / 180) +
                cos(6 * angle * M_PI / 180) + cos(7 * angle * M_PI / 180);
    double z2 = 4 * cos(0.5 * angle * M_PI / 180) * cos(2.5 * angle * M_PI / 180) *
                cos(4 * angle * M_PI / 180);

    printf("z1: %lf\nz2: %lf", z1, z2);
}
