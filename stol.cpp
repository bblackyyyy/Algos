#include <iostream>
//#include <string>
using namespace std;

struct food {
  char name[20];
  int cal;
};
// int minn(food arr[],  int n){
//   int min = arr[0].cal;
//   for(int i =0; i<n; i++){
//     if(min > arr[i].cal){
//       min = arr[i].cal;
//     }
//   }
//   return min;
// }


// int maxx(food arr[],  int n){
//   int max = arr[0].cal;
//   for(int i =0; i<n; i++){
//     if(max < arr[i].cal){
//       max = arr[i].cal;
//     }
//   }
//   return max;
// }
// int maxx(food arr[], int n) {
//   int max = arr[0].cal;
//   for (int i = 1; i < n; i++) {
//     if (max < (arr + i)->cal) {
//       max = (arr + i)->cal;
//     }
//   }
//   return max;
// }

void countingSort(food arr[], int n, int exp) {
  const int RANGE = 10;

  food output[n];
  int count[RANGE] = {0};

  for (int i = 0; i < n; i++) {
    count[(arr[i].cal / exp) % RANGE]++;
  }

  for (int i = 1; i < RANGE; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[--count[(arr[i].cal / exp) % RANGE]] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(food arr[], int n, int maxi) {
  int val_max =maxi; //maxx(arr,n);


  for (int exp = 1; val_max / exp > 0; exp *= 10) {
    countingSort(arr, n, exp);
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);




  int n;
  cin >> n;
  food *arr = new food[n];
  int maxi =0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].name >> arr[i].cal;
    if(maxi < arr[i].cal){
          maxi = arr[i].cal;
        }
      }

  radixSort(arr, n,maxi);

  for (int i = 0; i < n; i++) {
    cout<<arr[i].name<< " ";
  }

  delete[] arr;
  return 0;
}
