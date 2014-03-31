#include <iostream>
#include <vector>

using namespace std;

enum {MAX_SIZE = 100};
enum {INF = 10000};

int m[MAX_SIZE][MAX_SIZE] = {{0}};
int s[MAX_SIZE][MAX_SIZE] = {{0}};

template <typename T>
void MATRIX_CHAIN_ORDER(T & p) {
    int n = p.size() - 1;
    for (int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }
    for (int L = 2; L <= n; ++L) {
        for (int i = 1; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            m[i][j] = INF;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void PRINT_OPTIMAL_PARENS(int i, int j) {
    if (i == j) {
        cout << "A";
    } else {
        cout << "(";
        PRINT_OPTIMAL_PARENS(i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    vector<int> p{3, 5, 2, 1, 10};
    MATRIX_CHAIN_ORDER<vector<int>>(p);
    PRINT_OPTIMAL_PARENS(1, p.size() - 1);
    return 0;
}
