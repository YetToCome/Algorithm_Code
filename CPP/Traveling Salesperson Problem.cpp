#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

constexpr int INF = 10000;
constexpr size_t N = 7;
vector<vector<int>> MAP{{INF, 16 , 12 , 13 , 6  , 7  , 11},
                        {INF, INF, 21 , 18 , 8  , 19 , 5 },
                        {INF, INF, INF, 20 , 1  , 3  , 15},
                        {INF, INF, INF, INF, 14 , 10 , 4 },
                        {INF, INF, INF, INF, INF, 2  , 17},
                        {INF, INF, INF, INF, INF, INF, 9 },
                        {INF, INF, INF, INF, INF, 9  ,INF}};

set<int> Nodes;

int main()
{
    while (Nodes.size() != N) {
            int ss;
        int min_nodes = INF;
        int min_i = 0, min_p = 0;
        for (size_t i = 0; i != MAP.size(); ++i) {
            auto p = min_element(MAP[i].begin(), MAP[i].end());
            if (min_nodes > *p){
                min_nodes = *p;
                min_i = i; min_p = 0;
                for (auto x = MAP[i].begin(); x != p; ++min_p, ++x);
            }
        }
        cout << min_i << " " << min_p << endl;
        if (Nodes.find(min_i) == Nodes.end() || Nodes.find(min_p) == Nodes.end()){
            Nodes.insert(min_i);
            Nodes.insert(min_p);
        }
        for (auto x : Nodes) {
            cout << x << endl;
        }
        cin >> ss;
    }
    return 0;
}
