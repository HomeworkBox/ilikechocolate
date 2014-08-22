//
//  experimental.h
//  pa2x
//
//  Created by Tyler Weimin Ouyang on 8/21/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//
#include <stdlib.h>
#include <string.h>

#ifndef pa2x_experimental_h
#define pa2x_experimental_h

 #define SWAP(type, a, b) \
do { type t=(a);(a)=(b);(b)=t; } while (0)

static void reverse_(int* a, int* b)
{
    for ( --b; a < b; a++, b-- )
        SWAP(int, *a, *b);
}
static int* rotate_(int* a, int* b, int* c)
/* swap the sequence [a,b) with [b,c). */
{
    if (a != b && b != c)
    {
        reverse_(a, b);
        reverse_(b, c);
        reverse_(a, c);
    }
    return a + (c - b);
}

static int* lower_bound_(int* a, int* b, const int key)
/* find first element not less than @p key in sorted sequence or end of
 * sequence (@p b) if not found. */
{
    int i;
    for ( i = b-a; i != 0; i /= 2 )
    {
        int* mid = a + i/2;
        if (*mid < key)
            a = mid + 1, i--;
    }
    return a;
}
static int* upper_bound_(int* a, int* b, const int key)
/* find first element greater than @p key in sorted sequence or end of
 * sequence (@p b) if not found. */
{
    int i;
    for ( i = b-a; i != 0; i /= 2 )
    {
        int* mid = a + i/2;
        if (*mid <= key)
            a = mid + 1, i--;
    }
    return a;
}

static void ip_merge_(int* a, int* b, int* c)
/* inplace merge. */
{
    int n1 = b - a;
    int n2 = c - b;
    
    if (n1 == 0 || n2 == 0)
        return;
    if (n1 == 1 && n2 == 1)
    {
        if (*b < *a)
            SWAP(int, *a, *b);
    }
    else
    {
        int* p, * q;
        
        if (n1 <= n2)
            p = upper_bound_(a, b, *(q = b+n2/2));
        else
            q = lower_bound_(b, c, *(p = a+n1/2));
        b = rotate_(p, b, q);
        
        ip_merge_(a, p, b);
        ip_merge_(b, q, c);
    }
    
}

void mergesort2(int* v, int n)
{
    if (n > 1)
    {
        int h = n/2;
        mergesort2(v, h); mergesort2(v+h, n-h);
        ip_merge_(v, v+h, v+n);
    }
}
#endif
