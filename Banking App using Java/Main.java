import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BankSystem bankSystem = new BankSystem();
        int choice;

        System.out.println("=== Welcome to Simple Banking App ===");

        while (true) {
            System.out.println("\n1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Check Balance");
            System.out.println("5. Transaction History");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    bankSystem.createAccount();
                    break;
                case 2:
                    bankSystem.deposit();
                    break;
                case 3:
                    bankSystem.withdraw();
                    break;
                case 4:
                    bankSystem.checkBalance();
                    break;
                case 5:
                    bankSystem.printTransactionHistory();
                    break;
                case 6:
                    System.out.println("Thank you for using our banking app.");
                    return;
                default:
                    System.out.println("Invalid option!");
            }
        }
    }
}
