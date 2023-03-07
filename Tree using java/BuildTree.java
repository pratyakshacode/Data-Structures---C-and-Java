import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BuildTree{

    static Scanner sc = new Scanner(System.in);

    public Node buildTree(Node root){

        System.out.print("Enter the data : ");
        int data = Integer.parseInt(sc.nextLine());

        if(data == -1) return null;

        root = new Node(data);

        System.out.printf("Enter data for left Node of [%d] : ", root.data);
        root.left = buildTree(root.left);
        System.out.printf("Enter data for the right Node of [%d] : " , root.data);
        root.right = buildTree(root.right);

        return root;
    }

    public static void levelOrderTraversal(Node root){

        if(root == null) return;

        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        while(!q.isEmpty()){

            Node frontNode = q.poll();

           if(frontNode == null){
            System.out.println();

            if(!q.isEmpty()){
                q.add(null);
            }
           }
           else {

            System.out.print(" " + frontNode.data + "   ");

            if(frontNode.left != null) q.add(frontNode.left);
            if(frontNode.right != null) q.add(frontNode.right);

           }
        }

    }

    public static int height(Node root){


        if(root == null) return 0;

        int left = height(root.left);
        int right = height(root.right);

        int h = Integer.max(left, right) + 1;
        return h;

    }

    static Pair<Integer, Integer> diameter (Node root){

        if(root == null) {
            return new Pair<Integer,Integer>(0, 0);
        }

        Pair<Integer, Integer> left = diameter(root.left);
        Pair<Integer, Integer> right = diameter(root.right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        Pair<Integer,Integer> ans = new Pair<Integer,Integer>(0, 0);

        ans.first = Integer.max(op1, Integer.max(op2, op3));
        ans.second = Integer.max(left.first, right.first) + 1;

        return ans;

    }

    
    public static void main(String[] args) {
        
        BuildTree tree = new BuildTree();
        Node root = null;

        root = tree.buildTree(root);

        // System.out.println(root.data);

        System.out.println();
        System.out.println();
        levelOrderTraversal(root);

        System.out.println("Height of binary tree is : " + height(root));
        System.out.println("Diameter of the tree is : " + diameter(root).first);

    }
}

// 1 2 4 -1 -1 5 11 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 -1

