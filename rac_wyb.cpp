#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

 //double pi = 3.141593;
 double num = 2.54 * 3.141593;
//double num =  0.00007979646 ;

struct Car {
    string name;
    double p;
    long long int d;
    long long int rotations;
};

bool compareCars(const Car& car1, const Car& car2) {
    if (car1.rotations != car2.rotations) {
        return car1.rotations < car2.rotations;
    }
    return car1.name < car2.name;
}

int main() {
std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

     long int n;
    cin >> n;
    cin.ignore();

    vector<Car> cars(3);

    for (int i = 0; i < 3; ++i) {
        getline(cin, cars[i].name);
        cin >> cars[i].p >> cars[i].d;
        cin.ignore();
        cars[i].rotations = (long long int )((cars[i].p * 100000) / (cars[i].d * num));

    }
sort(cars.begin(), cars.end(), compareCars);

    for (int i = 3; i < n; ++i) {
        Car car;
        getline(cin, car.name);
        cin >> car.p >> car.d;
        cin.ignore();
        car.rotations = (long long int)((car.p * 100000)/ (car.d * num));

        if (car.rotations < cars[2].rotations) {
            cars[2] = car;
            //sort(cars.begin(), cars.end(), compareCars);
        }
        else if (car.rotations == cars[2].rotations) {
            if (car.name < cars[2].name) {
                cars[2] = car;
            }
        }
        sort(cars.begin(), cars.end(), compareCars);
    }

    sort(cars.begin(), cars.end(), compareCars);

    for (int i = 0; i < 3; i++) {
        cout << cars[i].name << endl;
        cout << cars[i].rotations << endl;
    }

    return 0;
}
