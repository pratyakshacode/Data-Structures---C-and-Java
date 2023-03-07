public class Pair <K, V> {
    
    K first;
    V second;

    public Pair(K first, V second){

        this.first = first;
        this.second = second;
    }

    Pair<K, V> makePair(K first, V second){

        return new Pair<K,V>(first, second);
    }
}
