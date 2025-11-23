#include <iostream>
#include <list>
#include <vector>
using namespace std;


void removAdj(vector <vector <int>> &adjList, int index, int adj)
{   
    for(int i = 0; i< adjList[index].size(); i++){
        cout << "valor :: na lista de adj: " << adjList[index][i] << " || valor procurado ::" << adj << '\n';
        if(adjList[index][i] == adj)
            adjList[index].erase(adjList[index].begin() + i);
    }
}

void printAdj(vector<vector<int>> adjList)
{
    for(int i=0; i<adjList.size(); i++)
    {   
        cout << i << ":: {";
        for(int j=0; j<adjList[i].size(); j++){
            cout << adjList[i][j] << ", ";
        }
        cout << "}\n";

    }
}

int main()
{
    vector < vector <int>> adjList;

    adjList.push_back({1,2,4});
    adjList.push_back({0,2,3});
    adjList.push_back({0,1,2,3,4});
    adjList.push_back({1,2});
    adjList.push_back({0,2});
    
    printAdj(adjList);
    cout << "-----------\n\n";
    for (int i = 0; i < adjList.size(); i++)
        for(int j = 0; j<adjList[i].size(); j++)
            removAdj(adjList, j, i);

    printAdj(adjList);
        
}