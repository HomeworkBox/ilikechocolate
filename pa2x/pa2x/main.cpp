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

bool arrays_equal(int *a1, int *a2, const int n) {
    if(!a1 && !a2 || n == 0)
        return true;
    else if(a1 && !a2 || !a1 && a2 || n < 0)
        return false;
    else {
        for(int i = 0; i < n; i++) {
            if(a1[i] != a2[i])
                return false;
        }
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    int testarray[]={  -1, 0, -2 }, a2[]={ -2, -1, 0};
    merge_sort(&testarray[0], 3);
    for (int i=0; i<3; i++){
        std::cout << testarray[i]<<'\n';
    }
//    std::cout << "1 for fail 0 for good\n"
//    << insertion_sort(&testarray[4],6) << "\n"
//    << testarray[0]<< testarray[1]<< testarray[2]<< testarray[3] << testarray[4];
//
    
    std::cout << arrays_equal(&testarray[0], &a2[0], 2)<< "\nHello, World!\n";
    return 0;
}

