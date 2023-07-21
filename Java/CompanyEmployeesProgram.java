import java.util.ArrayList;
import java.io.File; 
import java.io.FileNotFoundException; 
import java.io.IOException; 
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.util.List;
import java.util.Scanner;

class CompanyEmployeesProgram {

  public static ArrayList<CompanyEmployee> readEmployees(String csvFile) {
    // Create an empty ArrayList of CompanyEmployee objects
    ArrayList<CompanyEmployee> employeeList = new ArrayList<>();
    
    File inputDataFile = new File(csvFile);
  
    try {
      List<String> lines = Files.readAllLines(inputDataFile.toPath());
      for(String line : lines) {
        String[] employeeData = line.split(",");
        int id = Integer.parseInt(employeeData[0]);
        int salary = Integer.parseInt(employeeData[1]);
        // Last name & first name don't need conversion to another datatype. 
        String lastName = employeeData[2];
        String firstName = employeeData[3];
        // Now construct a CompanyEmployee object for each employee
        CompanyEmployee empl = new CompanyEmployee(lastName, firstName, id, salary);
        // Add CompanyEmployee object to ArrayList
        employeeList.add(empl);
      }
    }
    catch(FileNotFoundException ex) {
      System.out.println("File not found: " + ex.getMessage());
    }
    catch(IOException ex) {
      System.out.println("I/O error: " + ex.getMessage());
    }
    catch(NumberFormatException ex) {
       System.out.println("Number Format Error: " + ex.getMessage());
    }
    return employeeList;
  }

  public static void writeEmployees(String csvFile, ArrayList<CompanyEmployee> employees) {
    // Convert ArrayList<CompanyEmployee> to ArrayList<String>
    ArrayList<String> newEmployees = new ArrayList<>();
    for(CompanyEmployee employee : employees) {
      newEmployees.add(employee.getId() + "," + employee.getSalary() + "," + employee.getLastName() + "," +       
                       employee.getFirstName());
    }
    File outputFile = new File(csvFile);
    try {
      // Write to output file in APPEND mode
      Files.write(outputFile.toPath(), newEmployees, StandardOpenOption.APPEND);
    }
    catch(IOException ex) {
      System.out.println("Error writing to file: " + ex.getMessage());
    }
  }

  public static void addEmployees(Scanner input, String csvFile) {
    ArrayList<CompanyEmployee> employeesToAdd = new ArrayList<>();
    char keepGoing = 'Y';
    while(keepGoing == 'Y') {
      System.out.print("Enter employee last name: ");
      String lastName = input.nextLine();
      System.out.print("Enter employee first name: ");
      String firstName = input.nextLine();
      System.out.print("Enter employee ID#: ");
      int id = input.nextInt();
      System.out.print("Enter employee salary: ");
      int salary = input.nextInt();
      // Remove new line left in buffer
      input.nextLine();
      CompanyEmployee employee = new CompanyEmployee(lastName, firstName, id, salary);
      employeesToAdd.add(employee);

      // Does user want to continue?
      System.out.print("Add another employee? (Y/N): ");
      keepGoing = input.nextLine().charAt(0);
    }

    // Now call method to write new data to file
    writeEmployees("employees.csv", employeesToAdd);
  }

  public static void listEmployees(String csvFile) {
    ArrayList<CompanyEmployee> employees = readEmployees(csvFile);
    int menuNumber = 1;
    for(CompanyEmployee employee : employees) {
      System.out.println(menuNumber++ + ". " + employee);
    }
  }

   public static boolean deleteEmployee(String csvFile, int emplID) {
    // Read contents of existing file
    ArrayList<CompanyEmployee> employees = readEmployees(csvFile);
    // Track if employee has been found and deleted
    boolean employeeDeleted = false;
    CompanyEmployee emplToDelete = null; 
    for(CompanyEmployee empl : employees) {
      if(empl.getId() == emplID) {
        emplToDelete = empl;
      }
    }
    if(emplToDelete != null) {
      employees.remove(emplToDelete);
      employeeDeleted = true;
      ArrayList<String> remainingEmployees = new ArrayList<>();
      for(CompanyEmployee empl : employees) {
        remainingEmployees.add(empl.getId() + "," + empl.getSalary() + "," + empl.getLastName() +
          "," + empl.getFirstName());
      }
      File outputFile = new File(csvFile);
      try {
        // Write to output file - overwrite if it already exists
        Files.write(outputFile.toPath(), remainingEmployees, StandardOpenOption.TRUNCATE_EXISTING);
      }
      catch(IOException ex) {
        System.out.println("Error writing to file: " + ex.getMessage());
      }
    }
    return employeeDeleted;
   }

  public static void displayMenu() {
    System.out.println("\nlist - List all employees");
    System.out.println(" add - Add an employee");
    System.out.println(" del - Delete an employee");
    System.out.println("exit - Exit program");
    System.out.print("Enter Command: ");
  }
  
  
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    String cmd = "";
    System.out.print("Enter the name of the CSV file: ");
    String csvFile = input.nextLine();
      
    while(!cmd.toLowerCase().equals("exit")) {
      displayMenu();
      cmd = input.nextLine();
      if(cmd.toLowerCase().equals("list")) {
        listEmployees(csvFile);   
      }
      else if(cmd.toLowerCase().equals("add")) {
        addEmployees(input, csvFile);
      }
      else if(cmd.toLowerCase().equals("del")) {
         System.out.print("Employee ID to delete: ");
         int emplId = input.nextInt();
          deleteEmployee(csvFile, emplId);
      }
    }
  }
}
  