import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.List;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Stack;
import java.util.Queue;

public class DirectedGraph {

    static class DGraph{

        Map<Integer, List<Integer>> map = new HashMap<>();

        void addVertex(int u){
            map.put(u, new ArrayList<>());
        }

        void add(int u, int v){

            if(map.get(u) == null){
                addVertex(u);
            }

            map.get(u).add(v);
        }

        void getAdjecency(){

            System.out.println(map);
        }

        boolean cycleDetect(Map<Integer, Boolean> visited, Map<Integer, Boolean> dfsVisited, int src){

            visited.put(src, true);
            dfsVisited.put(src, true);
            
            System.out.println(map.get(src));

            try{
            for(var neighbour : map.get(src)){

                if(visited.get(neighbour) == null || !visited.get(neighbour)){

                    boolean cycle = cycleDetect(visited, dfsVisited, neighbour);
                    if(cycle) return true;
                }
                else {
                    if(dfsVisited.get(neighbour)) return true;
                }
            }
        } catch(Exception e){
           
        }
        finally{

            dfsVisited.put(src, false);
        }
            return false;
        }

        void topologicalSort(Stack<Integer> st, Map<Integer, Boolean> visited, int src){

            visited.put(src, true);

            Iterator<Integer> it = map.get(src).iterator();

            while(it.hasNext()){
                Integer i = it.next();

                if(visited.get(i) == null || !visited.get(i)){
                    topologicalSort(st, visited, i);
                }
            }
            st.push(src);
        } 

        int [] getInDegree(){

            int inDegree [] = new int[map.size()+1];
            inDegree[0] = -1;

            for(var key : map.keySet()){

                try{
                for(var listElement : map.get(key)){
                    inDegree[listElement]++;
                }
            } catch(Exception e){}
            }

            for(var element : inDegree){
                System.out.print(element + " ");
            }

            return inDegree;
        }

        void topoSort(int src, Map<Integer, Boolean> visited){

            Queue<Integer> q = new ArrayDeque<>();
            
            
        }

        }
    public static void main(String[] args) {
        
        DGraph g = new DGraph();
        g.add(1, 2);
        g.add(1, 3);
        g.add(2, 5);
        g.add(3, 5);
        g.add(5, 4);

        Map<Integer, Boolean> visited = new HashMap<>();
        Map<Integer, Boolean> parent = new HashMap<>();

        System.out.println(g.cycleDetect(visited, parent, 1));

        Stack<Integer> st = new Stack<>();
        visited.clear();

        // g.topologicalSort(st, visited, 1);
        
        System.out.println("Printing the topological sort sequence");
        
        
        g.getAdjecency();
        // System.out.println(g.map.size());
        g.getInDegree();
    }
}
