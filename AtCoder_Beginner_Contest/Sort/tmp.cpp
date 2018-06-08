#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
  // return i <= j;
  return i < j;
}

// int main(){
//   int data[] = {1, 5, 3, 2};
//   vector<int> A(data, data+4);
//   sort(A.begin(), A.end(), compare);

//   // output
//   for(size_t i=0; i<A.size(); i++)
//     cout << A[i] << ' ';
//   cout << endl;

//   return 0;
// }

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++)
    A[i] = 1;
  sort(A.begin(), A.end(), compare);

  // output
  for(int i=0; i<N; i++)
    cout << A[i] << ' ';
  cout << endl;

  return 0;
}
