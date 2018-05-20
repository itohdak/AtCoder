#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A, B, C;
  int input;
  for(int i=0; i<N; i++){
    cin >> input;
    A.push_back(input);
  }
  for(int i=0; i<N; i++){
    cin >> input;
    B.push_back(input);
  }
  for(int i=0; i<N; i++){
    cin >> input;
    C.push_back(input);
  }
  sort(A.begin(), A.end(), less<int>());
  sort(C.begin(), C.end(), less<int>());

  long long ret = 0;
  for(vector<int>::iterator b=B.begin(); b!=B.end(); b++){
    int val = *b;
    vector<int>::iterator a = lower_bound(A.begin(), A.end(), val);
    vector<int>::iterator c = upper_bound(C.begin(), C.end(), val);
    ret += ((long long)(a - A.begin()) * (long long)(C.end() - c));
  }

  cout << ret << endl;

  return 0;
}

