/*******************************************
 * Wayne Mack                              *
 * Advent of Code 2022 - Day 2             *
 * Written in: C#                          *
 * Main Program                            *
 *******************************************/

using System;
namespace Day2_AOC_2022
{
    class Program
    {
        static RockPaperScissors rockPaperScissors;
        static void Main(string[] args)
        {
            rockPaperScissors = new RockPaperScissors();
            foreach (string line in System.IO.File.ReadAllLines("/Users/waynemack/Projects/Day2-AOC_2022/Day2-AOC_2022/Day2Data.txt"))
            {
                SELECTION getSelection(string item)
                {
                    switch (item)
                    {
                        case "A":
                            return SELECTION.A;
                        case "B":
                            return SELECTION.B;
                        case "C":
                            return SELECTION.C;
                        case "X":
                            return SELECTION.X;
                        case "Y":
                            return SELECTION.Y;
                        default:
                            return SELECTION.Z;
                    }
                }
                String [] readLine  = line.Split(" ");
                rockPaperScissors.add(getSelection(readLine[1]), getSelection(readLine[0]));
            }
            rockPaperScissors.printData();
            // Part 1 Answer:
            Console.WriteLine("The total of all games is :" + rockPaperScissors.getTotal());
            // Part 2 Answer;
            Console.WriteLine("The total number by the second set of rules is : " + rockPaperScissors.root.secondPredeterminiteValue());
        }
    }
}