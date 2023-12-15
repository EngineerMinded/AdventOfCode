////////////////////////////////////////////////////////
// Wayne Mack                                         //
// Advent Of Code : --- Day 10: Pipe Maze ---         //
// -------------------------------------------------- //
// Written in C#                                      //
// FIRST STAR ACHIEVED                                //
////////////////////////////////////////////////////////

using Day10;
using System;
using System.Collections.Specialized;
using System.IO;
using System.IO.IsolatedStorage;
using System.IO.Pipes;
using System.Numerics;
using System.Runtime.InteropServices;

class Program
{
    static Trail trail;
    static char[,] map;

    static void Main(string[] args)
    {
        string fileName = "puzzle.data";

        map = getMapData(fileName);
        int startX = 0, startY = 0;
        (int, int) getS = getSLocation(map, true);
        startX = getS.Item1;
        startY = getS.Item2;
        Console.WriteLine("\nPart One : ->" + partOne(startX, startY));
        Console.WriteLine("\nPart Two : ->" + partTwo(map));


        

        

    }

    static char[,] getMapData(string filePath)
    {
        char[,] resultArray = null;

        try
        {
            string[] lines = File.ReadAllLines(filePath);

            int rows = lines.Length;
            int cols = lines[0].Length;

            resultArray = new char[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                if (lines[i].Length != cols)
                {
                    throw new InvalidOperationException("Invalid file format. All rows should have the same number of characters.");
                }

                for (int j = 0; j < cols; j++)
                {
                    resultArray[i, j] = lines[i][j];
                }
            }
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine("File not found.");
        }
        catch (InvalidOperationException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (Exception)
        {
            Console.WriteLine("An error occurred while reading the file.");
        }

        return resultArray;
    }

    static (int, int) getSLocation(char[,] map, bool printMap)
    {
        int x = 0, y = 0;
        for (int i = 0; i < map.GetLength(0); i++)
        {
            for (int j = 0; j < map.GetLength(1); j++)
            {
                if (printMap)
                {
                    Console.Write(map[i, j]);
                }
                if (map[i, j] == 'S')
                {
                    x = i; y = j;
                }
                
            }
            Console.WriteLine();
        }
        return (x, y);
    }

    static int partOne( int x, int y) {
        Trail t1, t2;
        (int, int) startTrail1 = (x, y), startTrail2 = (x, y);
        // find starting points 
        if (x > 0)
        {
            if (map[x - 1, y] == '|'  || map[x - 1, y] == 'F' || map[x - 1, y] == '7')
            {
                if (startTrail1 == (x,y))
                {
                    startTrail1 = (x - 1, y);
                }
                else
                {
                    startTrail2 = (x - 1, y);
                }
            }
        }
        if (x < map.GetLength(0))
        {
            if (map[x + 1, y] == '|' || map[x + 1, y] == 'L' || map[x + 1, y] == 'J')
            {
                if (startTrail1 == (x, y))
                {
                    startTrail1 = (x + 1, y);
                }
                else
                {
                    startTrail2 = (x + 1, y);
                }
            }
        }
        if (y > 0)
        {
            {
                if (map[x, y - 1] == '-' || map[x, y - 1] == 'F' || map[x, y - 1] == 'L')
                {
                    if (startTrail1 == (x, y))
                    {
                        startTrail1 = (x, y - 1);
                    }
                    else
                    {
                        startTrail2 = (x, y - 1);
                    }
                }
            }
        }
        if (y < map.GetLength(1))
        {
            {
                if (map[x, y + 1] == '-' || map[x , y + 1] == 'J' || map[x, y + 1] == '7')
                {
                    if (startTrail1 == (x, y))
                    {
                        startTrail1 = (x, y + 1);
                    }
                    else
                    {
                        startTrail2 = (x, y + 1);
                    }
                }
            }
        }
        t1 = new Trail(x,y);
        t1.add(startTrail1.Item1, startTrail1.Item2);
        t2 = new Trail(x,y);
        t2.add(startTrail2.Item1, startTrail2.Item2);
        do
        {
            Console.WriteLine();
            t1.getNextDirection(map);
            t2.getNextDirection(map);
            //Console.WriteLine(t1.getLastX() + "," + t1.getLastY() + " , " + t2.getLastX() + "," + t2.getLastY());
        } while (!((t1.getLastX() == t2.getLastX()) && (t1.getLastY() == t2.getLastY()))) ;
            t1.printAll();
        Console.WriteLine();
        t2.printAll();

        return t1.getHighestValue();
    }

    static int partTwo(char[,] map)
    {
        for (int x = 0; x < map.GetLength(0); x++)
        {
            for (int y = 0; y < map.GetLength(1); y++)
            {
                if (map[x,y] == '.')
                {
                    map[x, y] = 'I';
                }
            }
        }
        int returnThis = 0;
        map = parsePart2(map);
        printMap(map);
        for (int x = 0; x < map.GetLength(0); x++)
        {
            for (int y = 0; y < map.GetLength(1); y++)
            {
                if (map[x, y] == 'I')
                {
                    returnThis++;
                }
            }
        }
        return returnThis;
    }

    // WORKS FOR THE EXAMPLES BUT NOT FOR THE PRACTICAL //
    static char[,] parsePart2(char[,] map)
    {
        
        for (int x = 0; x < map.GetLength(0); x++)
        {
            char turnInto = 'O';
            for (int y = 0; y < map.GetLength(1); y++)
            {
                if (map[x,y] == 'I')
                {
                    map[x,y] = turnInto;
                }
                if (map[x,y] == '|' )
                {
                    if (turnInto == 'O')
                    {
                        turnInto = 'I';
                    }
                    else
                    {
                        turnInto = 'O';
                    }
                }
            }
            
        }
        for (int y = 0; y < map.GetLength(1); y++)
        {
            char turnInto = 'O';
            for (int x = 0; x < map.GetLength(0); x++)
            {
                if (map[x, y] == 'I')
                {
                    map[x, y] = turnInto;
                }
                if (map[x, y] == '-')
                {
                    if (turnInto == 'O')
                    {
                        turnInto = 'I';
                    }
                    else
                    {
                        turnInto = 'O';
                    }
                }
            }

        }

        return map;
    }


    static void printMap(char[,]map)
    {
        for (int x = 0; x < map.GetLength(0); x++)
        {
            for (int y = 0; y < map.GetLength(1); y++)
            {
                Console.Write(map[x, y]);
            }
            Console.WriteLine();
        }
    }

};
