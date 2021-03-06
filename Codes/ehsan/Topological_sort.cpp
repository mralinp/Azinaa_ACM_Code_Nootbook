#include<iostream>
#include <vector>
using namespace std;

const int Gsize=100000;

int _color[Gsize], _p[Gsize] ,_d[Gsize] ,_f[Gsize] , _time;
vector<int> _V;
void DFS_visit(vector<int> G[] ,int u)
{
  _time++;
  _d[u]=_time;
  _color[u]=1;
  int v;
  for(int i=0;i<G[u].size();i++)
  {
    v=G[u][i];
    if(!_color[v])
    {
      _p[v]=u;
      DFS_visit(G ,v);
    }
  }
  _color[u]=2;
  _time++;
  _f[u]=_time;
  _V.push_back(u);
}
void DFS(vector<int>G[])
{
  for(int i=0;i<Gsize;i++)
  {
    _color[i]=0; _p[i]=0;
  }
  _time=0;
  for(int i=0;i<Gsize;i++)
    if(!_color[i])
      DFS_visit(G ,i);
}

void Topological_sort(vector<int> G[], int arr[])
{
  _V.clear();
  DFS(G);
  for(int i=0;i<_V.size();i++)
    arr[_V.size()-1-i] = _V[i];
}

int main()
{

  return 0;
}
