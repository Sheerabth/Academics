#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
    map<int, set<int>> adjacencyList;
    void insert(int, set<int>);
    void printAdjacent(int);
    void printVerticesWithDegree(int);
    int returnSumOfDegrees();
    bool hasPathTo(int, int, set<int>&);
    bool hasPath(int, int);
    void BFS(int);
    void DFS(int);
};

void Graph::insert(int value, set<int> connectedNodes)
{
    map<int, set<int>>::iterator iterator = adjacencyList.find(value);
    if (iterator == adjacencyList.end())
        adjacencyList.insert(pair<int, set<int>>(value, connectedNodes));
    else
        iterator->second.insert(connectedNodes.begin(),connectedNodes.end());
    
    set<int>::iterator connectedNode = connectedNodes.begin();
    for (int connectedNode: connectedNodes)
    {
        map<int, set<int>>::iterator iterator = adjacencyList.find(connectedNode);
        if (iterator != adjacencyList.end())
            iterator->second.insert(value);
        else{
            set<int> connected({value});
            adjacencyList.insert(pair<int, set<int>>(connectedNode, connected));
        }
    }
}

void Graph :: printAdjacent(int value)
{
    map<int, set<int>>::iterator iterator = adjacencyList.find(value);
    set<int> :: iterator set_it = iterator->second.begin();
    cout << "The vertices adjacent to the given vertex " << value << " is: [";
    

    for (set_it = iterator->second.begin(); set_it != iterator->second.end(); ++set_it) 
        cout << *set_it << ", ";

    cout << "\b\b";
    cout << "]" << endl;
}


void Graph :: printVerticesWithDegree(int degree)
{
    map<int, set<int>> :: iterator map_itretor = adjacencyList.begin();
    cout << "The vertices which have the degree " << degree << " is: [";
    for (; map_itretor != adjacencyList.end(); map_itretor++)
    {
        if(map_itretor->second.size() == degree)
        {
            cout << map_itretor->first << ", ";
        }
    }
    cout << "\b\b";
    cout << "]" << endl;
}

int Graph :: returnSumOfDegrees()
{
    map<int, set<int>> :: iterator map_itretor = adjacencyList.begin();
    int sum = 0;
    for (; map_itretor != adjacencyList.end(); map_itretor++)
    {
        sum += map_itretor->second.size(); 
    }
    return sum;
}

bool Graph::hasPathTo(int src, int dest, set<int>& visited)
{
    map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(src);
    for (int connectedNode : iteratorToSrc->second)
    {
        if (connectedNode == dest)
            return true;
        else
        {
            if (visited.find(connectedNode) == visited.end())
            {
                visited.insert(connectedNode);
                if (hasPathTo(connectedNode, dest, visited))
                    return true;
            }
        }
    }
    return false;
}

bool Graph::hasPath(int src, int dest)
{
    set<int> visited;
    bool isConnected = hasPathTo(src, dest, visited);
    return isConnected;
}

void Graph::BFS(int node)
{
    set<int> visited;
    queue<int> q;

    visited.insert(node);
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        cout << node << " ";
        q.pop();
        
        map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(node);
        for (int connectedNode : iteratorToSrc->second){
            if(visited.find(connectedNode) == visited.end()){
                visited.insert(connectedNode);
                q.push(connectedNode);
            }
        }
    }
}

void Graph::DFS(int node)
{
    set<int> visited;
    stack<int> s;

    visited.insert(node);
    s.push(node);

    while (!s.empty())
    {
        node = s.top();
        cout << node << " ";
        s.pop();

        map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(node);
        for (int connectedNode : iteratorToSrc->second){
            if(visited.find(connectedNode) == visited.end()){
                visited.insert(connectedNode);
                s.push(connectedNode);
            }
        }
    }
}

int main()
{
    Graph graph;
    graph.insert(1, {3});
    graph.insert(3, {2, 4, 8});
    graph.insert(2, {5});
    graph.insert(4, {5, 8});
    graph.insert(5, {6, 9, 10});
    graph.insert(6, {7});
    graph.insert(7, {8});
    graph.insert(8, {4});
    //graph.printAdjacent(1);
    //graph.printVerticesWithDegree(1);
    // int sum = graph.returnSumOfDegrees();
    // cout << "The sum is " << sum << endl;
    if(graph.hasPath(1, 8))
        cout << "Exists" << endl;

}