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
    long long getLocationNumber(long long);
    void addMap(string);
    void addData(string);
    long long getDataNumber(long long);
    void printData();
    void printMap();

};