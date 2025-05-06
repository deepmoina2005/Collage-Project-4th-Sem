import java.io.Serializable;

public class Task implements Serializable {
    private static final long serialVersionUID = 1L;
    private static int idCounter = 1;

    private int id;
    private String description;
    private boolean isCompleted;

    public Task(String description) {
        this.id = idCounter++;
        this.description = description;
        this.isCompleted = false;
    }

    public int getId() {
        return id;
    }

    public String getDescription() {
        return description;
    }

    public boolean isCompleted() {
        return isCompleted;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void markAsCompleted() {
        this.isCompleted = true;
    }

    @Override
    public String toString() {
        return "[" + (isCompleted ? "X" : " ") + "] Task ID: " + id + " - " + description;
    }
}