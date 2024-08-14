#include "mknn.h"


int main(void){
  u8 rows = 10, cols = 5, k =2;
  Data *data = create_synthetic_data(rows,cols,cols);
  calculate_distances(data, rows, cols);
  // print_data(data, rows,cols);
  // printf("\n");
  // print_distances(data,rows);
  // printf("\n");
  //
  sorted(data, rows);
  // print_distances(data,rows);
  // printf("\n");
  print_idx_dist(data,rows);
  printf("\n");
  print_y(data,rows);
  printf("\n");
  validity(data,rows,k);
  print_predict(data,rows);
  printf("\n");
  print_validity(data,rows);
  calculate_weight(data,rows,k);
  printf("\n");
  print_predict(data,rows);

  printf("accuracy : %f\n",accuracy(data,rows));
  free_data(data, rows);
  return 0;
}
