/***************************************
 * Wayne Mack                          *
 * Advent Of Code - Day 9              *
 * ----------------------------------- *
 * Written in: Java                    *
 * Only part one successful            *
 ***************************************/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    static Rope rope;
    static String Path = "/Users/waynemack/Desktop/untitled folder/Day 9 - Rope Bridge/src/Day9Data.txt";
    public static void main (String [] args) {
        //////////////////////////////// PART ONE ///////////////////////////////////////////////////////
        calculateAtNumber(2);
        calculateAtNumber(10);

    }
    private static void calculateAtNumber (int numberOfTrailingKnots) {
        rope = new Rope(numberOfTrailingKnots);
        try {
            File myObj = new File(Path);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String [] instruction = (myReader.nextLine().split(" "));
                Direction direction;
                switch (instruction[0]) {
                    case "U": {
                        direction = Direction.UP;
                        break;
                    }
                    case "D": {
                        direction = Direction.DOWN;
                        break;
                    }
                    case "L": {
                        direction = Direction.LEFT;
                        break;
                    }
                    default : {
                        direction = Direction.RIGHT;
                        break;
                    }
                }

                rope.move(direction, Integer.parseInt(instruction[1]));
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        System.out.println("The total number of trails taken are: " + rope.getAllTally());
    }
}
