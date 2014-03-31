#include <iostream>
#include <vector>
#include <utility>

using namespace std;

enum {MAX_SIZE = 100};

int c[MAX_SIZE][MAX_SIZE] = {{0}};
char b[MAX_SIZE][MAX_SIZE];

template <typename T>
pair<int, int> LCS_LENGTH(T &X, T &Y) {
    int max_len = 0;
    int max_end = 0;
    for (size_t i = 0; i != X.size(); ++i) {
        for (size_t j = 0; j != Y.size(); ++j) {
            if (X[i] != Y[j]) c[i][j] = 0;
            else {
                if (i == 0 || j == 0) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = c[i - 1][j - 1] + 1;
                }
                if (c[i][j] > max_len) {
                    max_len = c[i][j];
                    max_end = i;
                }
            }
        }
    }
    return make_pair(max_len, max_end);
}

int main()
{
    string X{"xzyzzyx"};
    string Y{"zxyyzxz"};
    auto a = LCS_LENGTH(X, Y);
    cout << a.first << endl;
    for (size_t i = a.first; i != 0; --i) cout << X[a.second - i + 1];
    cout << endl;
    return 0;
}
