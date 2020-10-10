#include "header.hpp"

bool comp(int i, int j){
  // return i <= j;
  return i < j;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++)
    A[i] = 1;
  sort(A.begin(), A.end(), comp);
  for(int i=0; i<N; i++)
    cout << A[i] << ' ';
  cout << endl;
  return 0;
}

// https://stackoverflow.com/questions/6978201/why-does-stdsort-throw-a-segmentation-fault-on-this-code
// https://stackoverflow.com/questions/1541817/sort-function-c-segmentation-fault
