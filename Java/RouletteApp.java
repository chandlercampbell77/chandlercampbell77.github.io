import java.util.Scanner; // Needed for input
import java.util.Random; // Needed for random number generator
import java.util.ArrayList; // Needed for ArrayList
import java.util.InputMismatchException; // Needed for try + catch blocks
import java.text.DecimalFormat; // Needed to format doubles

public class RouletteApp {
  // Global variables
  // Users start with $1000 in cash
  static int cash = 1000;
  
  // No earnings because they haven't played yet
  static int netEarnings = 0;
  
  // Menu method that displays commands to the user
  static void menu() {
    System.out.println("\nplay -- start a round of roulette");
    System.out.println("deposit -- add money to your account");
    System.out.println("withdraw -- remove money from your account");
    System.out.println("check -- determine cash available");
    System.out.println("stat -- view playing history");
    System.out.println("exit -- quit the program");
    System.out.print("\nEnter Command: ");
  }
  
  // Method to play 1 round of roulette
  static boolean play() {
    
    // Some variables that will come in handy later
    boolean betPlaced = false;
    boolean win = false;
    int roundEarnings = 0;
    int iteration = 0;
    
    // Random number generator
    Random number = new Random();
    
    // Two lists to keep track of bets for the round
    ArrayList<Integer> betNumbers = new ArrayList<Integer>();
    ArrayList<Integer> betAmounts = new ArrayList<Integer>();
    
    // Loop until the user has placed all bets
    while (!betPlaced) {
      
      // Retrieve user bet amount
      Scanner input = new Scanner(System.in);
      System.out.print("Enter a bet amount: $");
      try {
        int amount = input.nextInt();
        if (amount < 1) {
          System.out.println("Please enter a bet amount of at least $1.");
          continue;
        }
        betAmounts.add(amount);
        if (betAmounts.get(iteration) > cash) {
          System.out.println("Not enough cash available. You only have $" + cash + " available.");
          continue;
        }
      }
      catch(InputMismatchException ex) {
        System.out.println("Please enter numbers only.");
        input.nextLine();
        continue;
      }
      // Deduct bet amount from user
      netEarnings -= betAmounts.get(iteration);
      roundEarnings -= betAmounts.get(iteration);
      // Retrieve user betting number
      System.out.print("Enter a number 0-36: ");
      try {
        int num = input.nextInt();
        if (num < 0 || num > 36) {
          System.out.println("Number must be between 0-36 (inclusive).");
          continue;
        }
        betNumbers.add(num);
        input.nextLine();
        System.out.println("\nYou bet $" + betAmounts.get(iteration) + " on " + betNumbers.get(iteration) + "!");
      }
      catch(InputMismatchException ex) {
        System.out.println("Please enter numbers only.");
        input.nextLine();
        continue;
      }
      System.out.print("Do you want to bet on more numbers? (yes/no): ");
      try {
        String betMore = input.nextLine();
        if (betMore.toLowerCase().equals("no")) {
          betPlaced = true;
        }
        // Otherwise, the user wants to bet more so we should loop again
        iteration++;
      }
      catch(InputMismatchException ex) {
        System.out.println("Please enter 'yes' or 'no' only.");
        input.nextLine();
        continue;
      }
    }
    // The user is done betting now so we can begin the "spin"
    System.out.println("Deducting bets from account and spinning the wheel...\n");

    // This generates a random winning number 0-36
    int winningNumber = number.nextInt(37);

    // Loop through user bets to see if they won
    for (int i = 0; i < betNumbers.size(); i++) {
      if (betNumbers.get(i) == winningNumber) {
        win = true;
        netEarnings += betAmounts.get(i);
        netEarnings += betAmounts.get(i) * 35;
        roundEarnings += betAmounts.get(i);
        roundEarnings += betAmounts.get(i) * 35;
      }
    }
    // Update cash based on whether user won
    cash += roundEarnings;
      
    // Inform user on whether they won
    System.out.println("The winning number is " + winningNumber + "!");
    if (win) {
      System.out.println("You won $" + roundEarnings + "!");
    }
    else {
      System.out.println("You lost. Better luck next time.");
    }
    System.out.println("Your total cash is now $" + cash + ".");
    return win;
  }
  
