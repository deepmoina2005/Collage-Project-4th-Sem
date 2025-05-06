import java.util.ArrayList;
import java.util.Scanner;

public class ExpenseTracker {
    private ArrayList<Expense> expenses;

    // Constructor
    public ExpenseTracker() {
        expenses = new ArrayList<>();
    }

    // Method to add expense or income
    public void addExpense(String category, double amount, String description) {
        Expense expense = new Expense(category, amount, description);
        expenses.add(expense);
    }

    // Method to view all expenses
    public void viewExpenses() {
        if (expenses.isEmpty()) {
            System.out.println("No expenses recorded yet.");
        } else {
            System.out.println("----- All Expenses -----");
            for (Expense expense : expenses) {
                System.out.println(expense);
            }
        }
    }

    // Method to view the total expense
    public void viewTotalExpense() {
        double total = 0;
        for (Expense expense : expenses) {
            total += expense.getAmount();
        }
        System.out.println("Total Expense: " + total);
    }

    // Method to view total income
    public void viewTotalIncome() {
        double total = 0;
        for (Expense expense : expenses) {
            if (expense.getAmount() > 0) {
                total += expense.getAmount();
            }
        }
        System.out.println("Total Income: " + total);
    }

    // Method to view total spending
    public void viewTotalSpending() {
        double total = 0;
        for (Expense expense : expenses) {
            if (expense.getAmount() < 0) {
                total += Math.abs(expense.getAmount());  // Make sure to sum positive value for spending
            }
        }
        System.out.println("Total Spending: " + total);
    }

    // Method to remove expense by index
    public void removeExpense(int index) {
        if (index >= 0 && index < expenses.size()) {
            expenses.remove(index);
            System.out.println("Expense removed successfully.");
        } else {
            System.out.println("Invalid index. No expense removed.");
        }
    }
}