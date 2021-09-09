#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  vector<vector<int>> lst(a.size()+1,vector<int>(b.size()+1));
  for (int i=1;i<=a.size();i++){
     for (int j=1;i<=b.size();i++){ 
        if (i==0 || j==0){
           lst[i][j]=0;
         }else if(a[i-1]==b[j-1]){
           lst[i][j]=lst[i-1][j-1]+1;
         }else{
           lst[i][j]=max(lst[i-1][j],lst[i][j-1]);
         }
     }
  }
 return lst[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
