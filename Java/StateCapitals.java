import java.util.*;

public class StateCapitals {
  public static void main (String [] args) {
    // Create 2D array with all 50 states and their respective capitals, sorted by states alphabetically
    // States are in row 0, capitals are in row 1
    String[][] statesAndCapitals = {
      {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"},
      {"Montgomery", "Juneau", "Phoenix", "Little Rock", "Sacramento", "Denver", "Hartford", "Dover", "Tallahassee", "Atlanta", "Honolulu", "Boise", "Springfield", "Indianapolis", "Des Moines", "Topeka", "Frankfort", "Baton Rouge", "Augusta", "Annapolis", "Boston", "Lansing", "Saint Paul", "Jackson", "Jefferson City", "Helena", "Lincoln", "Carson City", "Concord", "Trenton", "Santa Fe", "Albany", "Raleigh", "Bismarck", "Columbus", "Oklahoma City", "Salem", "Harrisburg", "Providence", "Columbia", "Pierre", "Nashville", "Austin", "Salt Lake City", "Montpelier", "Richmond", "Olympia", "Charleston", "Madison", "Cheyenne"}
    };
    // Create a new input reader
    Scanner input = new Scanner(System.in);
    // Ask the user to name a state capital
    System.out.println("Guess a state capital then press enter: ");
    String capitalGuess = input.nextLine();
    // Variable to see to keep track of if user was correct
    int correct = 0;
    // Variable to store state of state capital user guessed
    // Setting to -1 because we are unsure if the user is correct yet
    int stateIndex = -1;
    // Create a variable to store number of capitals
    int capitalCount = statesAndCapitals[1].length;
    // Create a for loop to compare user's guess with all capitals
    for (int i = 0; i < capitalCount; i++) {
      if (statesAndCapitals[1][i].equalsIgnoreCase(capitalGuess)) {
        correct = 1;
        stateIndex = i;
        break;
      }
    }
    // If the user guessed a correct capital, let them know
    if (correct == 1) {
        System.out.println("You are correct! " + capitalGuess + " is the state capital of "
                           + statesAndCapitals[0][stateIndex] + "!");
        System.out.println();
    }
    // Otherwise, tell user they were incorrect
    else {
        System.out.println("You are incorrect. " + capitalGuess + " is not the capital of any US state.");
        System.out.println();
    }
    // Explain to user next part of program
    System.out.println("Here are all the states and their respective capitals:");
    // Use for loop to print out 2D array
    for (int i = 0; i < capitalCount; i++) {
        System.out.println(statesAndCapitals[1][i] + " is the capital of " + statesAndCapitals[0][i] + ".");
    }
    // Explain to user next part of program
    System.out.println("\nThe program will now reorder the contents of the 2D array by capital instead of state.");
    // Using bubble sort to reorder 2D array. Bubble sort requires 2 for loops, one nested inside the other.
    // The purpose is to compare each capital to the next one and 'float' the higher values to the end of the array
    // Higher values means capitals that start with letters towards the end of the alphabet
    for (int i = 0; i < capitalCount; i++) {
        for (int j = i + 1; j < capitalCount; j++) {
            // Variables that will be necessary to swap the values
            String tempCapital;
            String tempState;
            // If current capital has a higher value than next capital
            if (statesAndCapitals[1][i].compareTo(statesAndCapitals[1][j]) > 0) {
                // Then swap the order of the 2 capitals using temp variable
                tempCapital = statesAndCapitals[1][i];
                statesAndCapitals[1][i] = statesAndCapitals[1][j];
                statesAndCapitals[1][j] = tempCapital;
                // Have to do the same swap on states so states still match capitals
                tempState = statesAndCapitals[0][i];
                statesAndCapitals[0][i] = statesAndCapitals[0][j];
                statesAndCapitals[0][j] = tempState;
            }
        }
    }
    // Explain the next part of the program
    System.out.println("Your next task is to name as many state capitals as you can remember.");
    System.out.println("Press enter after each capital. Type the word 'quit' when you can't think of more capitals.");
    // Create a list of type string to store user answers
    ArrayList<String> userGuesses = new ArrayList<>();
    // Use an indefinite loop that will run until user quits
    while (true) {
        String guess = input.nextLine();
        if (guess.equalsIgnoreCase("quit")) {
            break;
        }
        else {
            userGuesses.add(guess);
        }
    }
    // Variable to keep track of how many capitals are correct
    int numberCorrect = 0;
    // Use nested for loops to see if each guess equals any of the capitals in the 2D array
    for (String guess : userGuesses) {
        for (int i = 0; i < capitalCount; i++) {
            if (guess.equalsIgnoreCase(statesAndCapitals[1][i]))
                numberCorrect += 1;
        }
    }
    // Tell user how many guesses they got correct
    System.out.println("You guessed " + userGuesses.size() + " capitals! You got " + numberCorrect + " guesses correct!");
    // Explain the next part of the program
    System.out.println("The 2D arrays of states and their capitals will now be placed into a hash map.");
    // Create the hash map, making states the key and capitals the value
    HashMap<String, String> stateCapitalMap = new HashMap<>(capitalCount);
    // Use a for loop to fill up the hash map
    for (int i = 0; i < capitalCount; i++) {
        stateCapitalMap.put(statesAndCapitals[0][i], statesAndCapitals[1][i]);
    }
    // Print out the contents of the hash map for the user to see using for loop
    for (String key : stateCapitalMap.keySet()) {
        System.out.println(key + "'s capital is " + stateCapitalMap.get(key) + ".");
    }
    // Sorting the hash map in a tree map using a binary tree
    TreeMap<String, String> sortedStateCapitalMap = new TreeMap<>(stateCapitalMap);
    // Explaining the next part of the program
    System.out.println("Your next task is to enter as many states as you want and I will tell you the capital of that state.");
    System.out.println("Press enter after each state. Type the word 'quit' when you can't think of more states.");
    System.out.println("States are case-sensitive. Don't forget to capitalize them!");
    // Creating indefinite loop for user to type in states and get their capitals
    while (true) {
      System.out.print("State: ");
      String state = input.nextLine();
      if (state.equalsIgnoreCase("quit")) {
          break;
      }
      // Otherwise, check if they entered a valid state
      else if (sortedStateCapitalMap.containsKey(state)) {
        System.out.println(sortedStateCapitalMap.get(state) + " is the capital of " + state + ".");
      }
      // Otherwise, user answered invalid state, misspelled or didn't capitialize
      else {
        System.out.println("The state you entered is not correct.");
        System.out.println("Either enter a correct state, fix your spelling, capitalize the first letter, or quit the program.");
      }
    }
  }
}