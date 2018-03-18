//
// How to implement a rolling buffer concept in C++
//

#include <iostream>
#include "src/extendedRollingBuffer.h"
#include "src/simpleLogger.h"

using namespace std;

int main() {

    int max_cap = 10;               // max actual capacity

   extendedRollingBuffer rollBuff(max_cap);

    for (int i = 0; i<21; i++){

        rollBuff.insertNewItem(rand() % 100);

        LOG_INFO << "Current vector size/average = " << rollBuff.getCurrSize() << "/" << rollBuff.getAverage();

    }

    return 0;
}
