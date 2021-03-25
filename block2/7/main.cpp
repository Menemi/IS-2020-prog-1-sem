#include <stdio.h>
#include <math.h>

enum typesOfPrintedPublications {
    BOOK,
    MAGAZINE,
    NEWSPAPER,
    MAP,
    ALBUM,
    PHOTOALBUM
};

class Triangle {
private:
    float x0, y0, a, b, c;
public:
    float area() {
        float poluperim = (a + b + c) / 2;
        return sqrt(poluperim * (poluperim - a) * (poluperim - b) * (poluperim - c));
    }

    float perimeter() { return a + b + c; }

    Triangle(float x0, float y0, float a, float b, float c) {
        this->x0 = x0;
        this->y0 = y0;
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

Triangle *t1 = new Triangle(10, 10, 10, 10, 10);

struct cardReader {
    int on: 1;
    int activeSDCard: 1;
    int aciveCompactFlash: 1;
    int activeMemoyStick: 1;
};

int main() {
    printf("Newspaper index: %d\n\n", NEWSPAPER);

    struct cardReader a;
    int temp;

    scanf_s("%x", &temp);

    a.on = temp >> 3;
    a.activeSDCard = (temp >> 2) % 10;
    a.aciveCompactFlash = (temp >> 1) % 10;
    a.activeMemoyStick = temp % 10;

    printf("Is card-reader on: %d\n", a.on);
    printf("Is SD-card active: %d\n", a.activeSDCard);
    printf("Is CompactFlash acive: %d\n", a.aciveCompactFlash);
    printf("Is MemoyStick active: %d\n", a.activeMemoyStick);
}