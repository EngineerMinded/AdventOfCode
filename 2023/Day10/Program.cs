﻿////////////////////////////////////////////////////////
// Wayne Mack                                         //
// Advent Of Code : --- Day 10: Pipe Maze ---         //
// -------------------------------------------------- //
// Written in C#                                      //
// FIRST STAR ACHIEVED                                //
////////////////////////////////////////////////////////

using Day10;
using System.Collections.Specialized;

class Program
{
    static Trail trail;
    static char[,] map;
    static Trail t1, t2;

    static void Main(string[] args)
    {
        string fileName = "puzzle.data";

        map = getMapData(fileName);
        int startX = 0, startY = 0;
        (int, int) getS = getSLocation(map, true);
        startX = getS.Item1;
        startY = getS.Item2;
        Console.WriteLine("\nPart One : ->" + partOne(startX, startY));
        Console.WriteLine("\nPart Two : ->" + partTwo(map, t1, t2));

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
        }
        return (x, y);
    }

    static int partOne( int x, int y) {
        //Trail t1, t2;
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
            //Console.WriteLine();
            t1.getNextDirection(map);
            t2.getNextDirection(map);
        } while (!((t1.getLastX() == t2.getLastX()) && (t1.getLastY() == t2.getLastY()))) ;
        //t1.printAll();
        //Console.WriteLine();
        //t2.printAll();

        return t1.getHighestValue();
    }

    static int partTwo(char[,] map, Trail t1, Trail t2)
    {
        int returnThis = 0;
        char lastCharacter = '?';
        for (int x = 0; x < map.GetLength(0); x++)
        {
            bool outside = true;
            for (int y = 0; y < map.GetLength(1); y++)
            {
                if (t1.exists(x,y) || t2.exists(x,y))
                {
                    switch (map[x,y])
                    {
                        case '|': { outside = !outside; break; }
                        case 'F': { lastCharacter = map[x,y]; break; }
                        case 'L': { lastCharacter= map[x,y]; break; }
                        case '-': { /*NOTHING*/ break; }
                        case '7': { if (lastCharacter == 'L') { outside = !outside; } break; }
                        case 'J': { if (lastCharacter == 'F') { outside = !outside; } break; }
                        default: { if (outside) { map[x, y] = 'O'; } else { map[x, y] = 'I'; returnThis++; } break; }
                    }
                }
                else
                {
                    if (outside) { map[x, y] = 'O'; } else { map[x, y] = 'I'; returnThis++; }
                }
            }
        }
        printMap(map);
        return returnThis;
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
