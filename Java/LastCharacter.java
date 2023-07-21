import java.util.Scanner; // Needed for reading user input 
public class LastCharacter {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("Type in a word or phrase and press enter.");
    String word = input.nextLine();
    int length = word.length();
    int lastindex = length - 1;
    char lastchar = word.charAt(lastindex);
    System.out.println("The last character in " + word + " is " + lastchar + "!");
    
  }
}