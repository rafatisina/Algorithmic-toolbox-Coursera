#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  int l=left;
  int r = ave;
  int curr = left;
  while(l < ave || r < right){
     if(l < ave && r < right){
         if(a[r] < a[l]){
             number_of_inversions += ave - l;
             b[curr++] = a[r++];
         }else{
             b[curr++] = a[l++];
         }
         continue;
     }
     if(l < ave) b[curr++] = a[l++];
     if(r < right) b[curr++] = a[r++];
 }
 for(int i = left; i < right; ++i){
     a[i] = b[i];
 }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
