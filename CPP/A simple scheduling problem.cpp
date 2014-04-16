#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> time = {15, 8, 3, 10};
constexpr int N = 4;

int main()
{
    sort(time.begin(), time.end(), less<int>());
    for (int i = 1; i != N; ++i) {
        time[i] += time[i - 1];
    }
    cout << accumulate(time.begin(), time.end(), 0) << endl;
    return 0;
}
