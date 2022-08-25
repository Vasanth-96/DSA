//graphs
// adjacency matrix vertices*edges  n*m O(v*E) complexity.
// so lets take input

// *************************************************//

int n,m;
cin>>n>>m;
int graph[n][m];//global declare and if n>1e6 then this apporcah is not good.
for(int i=0;i<m;i++)
{
    int v1,v2;
    cin>>v1>>v2;
    graph[v1][v2]=1;
    graph[v2][v1]=1;
}

// *************************************************//

//adjancey list moslty used.
// O(v+e) space complexity.

vector<int> g(n);
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int v1,v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

//if weights ae given to store it create a vector of pair like vector<pair<int,int> g 
//then g[v1].push_back({v2, wt}); 

// *************************************************//
//dfs

vector<int> g(n);
bool visted[n];
void dfs(int vertex)
{
    if(visted[vertex]) return;
    visted[vertex]=true;
    for(int child : g[vertex])
    {
        dfs(child);
    }
}

// *************************************************//

//connected components count
void connected_count()
{
    int ct=0;
    for(int i=0;i<n;i++)
    {
        if(visted[i]==false)
        {
            dfs(i);
            ct++;
        }
    }
    cout<<ct;
}//we can also store the vertex list of conected components using the vector of vector.

// *************************************************//

//find cycle in a graph.
//here we use parent node in argument 
bool dfs(int vertex, int par)
{
    visted[vertex]=true;
    bool ans = false;
    for(int child: g[vertex])
    {
        if(child==par && visited[child]==true)continue;
        if(visited[child])
        {
            return true;
        }
        ans |= dfs(child, vertex);
    }
}


// *************************************************//

//find lca 
int parent[n];
viod dfs(int v, int par=-1)
{
    parent[v]=par;
    for(int child: v)
    {
        if(child==par)continue;
        dfs(child, v);
    }
}
vector<int> path(int v)
{
    vector<int> ans;
    while(v!=-1)
    {
        ans.push_back(v);
        v=parent[v];
    }
    reverse(ans.begin(), ans.end());
}
// *************************************************//
// dfs in matrix river sizes question
#include <vector>
using namespace std;
void dfs(int &ct, vector<vector<int>> &matrix, int i, int j, int n, int m)
{
  if(i>=0 && j>=0 && i<n && j<m)
  {
    if(matrix[i][j]==1)
    {
      ct++;
      matrix[i][j]=0;
      dfs(ct, matrix, i-1, j, n, m);
      dfs(ct, matrix, i, j-1, n, m);
      dfs(ct, matrix, i+1, j, n, m);
      dfs(ct, matrix, i, j+1, n, m);
    }
  }
}
vector<int> riverSizes(vector<vector<int>> matrix) {
  int n=matrix.size();
  int m=matrix[0].size();
  vector<int> ans;
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        {
          if(matrix[i][j]==1)
          {
            int ct=0;
            dfs(ct, matrix, i, j, n, m);
            ans.push_back(ct);
          }
        }
    }
  return ans;
}


//depth of a tree and height
int depth[n];
int height[n];
void dfs(int v, int par=-1)
{
    for(int child: g[v])
    {
        if(child==par)continue;
        depth[child]=depth[v] + 1;
        dfs(child, v);
        height[v]=max(height[v], height[child]+1);
    }
}


//precomputation using dfs very imporant.

int subtreesum[n];
void dfs(int v, int par=0)
{
    // 1 before going in child
    subtreesum[v]+=value[v];
    for(int child: v)
    {
        if(child==par)continue;
        // 2 
        // after entereing in child
        dfs(child, v);
        // 3
        // exiting in child
        subtreesum[v]+=subtreesum[child];
    }
    // 4
    // exiting the vertex
}
}

//

//breadth first search
//lets complete
// only vis when pushed.
const int N = 1e5+10;

int vis[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for(int child : graph[cur_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
}
vector<int> graph(N);
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
}


//as simple as that.it is used in shortest path algorithms rather than dijjstra as it store the level and diference gives the level
// so use bfs for unweighted graphs

//biparitite graph
// jus using the bfs or dfs maintaining the marix of interger intitilized with -1 then color it with 1 then check the childreen then color it wiht 0 for the chidren if children already have same color then it is not a bipartite graph.


//toplogical  sorting
vector<int> g[n];
vector<int> vis(n, 0);
stack<int> st;
topologicalsort(int v)
{
    vis[i]=1;
    for(auto child: g[v])
    {
        if(!vis[child])
        {
            topologicalsort(child);
        }
    }
    st.push(v);
}
int main()
{
    vector<int> sorted;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topologicalsort(i);
        }
    }
    while(!st.empty())
    {
        int x = st.top();
        st.pop()
        sorted.push_back(x);
    }
}
// *************************************************//

//now lets start with dijistras algorithm
// complexity is 
vector<int> vis[n+1];
vector<int> dist(n+1, INT_MAX);
void dijkstra(int source)
{
    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source]=0;
    while(s.size()>0)
    {
        auto it = *s.begin();
        int v = it.second;
        int dis=it.first;
        s.erase(s.begin());
        if(vis[v])continue;
        vis[v]=1;
        for(auto child: g[v])
        {
            int cv=child.second;
            int d=child.first;
            if(dist[v]+d < dist[cv])
            {
                dist[cv]=dist[v]+d;
                s.insert({dist[cv], cv});
            }
        }
    }
    
}


//bellman ford for negative edges;//deteck negative cycle


//prims using priority queue or set 

int main()
{
    vector<pair<int, int>> g; 
    int key[n];
    int parent[n];
    bool inmst[n];
    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX, parent[i]=-1, inmst=false;
    }
    key[0]=0;//staring node inserted
    parent[0]=-1;
    set<pair<int, int>> st;
    st.insert({0, 0});
    for(int edge=0;edge<n-1;edge++)
    {
        int ver = *st.begin().second;
        st.erase(st.begin());
        inmst[ver]=true;
        for(auto it: g[ver])
        {
            int v = it.first;
            int weigth = it.second;
            if(inmst[v]==false && weigth < key[v])
            {
                parent[v] = ver;
                key[v] = weigth;
                st.insert({key[v], v});
            }
        }
    }
}

//disjoint set union

// union operation and findpar
int parent[1e5];
int rank[1e5];
void makeset()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findpar(int node)
{
    if(node==parent[node])
    {
        return node;
    }
    else
    {
        return parent[node] = findpar(parent[node]);
    }
}

void union(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    if(rank[a] < rank[b])
    {
        parent[a] = b;
    }
    else if(rank[a] > rank[[b]])
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
        rank[b]++;
    }
}


//kruskals algorithm

// this is using the disjoint set by disjoint set is similar to storing the parents right?
// so we could just use a array instead
int par[n+1];//for 1 base idexing if needed
for(int i=0;i<n;i++)
{
    par[i]=i;
}
vector<int> g[n+1];
set<pair<int, pair<int, int>>> st;//to store the wieghts associated with the given nodes.
int nodes=0;
while(nodes!=n-1)
{
    auto cur = *st.begin();
    st.erase(st.begin());
    int weigth = cur.first;
    int u = cur.second.first;
    int v = cur.second.second;
    if(par[u]!=par[v])
    {
        par[v] = u;
        //add this in the mst;
        nodes++;
    }
    else
    {
        // simply continue without doing anything.
    }
}




//completed grpah series ..............




