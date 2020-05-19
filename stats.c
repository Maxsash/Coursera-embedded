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
  print_statistics(test, SIZE);
}

void print_statistics(unsigned char *data, unsigned int size){
  printf("\nPrinting the contents of dataset...\n\n");
  print_array(data, SIZE);
  printf("\nThe Median rounded off to integer is %d\n", find_median(data, SIZE));
  printf("The Mean rounded off to integer is %d\n", find_mean(data, SIZE));
  printf("The Maximum value is %d\n", find_maximum(data, SIZE));
  printf("The Minimum value is %d\n", find_minimum(data, SIZE));
  printf("\nThe sorted dataset...\n\n");
  print_array(data, SIZE);
}

void print_array(unsigned char *data, unsigned int size){
  int i;
  for(i=0;i<size;i++){
    printf("Index[%d] = %d\t",i, data[i]);
        if((i+1)%4==0){
      printf("\n\n");
    }
  }
}

unsigned int find_median(unsigned char *data, unsigned int size){
  int i;
  sort_array(data, size);
  if(size%2!=0){
    return data[size/2];
  }
  else{
    return (data[size/2]+data[(size/2)+1])/2;
  }
}

unsigned int find_mean(unsigned char *data, unsigned int size){
  int i, sum=0;
  for(i=0;i<size;i++){
    sum += data[i];
  }
  return (sum/size);
}

unsigned int find_maximum(unsigned char *data, unsigned int size){
  int i;
  sort_array(data, size);
  return data[0];
}

unsigned int find_minimum(unsigned char *data, unsigned int size){
  int i;
  sort_array(data, size);
  return data[size-1];
}

void sort_array(unsigned char *data, unsigned int size){
  //implementing reverse bubblesort
  int i, j; 
   for (i = 0; i < (size-1); i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < (size-i-1); j++)  
           if (data[j] < data[j+1]) 
              swap(&data[j], &data[j+1]); 
}

void swap(unsigned char *first, unsigned char *second){
  unsigned char temp;
  temp = *first;
  *first = *second;
  *second = temp;
}
