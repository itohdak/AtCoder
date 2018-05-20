#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A;
  for(int i=0; i<N; i++){
    long long in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  vector<long long>::iterator it = A.begin();
  int ret = 0;
  while(it < A.end()){
    long long tmp = *it;
    int num = 0;
    while(*it == tmp && it < A.end()){
      it++;
      num++;
    }
    if(num < tmp){
      ret += num;
    } else {
      ret += num - tmp;
    }
  }
  cout << ret << endl;
  return 0;
}

