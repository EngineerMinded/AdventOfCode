/*************************************************************************
 * Wayne Mack                                                            *
 * Advent of Code Day 10 - Cathode Ray Tube                              *
 * Written in: C#                                                        *
 * --------------------------------------------------------------------- *
 * Program.cs                                                            *
 *************************************************************************/

class Program
{
    static void Main (string[] args)
    {
        CPU cpu = new CPU();
        string command;
        int countForArray = 0;
        string fileName = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 10 - Cathode Ray Tube\\Day 10 - Cathode Ray Tube\\Day10Data.txt";

        string [] commandList = new string[150];
        // Read from the text file
        foreach (string line in File.ReadLines(fileName))
        {
            commandList[countForArray] = line;
            countForArray++;
        }
        ///////////////////////////////////////////////////PART ONE //////////////////////////////////////////////////////////////////
        int total = 0; 
       
        total = total + (cpu.getCountAt(20, commandList, countForArray, true));
        total = total + (cpu.getCountAt(60, commandList, countForArray, true));
        total = total + (cpu.getCountAt(100, commandList, countForArray, true));
        total = total + (cpu.getCountAt(140, commandList, countForArray, true));
        total = total + (cpu.getCountAt(180, commandList, countForArray, true));
        total = total + (cpu.getCountAt(220, commandList, countForArray, true));

        Console.WriteLine("The sum of Part One is : " + total);
        ///////////////////////////////////////////////////PART TWO///////////////////////////////////////////////////////////////////
        char[] image = cpu.getData(240, commandList, countForArray, false);
        Console.WriteLine();
        for (int x = 0; x < 40; x++) 
        {
            Console.Write(image[x]);
        }
        Console.WriteLine();
        for (int x = 40; x < 80; x++)
        {
            Console.Write(image[x]);
        }
        Console.WriteLine(); 
        for (int x = 80; x < 120; x++)
        {
            Console.Write(image[x]);
        }
        Console.WriteLine(); 
        for (int x = 120; x < 160; x++)
        {
            Console.Write(image[x]);
        }
        Console.WriteLine(); 
        for (int x = 160; x < 200; x++)
        {
            Console.Write(image[x]);
        }
        Console.WriteLine(); 
        for (int x = 200; x < 240; x++)
        {
            Console.Write(image[x]);
        }
        Console.WriteLine();
    }
}
