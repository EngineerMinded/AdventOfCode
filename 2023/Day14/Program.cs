//////////////////////////////////////////////////////////////////
// Wayne Mack                                                   //
// Advent Of Code Day 14                                        //
// --- Day 14: Parabolic Reflector Dish ---                     //
// Written in: C#                                               //
// GOT FIRST STAR RUNNING THIS AND SECOND RUNNING PYTHON SCRIPT //
//////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.IO;
using System.ComponentModel;
using System.Data;
using System.Runtime.ExceptionServices;
using System.Xml.Schema;

class Program
{
    static Platform platform;

    static void Main()
    {
        platform = new Platform();

        string filePath = "puzzle.data.txt"; // Replace this with the path to your file

        try
        {
            string[] lines = File.ReadAllLines(filePath);

            List<string[]> arrays = new List<string[]>();
            List<string> currentArray = new List<string>();

            foreach (string line in lines)
            {
                if (string.IsNullOrWhiteSpace(line))
                {
                    if (currentArray.Count > 0)
                    {
                        arrays.Add(currentArray.ToArray());
                        currentArray.Clear();
                    }
                }
                else
                {
                    currentArray.Add(line);
                }
            }

            if (currentArray.Count > 0)
            {
                arrays.Add(currentArray.ToArray());
            }

            foreach (var array in arrays)
            {
                platform.Add(array);
                platform.print();
                Console.WriteLine("");
                platform.tiltNorth();
                platform.print();
                // ANSWER TO PART ONE
                Console.WriteLine("Part One -> " + platform.calculateLoad());
                platform.Add(array);
                int numberOfCycles = 1000000000;
                for (int x = 0; x < numberOfCycles; x++)
                {
                    platform.tiltWest();
                    platform.tiltSouth();
                    platform.tiltEast();
                    //platform.print();
                    Console.WriteLine();
                    if (x < numberOfCycles - 1)
                    {
                        Console.WriteLine ("              cycle: " + x + " value -> " + platform.calculateLoad());
                        platform.tiltNorth();
                    }
                    
                }
                Console.WriteLine ("Part Two -> " + platform.calculateLoad());
            }
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine("File not found.");
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }

    }
}
class Platform
{
    private char[,] Map;
    private Platform Next;



    public Platform()
    {
        Next = null; 
    }

    public void Add( string[] here)
    {
        if (Map == null)
        {
            Map = new char[here.Length, here[0].Length];
            for (int x = 0; x < here.Length; x++)
            {
                char[] line = here[x].ToCharArray();
                for (int y = 0; y < here[0].Length; y++)
                {
                    Map[x, y] = line[y];
                }
            }
            Next = new Platform();
        }
        else
        {
            Next.Add(here);
        }

    }

    public void tiltNorth()
    {
       for (int x = 0; x < Map.GetLength(0); x++)
        {
            for (int y = 0; y < Map.GetLength(1); y++)
            {
                if ((x > 0) && (Map[x,y] == 'O'))
                {
                    int xx = x;
                    while ((xx > 0) && (Map[xx - 1,y] == '.')) {
                        Map[xx, y] = '.';
                        Map[xx - 1, y] = 'O';
                        xx = xx - 1;

                    }
                }
            }
        }
    }

    public void tiltWest()
    {
        for (int x = 0; x < Map.GetLength(0); x++)
        {
            for (int y = 0; y < Map.GetLength(1); y++)
            {
                if ((y > 0) && (Map[x, y] == 'O'))
                {
                    int yy = y;
                    while ((yy > 0) && (Map[x, yy - 1] == '.'))
                    {
                        Map[x, yy] = '.';
                        Map[x, yy - 1] = 'O';
                        yy = yy - 1;

                    }
                }
            }
        }
    }
    public void tiltSouth()
    {
        for (int x = Map.GetLength(0) - 1; x >=0; x--)
        {
            for (int y = 0; y < Map.GetLength(1); y++)
            {
                if ((x < Map.GetLength(0) - 1) && (Map[x, y] == 'O'))
                {
                    int xx = x;
                    while ((xx < Map.GetLength(0) -1 && (Map[xx + 1, y] == '.')))
                    {
                        Map[xx, y] = '.';
                        Map[xx + 1, y] = 'O';
                        xx = xx + 1;

                    }
                }
            }
        }
    }

    public void tiltEast()
    {
        for (int x = 0; x < Map.GetLength(0); x++)
        {
            for (int y = Map.GetLength(1) - 1; y>=0; y--)
            {
                if ((y < Map.GetLength(1) - 1) && (Map[x, y] == 'O'))
                {
                    int yy = y;
                    while ((yy < Map.GetLength(1) - 1) && (Map[x, yy + 1] == '.'))
                    {
                        Map[x, yy] = '.';
                        Map[x, yy + 1] = 'O';
                        yy = yy + 1;

                    }
                }
            }
        }
    }


    public long calculateLoad()
    {
        long returnThis = 0;
        for (int x = 0; x < Map.GetLength(0); x++)
        {
            for (int y = 0; y < Map.GetLength(1); y++)
            {
                int multiplier = Map.GetLength(0) - x;
                if (Map[x,y] == 'O')
                {
                    returnThis = returnThis + multiplier;
                }
            }
        }
        return returnThis;
    }

    public void print()
    {
        for(int i = 0; i < Map.GetLength(0); i++)
        {
            for (int j=0; j < Map.GetLength(1); j++)
            {
                Console.Write(Map[i,j]);
            }
            Console.WriteLine();
        }
    } 
}

class Cycle
{
  
}