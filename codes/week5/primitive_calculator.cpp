#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> op_seq(int n){
  std:vector<int> lst;
  lst[0]=-1;
  lst[1]=0;
  lst[2]=1;
  lst[3]=1;
  for (int i=4;i<n;i++){
      if (i%3==0){
        lst[i]=lst[i/3]+1;
      }else if(i%2==0){
        lst[i]=lst[i/2]+1;
      }else{
        lst[i]=lst[i-1]+1;
      }
   }
  return lst;
 }

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
//  vector<int> sequence = optimal_sequence(n);
  vector<int> tst = op_seq(n);
 // std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < tst.size(); ++i) {
   // std::cout << sequence[i] << " ";
    std::cout<<tst[i]<<" ";
  }
}
