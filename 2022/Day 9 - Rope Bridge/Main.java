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
        rope = new Rope();
        try {
            File myObj = new File(Path);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                rope.Move(myReader.nextLine());
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        System.out.println("The number of times the head and tail intersected is :"  + (rope.intersecting));
        System.out.println("The number of times with a chain is counted as :" + (rope.chainIntersecting));

    }
}
