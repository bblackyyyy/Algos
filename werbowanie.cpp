#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//const long long MOD = 1000003;
struct Person {
    string name;
    long long minute;
};
// void sort(Person p[], long long n){
//   for(long long i  =0; i<n; i++){
//     for(long long j = i+1; j<n; j++){
//       if(p[i].name > p[j].name){
//         Person tmp = p[i];
//         p[i] = p[j];
//         p[j] = tmp;
//       }
//     }
//   }
// }
// void sort(Person arr[], long long size) {
//     for (long long i = 0; i < size - 1; i++) {
//         for (long long j = i + 1; j < size; j++) {
//             if (arr[i].minute == arr[j].minute) {
//                 if (arr[i].name > arr[j].name) {
//                     swap(arr[i], arr[j]);
//                 }
//             }
//         }
//     }
// }
void shellSort(Person arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Person temp = arr[i];
            int j;
            for (  j = i; j >= gap && (arr[j - gap].minute < temp.minute || (arr[j - gap].minute == temp.minute && arr[j - gap].name > temp.name)); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// void insertionSort(Person arr[], int n) {
//     for (int i = 1; i < n; ++i) {
//         Person key = arr[i];
//         int j = i - 1;
//
//         while (j >= 0 && arr[j].minute < key.minute) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//
//         arr[j + 1] = key;
//     }
// }

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, p;
        cin >> n >> p;
        Person people[n];
        //long long size = sizeof(people) / sizeof(people[0]);
        for (long long i = 0; i < n; i++) {
            cin >> people[i].name >> people[i].minute;
        }
       shellSort(people, n);
      //insertionSort(people, n);
// for(long long i =0; i<p; i++){
//   for(long long j = i+1; j<p; j++){
//     if(people[i].minute == people[j].minute){
//       sort(people, p);
//     }
//   }
// }
      //  sort(people,p);
        long long totalTime = 0;
        //if(people[i].minute)
        for (long long i = 0; i < n; i++) {
            totalTime += people[i].minute * i + 1;
        }
        for(int i = 0; i < p; i++) {
          cout << people[i].name << " ";
        }
        cout << "\n" << totalTime % (1000000+3) << endl;
    }
  //  cout << "\n" << totalTime << endl;
    return 0;
}
