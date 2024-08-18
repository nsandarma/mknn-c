#include "mknn.h"

// KNN
// 1. create_synthetic_data
// 2. calculate_distances
// 3. sorted
// 4. voting

void knn(Data *data , u8 rows , u8 cols, u8 k){
  calculate_distances(data, rows, cols);
  sorted(data,rows);
  voting(data,rows,k);
  print_predict(data,rows);
}

// MKNN
// 1. create_synthetic_data
// 2. calculate_distances
// 3. sorted
// 4. validity
// 5. calculate_weight

void mknn(Data *data, u8 rows, u8 cols, u8 k){
  calculate_distances(data, rows, cols);
  sorted(data,rows);
  validity(data, rows,k);
  calculate_weight(data,rows,k);
  print_predict(data,rows);
}



int main(void){
  u8 rows = Rows, cols = Cols, k = K;
  Data *data = create_synthetic_data(rows,cols,cols);
  mknn(data,rows,cols,k);

  free_data(data, rows);
  return 0;
}
