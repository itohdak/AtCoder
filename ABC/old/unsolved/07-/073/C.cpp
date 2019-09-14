#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define max_n 100000

int main(){
  int n;
  int a[max_n];
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a, a+n);

  int index = 0;
  int ret = 0;
  while(index < n){
    int num = 0;
    int tmp = a[index];
    while(index < n && a[index] == tmp){
      num++;
      index++;
    }
    ret += num%2;
  }
  cout << ret << endl;

  return 0;
}
