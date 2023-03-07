#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> visited, vector<vector<int>> m, int n, int x, int y){
    if((x >=0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1)){
            return true;
    }   
    else{
        return false;
    }
}

void solve(vector<vector<int>> m, int n, vector<vector<int>> visited, int x, int y, vector<string>& ans, string path){

        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        //down 
        int newx = x+1;
        int newy = y;
        if(isSafe(visited, m, n, newx, newy)){
            path.push_back('D');
            solve(m, n, visited, newx, newy, ans, path);
            path.pop_back();
        }

    //left
        newx = x;
        newy = y-1;

        if(isSafe(visited, m, n, newx, newy)){
            path.push_back('L');
            solve(m, n, visited, newx, newy, ans, path);
            path.pop_back();
        }

//right
        newx = x;
        newy = y+1;

        if(isSafe(visited, m, n, newx, newy)){
            path.push_back('R');
            solve(m, n, visited, newx, newy, ans, path);
            path.pop_back();
        }

        //up

        newx = x-1;
        newy = y;

        if(isSafe(visited, m, n, newx, newy)){
            path.push_back('U');
            solve(m, n, visited, newx, newy, ans, path);
            path.pop_back();
        }

        visited[x][y] = 0;
}

int main(){
    int n,e;

    vector<vector<int>> m; //input array m -> maze
  
    vector<string> ans;
   

    cout << "Enter the size: " << endl;
    cin >> n;

    cout << "Enter the path values into the m vector: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> m[i][j];
        }
    }
  vector<vector<int>> visited = m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    
    // if(m[0][0] == 0){
    //     cout << "Not Possible " << endl;
    //     return 0;
    // }

    int srcx = 0;
    int srcy = 0;
    string path = "";

    solve(m, n, visited, srcx, srcy, ans,path);

    for(auto value : ans) cout << value << " ";

    return 0;
}