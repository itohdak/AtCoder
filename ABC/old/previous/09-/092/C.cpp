#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> A, D1, D2;
  ll sum = 0;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
    if(i == 0){
      int d1 = abs(in);
      D1.push_back(d1);
      sum += d1;
    } else {
      int d1 = abs(in - A[i-1]);
      D1.push_back(d1);
      sum += d1;
    }

    if(i > 0){
      if(i == 1){
	int d2 = abs(in);
	D2.push_back(d2);
      } else {
	int d2 = abs(in - A[i-2]);
	D2.push_back(d2);
      }
    }
  }
  sum += abs(A[N-1]);
  D1.push_back(abs(A[N-1]));
  D2.push_back(abs(A[N-2]));

  for(int i=0; i<N; i++){
    cout << sum - D1[i] - D1[i+1] + D2[i] << endl;
  }
  return 0;
}

