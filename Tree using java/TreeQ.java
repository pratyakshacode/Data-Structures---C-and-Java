
public class TreeQ {

    Pair<Boolean, Integer> p = new Pair<>(true, 0);

    //check for balance Tree

    public Pair<Boolean, Integer> checkTree(Node root){

        if(root == null) return new Pair<Boolean,Integer>(true, 0);

        Pair<Boolean, Integer> left = checkTree(root.left);
        Pair<Boolean, Integer> right = checkTree(root.right);

        Pair<Boolean, Integer> ans = new Pair<Boolean,Integer>(true, 0);
        Boolean curr = Math.abs(left.second - right.second) <= 1;

        ans.first = left.first && right.first && curr;
        ans.second = Integer.max(left.second, right.second) + 1;

        return ans;
        
    }

    public boolean isIdentical(Node root1, Node root2){

        if(root1 == null && root2 == null) return true;
        if((root1 == null && root2 != null ) || (root1 != null && root2 == null)) return false;

        boolean left = isIdentical(root1.left, root2.left);
        boolean right = isIdentical(root1.right, root2.right);

        return left && right && root1.data == root2.data;

    }

    public Pair<Integer, Boolean> sumTree(Node root){

        if(root == null) return new Pair<Integer,Boolean>(0, true);
        if(root.left == null && root.right == null) return new Pair<Integer, Boolean>(root.data, true);

        Pair<Integer, Boolean> left = sumTree(root.left);
        Pair<Integer, Boolean> right = sumTree(root.right);
        int sum = left.first + right.first;

        Pair<Integer, Boolean> ans = new Pair<Integer,Boolean>(null, null);
        
        boolean leftans = left.second;
        boolean rightans = right.second;
        boolean condn = (root.data == sum);

        if(leftans && rightans && condn){
            ans.second = true;
            ans.first = root.data;
        }
        else {
            ans.second = false;
            ans.first = sum;
        }
        return ans;
    }

    public boolean isSumTree(Node root){

        if(root == null || (root.left == null && root.right == null)) return true;

        int left, right;

        if(isSumTree(root.left) && isSumTree(root.right)){

            //checking for the sum tree
            if(root.left == null)
                left = 0;
            else if(root.left.left == null && root.right.right == null)
                left = root.left.data;
            else left = 2 * root.left.data;


            if(root.right == null)
                right = 0;
            else if(root.right.left == null && root.right.right == null)
                right = root.right.data;
            else right = 2 * root.right.data;
            
            if(left + right == root.data) return true;
            else return false;
        }

        return false;
    }

    public static void main(String[] args) {

        BuildTree tree = new BuildTree();
        TreeQ tq = new TreeQ();

        Node root1 = null;
        Node root2 = null;

        tree.buildTree(root1);
        // tree.buildTree(root2);

        System.out.println("\n {" + tq.checkTree(root1).first + ", " + tq.checkTree(root1).second + "}");
        System.out.println("Two trees are identical ? " + tq.isIdentical(root1, root2));

        Pair<Integer, Boolean> pair = tq.sumTree(root1);

        System.out.println("{" + pair.first + ", " +  pair.second + "}");
        System.out.println("isSumTree : " + tq.isSumTree(root1));
    }
}
