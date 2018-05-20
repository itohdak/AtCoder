#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
  }
  int max_index = distance(A.begin(), max_element(A.begin(), A.end()));
  int min_index = distance(A.begin(), min_element(A.begin(), A.end()));
  int max = A[max_index];
  int min = A[min_index];
  if(min >= 0){
    cout << N-1 << endl;
    for(int i=0; i<N-1; i++)
      cout << i+1 << ' ' << i+2 << endl;
  } else if(max < 0){
    cout << N-1 << endl;
    for(int i=N-2; i>=0; i--)
      cout << i+2 << ' ' << i+1 << endl;
  } else if(abs(min) <= max){
    cout << 2*N-1 << endl;
    for(int i=0; i<N; i++)
      cout << max_index+1 << ' ' << i+1 << endl;
    for(int i=0; i<N-1; i++)
      cout << i+1 << ' ' << i+2 << endl;
  } else if(abs(min) > max){
    cout << 2*N-1 << endl;
    for(int i=0; i<N; i++)
      cout << min_index+1 << ' ' << i+1 << endl;
    for(int i=N-2; i>=0; i--)
      cout << i+2 << ' ' << i+1 << endl;
  }
  return 0;
}

