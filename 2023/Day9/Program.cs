////////////////////////////////////////////////////////////
// Wayne Mack                                             //
// Advent Of Code : Day 9                                 //
// ------------------------------------------------------ //
// Written in: C#                                         //
// FIRST STAR ACHIEVED : YEA C SHARP                      // 
////////////////////////////////////////////////////////////


using System;
using System.IO;
using System.Security.Cryptography.X509Certificates;

class Oasis
{
    public int sequence(string value, bool isPartOne)
    {
        string[] splitValue = value.Split(' ');
        int []values = new int[splitValue.Length];
        for (int g = 0; g < splitValue.Length; g++)
        {
            values[g] = int.Parse(splitValue[g]);
        }
        print(values);
        int answer = sequence(values, isPartOne);
        Console.WriteLine("Answer: " + answer);
        return answer;
    }

    public int sequence(int[] newValues , bool isPartOne)
    {   
        if (allEqual(newValues))
        {
            return newValues[0];
        }
        else
        {
            int [] nextValues = new int[newValues.Length - 1];
            for (int g = 0; g < newValues.Length - 1; g++)
            {
                nextValues[g] = newValues[g + 1] - newValues[g];
            }
            print (nextValues);
            if (isPartOne)
            {
                return sequence(nextValues, isPartOne) + newValues[newValues.Length - 1];
            }
            else
            {
                return newValues[0]  - sequence(nextValues, isPartOne);
            }
             
        }
    }
    bool allEqual(int[] list)
    {
        int compare = list[0];
        foreach (int value in list)
        {
            if (value != compare) { 
            return false;
            }
        }
        return true;
    }

    void print(int[] printMe)
    {
        for (int i = 0; i < printMe.Length; i++)
        {
            Console.Write(printMe[i] + " ");
        }
        Console.WriteLine("\n");
    }
};

class Program
{
    static void Main(string[] args)
    {


        try
        {
            string filePath = "puzzle.data";

            if (File.Exists(filePath))
            {
                string fileContents = File.ReadAllText(filePath);
                int total = 0;
                int secondTotal = 0;
                foreach (string line in fileContents.Split("\n"))
                {
                    total = total + new Oasis().sequence(line, true);
                    secondTotal = secondTotal + new Oasis().sequence(line, false);
                }
                Console.WriteLine("The total for part one is: " + total + " .\n");
                Console.WriteLine("The total for part two is: " + secondTotal + " .\n");
            }
            else
            {
                Console.WriteLine("File does not exist.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }
    }

}
