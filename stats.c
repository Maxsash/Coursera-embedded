/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief The main file for program that does basic operations on data array.
 *
 * Contains functions that analyze an array of unsigned char data items and report array analytics on 
 * the maximum, minimum, mean and median of the dataset. Additionally, this data is reordered from large to 
 * small. Statistics are rounded donw to the nearest integer.
 *
 * @author Yash Shrivastava
 * @date 18th May 2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_array(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d\n", data);
  }
}

unsigned int find_median(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d\n", data);
  }
}

unsigned int find_mean(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d\n", data);
  }
}

unsigned int find_maximum(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d\n", data);
  }
}

unsigned int find_minimum(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("%d\n", data);
  }
}

unsigned char sort_array(unsigned char *data, unsigned int size){

}
