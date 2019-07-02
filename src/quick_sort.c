#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}



int pivot;
int j;
/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int i;
  if (sizeof(A[n])==0){
      return ;
  }
  for(i=0;i<n;i++){
        pivot = A[n/2];
        A[n/2] = A[0];
        A[0] = pivot;
      for(i = j =1; i < n ; i++){
          if (A[i] <= pivot){
              swap(A+i,A+j);
              j++;
            }
          }
       swap(A+0,A+j-1);
     }
   quick_sort(A+0, j-1),quick_sort(A+j+1,n-j);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }}
