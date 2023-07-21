import java.util.Scanner;

class UserLoginExample {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("Create New User Account: ");
    System.out.print("Enter User Name: ") ;
    String user = input.nextLine();
    System.out.print("Enter Password: ");
    String passwd = input.nextLine();

    System.out.println("Creating account...");
    UserAccount acct = new UserAccount(user, passwd);
    
    System.out.println("Now Check the Login: ");
    System.out.print("Enter User Name: ");
    String userToCheck = input.nextLine();
    System.out.print("Enter the Password: ");
    String passwordToCheck = input.nextLine();

    boolean result = acct.checkCredentials(userToCheck, passwordToCheck);
    if(result) {
      System.out.println("Login successful.");
    }
    else {
      System.out.println("Login failed!");
    }
  }
}
