import java.util.ArrayList;
import java.util.List;

public class TaskManager {
    private List<Task> tasks = new ArrayList<>();

    public void addTask(String description) {
        Task task = new Task(description);
        tasks.add(task);
        System.out.println("Task added successfully.");
    }

    public void viewTasks() {
        if (tasks.isEmpty()) {
            System.out.println("No tasks available.");
            return;
        }
        for (Task task : tasks) {
            System.out.println(task);
        }
    }

    public void markTaskAsCompleted(int id) {
        Task task = findTaskById(id);
        if (task != null) {
            task.markAsCompleted();
            System.out.println("Task marked as completed.");
        } else {
            System.out.println("Task not found.");
        }
    }

    public void updateTask(int id, String newDescription) {
        Task task = findTaskById(id);
        if (task != null) {
            task.setDescription(newDescription);
            System.out.println("Task updated successfully.");
        } else {
            System.out.println("Task not found.");
        }
    }

    public void deleteTask(int id) {
        Task task = findTaskById(id);
        if (task != null) {
            tasks.remove(task);
            System.out.println("Task deleted successfully.");
        } else {
            System.out.println("Task not found.");
        }
    }

    private Task findTaskById(int id) {
        for (Task task : tasks) {
            if (task.getId() == id) {
                return task;
            }
        }
        return null;
    }
}