import java.util.Scanner;

public class ExpenseTrackerApp {
    private static Scanner scanner = new Scanner(System.in);
    private static ExpenseTracker tracker = new ExpenseTracker();

    public static void main(String[] args) {
        // Display welcome message
        System.out.println("Welcome to the Daily Expense Tracker!");

        while (true) {
            // Display menu
            displayMenu();
            int choice = getChoice();

            // Handle user choice
            switch (choice) {
                case 1:
                    addExpense();
                    break;
                case 2:
                    tracker.viewExpenses();
                    break;
                case 3:
                    tracker.viewTotalExpense();
                    break;
                case 4:
                    tracker.viewTotalIncome();
                    break;
                case 5:
                    tracker.viewTotalSpending();
                    break;
                case 6:
                    removeExpense();
                    break;
                case 7:
                    System.out.println("Exiting the system...");
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }

    // Display the main menu
    private static void displayMenu() {
        System.out.println("\n----- Menu -----");
        System.out.println("1. Add Expense/Income");
        System.out.println("2. View All Expenses");
        System.out.println("3. View Total Expense");
        System.out.println("4. View Total Income");
        System.out.println("5. View Total Spending");
        System.out.println("6. Remove Expense");
        System.out.println("7. Exit");
    }

    // Get user's menu choice
    private static int getChoice() {
        System.out.print("Choose an option: ");
        while (!scanner.hasNextInt()) {
            System.out.println("Invalid input. Please enter a number.");
            scanner.next(); // Consume the invalid input
        }
        return scanner.nextInt();
    }

    // Add an expense or income
    private static void addExpense() {
        System.out.print("Enter Category (e.g., Food, Rent, Salary): ");
        scanner.nextLine();  // Consume newline
        String category = scanner.nextLine();

        System.out.print("Enter Amount (positive for income, negative for expense): ");
        double amount = scanner.nextDouble();

        System.out.print("Enter Description: ");
        scanner.nextLine();  // Consume newline
        String description = scanner.nextLine();

        tracker.addExpense(category, amount, description);
        System.out.println("Expense/Income added successfully.");
    }

    // Remove an expense
    private static void removeExpense() {
        System.out.println("Enter the index of the expense to remove:");
        tracker.viewExpenses();

        int index = scanner.nextInt();
        tracker.removeExpense(index);
    }
}