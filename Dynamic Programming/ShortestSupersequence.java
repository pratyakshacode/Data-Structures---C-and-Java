public class ShortestSupersequence {

    LCS lcs = new LCS();

    public int shortestSupersequence(String x, String y){

        
        int lcsLength = lcs.lcsUsingTabulation(x, y);

        return x.length() + y.length() - lcsLength;
    }

    public Pair insertionDeletion(String x, String y){
        
        int lcsLength = lcs.lcsUsingTabulation(x, y);

        Pair pair = new Pair(y.length() -lcsLength, x.length() - lcsLength);

        return pair;
        
    }
    public static void main(String[] args) {
        
        ShortestSupersequence shortest = new ShortestSupersequence();

        String x = "heap";
        String y = "pea";

        System.out.println("Shortest Supersequence Length : " + shortest.shortestSupersequence(x, y));
        Pair pair = shortest.insertionDeletion(x, y);

        System.out.println("{ Insertion : " + pair.first + " Deletion : " + pair.second + " }");

    }
}
