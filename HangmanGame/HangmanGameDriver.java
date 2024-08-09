import java.util.*;
class HangmanGame{
    private List<List<String>> list;
    private int numberOfGuessLeft = 5;
    private int score = 0;
    private Scanner scan = new Scanner(System.in);
    private String theChosenWord;
    private int type;
    private char []currentBox;
    HangmanGame(){
        list = new ArrayList<>(); 
        list.add(new ArrayList<>(Arrays.asList("Animal", "cat", "dog", "bird", "kitten", "mahdi")));
        list.add(new ArrayList<>(Arrays.asList("Vehicle", "car", "motorcycle", "bicycle", "bruck", "bus")));
        list.add(new ArrayList<>(Arrays.asList("Food", "pizza", "salad", "sushi", "pasta", "steak")));
        list.add(new ArrayList<>(Arrays.asList("Fruit", "apple", "banana", "orange", "strawberry", "pineapple")));
        list.add(new ArrayList<>(Arrays.asList("Tech", "phone", "computer", "car", "internet", "facebook")));
        type = new Random().nextInt(5);
        theChosenWord = wordToGuess();
        currentBox = new char[theChosenWord.length()];
        for (int i = 0; i < currentBox.length; ++i)
            currentBox[i] = '_';
    }
    public void go(){
        System.out.format("Guess the word! One charachter at a time please. It's a(n) %s:%n", list.get(type).get(0));
        do{
            start();
            char guessed = getUserInput(scan);
            guessWasRight(guessed, theChosenWord);
        }while(numberOfGuessLeft > 0 && (score / 100 < currentBox.length));
        if (numberOfGuessLeft > 0)
            System.out.println("You won! Your score: " + score);
        else
            System.out.println("You lost! Your socre: " + score);
        System.out.println("The word was " + theChosenWord);
        
    }
    // get User Input
    private char getUserInput(Scanner scan){
        char usuerInput = scan.next().toLowerCase().charAt(0);
        if (Character.isLetter(usuerInput))
            return usuerInput;
        return getUserInput(scan);
    }
    // check if it's right
    private void guessWasRight(char guess, String chosen){
        for (int i = 0; i < chosen.length(); ++i)
            if (guess == chosen.charAt(i)){
                modify(i, guess);
                score += 100;
                return;
            }
        numberOfGuessLeft--;
    }
    // modifies the word box
    private void modify(int loc, char guess){
        currentBox[loc] = guess;
    }
    private void start(){
        System.out.print("Number of guess left: " + numberOfGuessLeft + " Guess: ");
        for (int i = 0; i < currentBox.length; ++i)
            System.out.print(currentBox[i]);
        System.out.println();
    }
    private String wordToGuess(){
        int w = new Random().nextInt(5) + 1;
        return list.get(type).get(w);
    }
}
public class HangmanGameDriver {
    public static void main(String[] args) {
        new HangmanGame().go();
    }
}
