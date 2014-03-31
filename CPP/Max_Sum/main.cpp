#include <iostream>
#include <vector>

using namespace std;

vector<int> m{-2, 11, -4, 13, -5, -2};

template <typename T>
int sequence(const T & numbers) {
    int max_sum_number  = numbers[0], max_tail = numbers[0];
    for(size_t i = 1; i < numbers.size(); ++i) {
        if(max_tail < 0) {
            max_tail = numbers[i];
        } else {
            max_tail += numbers[i];
        }
        if(max_tail >= max_sum_number ) {
            max_sum_number  = max_tail;
        }
    }
    return max_sum_number;
}

int main() {
    cout << sequence(m);
    return 0;
}
