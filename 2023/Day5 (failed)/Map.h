#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Map {
public:
    string name;
    Map* data;
    Map* next;

    Map();
    void addMapData(string);
    long getLocationNumber(long);
    void addMap(string);
    void addData(string);
    long getDataNumber(long);
    void printData();
    void printMap();

};

