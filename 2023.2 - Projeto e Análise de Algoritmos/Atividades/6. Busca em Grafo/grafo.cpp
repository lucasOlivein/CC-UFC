#include <iostream>
#include <vector>
using namespace std;

struct Vertice
{
    int num_camin;
    vector<int> adj;
    bool visited;
    Vertice(vector<int> adjs)
    {
        adj = adjs;
        num_camin = 0;
        visited = false;
    }
};
bool contain(vector<int> queue, int v)
{
    for (int i = 0; i < queue.size(); i++)
        if (queue[i] == v)
            return true;

    return false;
}

void findOrigin(vector<Vertice> &vertice, int origem, int atual, int aux, vector<int> explored = {})
{

    if (!contain(explored, aux))
        explored.push_back(aux);

    for (int i = 0; i < vertice[aux].adj.size(); i++)
    {
        int adj = vertice[aux].adj[i];

        if (!contain(explored, adj))
            if (adj == origem)
            {
                vertice[atual].num_camin += 1;
            }
            else
            {
                findOrigin(vertice, origem, atual, adj, explored);
            }
    }
}
void expand(vector<int> &frontier, int atual, vector<Vertice> &vertice)
{
    for (int i = 0; i < vertice[atual].adj.size(); i++)
    {
        int adj = vertice[atual].adj[i];

        if (!contain(frontier, adj) && !vertice[adj].visited)
            frontier.push_back(adj);
    }
}
void findWays(vector<Vertice> &vertice, int origem)
{
    vector<int> frontier = vertice[origem].adj;
    vertice[origem].visited = true;

    while (!frontier.empty())
    {
        int atual = frontier[0];

        expand(frontier, atual, vertice);
        findOrigin(vertice, origem, atual, atual);
        vertice[atual].visited = true;

        frontier.erase(frontier.begin());
    }
}

void printWays(vector<Vertice> grafo)
{
    for (int i = 0; i < grafo.size(); i++)
    {
        cout << "Vertice " << i << ":: " << grafo[i].num_camin << " \n";
    }
}

bool circle(vector<Vertice> grafo, int origem = 0)
{
    vector<int> frontier = grafo[origem].adj;
    grafo[origem].visited = true;

    while (!frontier.empty())
    {
        int atual = frontier[frontier.size() - 1];
        frontier.erase(frontier.end() - 1);

        if (atual <= grafo.size() - 1)
            if (!grafo[atual].visited)
            {
                grafo[atual].visited = true;
                for (int i = 0; i < grafo[atual].adj.size(); i++)
                {
                    frontier.push_back(grafo[atual].adj[i]);
                }
            }
            else
                return true;
    }

    return false;
}

int main()
{
    vector<Vertice> grafo;
    grafo.push_back(Vertice({1, 2}));
    grafo.push_back(Vertice({0, 3, 5}));
    grafo.push_back(Vertice({0, 3}));
    grafo.push_back(Vertice({1, 2, 4, 7}));
    grafo.push_back(Vertice({3, 5}));
    grafo.push_back(Vertice({1, 4, 6}));
    grafo.push_back(Vertice({5, 7}));
    grafo.push_back(Vertice({3, 6, 8}));
    grafo.push_back(Vertice({7}));

    // findWays(grafo, 8);
    // printWays(grafo);

    vector<Vertice> grafo_02;

    grafo_02.push_back(Vertice({2}));
    grafo_02.push_back(Vertice({4}));
    grafo_02.push_back(Vertice({3}));
    grafo_02.push_back(Vertice({4}));
    grafo_02.push_back(Vertice({5}));
    // grafo_02.push_back(Vertice({}));

    cout << circle(grafo_02);
}