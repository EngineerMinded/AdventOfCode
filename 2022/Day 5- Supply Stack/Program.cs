/* Wayne Mack
 * Advent of Code 2022 - Day 5
 * Written in C#
 * 
 */

using System;
using System.IO;

class Program
{
    static Container commands, pile;
    static Platform deck;
    static void Main(string[] args )
    {
        void generatePlatform ()
        {
            commands = new Container();
            pile = new Container();
            // READ FROM FILE A PLACE DATA INTO STACKS
            foreach (string line in File.ReadAllLines("C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 5 - Supply Stacks\\Day 5 - Supply Stacks\\Day5Data.txt"))
            {
                if (line.Contains("["))
                {
                    pile.push(line);
                }
                else if (line.Contains("move"))
                {
                    commands.push(line);
                }
            }
            pile.display();
            Console.WriteLine("There are {0} piles!", pile.getPileSize());
            //commands.display();
            // PARSE PILE DATA INT PLATFORMS
            deck = new Platform(pile.getPileSize());
            while (!(pile.isEmpty))
            {
                bool isCharacter(char test)
                {
                    return (test != ' ');
                }
                int startPoint = 1, address = 1;
                char[] rawData = pile.pop().ToCharArray();
                while (startPoint < rawData.Length)
                {
                    if (isCharacter(rawData[startPoint]))
                    {
                        deck.to(address, rawData[startPoint].ToString());
                    }
                    startPoint = startPoint + 4; address = address + 1;
                }
            }
        }
        generatePlatform();
        // PARSE COMMANDS AND FOLLOW THROUGH ACCORDINGLY
        bool reachedEnd = false;
        while (!(reachedEnd))
        {
            string []currentLine = commands.record().Split(" ");
            if (currentLine.Length > 5)
            {
                for (int e = 0; e < currentLine.Length; e++)
                {
                    Console.Write(currentLine[e] + " ");
                }
                for (int i = 0; i < int.Parse(currentLine[1]); i++)
                {
                    
                    string nextobject = deck.from(int.Parse(currentLine[3]));
                    deck.to(int.Parse(currentLine[5]), nextobject);
                }
            }
            else
            {
                reachedEnd = true;
            }
            Console.WriteLine(deck.getPartOneAnswer());
        }
        /////////////////////////////////////////////PART ONE////////////////////////////////////////
        Console.WriteLine("\nResults:");
        Console.Write("The topmost units for Part one are:" + deck.getPartOneAnswer());
        /////////////////////////////////////////////PART TWO////////////////////////////////////////
        Console.WriteLine("\n\n");
        generatePlatform();
        deck.reset();
        reachedEnd = false;
        while (!(reachedEnd))
        {
            string[] currentLine = commands.record().Split(" ");
            if (currentLine.Length > 5)
            {
                for (int e = 0; e < currentLine.Length; e++)
                {
                    Console.Write(currentLine[e] + " ");
                }

                deck.to(int.Parse(currentLine[5]), deck.from(int.Parse(currentLine[3]), int.Parse(currentLine[1])));
            }
            else
            {
                reachedEnd = true;
            }
            Console.WriteLine(deck.getPartOneAnswer());
        }
        Console.WriteLine("\n\nThe topmost units for part two are :" + deck.getPartOneAnswer());
    }
}
