import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Jarvis bot = new Jarvis();
        bot.greetUser();

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("> ");
            String input = scanner.nextLine();
            bot.handleInput(input);
        }
    }
}