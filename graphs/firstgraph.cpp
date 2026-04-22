#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph
{
    int V;
    std::list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new std::list<int>[V];
    }

    void insertVerticies(int u, int v) // undirected graph
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS()
    {
        std::queue<int> q;
        std::vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;

        while (q.size() > 0)
        {
            int src = q.front();
            q.pop();

            std::cout << src << " ";

            for (int dest : l[src])
            {
                if (!vis[dest])
                {
                    vis[dest] = true;
                    q.push(dest);
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int src, std::vector<bool> &vis)
    {
        std::cout << src << " ";
        vis[src] = true;

        for (auto dest : l[src])
        {
            if (!vis[dest])
            {
                DFS(dest, vis);
            }
        }
    }

    bool isCycleUnDir(int u, int par, std::vector<bool> &vis)
    {
        vis[u] = true;

        for (auto v : l[u])
        {
            if (!vis[v])
            {
                if (isCycleUnDir(v, u, vis))
                    return true;
            }
            else if (v != par)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycleBFS(int u, std::vector<bool> &vis)
    {
        std::queue<std::pair<int, int>> q;
        q.push({u, -1});

        vis[u] = true;

        while (q.size() > 0)
        {
            u = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto v : l[u])
            {
                if (!vis[u])
                {
                    q.push({v, u});
                    vis[v] = true;
                }
                else if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle()
    {
        std::vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUnDir(i, -1, vis))
                    return true;
            }
        }

        return false;
    }

    // Directed Graph

    void insertVerticiesDir(int u, int v) // for directed graph
    {
        l[u].push_back(v);
    }

    bool isCycleDir(int curr, std::vector<bool> &vis, std::vector<bool> &recPath)
    {
        vis[curr] = true;
        recPath[curr] = true;

        for (auto v : l[curr])
        {
            if (!vis[v])
            {
                if (isCycleDir(v, vis, recPath))
                {
                    return true;
                }
                else if (recPath[v])
                {
                    return true;
                }
            }
        }

        recPath[curr] = false;

        return false;
    }

    bool cycleDetectionDir()
    {
        std::vector<bool> vis(V, false);
        std::vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleDir(i, vis, recPath))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    std::vector<bool> arr(5, false);

    g.insertVerticiesDir(1, 0);
    g.insertVerticiesDir(0, 2);
    g.insertVerticiesDir(2, 3);
    g.insertVerticiesDir(3, 0);

    std::cout << g.cycleDetectionDir() << std::endl;

    return 0;
}