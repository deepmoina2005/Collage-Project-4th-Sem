import java.io.*;
import java.util.Scanner;

public class DataManager {
    private final String FILE_NAME = "notes.txt";

    public void saveNote(Scanner scanner) {
        System.out.print("Enter your note: ");
        String note = scanner.nextLine();

        try (FileWriter fw = new FileWriter(FILE_NAME, true)) {
            fw.write(note + "\n");
            System.out.println("Note saved.");
        } catch (IOException e) {
            System.out.println("Error saving note.");
        }
    }

    public void showNotes() {
        System.out.println("Your saved notes:");
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println("- " + line);
            }
        } catch (IOException e) {
            System.out.println("No notes found.");
        }
    }
}