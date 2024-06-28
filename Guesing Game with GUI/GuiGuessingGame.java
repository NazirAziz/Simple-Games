
import java.util.Random;
import javax.swing.JOptionPane;

public class GuiGuessingGame {
    public static int getRandom(){
        Random rand = new Random();
        return rand.nextInt(10) + 1;
    }


    public static void main(String[] args) {
            int rand = getRandom();
            byte chances = 3;
            do{
                int choice = Integer.parseInt(JOptionPane.showInputDialog("You have " + chances + " chances. "+"Guess a number between 1-10:"));
                if (choice == rand){
                    JOptionPane.showMessageDialog(null,"You got it right in " + ((3 - chances) + 1) + " tries");
                    break;
                }else if (choice > rand){
                    JOptionPane.showMessageDialog(null, "Too high");
                }else{
                    JOptionPane.showMessageDialog(null, "Too low");
                }
                chances--;
            }while (chances > 0);
            if (chances == 0){
                JOptionPane.showMessageDialog(null, "You lost");
            }
    }
}
