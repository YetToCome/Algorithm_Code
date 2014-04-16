#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 5, W = 100;

int d[N + 1][W + 1];

int w[N] = {50, 45, 30, 25, 5};
int v[N] = {200, 225, 180, 200, 50};

int knapsack() {
    double maxValue = 0;
    int sum = 0, i = 0;
    for (i = 0; i != N; ++i) {
        if (sum + w[i] < W) {
            sum += w[i];
            maxValue += v[i];
        } else {
            break;
        }
    }
    if (i < N&&sum < W) {
        maxValue += (double)(W - sum) / w[i] * v[i];
    }
    return maxValue;
}

int main()
{
    cout << knapsack() << endl;
    return 0;
}
