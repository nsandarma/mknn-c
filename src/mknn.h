#ifndef MKNN_H
#define MKNN_H

#define u8 unsigned char

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  float weight;
  float *x;
  float *distances;
  u8    *idx_neighbors;
  u8    validity;
  u8    predict;
  u8    y;
}Data;


u8 generate_class(float *x,u8 size,float th);
Data* create_synthetic_data(u8 rows, u8 cols,float th);
void print_data(Data* data, u8 rows, u8 cols);
void free_data(Data* data, u8 rows); 
float euclidean(Data row1, Data row2, u8 cols);

void print_distances(Data *data,u8 rows);
void print_idx_dist(Data *data, u8 rows);
void print_y(Data *data, u8 rows);
void print_validity(Data *data, u8 rows);
void print_predict(Data *data, u8 rows);

void calculate_distances(Data *data, u8 rows,u8 cols);
void calculate_weight(Data *data,u8 rows,u8 k);

void sort(float *arr,u8 *indices, u8 rows);
void sorted(Data *data, u8 rows);
void voting(Data *data, u8 rows, u8 k);
void validity(Data *data, u8 rows, u8 k);
float accuracy(Data *data, u8 rows);
u8 count_value(u8 *arr, u8 size);

#endif 

#ifndef R
#define R 2.0
#endif // !R

#ifndef Rows
#define Rows 10
#endif // !Rows

#ifndef Cols
#define Cols 3
#endif // !Cols

#ifndef K
#define K  2
#endif // !K
