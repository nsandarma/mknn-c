#include "mknn.h"

void voting(Data *data,u8 rows,u8 k){
  u8 i,j;
  for(i=0; i < rows; i++)
  {
    u8 temp[k];
    for(j = 0 ; j < k; j++){
      temp[j] = data[data[i].idx_neighbors[j]].y;
    }
    data[i].predict = count_value(temp, k);
  }
}

void validity(Data *data,u8 rows,u8 k){
  voting(data,rows,k);
  for(u8 i = 0 ; i < rows; i++)
  {
    u8 actual = data[i].y;
    u8 predict = data[i].predict;
    if (actual == predict){
      data[i].validity = 1;
    }
    else{
      data[i].validity = 0;
    }
  }
}

Data* create_synthetic_data(u8 rows, u8 cols,float th) 
{
    Data* data = (Data*)malloc(rows * sizeof(Data));
    for (u8 i = 0; i < rows; i++) {
        data[i].x = (float*)malloc(cols * sizeof(float));
        for (u8 j = 0; j < cols; j++) {
            data[i].x[j] = ((float)rand()/(float)(RAND_MAX)) * R;
        }
        data[i].y = generate_class(data[i].x, cols,th);
    }
    return data;
}


void calculate_distances(Data *data,u8 rows,u8 cols)
{
  u8 i ,j;
  for(i = 0; i < rows ; ++i){
    data[i].distances = (float*)malloc(rows * sizeof(float));
    data[i].idx_neighbors = (u8*)malloc(rows * sizeof(u8));
    for (j = 0 ; j < rows ; ++j ){
      data[i].distances[j] = euclidean(data[i],data[j],cols);
      data[i].idx_neighbors[j] = j;
    }
  }
}

void calculate_weight(Data *data, u8 rows,u8 k)
{
  u8 i,j;

  for(i = 0 ; i < rows ; i++){
    float max_weight = 0.0;
    u8 indices = 0;
    for(j=0; j < k ; j ++){
      float dist = data[i].distances[j];
      u8 validity = data[i].validity;
      float weight = validity * 1 / (dist + 0.5);
      if (weight > max_weight){
        max_weight = weight;
        indices = data[i].idx_neighbors[j];
      }
    }
    data[i].predict = data[indices].y;
  }
}


void free_data(Data* data, u8 rows) 
{
  for (int i = 0; i < rows; i++) {
    free(data[i].x);
    data[i].x = NULL;
    free(data[i].distances);
    data[i].distances = NULL;
    free(data[i].idx_neighbors);
    data[i].idx_neighbors = NULL;
  }
  free(data);
  data = NULL;
}

float euclidean(Data row1, Data row2, u8 cols)
{
  float sum = 0.0;
  for (int i = 0; i < cols; i++) {
      float diff = (float)(row1.x[i] - row2.x[i]);
      sum += diff * diff;
  }
  return sqrt(sum);
}

