import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class Main {
    static Deck deck;
    public static void main(String[] args) {
        // Check if a file path is provided as a command-line argument
        if (args.length != 1) {

            String filePath = "part1.data";

            try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
                String line;
                while ((line = br.readLine()) != null) {
                    Cards nextHand = new Cards(line);
                    if (deck == null) {
                        deck = new Deck(nextHand);
                    }
                    else {
                        deck.rank(nextHand);
                    }
                }
                deck.printAll();
                System.out.println("The Answer for part One is: " + deck.partOneAnswer());
            } catch (IOException e) {
                System.err.println("Error reading file: " + e.getMessage());
            }
        }
    }
}
