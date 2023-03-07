#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

    public:
        unordered_map<T, list<T>> adj;
        
        // functions or members

        void addEdge(T u, T v, bool directed = 0){

            adj[u].push_back(v);

            //now for the undirected graph their will be edges connected to the both sides
            if(directed == 0){
                adj[v].push_back(u);
            }
        } 

        void printGraph(){

            for(auto i : adj){
                cout << i.first << " -> ";
                for(auto j : i.second){
                    cout << j << " ";
                }

                cout << endl;
            }
        }

        void bfs(int src, vector<int>& ans, unordered_map<int, bool>& visited){

            queue<T> q;
            
            //entring the first node or the source node in the queue as we have visited it
            q.push(src);
            visited[src] = true;

            while(!q.empty()){

                //getting the visited of the queue 
                int frontNode = q.front();
                q.pop();

                //storing the visited node
                ans.push_back(frontNode);

                //now getting the childs of that node
                for(auto child : adj[frontNode]){

                    if(!visited[child]){
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
        }

        void dfs(int node, vector<int>& ans, unordered_map<int, bool>& visited){

            visited[node] = true;
            ans.push_back(node);

            for(auto child : adj[node]){
                if(!visited[child]){
                    dfs(child, ans, visited);
                }
            }
        }

        bool cycleDetectUsingBfs(int src, unordered_map<int, bool>& visited){

            unordered_map<int, int> parent;

            visited[src] = true;
            parent[src] = -1;

            queue<int> q;
            q.push(src);

            while(!q.empty()){

                int frontNode = q.front();
                q.pop();

                for(auto child : adj[frontNode]){
                    if(visited[child] && parent[frontNode] != child){
                        return true;
                    }
                    else if(!visited[child]){
                        q.push(child);
                        visited[child] = true;
                        parent[child] = frontNode;
                    }
                }
            }

            return false;
        }

        bool cycleDetectUsingDfs(int node, unordered_map<int, bool>&visited, unordered_map<int, int>& parent){

            visited[node] = true;
            for(auto child : adj[node]){
                if(!visited[child]){
                    bool cycle = cycleDetectUsingDfs(child, visited);
                    if(cycle) return true;
                }
                else if(child != parent[node]){
                    return true;
                }
            }

        return false;
        }
};




int main(){

    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    // g.addEdge(1,4);
   
    g.printGraph();

    vector<int> bfsVect;
    vector<int> dfsVect;
    unordered_map<int, bool> visited;

    g.bfs(0, bfsVect, visited);
    cout << endl;

    for(auto i: bfsVect){
        cout << i << " ";
    }

    visited.clear();
    cout << endl;

    g.dfs(0, dfsVect, visited);
    
    for(auto element : dfsVect){
        cout << element << " ";
    }

    cout << endl;
    visited.clear();

    if(g.cycleDetectUsingBfs(0, visited)){
        cout << "Cycle Detected" << endl;
    }
    else {
        cout << "No Cycle Present" << endl;
    }

    visited.clear();
    cout << endl;

    unordered_map<int, int> parent;

    cout << g.cycleDetectUsingDfs(0, visited, parent);


    return 0;
}