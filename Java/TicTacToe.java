import java.util.Arrays;
import java.util.Scanner;

public class TicTacToeMethods {
  public static void main(String[] args) {
    String[][] board = {{" - ", " - ", " - "},
                        {" - ", " - ", " - "},
                        {" - ", " - ", " - "}};
    // Array of player marks    
    char[] player = {'X', 'O'};
        
    int col = 0;
    int row = 0;
    // Initialized so input while loop runs until entry is valid    
    boolean validSelection = false;
        
    Scanner input = new Scanner(System.in);
        
    // Draw initial empty board
    drawGame(board);
        
        // Start turns. Even turns are X, odd turns are O
    for(int turn = 0; turn < 9; turn++) {
      // Prompt for input until the user makes a valid move
      while(!validSelection) {
        System.out.print(player[turn % 2] + " - Select row (1 - 3) & " +
          "select column (1 - 3) separated by a space: ");
        row = input.nextInt();
        col = input.nextInt();
        if(isValidSelection(row, col)) {
          if(isPositionOpen(board, row, col)) {
            // Set player character at position
            board[row - 1][col - 1] = " " + player[turn % 2] + " ";
            // while loop will end when selected move is valid
            validSelection = true;
          }
          else { // Position is not open
            System.out.println("Sorry, that spot is taken.");
          }
        }
        // Not a valid position
        else {
          System.out.println("Sorry, that is not a valid selection.");
        }

      }
      drawGame(board);
      // Check if this is 5th or later turn (turn starts at 0)
      if(turn >= 4) {
        int winningRow = checkForRowWin(board, player[turn % 2]);
        int winningColumn = checkForColumnWin(board, player[turn % 2]);
        int winningDiagonal = checkForDiagonalWin(board, player[turn % 2]);
        if(winningRow > 0 || winningColumn > 0 || winningDiagonal > 0) {
          System.out.println("\n" + player[turn % 2] + " wins!\n");
          break;
        }
      }
      // Set so that while loop repeats until next player makes valid move
      validSelection = false;
    } // end of for loop for turns
  } // end of main()
  
  // Method to draw board. Parameter is a 2-d array with board data.  
  public static void drawGame(String[][] board) {
    for(int row = 0; row < board.length; row++) {
      System.out.println(Arrays.toString(board[row]));
    }
    System.out.println();
  }
  
  // Method to check if player has selected row & column within bounds
  // Takes 2 int parameters for selected row & column.
  // Returns true if selection is in bounds, false if not  
  public static boolean isValidSelection(int row, int column) {
    // ! needed to return true if selection is valid position
    return !(row < 1 || row > 3 || column < 1 || column > 3);
  }
  
  // Method to check if selected position is open. 
  // Parameters: 2-d array with board data, ints for row & column
  // Returns true is selected position is open, otherwise false  
  public static boolean isPositionOpen(String[][] board, int row, int column)   
  {
    // Open squares marked with " - "
    return board[row - 1][column - 1].equals(" - ");
  }
  
  // Check if a player has a win in 1 of the rows. 
  // Parameters: 2-d array with board data, char ('X' or 'O') for player
  // Returns 0 if no winning row, or 1, 2, or 3 if winning row  
  public static int checkForRowWin(String[][] board, char player) {
    int rowNumber = 0;
    for(int row = 0; row < 3; row++) {
      if(board[row][0].equals(" " + player + " ") &&
          board[row][1].equals(" " + player + " ") &&
          board[row][2].equals(" " + player + " ")) {
        rowNumber = row + 1;
        break;
      }
    }
    return rowNumber;
  }
    
  // Check if a player has a win in 1 of the columns. 
  // Parameters: 2-d array with board data, char ('X' or 'O') for player
  // Returns 0 if no winning col, or 1, 2, or 3 if winning col  
  public static int checkForColumnWin(String[][] board, char player) {
    int columnNumber = 0;
    for(int column = 0; column < 3; column++) {
      if(board[0][columnNumber].equals(" " + player + " ") &&
          board[1][columnNumber].equals(" " + player + " ") &&
          board[2][columnNumber].equals(" " + player + " ")) {
        columnNumber = column + 1;                
      }
    }
    return columnNumber;
  }
  
  // Check if a player has a win in 1 of the diagonals. 
  // Parameters: 2-d array with board data, char ('X' or 'O') for player
  // Returns 0 if no winning diagonal, or 1 or 2 if winning diagonal  
  
  public static int checkForDiagonalWin(String[][] board, char player) {
    int diagonalNumber = 0;
    // Player must have central square to have winning diagonal
    if(board[1][1].equals(" " + player + " ")) {
      if(board[0][0].equals(" " + player + " ") &&
          board[2][2].equals(" " + player + " ")) {
        diagonalNumber = 1;
      }
      else if(board[0][2].equals(" " + player + " ") &&
          board[2][0].equals(" " + player + " ")) {
        diagonalNumber = 2;
      }
    }
    return diagonalNumber;
  }

} // end of TicTacToeMethods class