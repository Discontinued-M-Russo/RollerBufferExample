//
// Created by Russo, Michelangelo (GE Global Research) on 3/18/18.
//
// Rolling buffer, extended with average
//

#ifndef VECTORSAVERAGEEXAMPLE_EXTENDEDROLLINGBUFFER_H
#define VECTORSAVERAGEEXAMPLE_EXTENDEDROLLINGBUFFER_H

#include <vector>

using namespace std;

class extendedRollingBuffer {
    vector<int> buffer;
    vector<int>::iterator next;
    int maxCapacity;
    double average;
public:
    extendedRollingBuffer(int maxCap);  //  Constructor with capacity as an input
    ~extendedRollingBuffer();
    void insertNewItem(int input);
    double getAverage();
    int getCurrSize();
};


#endif //VECTORSAVERAGEEXAMPLE_EXTENDEDROLLINGBUFFER_H
