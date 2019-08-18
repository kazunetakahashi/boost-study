#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>

using namespace std;
using namespace boost;
using ll = long long;

using Graph = adjacency_list<vecS, vecS, directedS, no_property, property<edge_weight_t, ll>>;
using Edge = std::tuple<int, int, ll>;

int main()
{
  constexpr int N{5};
  Graph G{N};
  vector<Edge> const E{{0, 2, 1}, {1, 1, 2}, {1, 3, 1}, {1, 4, 3}, {2, 1, 7}, {2, 3, 3}, {3, 4, 1}, {4, 0, 1}, {4, 1, 1}};
  for (auto e : E)
  {
    add_edge(get<0>(e), get<1>(e), get<2>(e), G);
  }
  vector<ll> D(N);
  dijkstra_shortest_paths(G, 0, distance_map(&D[0]));
   for (auto i = 0; i < N; i++)
  {
    cout << "D[" << i << "] = " << D[i] << endl;
  }
}