  // Method to add money to account
  static void deposit() {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter amount to deposit: $");
    try {
      int amount = input.nextInt();
      if (amount > 0) {
        cash += amount;
        System.out.println("You deposited $" + amount + ". Your total cash is now $" + cash + ".");
      }
      else {
        System.out.println("You must deposit at least $1.");
      }
    }
    catch(InputMismatchException ex) {
      System.out.println("Please enter numbers only.");
      input.nextLine();
    }
  }
  
  // Method to remove money from account
  static void withdraw() {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter amount to withdraw: $");
    try {
      int amount = input.nextInt();
      if (amount <= cash) {
        cash -= amount;
        System.out.println("You withdrew $" + amount + ". Your total cash is now $" + cash + ".");
      }
      else {
        System.out.println("You do not have enough cash to withdraw $" + amount + ".");
      }
    }
    catch(InputMismatchException ex) {
      System.out.println("Please enter numbers only.");
      input.nextLine();
    }
  }
  
  // Method for user to view the cash they have
  static void check() {
    System.out.println("Your total cash is $" + cash + ".");
  }
  
  // Method to view playing history
  static void statistics(int wins, int losses, int games) {
    
    // Formating the winning percent as a percentage
    DecimalFormat decfor = new DecimalFormat("0.00");
    double winningPercent = 0.0;
    
    // Make sure not a 0 in the denominator
    if (games > 0) {
      winningPercent = ((double) wins / (double) games) * 100;
    }
    System.out.println("Wins: " + wins);
    System.out.println("Losses: " + losses);
    System.out.println("Games Played: " + games);
    System.out.println("Winning Percent: " + decfor.format(winningPercent) + "%");
    System.out.println("Net Earnings: $" + netEarnings);
  }

  // Main program utilizing methods
  public static void main(String[] args) {
    // When user starts, they have no playing history
    int wins = 0;
    int losses = 0;
    int games = 0;
    
    Scanner input = new Scanner(System.in);
    System.out.println("\nWelcome user. You have $1000 in cash available.");
    
    // This is how the user navigates the program -- by entering one-word commands
    // Start with no command
    String command = "";
    
    // Continuously display options until user exits program via command
    while (!command.equals("exit")) {
      menu();
      try {
        command = input.nextLine();
        
        // User selects to play a round of roulette
        if (command.toLowerCase().equals("play")) {
          
          // User cannot play unless they have money
          if (cash > 0) {
            
            // The play method returns a boolean of whether the user won
            boolean win = play();
            games++;
            if (win) {
              wins++;
            }
            else {
              losses++;
            }
          }
          else {
            System.out.println("Not enough cash available.");
          }
        }
          
        // User selects to add money to their account
        else if (command.toLowerCase().equals("deposit")) {
          deposit();
        }
          
        // User selects to remove money from their account
        else if (command.toLowerCase().equals("withdraw")) {
          // User can only remove money if they have some
          if (cash > 0) {
            withdraw();
          }
          else {
            System.out.println("Not enough cash available.");
          }
        }
          
        // User selects to see their balance
        else if (command.toLowerCase().equals("check")) {
          check();
        }
          
        // User selects to see their playing history
        else if (command.toLowerCase().equals("stat")) {
          statistics(wins, losses, games);
        }
          
        // User did not enter a valid command
        else if (!command.toLowerCase().equals("exit")) {
          System.out.println("Please enter a valid command.");
        }
      }
      catch(InputMismatchException ex) {
        System.out.println("Please enter a valid command");
        input.nextLine();
        continue;
      }
    }
  }
}