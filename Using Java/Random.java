class Player {
    int health;

    public Player(){
        this.health = 100;
    }

    void attack(Player p2){
        p2.health -= (int)(Math.random() * 10);
    }
}
public class Random {
    public static void main(String[] args) {

        Player p1 = new Player();
        Player p2 = new Player();

        // int chance = 20;

        while(true){

            p1.attack(p2);

            if(p1.health <= 0){
                System.out.println("p2 wins");
                break;
            }
            p2.attack(p1); 

            if(p2.health <= 0){
                System.out.println("p1 wins");
                break;
            }
        }

        
        
    }
}
