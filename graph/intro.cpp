#include <iostream>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

using Graph = adjacency_list<vecS, vecS, bidirectionalS>;
using Edge = pair<int, int>;

int main()
{
  constexpr int N{5};
  Graph G{N};
  vector<Edge> const E{{0, 1}, {0, 3}, {2, 0}, {3, 2}, {2, 4}, {1, 3}, {3, 4}};
  for (auto e : E)
  {
    add_edge(e.first, e.second, G);
  }
  // vertex sets
  auto vp = vertices(G);
  cout << "vertices of G: ";
  while (vp.first != vp.second)
  {
    cout << *vp.first << " ";
    vp.first++;
  }
  cout << endl;
  // edge sets
  cout << "edges of G: ";
  auto ep = edges(G);
  while (ep.first != ep.second)
  {
    cout << "(" << source(*ep.first, G) << ", " << target(*ep.first, G) << ") ";
    ep.first++;
  }
  cout << endl;
  cout << "Enter vertex: ";
  int v;
  cin >> v;
  // out-edge sets
  cout << "out-edges of G(" << v << "): ";
  auto oep = out_edges(v, G);
  while (oep.first != oep.second)
  {
    cout << "(" << source(*oep.first, G) << ", " << target(*oep.first, G) << ") ";
    oep.first++;
  }
  cout << endl;
  // in-edge sets
  cout << "in-edges of G(" << v << "): ";
  auto iep = in_edges(v, G);
  while (iep.first != iep.second)
  {
    cout << "(" << source(*iep.first, G) << ", " << target(*iep.first, G) << ") ";
    iep.first++;
  }
  cout << endl;
  // adjacent vertex sets
  cout << "adjacent vertices of G(" << v << "): ";
  auto avp = adjacent_vertices(v, G);
  while (avp.first != avp.second)
  {
    cout << *avp.first << " ";
    avp.first++;
  }
  cout << endl;
}