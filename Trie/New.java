public class New {
    public static void main(String...args){
        String name1 = "john";
        String name2 = new String("john");
        System.out.println(name1 == name2);
        String name3 = name2.intern();
        System.out.println(name1 == name3);
    }
}
