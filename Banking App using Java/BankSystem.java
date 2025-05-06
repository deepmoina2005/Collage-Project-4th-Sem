import java.util.ArrayList;
import java.util.Scanner;

public class BankSystem {
    private Account account;
    private final Scanner scanner = new Scanner(System.in);

    public void createAccount() {
        if (account != null) {
            System.out.println("Account already exists.");
            return;
        }

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        account = new Account(name);
        System.out.println("Account created for " + name);
    }

    public void deposit() {
        if (checkAccount()) return;

        System.out.print("Enter amount to deposit: ");
        double amount = scanner.nextDouble();

        account.deposit(amount);
    }

    public void withdraw() {
        if (checkAccount()) return;

        System.out.print("Enter amount to withdraw: ");
        double amount = scanner.nextDouble();

        account.withdraw(amount);
    }

    public void checkBalance() {
        if (checkAccount()) return;

        System.out.println("Current balance: " + account.getBalance());
    }

    public void printTransactionHistory() {
        if (checkAccount()) return;

        account.printTransactions();
    }

    private boolean checkAccount() {
        if (account == null) {
            System.out.println("No account found. Please create one first.");
            return true;
        }
        return false;
    }
}
