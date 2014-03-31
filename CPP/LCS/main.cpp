#include <iostream>
#include <vector>

using namespace std;

enum {MAX_SIZE = 100};

int c[MAX_SIZE][MAX_SIZE] = {{0}};
char b[MAX_SIZE][MAX_SIZE];

template <typename T>
void LCS_LENGTH(T &X, T &Y) {
    size_t m = X.size();
    size_t n = Y.size();
    for (size_t i = 1; i <= m; ++i) c[i][0] = 0;
    for (size_t j = 0; j <= n; ++j) c[0][j] = 0;
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } else {
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = '|';
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = '-';
                }
            }
        }
    }
}

template <typename T>
void PRINT_LCS(T &X, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == '\\') {
        PRINT_LCS(X, i - 1, j - 1);
        cout << X[i];
    } else if (b[i][j] == '|') {
        PRINT_LCS(X, i - 1, j);
    } else {
        PRINT_LCS(X, i, j - 1);
    }
}

int main()
{
    string X{"ALLAAQANKESSSESFISRLLAIVAD"};
    string Y{"KLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG"};
    LCS_LENGTH(X, Y);
    PRINT_LCS(X, X.size(), Y.size());
    return 0;
}
