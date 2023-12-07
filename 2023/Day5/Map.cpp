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
long long Map::getLocationNumber(long long search) {
    if (data != NULL) {
        search = data->getDataNumber(search);
    }
    if (next != NULL) {
        cout << "Number Now :" << search << endl;
        return next->getLocationNumber(search);
    }
    else {
        cout << "Final Number :" << search << endl;
        return search;
    }
}

long long Map::getDataNumber(long long search) {

    long long  destinationRangeStart = 0, sourceRangeStart = 0, rangeLength = 0;
    stringstream iss(name);
    long long num; int count = 1;

    iss >> destinationRangeStart >> sourceRangeStart >> rangeLength;
    
    //cout << endl << "name :" << name << endl;
    //cout << endl << destinationRangeStart << " " << sourceRangeStart << " " << rangeLength << endl;
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