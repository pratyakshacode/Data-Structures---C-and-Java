import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

public class WeightedGraph {

    static class pair<K, V>{
        K first;
        V second;

        public pair(K first, V second){
            this.first = first;
            this.second = second;
        }
    }

    static class Weighted {

        Map<Integer, List<pair<Integer, Integer>>> adj = new HashMap<>();

        void addVertex(int u){
            adj.put(u, new ArrayList<>());
        }

        void add(int u, int v, int w){

            if(adj.get(u) == null) addVertex(u);
            if(adj.get(v) == null) addVertex(v);

            adj.get(u).add(make_pair(v, w));
            adj.get(v).add(make_pair(u, w));

        }

        void printAdj(){
            
            for(var key : adj.keySet()){

                System.out.print(key + " -> ");

                for(var pair : adj.get(key)){
                    System.out.print(pair.first + " " + pair.second + ", ");
                }

                System.out.println();
            }
        }

        pair<Integer, Integer> make_pair(int first, int second){

            pair<Integer, Integer> p = new pair<Integer,Integer>(first, second);
            return p;
        }
        
    }
    public static void main(String[] args) {

        Weighted graph = new Weighted();
        graph.add(1, 2, 10);   
        graph.add(2, 3, 20);
        graph.add(4, 1, 3);
        graph.add(4, 3, 5);

        graph.printAdj();   
    }
}
