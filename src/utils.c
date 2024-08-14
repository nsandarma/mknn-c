#include "mknn.h"

void print_y(Data *data,u8 rows){

  for(u8 i=0; i < rows; i++)
  {
    printf("idx : %d | y : %d\n",i,data[i].y);
  }

}

void print_validity(Data *data, u8 rows){
  printf("idx \t | validity\n");
  for (u8 i=0; i < rows; i++)
  {
    printf("%d \t | %d\n",i,data[i].validity);
  }
}

void print_predict(Data *data, u8 rows){
  printf("idx \t | predict \t | actual\n");
  for (u8 i = 0; i < rows; i++){
    printf("%d \t | %d \t\t | %d\n",i,data[i].predict,data[i].y);
  }
}

void print_distances(Data *data, u8 rows)
{
  for (u8 i = 0; i < rows; i++) {
    printf("Row %d\t: ", i);
    for (u8 j = 0; j < rows; j++) {
        printf("%f |", data[i].distances[j]);
    }
    printf("\n");
  }
}

void print_idx_dist(Data *data, u8 rows){
  printf("IDX distances : \n");
  for (u8 i = 0; i < rows ; i ++){
    printf("Row %d\t: ", i);
    for (u8 j = 0; j < rows; j++) {
        printf("%d |", data[i].idx_neighbors[j]);
    }
    printf("\n");
  }
}

void print_data(Data* data, u8 rows, u8 cols)
{
  for (u8 i = 0; i < rows; i++) {
      printf("Row %d\t: ", i);
      for (u8 j = 0; j < cols; j++) {
          printf("%f \t|", data[i].x[j]);
      }
      printf(" = y : %d",data[i].y);
      printf("\n");
  }
}

float accuracy(Data *data, u8 rows){
  float sum = 0.0;
  for(u8 i = 0 ; i < rows; i++){
    if (data[i].predict == data[i].y){
      sum += 1.0;
    }
  }

  return sum / rows;
}

u8 generate_class(float *x,u8 size,float th){
  float temp = 0;
  for(u8 i  = 0; i < size ; i++){
    temp += x[i];
  }
  if(temp < th){
    return 0;
  }else{
    return 1;
  }
}

void sort(float *data,u8 *indices,u8 rows){
  u8 i,j;
  for(i=0; i < rows; i++){
    for (j = 0; j < rows - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        float temp = data[j];
        u8 idx = indices[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
        indices[j] = indices[j + 1];
        indices[j+1] = idx;
      }
    }
  }
}

void sorted(Data *data,u8 rows){
  for(u8 i =0 ; i < rows; i ++){
    sort(data[i].distances,data[i].idx_neighbors,rows);
  }
}

u8 count_value(u8 *arr,u8 size){
  u8 maxCount = 0;
  u8 mostFrequent = arr[0];

  for (int i = 0; i < size; i++) {
      int count = 0;
      for (int j = 0; j < size; j++) {
          if (arr[j] == arr[i]) {
              count++;
          }
      }

      if (count > maxCount) {
          maxCount = count;
          mostFrequent = arr[i];
      }
  }
  return mostFrequent;
}



