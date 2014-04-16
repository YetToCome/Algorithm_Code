#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 5, W = 100;

int d[N + 1][W + 1];

int w[N] = {50, 30, 45, 25, 5};
int v[N] = {200, 180, 225, 200, 50};

int knapsack(int i, int j) {
    if (d[i][j] > 0) {
        return d[i][j];
    }
    int res;
    if (i == N) {
        res = 0;
    } else if (j < w[i]) {
        res = knapsack (i + 1, j);
    } else {
        res = max(knapsack(i + 1, j), knapsack(i + 1, j - w[i]) + v[i]);
    }
    return d[i][j] = res;
}

int main()
{
    memset(d, -1, sizeof(d));
    cout << knapsack(0, W) << endl;
    return 0;
}
