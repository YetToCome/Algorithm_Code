#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

constexpr int INF = 10000;
constexpr size_t N = 7;
vector<vector<int>> MAP{{INF, 16 , 12 , 13 , 6  , 7  , 11},
                        {16 , INF, 21 , 18 , 8  , 19 , 5 },
                        {12 , 21 , INF, 20 , 1  , 3  , 15},
                        {13 , 18 , 20 , INF, 14 , 10 , 4 },
                        {6  , 8  , 1  , 14 , INF, 2  , 17},
                        {7  , 19 , 3  , 10 , 2  , INF, 9 },
                        {11 , 5  , 15 , 4  , 17 , 9  , INF}};

vector<int> Nodes;
multimap<int, pair<int, int>> Map_Node;
list<pair<int, pair<int, int>>> Sorted_Map;

int main()
{
    int SUM = 0;
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            Map_Node.insert(make_pair(MAP[i][j], make_pair(i, j)));
        }
    }
    for (auto a = Map_Node.begin(); a != Map_Node.end() && a->first != INF; ++a) {
        Sorted_Map.push_back(make_pair(a->first, make_pair(a->second.first, a->second.second)));
    }
    while (Nodes.size() != N) {
        for (auto node = Sorted_Map.begin(); node != Sorted_Map.end(); ++ node) {
            if (find(Nodes.begin(), Nodes.end(), node->second.first) == Nodes.end() || find(Nodes.begin(), Nodes.end(), node->second.second) == Nodes.end() )
            if (Nodes.empty() || node->second.first == Nodes.back()) {
                cout << node->second.first << "->" << node->second.second << " "<< node->first<<endl;
                SUM += node->first;
                if (Nodes.empty())
                    Nodes.push_back(node->second.first);
                Nodes.push_back(node->second.second);
                node = Sorted_Map.erase(node);
            }
        }
    }
    cout << SUM << endl;
    return 0;
}
