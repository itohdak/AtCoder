#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

void print_cards(vector<ll> &cards){
  for(vector<ll>::iterator it=cards.begin(); it!=cards.end(); it++){
    cout << *it << ' ';
  }
  cout << endl;
}

bool prime_p(int num){
  for(int i=2; i<num; i++){
    if(num % i == 0)
      return false;
  }
  return true;
}

void erase_cards(vector<ll> &cards, const ll picked_cards){
  // print_cards(cards);
  for(int i=2; i<35; i++){
    if(prime_p(i)){
      if(picked_cards % i == 0){
	vector<ll>::iterator it = cards.begin();
	while(it != cards.end()){
	  if(*it % i == 0)
	    cards.erase(it);
	  else
	    it++;
	  if(it == cards.end())
	    break;
	}
      }
    }
  }
  // print_cards(cards);
}

int calc(vector<ll> &cards){
  if(cards.size() == 0){
    return 1;
  } else {
    ll top = cards[0];
    cards.erase(cards.begin());
    vector<ll> copy_cards;
    copy(cards.begin(), cards.end(), back_inserter(copy_cards));
    erase_cards(copy_cards, top);
    return calc(copy_cards) + calc(cards);
  }
}

int main(){
  ll A, B;
  cin >> A >> B;
  vector<ll> cards;
  for(ll i=A; i<=B; i++)
    cards.push_back(i);
  cout << calc(cards) << endl;
  return 0;
}
