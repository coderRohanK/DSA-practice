#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    sort(cars.rbegin(), cars.rend());
    stack<double> st;
    for (auto& car : cars) {
        double time = car.second;
        if (st.empty() || time > st.top())
            st.push(time);
    }
    return st.size();
}

int main() {
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    cout << "Number of car fleets: " << carFleet(target, position, speed);
}
