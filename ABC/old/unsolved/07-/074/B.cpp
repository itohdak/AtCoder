#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
  int n, k;
  vector<int> x;
  cin >> n >> k;
  int in;
  int i;
  for(i=0; i<n; i++){
    cin >> in;
    x.push_back(in);
  }
  int sum = 0;
  for(i=0; i<n; i++){
    sum += min(abs(x[i]-0), abs(x[i]-k));
  }
  cout << sum*2 << endl;
  return 0;
}
