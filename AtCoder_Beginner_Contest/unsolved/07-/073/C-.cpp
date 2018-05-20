#include <iostream>
#include <cstdlib>

using namespace std;

#define max_n 100000

int main(){
  int n;
  int a[max_n], b[max_n];
  int end = 0;
  int i, j;
  cin >> n;
  for(j=0; j<n; j++){
    int input;
    cin >> input;
    bool is_there = false;
    for(i=0; i<end; i++){
      if(a[i] == input){
        is_there = true;
        break;
      }
    }
    if(is_there == false){
      end++;
      a[i] = input;
      b[i] = 1;
    } else {
      b[i]++;
    }
  }

  int ret = 0;
  for(i=0; i<end; i++){
    if(b[i] % 2 == 1){
      ret++;
    }
  }
  cout << ret << endl;

  return 0;
}
