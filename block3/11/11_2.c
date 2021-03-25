#include "11_2.h"
#include <math.h>

float P(struct coordinate dot1, struct coordinate dot2, struct coordinate dot3) {
    return sqrt(pow(dot1.x - dot2.x, 2) + pow(dot1.y - dot2.y, 2))
           + sqrt(pow(dot2.x - dot3.x, 2) + pow(dot2.y - dot3.y, 2))
           + sqrt(pow(dot3.x - dot1.x, 2) + pow(dot3.y - dot1.y, 2));
}

float S(struct coordinate dot1, struct coordinate dot2, struct coordinate dot3) {
    int poluper = P(dot1, dot2, dot3) / 2;
    return sqrt(poluper *
                (poluper - (sqrt(pow(dot1.x - dot2.x, 2) + pow(dot1.y - dot2.y, 2)))) *
                (poluper - (sqrt(pow(dot2.x - dot3.x, 2) + pow(dot2.y - dot3.y, 2)))) *
                (poluper - (sqrt(pow(dot3.x - dot1.x, 2) + pow(dot3.y - dot1.y, 2)))));
}
