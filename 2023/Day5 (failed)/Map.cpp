#include "Map.h"

/* Map.cpp */
Map::Map() {
    name = "";
    next = NULL;

}


void Map::addMap(string newName) {
    if (next == NULL) {
        next = new Map();
        next->name = newName;
    }
    else {
        next->addMap(newName);
    }
}

void Map::addMapData(string newData) {
    if (next != NULL) {
        next->addMapData(newData);
    }
    else if (data == NULL) {
        data = new Map();
        data->name = newData;
    }
    else {
        data->addData(newData);
    }
}

void Map::addData(string newData) {

    if (next == NULL) {
        next = new Map();
        next->name = newData;
    }
    else {
        next->addData(newData);
    }
}

void Map::printData() {
    cout << "    " << name << " " << endl;
    if (next != NULL) {
        next->printData();
    }
}
void Map::printMap() {
    cout << name << endl;
    if (data != NULL) {
        data->printData();
    }
    if (next != NULL) {
        next->printMap();
    }
}
long Map::getLocationNumber(long search) {
    if (data != NULL) {
        search = data->getDataNumber(search);
    }
    if (next != NULL) {
        return next->getLocationNumber(search);
    }
    else {
        return search;
    }
}

long Map::getDataNumber(long search) {
  
    long  destinationRangeStart = 0, sourceRangeStart = 0, rangeLength = 0;
    istringstream iss(name);
    long num; int count = 1;

    // extract data from string;
    while (iss >> num) {
        if (count == 3) {
            rangeLength = num;
        }
        else if (count == 2) {
            sourceRangeStart = num;
            count = 3;
        }
        else {
            destinationRangeStart = num;
            count = 2;
        }
    }
    //cout << destinationRangeStart << " " << sourceRangeStart << " " << rangeLength;
    if ((search >= sourceRangeStart) && (search <= sourceRangeStart + rangeLength)) {
        return search - sourceRangeStart + destinationRangeStart;
    }
    else if (next != NULL) {
        return next->getDataNumber(search);
    }
    else {
        return search;
    }
}
