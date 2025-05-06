import java.util.Scanner;

public class ToDoListApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TaskManager manager = new TaskManager();
        int choice;

        do {
            System.out.println("\n=== To-Do List Menu ===");
            System.out.println("1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Mark Task as Completed");
            System.out.println("4. Update Task");
            System.out.println("5. Delete Task");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            while (!scanner.hasNextInt()) {
                System.out.print("Please enter a valid number: ");
                scanner.next();
            }
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter task description: ");
                    String desc = scanner.nextLine();
                    manager.addTask(desc);
                    break;
                case 2:
                    manager.viewTasks();
                    break;
                case 3:
                    System.out.print("Enter task ID to mark as completed: ");
                    int completeId = scanner.nextInt();
                    manager.markTaskAsCompleted(completeId);
                    break;
                case 4:
                    System.out.print("Enter task ID to update: ");
                    int updateId = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    System.out.print("Enter new description: ");
                    String newDesc = scanner.nextLine();
                    manager.updateTask(updateId, newDesc);
                    break;
                case 5:
                    System.out.print("Enter task ID to delete: ");
                    int deleteId = scanner.nextInt();
                    manager.deleteTask(deleteId);
                    break;
                case 6:
                    System.out.println("Exiting application. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 6);

        scanner.close();
    }
}