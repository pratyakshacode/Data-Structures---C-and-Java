import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

class pair <K, V> {
    K first;
    V second;

    public pair(K first, V second){
        this.first = first;
        this.second = second;
    }
}
class WeightedGraph{

    Map<Integer, List<pair<Integer, Integer>>> adj = new HashMap<>();

    private void addVertex(int u){
        adj.put(u, new ArrayList<>());
    }

    void add(int u, int v, int w){

        if(adj.get(u) == null) addVertex(u);

        adj.get(u).add(make_pair(v, w));
    }

    public pair<Integer, Integer> make_pair(int u, int v){

        pair<Integer, Integer> p = new pair<>(u, v);
        return p;

    }

    void getAdjecency(){
        
        for(var key : adj.keySet()){

            System.out.print(key + " -> ");

            for(var listElement : adj.get(key)){
                System.out.print("Node : "+listElement.first + " Weight : " + listElement.second + ", ");
            }

            System.out.println();
        }
    }

    void topologicalSort(Stack<Integer> st, int src){

        
    }

    void minimumCostFromSource(int [] cost, Stack<Integer> st, int src){

        cost[src] = 0;

        
    }   
}

public class WeightedDirectedGraph {
    public static void main(String[] args) {
        
        WeightedGraph g = new WeightedGraph();
        g.add(1, 2, 5);
        g.add(1, 3, 10);
        g.add(2, 3, 3);
        g.add(3, 5, 10);
        g.add(2, 4, 8);
        g.add(4, 5, 1);

        // g.getAdjecency();


    }
}
