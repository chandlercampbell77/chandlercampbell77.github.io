// Needed for input
import java.util.Scanner;
// Needed for writing to files
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.io.IOException;
// Needed for converting array to deep string
import java.util.Arrays;

class AISurveyProgram {
  public static void main(String[] args) {
    System.out.println();
    System.out.println("Welcome to the AI Survey Program!");
    System.out.println("You will be asked 20 questions. Your answers will help me predict your political party.");
    System.out.println("To select an answer, type the letter choice and press enter.");
    System.out.println();

    // Initialize and fill a 2D array
    // The first bracket lets you access the rows (20 question objects)
    // The second bracket lets you access the columns (5 objects per question object, 1 actual question and 4 answer choices)
    String[][] qAndA = {
      {"1. What should be done about Social Security?", "A. Expand it to everyone", "B. Protect it", "C. Cut it", "D. Eliminate it"},
      {"2. What should be done about Medicare?", "A. Expand it to everyone", "B. Protect it", "C. Cut it", "D. Eliminate it"},
      {"3. What should be done about the military?", "A. Eliminate it--war is wrong", "B. Cut it", "C. Expand it", "D. Replace it with private militias"},
      {"4. What should be done about immigration?", "A. Eliminate the border--borders are racist", "B. Protect undoccumented immigrants", "C. Reduce illegal immigration", "D. Expand immigration to benefit the economy"},
      {"5. What should be done about minorities?", "A. Extensive reparations", "B. More Affirmative Action", "C. Less Affirmative Action", "D. Let the free market determine"},
      {"6. What should be done about the LGBTQ community?", "A. Extensive reparations", "B. Protect them from discrimination", "C. Ban them from schools", "D. Let the free market determine"},
      {"7. What should be done about taxes?", "A. Expand them extensively", "B. Keep the same or raise a little", "C. Cut them", "D. Eliminate all taxes"},
      {"8. What should be done about the poor?", "A. Wealth redistribution", "B. Expanded welfare", "C. Work training programs", "D. Let the free market determine"},
      {"9. What should be done about the environment?", "A. Eliminate all industrial activity", "B. Tax heavy polluters", "C. The same as now", "D. Eliminate all environmental protection"},
      {"10. What should be done about the police?", "A. Eliminate all police", "B. Body cameras and training", "C. The same as now", "D. Replace with private security"},
      {"11. What should be done about guns?", "A. Take all the guns", "B. More gun laws", "C. Less gun laws", "D. No gun laws"},
      {"12. What should be done about equal pay for men and women?", "A. Strictly enforce it", "B. Advocate for it", "C. The same as now", "D. Let the free market determine"},
      {"13. What should be done about abortion?", "A. Give money to women to have abortions", "B. Allow it until 6 months", "C. Greatly restrict it", "D. No government regulations"},
      {"14. What should be done about religion?", "A. Ban it", "B. Keep it out of schools", "C. Put it in schools", "D. Let people do believe whatever they want"},
      {"15. What should be done about rising college costs?", "A. Make it free", "B. Partial student loan forgiveness", "C. Eliminate low-paying majors", "D. Let the colleges charge whatever they want"},
      {"16. What should be done about social media?", "A. Eliminate all private companies", "B. Regulate it to prevent hate speech", "C. Regulate it to prevent discrimination against conservatives", "D. Let the free market determine"},
      {"17. What should be done about the death penalty?", "A. Allow for the rich only", "B. Eliminate it as it is racist", "C. Expand it", "D. Create private companies to do it"},
      {"18. What should be done about surveilance?", "A. Use it to spy on the rich", "B. Reduce it", "C. Use it to spy on potential terrorists", "D. Eliminate it"},
      {"19. What should be done about private prisons?", "A. Eliminate them", "B. More regulation", "C. The same as now", "D. Let the free market determine"},
      {"20. Which political party do you affiliate with?", "A. Communist", "B. Democrat", "C. Republican", "D. Libertarian"}
    };

    // Setting up file names that will be needed later to create and access the files
    String comFile = "communist.txt";
    String demFile = "democrat.txt";
    String repFile = "republican.txt";
    String libFile = "libertarian.txt";

    // questionLen = 20 because there are 20 question objects
    int questionLen = qAndA.length;
    // answerLen = 5 because there is the wording of the question and then 4 answer choices
    int answerLen = qAndA[0].length;

    // For simplicity, all the 'A' answer choices correspond to the Communist Party
    String communist = "A";
    // For simplicity, all the 'B' answer choices correspond to the Democrat Party
    String democrat = "B";
    // For simplicity, all the 'C' answer choices correspond to the Republican Party
    String republican = "C";
    // For simplicity, all the 'D' answer choices correspond to the Libertarian Party
    String libertarian = "D";

    // Initializing variables used to predict party affiliation
    int comPoints = 0;
    int demPoints = 0;
    int repPoints = 0;
    int libPoints = 0;

    // Variables initialized that will be used in the loops below
    // Scanner for input, answer to store user input, content for writing to file, answered to determine if user answered question
    Scanner scanner = new Scanner(System.in);
    String answer = "";
    String content = "";
    boolean answered = false;

    // Nested for loops will display the questions, keep track of answers, and write questions and answers to files
    // Loop through all the question objects
    for (int i = 0; i < questionLen; i++) {
      // If the user has answered 8 questions, it is possible that a prediction can be made, so check
      if (i >= 8) {
        // 23 is used because there are 45 points to allocate. 23/45 is a majority of points
        if (comPoints >= 23 || demPoints >= 23 || repPoints >= 23 || libPoints >= 23) {
          System.out.println();
          System.out.println("I have enough information to predict your political party. No need for further questions.");
          break;
        }
      }
      // For each new question, reset boolean answered variable and print a new line
      answered = false;
      System.out.println();
      // Access a particular question object's elements
      for (int j = 0; j < answerLen; j++) {
        System.out.println(qAndA[i][j]);
        // If j is 4 then the entire question object has been printed out
        if (j == 4) {
          // While loop to make sure user enters a valid answer
          while (!answered) {
            System.out.println();
            System.out.print("Answer: ");
            answer = scanner.nextLine();
            if (answer.equalsIgnoreCase(communist)) {
              answered = true;
              try {
                // Write the content of the question object and user answer to communist.txt file
                content = Arrays.deepToString(qAndA[i]) + "\nAnswer: " + answer.toUpperCase() + "\n\n";
                Files.write(Paths.get(comFile), content.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
              } catch (IOException e) {
                System.out.println("An error occurred while writing to the file.");
                e.printStackTrace();
              }
              // First 10 questions are weighted 3 points each
              if (i < 10) {
                comPoints += 3;
              }
              // Questions 11-15 are weighted 2 points each
              else if (i >= 10 && i < 15) {
                comPoints += 2;
              }
              // Questions 16-20 are weighted 1 point each
              else {
                comPoints += 1;
              }
            }
            else if (answer.equalsIgnoreCase(democrat)) {
              answered = true;
              try {
                // Write the content of the question object and user answer to democrat.txt file
                content = Arrays.deepToString(qAndA[i]) + "\nAnswer: " + answer.toUpperCase() + "\n\n";
                Files.write(Paths.get(demFile), content.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
              } catch (IOException e) {
                System.out.println("An error occurred while writing to the file.");
                e.printStackTrace();
              }
              // First 10 questions are weighted 3 points each
              if (i < 10) {
                demPoints += 3;
              }
              // Questions 11-15 are weighted 2 points each
              else if (i >= 10 && i < 15) {
                demPoints += 2;
              }
              // Questions 16-20 are weighted 1 point each
              else {
                demPoints += 1;
              }
            }
            else if (answer.equalsIgnoreCase(republican)) {
              answered = true;
              try {
                // Write the content of the question object and user answer to the republican.txt file
                content = Arrays.deepToString(qAndA[i]) + "\nAnswer: " + answer.toUpperCase() + "\n\n";
                Files.write(Paths.get(repFile), content.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
              } catch (IOException e) {
                System.out.println("An error occurred while writing to the file.");
                e.printStackTrace();
              }
              // First 10 questions are weighted 3 points each
              if (i < 10) {
                repPoints += 3;
              }
              // Questions 11-15 are weighted 2 points each
              else if (i >= 10 && i < 15) {
                repPoints += 2;
              }
              // Questions 16-20 are weighted 1 point each
              else {
                repPoints += 1;
              }
            }
            else if (answer.equalsIgnoreCase(libertarian)) {
              answered = true;
              try {
                // Write the content of the quesiton object and user answer to the libertarian.txt file
                content = Arrays.deepToString(qAndA[i]) + "\nAnswer: " + answer.toUpperCase() + "\n\n";
                Files.write(Paths.get(libFile), content.getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
              } catch (IOException e) {
                System.out.println("An error occurred while writing to the file.");
                e.printStackTrace();
              }
              // First 10 questions are weighted 3 points each
              if (i < 10) {
                libPoints += 3;
              }
              // Questions 11-15 are weighted 2 points each
              else if (i >= 10 && i < 15) {
                libPoints += 2;
              }
              // Questions 16-20 are weighted 1 point each
              else {
                libPoints += 1;
              }
            }
            else {
              System.out.println("Please enter a valid answer choice: A, B, C, or D");
            }
          }
        }
      }
    }

    // Displaying results to user
    System.out.println();
    System.out.println("Communist Points: " + comPoints);
    System.out.println("Democrat Points: " + demPoints);
    System.out.println("Republican Points: " + repPoints);
    System.out.println("Libertarian Points: " + libPoints);
    System.out.println();

    // Make prediction of user's political party based on which received the plurality of points
    if (comPoints > demPoints && comPoints > repPoints && comPoints > libPoints) {
      System.out.println("Your party affiliation is likely Communist.");
    }
    else if (demPoints > comPoints && demPoints > repPoints && demPoints > libPoints) {
      System.out.println("Your party affiliation is likely Democrat.");
    }
    else if (repPoints > comPoints && repPoints > demPoints && repPoints > libPoints) {
      System.out.println("Your party affiliation is likely Republican.");
    }
    else if (libPoints > comPoints && libPoints > demPoints && libPoints > repPoints) {
      System.out.println("Your party affiliation is likely Libertarian.");
    }
    else {
      System.out.println("There was a tie! Your party affiliation cannot be determined.");
    }
  }
}