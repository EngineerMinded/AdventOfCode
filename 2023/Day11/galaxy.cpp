#include "galaxy.h"
#include <iostream>
using namespace std;


Galaxy::Galaxy() {
    x = -1; y = -1;
}

void Galaxy::add(long long xx, long long yy) {
    if (x == -1) {
        this->x = xx;
        this->y = yy;
        next = NULL;
    }
    else if (next == NULL) {
        next = new Galaxy();
        next->x = xx;
        next->y = yy;
    }

    else {
        next->add(xx, yy);
    }
}

void Galaxy::expandY( long long yy,  long long expandValue) {
    if (y > yy) { y = y + expandValue; }
    if (next != NULL) {
        next->expandY(yy, expandValue);
    }
}

void Galaxy::print() {
    cout << x << " , " << y << endl;
    if (next != NULL) {
        next->print();
    }
}

long long Galaxy::partOne() {
    if (next != NULL) {
        long long returnThis = next->distance(x, y);
        return returnThis + next->partOne();
    }
    return 0;
}

long long Galaxy::distance(long long xx, long long yy) {
    long long answer = ((absoluteValue(xx - x)) + (absoluteValue(yy - y)));
    if (next != NULL) {
        return answer + next->distance(xx, yy);
    }
    else {
        return answer;
    }
}

long long Galaxy::absoluteValue(long long n) { return (n < 0 ? -n : n); }

long long Galaxy::getMaxY(long long yy) {
    if (y > yy) {
        yy = y;
    }
    if (next != NULL) {
        return next->getMaxY(yy);
    }
    return yy;
}

long long Galaxy::getMaxX(long long yy) {
    if (x > yy) {
        yy = x;
    }
    if (next != NULL) {
        return getMaxX(yy);
    }
    return yy;
}

bool Galaxy::exists(long long xx, long long yy) {
    if (xx == -1) { if (yy == y) { return true; } }
    if (yy == -1) { if (xx == x) { return true; } }
    if (xx == x && yy == y) { return true;}
    if (next == NULL) { return false; }
    return next->exists(xx, yy);
}
