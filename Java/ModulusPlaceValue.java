public class ModulusPlaceValue {
  public static void main(String[] args) {
    int number = 6849;
 
    System.out.println("Using modulus to get rightmost digit(s): ");
    // Get the rightmost digit using % 10
    int modulus = number % 10;
    System.out.println("The rightmost digit in " + number + " is " + modulus + " (" + number + " % 10).");
    // Get the rightmost 2 digits using % 100
    modulus = number % 100;
    System.out.println("The rightmost 2 digits in " + number + " are " + modulus + " (" + number + " % 100).");
  }
}