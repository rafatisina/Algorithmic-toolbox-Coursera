#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;
using std::cin;
using std::cout;

long long MaxPairWiseProduct(const vector<int>& numbers){
  long long result=0;
  int n = numbers.size();

  for (int i=0;i<n;++i){
    for (int j=i+1;j<n;++j){

      if (((long long)numbers[i])*numbers[j] > result){

        result=((long long)numbers[i])*numbers[j];
      }
    }

  }
  return result;
}

long long MaxPairWiseProductfast(const vector<int>& numbers){
  long long result=0;
  int n = numbers.size();
  int maxindex1=-1;
  for (int i=0;i<n;i++){
    if ((maxindex1==-1) || (numbers[i]>numbers[maxindex1])){
      maxindex1=i;
    }
  }
  int maxindex2=-1;
  for (int j=0;j<n;j++){
    if ((j!=maxindex1) && ((maxindex2==-1) || (numbers[j]>numbers[maxindex2]))){
      maxindex2=j;
    }
  }
  return ((long long) (numbers[maxindex1]))*numbers[maxindex2];
}

int main()
{
/*while (true) {
  int n=rand()%100+2;
  cout<<n<<"\n";
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    a.push_back(rand()%100000);
  }

  for (int i = 0; i < n; ++i) {
      cout<<a[i]<<' ';
  }
  cout<<"\n";

  long long res1=MaxPairWiseProduct(a);
  long long res2=MaxPairWiseProductfast(a);

  if (res1!=res2){
    cout<< "Wrong answer: " << res1 << ' '<< res2 << "\n";
    break;
  }
  else{
    cout<<"OK\n";
  }
}*/
  int n;
  cin>>n;
  vector<int> numbers(n);

  for (int i=0; i<n; ++i) {
    cin >> numbers[i];
  }

  long long result = MaxPairWiseProductfast(numbers);
  cout << result <<"\n";
  return 0;
}
