//
//  main.cpp
//  pa2x
//
//  Created by Tyler Weimin Ouyang on 8/16/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//

#include <iostream>
#include "sorting.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int testarray[5]={4,3,2,1,0};
    insertion_sort(&testarray[1],4);
    std::cout << testarray[0]<< testarray[1]<< testarray[2]<< testarray[3] << testarray[4];

    std::cout << "\nHello, World!\n";
    return 0;
}
