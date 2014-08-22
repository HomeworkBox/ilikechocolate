//
//  main.cpp
//  pa2x
//
//  Created by Tyler Weimin Ouyang on 8/16/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//

#include <iostream>
#include "sorting.h"
#include <ctime>
#include <cstdlib>


int main(int argc, const char * argv[]) {
    int testarray[]={ 1,2,9,10,11,12,3,4,5,6}, a2[]={ 10, 5, 1, 4, 5, 7, 2, 3, 6, 8, 9, 5, 5, 1, 4, 5, 7, 2, 3, 6, 8, 9,101,68,46,54,3};
    int test[]={7,8,9,10,3,4,5,6};
//    reverse(&test[0], &test[7]);
//    exchange(&test[0], &test[4], &test[7]);
    int *data = new int[99];
    for(int i = 0; i < 99; i++) {
        data[i] = 100-i;
    }
    
//    merge_sort(&a2[0], 27);
    
    partition(&testarray[0], &testarray[9]);
    
    for (int i=0; i<10; i++){
        std::cout << testarray[i]<<'\n';
    }
//    int * location = search(&testarray[0], 0, 10);
//    std::cout << "the location is " << location << ", which is "<< *location;
//    std::cout << "1 for fail 0 for good\n"
//    << insertion_sort(&testarray[4],6) << "\n"
//    << testarray[0]<< testarray[1]<< testarray[2]<< testarray[3] << testarray[4];
//
    
    std::cout << "\nHello, World!\n";
    return 0;
}

