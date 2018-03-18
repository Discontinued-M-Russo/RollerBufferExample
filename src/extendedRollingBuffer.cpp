//
// Created by Russo, Michelangelo (GE Global Research) on 3/18/18.
//
// Rolling buffer, extended with average
//

#include "extendedRollingBuffer.h"


// Constuctor with max capacity
extendedRollingBuffer::extendedRollingBuffer(int maxCap) {
    maxCapacity=maxCap;
}

// Destructor
extendedRollingBuffer::~extendedRollingBuffer() {
    buffer.clear();
}

// Insert new element
void extendedRollingBuffer::insertNewItem(int input) {

    if (buffer.size()<maxCapacity){
        // vector yet to be filled - keep pushing
        buffer.push_back(input);

        // initialize iterator after first insertion
        if (buffer.size() > 0) {
            next=buffer.begin();
        }
    }

    else{
        // vector filled - implementing rolling buffer
        // reset iterator to beginning of vector every time max cap is reached
        if ((next-buffer.begin() == maxCapacity)){
                next=buffer.begin();
        }

        *next = input;
        next++;
    }
}

// Calculate average
double extendedRollingBuffer::getAverage() {
    int sum = 0;

    for (int i = 0; i<buffer.size(); i++){
        sum = sum+buffer[i];
    }

    return (double(sum)/buffer.size());
}

// Get current size of the vector
int extendedRollingBuffer::getCurrSize() {

    return buffer.size();
}