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


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int i, pivot , j,l,r;
  if (n==0)   
      return ;
pivot = A[0];
  l = 0;
  r = n;
  i = 1;
  while(i < r){
    if(A[i] < pivot){
      swap(A+i, A+l);
      l++;
      i++;
    }
    else if(A[i] > pivot){
      r--;
      swap(A+i, A+r);
    }
    else i++;
  }
  quick_sort(A, l);
  quick_sort(A+r, n-r);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
