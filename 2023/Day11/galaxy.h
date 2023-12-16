#pragma once

/* galaxy.h */

class Galaxy {
private:
    long long x, y;
    Galaxy* next;
    long long absoluteValue(long long);
    
public:

    Galaxy();
    long long getMaxY(long long);
    long long getMaxX(long long);
    bool exists(long long, long long);
    void add(long long, long long);
    void expandY(long long, long long);
    void print();
    long long distance(long long, long long);
    long long partOne();
};
