#include <iostream>
#include <cstdlib>

using namespace std;

#define max_n 1000

int main(){
  int n;
  int l[max_n], r[max_n];
  cin >> n;
  int i;
  for(i=0; i<n; i++){
    cin >> l[i];
    cin >> r[i];
  }
  int sum = 0;
  for(i=0; i<n; i++){
    sum += r[i] - l[i] + 1;
  }
  cout << sum << endl;
  return 0;
}

