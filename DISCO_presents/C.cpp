#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int n, c;
  cin >> n >> c;
  int l[n];
  for(int i=0; i<n; i++)
    cin >> l[i];
  sort(l, l+n);

  int begin = 0;
  int end = n-1;
  int num_box = 0;

  while(begin < end){
    if(l[begin] + l[end] + 1 > c){
      num_box++;
      end--;
    } else {
      num_box++;
      begin++;
      end--;
    }
  }
  if(begin == end){
    num_box++;
  }

  cout << num_box << endl;

  return 0;
}
