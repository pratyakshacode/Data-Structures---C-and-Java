import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Graph {

    Map<Integer, List<Integer>> adj = new HashMap<>();

    void addVertex(int u){
        adj.put(u, new ArrayList<Integer>());
    }

    void add(int u, int v){

        if(adj.get(u) == null){
            addVertex(u);
        }
        if(adj.get(v) == null){
            addVertex(v);
        }

        adj.get(u).add(v);
        adj.get(v).add(u);
    }

   public void get(){
    System.out.println(adj);
   }

   public void bfs(int src){

    Map<Integer, Boolean> visited = new HashMap<>();
    
    Queue<Integer> q = new ArrayDeque<>();
    q.add(src);
    visited.put(src, true);

    while(!q.isEmpty()){

        int frontNode = q.poll();

        System.out.print(frontNode + " ");

        for(var element : adj.get(frontNode)){

            if(visited.get(element) == null || !visited.get(element))
                q.add(element);
                visited.put(element, true);
        }
     }

     System.out.println();
   }

   void dfs(Map<Integer, Boolean> visited, List<Integer> list, int src){

    list.add(src);
        visited.put(src, true);

        for(var children : adj.get(src)){
            if(visited.get(children) == null || !visited.get(children)){
                dfs(visited, list, children);
            }
        }
   }

   boolean cycleDetectUsingBfs(int src){

    Map<Integer, Boolean> visited = new HashMap<>();
    Map<Integer, Integer> parent = new HashMap<>();
    Queue<Integer> q = new ArrayDeque<>();
    q.add(src);
    parent.put(src, -1);
    visited.put(src, true);


    while(!q.isEmpty()){

        int frontNode = q.poll();

        for(var children : adj.get(frontNode)){
            if(visited.get(children) != null && visited.get(children) && children != parent.get(frontNode)){
                return true;
            }
            else if(visited.get(children) == null || !visited.get(children)){
                visited.put(children, true);
                q.add(children);
                parent.put(children, frontNode);
            }
        }
    }

    return false;
   }

   boolean cycleDetectUsingDfs(Map<Integer, Boolean> visited, Map<Integer, Integer> parent, int src){

    visited.put(src, true);

    for(var neighbour : adj.get(src)){

        if(visited.get(neighbour) == null || !visited.get(neighbour)){

            parent.put(neighbour, src);
            boolean cycle = cycleDetectUsingDfs(visited, parent, neighbour);
            if(cycle) return true;
        }

        else if(visited.get(neighbour) && parent.get(src) != neighbour){
            return true;
        }
    }

    return false;
   }

   void shortestDistance(int src, Map<Integer, Boolean> visited, int [] parent){

    Queue<Integer> q = new ArrayDeque<>();
    q.add(src);
    visited.put(src, true);

    while(!q.isEmpty()){

        int top = q.poll();
        
        for(var element : adj.get(top)){
           
            if(visited.get(element) == null || !visited.get(element)){
                visited.put(element, true);
                parent[element] = top;
                q.add(element);
            }
        }
    }
}

}

public class GraphImplement {

    
    public static void main(String[] args) {
        
        Graph g = new Graph();

        // creating a graph

        g.add(0,1);
        g.add(0, 2);
        g.add(1, 2);
        g.add(1, 3);
        g.add(2, 4);
        g.add(3, 4);

        g.get();
        
        g.bfs(1);

        List<Integer> list = new ArrayList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        Map<Integer, Integer> parent = new HashMap<>();

        g.dfs(visited, list, 1);

        for(var element : list){
            System.out.print(element + " ");
        }

        visited.clear();

        System.out.println(g.cycleDetectUsingBfs(1));
        System.out.println(g.cycleDetectUsingDfs(visited, parent, 1));

        int [] arr = new int [5];
        visited.clear();
        g.shortestDistance(0, visited, arr);


        // for(var element : arr){
        //     System.out.print(element + " ");
        // }

        int curr = 4;

        while(curr != 0){

            System.out.print(curr + " ");
            curr = arr[curr];
        }
        System.out.println(curr);
    }
}
