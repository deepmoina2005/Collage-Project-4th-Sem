import java.util.ArrayList;
import java.util.Date;

public class Account {
    private String name;
    private double balance;
    private ArrayList<Transaction> transactions;

    public Account(String name) {
        this.name = name;
        this.balance = 0.0;
        this.transactions = new ArrayList<>();
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Amount must be greater than zero.");
            return;
        }

        balance += amount;
        transactions.add(new Transaction("Deposit", amount));
        System.out.println("Deposited: " + amount);
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Amount must be greater than zero.");
            return;
        }

        if (amount > balance) {
            System.out.println("Insufficient funds.");
            return;
        }

        balance -= amount;
        transactions.add(new Transaction("Withdraw", amount));
        System.out.println("Withdrawn: " + amount);
    }

    public double getBalance() {
        return balance;
    }

    public void printTransactions() {
        if (transactions.isEmpty()) {
            System.out.println("No transactions available.");
        } else {
            System.out.println("--- Transaction History ---");
            for (Transaction t : transactions) {
                System.out.println(t);
            }
        }
    }
}
