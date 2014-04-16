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

vector<int> Nodes; //所有添加后的节点
multimap<int, pair<int, int>> Map_Node;  //地图
list<pair<int, pair<int, int>>> Sorted_Map; //排序好的地图
vector<pair<pair<int, int>, int>> edges; //添加进来的边
vector<int> path;  //路径

bool three_times(vector<pair<pair<int, int>, int>>& edges, int key) {
    int times = 0;
    for (auto i = edges.begin(); i != edges.end(); ++i) {
        if (i->first.first == key || i->first.second == key)
            times++;
    }
    if (times >= 2)
        return false;
    else return true;
}

bool issmae(vector<pair<pair<int, int>, int>>& edges, pair<int, int> e) {
    for (auto i = edges.begin(); i != edges.end(); ++i) {
        if (i->first.first == e.second && i->first.second == e.first)
            return true;
    }
    return false;
}

bool iscycle(vector<int>& path, pair<int, int> e) {
    if (e.first == path.front() && e.second == path.back()) return true;
    if (e.second == path.front() && e.first == path.back()) return true;
    return false;
}

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
    while (Nodes.size() <= N) {
        for (auto node = Sorted_Map.begin(); node != Sorted_Map.end(); ++ node) {
            if (Nodes.empty()) {
                cout << node->second.first << "->" << node->second.second<< " " <<node->first << endl;
                Nodes.push_back(node->second.first); path.push_back(node->second.first);
                Nodes.push_back(node->second.second); path.push_back(node->second.second);
                edges.push_back(make_pair(make_pair(node->second.first, node->second.second), 1));
                SUM += node->first;
            } else if (!iscycle(path, make_pair(node->second.first, node->second.second))){
                if (three_times(edges, node->second.first) && three_times(edges, node->second.second)) {
                    if (!issmae(edges, make_pair(node->second.first, node->second.second))) {
                        cout << node->second.first << "->" << node->second.second << " " <<node->first << endl;
                        if (find(Nodes.begin(), Nodes.end(), node->second.first) == Nodes.end())
                            Nodes.push_back(node->second.first);
                        else
                            Nodes.push_back(node->second.second);
                        SUM += node->first;
                        edges.push_back(make_pair(make_pair(node->second.first, node->second.second), 0));
                        for (auto x = edges.begin(); x != edges.end(); ++ x) {
                            if (x->second == 0 && x->first.first == path.back()) {
                                path.push_back(x->first.first); path.push_back(x->first.second);
                                x->second = 1;
                            } else if (x->second == 0 && x->first.second == path.back()) {
                                path.push_back(x->first.second); path.push_back(x->first.first);
                                x->second = 1;
                            }

                        }
                    }
                }
            }
        }
    }
    auto p = unique(path.begin(), path.end());
    path.erase(p, path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
    cout << SUM << endl;
    return 0;
}
