import java.util.*;
import java.io.*;

public class Jarvis implements Chatbot {
    private Scanner scanner;
    private String userName;
    private DataManager dataManager;
    private Map<String, String> customReplies;

    public Jarvis() {
        scanner = new Scanner(System.in);
        dataManager = new DataManager();
        customReplies = new HashMap<>();
        loadCustomData();
    }

    private void loadCustomData() {
        customReplies.put("what is java", "Java is a powerful object-oriented language.");
        customReplies.put("who made you", "I was built using Core Java by Deepmoina.");
    }

    @Override
    public void greetUser() {
        System.out.print("Hello! I'm JARVIS. What's your name? ");
        userName = scanner.nextLine();
        System.out.println("Hi " + userName + "! How can I assist you today?");
        System.out.println("Type 'exit' to quit.");
    }

    @Override
    public void handleInput(String input) {
        input = input.toLowerCase();

        if (customReplies.containsKey(input)) {
            System.out.println(customReplies.get(input));
        } else if (input.contains("time")) {
            System.out.println("Current time: " + new Date());
        } else if (input.contains("note")) {
            dataManager.saveNote(scanner);
        } else if (input.contains("show notes")) {
            dataManager.showNotes();
        } else if (input.contains("calculator")) {
            simpleCalculator();
        } else if (input.equals("exit")) {
            System.out.println("Goodbye " + userName + "!");
            System.exit(0);
        } else {
            System.out.println("Sorry, I don't understand that.");
        }
    }

    private void simpleCalculator() {
        try {
            System.out.print("Enter first number: ");
            double a = scanner.nextDouble();
            System.out.print("Enter operator (+, -, *, /): ");
            char op = scanner.next().charAt(0);
            System.out.print("Enter second number: ");
            double b = scanner.nextDouble();
            scanner.nextLine();

            double result;
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = b != 0 ? a / b : Double.NaN; break;
                default: System.out.println("Invalid operator."); return;
            }

            System.out.println("Result: " + result);
        } catch (InputMismatchException e) {
            System.out.println("Invalid input.");
            scanner.nextLine(); // clear
        }
    }
}