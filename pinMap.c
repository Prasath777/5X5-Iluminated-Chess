#include "pinMap.h"
#include <stdio.h>
#include <stdlib.h>

#define NumPinsPerHeader 46

GPIO_Pin GPIO_pinList[] = {
    /*{8,  3}, {8,  4}, {8,  5}, 
    {8,  6}, {8,  7}, {8,  8}, 
    {8,  9}, */ 

    //UNUSED/PROBLEM PINS:
    /*{8, 13},*/
    /*{8, 20}, {8, 21}, {8, 22}, {8, 23}, {8, 24}, {8, 25}, */
    {8, 10}, {8, 11}, {8, 12}, {8, 14}, {8, 15},
    {8, 16}, {8, 17}, {8, 18}, {8, 19}, {8, 26}, 
    {8, 27}, {8, 28}, {8, 29}, {8, 30}, {8, 32}, 
    {8, 33}, {8, 34}, {8, 35}, {8, 36}, {8, 37}, 
    {8, 38}, {8, 39}, {8, 40}, {8, 45}, {8, 46},
    
    // {8, 42}, //used for button
    {9, 11}, {9, 12}, {9, 13}, {9, 14}, {9, 15}, {9, 16},
    {9, 19}, {9, 20}, {9, 21}, {9, 22}, {9, 23}, {9, 24}, {9, 25}, {9, 26}, {9, 27}, {9, 28},
    {9, 29}, {9, 30}, {9, 31}, {9, 41}, {9, 42}
};

int P9_map[] = {
    0, //0
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,//1...10
    30, 60, 31, 50, 48, 51,  0,  0,  5,  4,//11...20
     3,  2, 49, 15,117, 14,115,113,111,112, //21...30
    110, 0,  0,  0,  0,  0,  0,  0,  0,  0, //31...40
    20,  7,  0,  0,  0,  0 //41...46
};

int P8_map[] = {
    0, 0, 0,
    38, 39, 34, 35, 66, 67, 69, 68, 45, 44, //4...13
    23, 26, 47, 46, 27, 65, 22, 63, 62, 37, //14...23
    36, 33, 32, 61, 86, 88, 87, 89, 10, 11, //24...33
     9, 81,  8, 80, 78, 79, 76, 77, 74, 75, //34...43
    72, 73, 70, 71 //41...50
};

//gets the GPIO number ex: gpio72
int getGPIO(int header_num, int pin_num)
{
    if(pin_num <= 0 || pin_num > NumPinsPerHeader){
        printf("ERROR: NOT A VALID PIN");
        exit(-1);
    }
    int result;
    if (header_num == 9) {
        result = P9_map[pin_num];
    } else if (header_num == 8) {
        result = P8_map[pin_num];
    } else {
        printf("ERROR: NOT A VALID PIN HEADER");
        exit(-1);
    }

    if (result == 0){
        printf("ERROR p%d.%d is NOT a gpio pin", header_num, pin_num);
        exit(-1);
    }
    return result;
}