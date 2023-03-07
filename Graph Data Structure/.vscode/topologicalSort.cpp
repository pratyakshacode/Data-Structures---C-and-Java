#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    public:
        unordered_map<int, set<int>> adj;

    void addEdge(int u, int v){
        adj[u].insert(v);
        // adj[v].insert(u);
  
    }

    void print(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void topologicalSort(int src, stack<int>& st, unordered_map<int, bool>& visited){

        visited[src] = true;

        for(auto nbr : adj[src]){
            
            if(!visited[nbr]){
                topologicalSort(nbr, st, visited);
            }
        }

        st.push(src);
    }

    bool detectCycle(int src, unordered_map<int, bool>& visited){
        
        queue<int> q;
        q.push(src);
        visited[src] = true;

        unordered_map<int, int> parent;
        parent[src] = -1;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr : adj[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = node;
                }
                else {
                    if(nbr != parent[node]){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool detectCycle(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited){

        visited[node] = true;
        dfsVisited[node] = true;

        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                bool cycle = detectCycle(nbr, visited, dfsVisited);

                if(cycle) return true;
            }
            else {

                //visited and if dfs visited means that the call has already gone and again it is making the call so it is the case of the cycle
                if(dfsVisited[nbr]){
                    return true;
                }
            }
        }
    
        dfsVisited[node] = false;
        return false;
    }
};
int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    g.print();

    unordered_map<int, bool> visited;
    stack<int> st;
    
    g.topologicalSort(0, st, visited);

    while(!st.empty()){
        int node = st.top();
        st.pop();
        cout << node << " ";
    }

    visited.clear();
    unordered_map<int, int> parent;
    unordered_map<int, bool> dfsVisited;


    // if(g.detectCycle(0, visited, parent)) cout <<"Yes" << endl;
    // else cout << "No" << endl;

    if(g.detectCycle(0, visited, dfsVisited)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}