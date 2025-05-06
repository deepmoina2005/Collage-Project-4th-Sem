import java.util.Date;

public class Expense {
    private String category;
    private double amount;
    private String description;
    private Date date;

    // Constructor
    public Expense(String category, double amount, String description) {
        this.category = category;
        this.amount = amount;
        this.description = description;
        this.date = new Date();  // Sets current date
    }

    // Getters
    public String getCategory() {
        return category;
    }

    public double getAmount() {
        return amount;
    }

    public String getDescription() {
        return description;
    }

    public Date getDate() {
        return date;
    }

    @Override
    public String toString() {
        return "Date: " + date.toString() + " | Category: " + category + " | Amount: " + amount + " | Description: " + description;
    }
}