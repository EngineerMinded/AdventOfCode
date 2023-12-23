////////////////////////////////////////////////////
// Wayne Mack                                     //
// Advent Of Code                                 //
//    --- Day 16: The Floor Will Be Lava ---      //
// Written in C#:                                 //
////////////////////////////////////////////////////
///

using System;
using System.ComponentModel.DataAnnotations;
using System.IO;
using System.Runtime.InteropServices;


enum direction {UP, DOWN, LEFT, RIGHT};
class Program
{
    static void Main()
    {
        // Specify the file path
        string filePath = "puzzle.data";

        char[,] map = getMap(filePath);
        int numRows = map.GetLength(0);
        int maxCols = map.GetLength(1);

        // PART ONE

        Display(map);

        //trail = makeTrails(direction.RIGHT, 0, 0, map, cleanTrail(numRows,maxCols));
        Display(map);
        char[,] trail = makeTrails(direction.RIGHT, 0, 0, map, cleanTrail(numRows, maxCols));
        Display(trail);
        Console.WriteLine("Part One : " + trail);

        // PART TWO (OH BOY!)

        int highestTrail = 0;

        for (int y = 0; y < maxCols; y++)
        {
                map = getMap(filePath);
                int currentCount = count('#', makeTrails(direction.DOWN, 0, y, map, cleanTrail(numRows, maxCols)));
                Console.WriteLine(y + " -> " + currentCount);
                if (highestTrail < currentCount)
                {
                    highestTrail = currentCount;
                }
                map = getMap(filePath);
                currentCount = count('#', makeTrails(direction.UP, map.GetLength(0) -1, y, map, cleanTrail(numRows, maxCols)));
                Console.WriteLine(y + " -> " + currentCount);
                if (highestTrail < currentCount)
                {
                    highestTrail = currentCount;
                }

            }
            for (int x = 0; x < numRows; x++)
            {
                map = getMap(filePath);
                int currentCount = count('#', makeTrails(direction.RIGHT, x, 0, map, cleanTrail(numRows, maxCols)));
                Console.WriteLine(x + " " + currentCount);
                if (highestTrail < currentCount )
                {
                    highestTrail = currentCount;
                }
                map = getMap(filePath);
                currentCount = count('#', makeTrails(direction.LEFT, x, map.GetLength(1) - 1, map, cleanTrail(numRows, maxCols)));
                Console.WriteLine(x + " " + currentCount);
                if (highestTrail < currentCount )
                {
                    highestTrail = currentCount;
                }

            }
            Console.WriteLine( "Part Two : " + highestTrail );

    }

    static void Display(char[,] here)
    {
        for (int i = 0; i < here.GetLength(0); i++)
        {
            for (int j = 0; j < here.GetLength(1); j++)
            {
                Console.Write(here[i, j] + " ");
            }
            Console.WriteLine();
        }
    }
    static char[,] makeTrails(direction d, int x, int y, char[,] map, char[,] trail)
    {
        while (x >= 0 && x < map.GetLength(0) && y >= 0 && y < map.GetLength(1))
        {
            //Console.Clear();
            trail[x, y] = '#';
            //Display(map);
            //Console.WriteLine();
            //Display(trail);
            //Console.WriteLine(x + " " + y);
            // determine what to do based on the character it landed on
            switch (map[x, y])
            {
                case '/':
                    {
                        if (d == direction.RIGHT)
                        {
                            d = direction.UP; x = x - 1;
                        }
                        else if (d == direction.LEFT)
                        {
                            d = direction.DOWN; x = x + 1;
                        }
                        else if (d == direction.DOWN)
                        {
                            d = direction.LEFT; y = y - 1;
                        }
                        else if (d == direction.UP)
                        {
                            d = direction.RIGHT; y = y + 1;

                        }
                        break;
                    }
                case '\\':
                    {
                        if (d == direction.LEFT)
                        {
                            x = x - 1; d = direction.UP;

                        }
                        else if (d == direction.RIGHT)
                        {
                            x = x + 1; d = direction.DOWN;
                        }
                        else if (d == direction.UP)
                        {
                            y = y - 1; d = direction.LEFT;
                        }
                        else if (d == direction.DOWN)
                        {
                            y = y + 1; d = direction.RIGHT;
                        }
                        break;
                    }
                case '-':
                    {
                        if (d == direction.LEFT)
                        {
                            y = y - 1;
                        }
                        else if (d == direction.RIGHT)
                        {
                            y = y + 1;
                        }
                        else if (d == direction.UP || d == direction.DOWN)
                        {
                            if (y > 0 && (map[x, y - 1] != '<' && map[x, y - 1] != '2'))
                            {
                                trail = makeTrails(direction.LEFT, x, y - 1, map, trail);
                            }
                            if (y < map.GetLength(1) - 1 && (map[x, y + 1] != '>' && map[x, y + 1] != '2'))
                            {
                                trail = makeTrails(direction.RIGHT, x, y + 1, map, trail);
                            }
                            return trail;
                        }

                        break;
                    }
                case '|':
                    {
                        if (d == direction.UP)
                        {
                            x = x - 1;
                        }
                        else if (d == direction.DOWN)
                        {
                            x = x + 1;
                        }
                        else if (d == direction.LEFT || d == direction.RIGHT)
                        {
                            if (x < map.GetLength(0) - 1 && (map[x + 1, y] != 'v' && map[x + 1, y] != '2'))
                            {

                                trail = makeTrails(direction.DOWN, x + 1, y, map, trail);
                            }
                            if (x > 0 && (map[x - 1, y] != '^' && map[x - 1, y] != '2'))
                            {
                                trail = makeTrails(direction.UP, x - 1, y, map, trail);
                            }
                            return trail;
                        }
                        break;
                    }
                default:
                    {
                        if (d == direction.UP)
                        {
                            if (looping(d, map[x,y])) { return trail; }
                            if (map[x,y] == '<' || map[x,y] == '>')
                            {
                                map[x, y] = '2';
                            }
                            else
                            {
                                map[x, y] = '^';
                            }
                            
                            x = x - 1;

                        }
                        else if (d == direction.DOWN)
                        {
                            if (looping(d, map[x, y])) { return trail; }
                            if (map[x, y] == '<' || map[x, y] == '>')
                            {
                                map[x, y] = '2';
                            }
                            else
                            {
                                map[x, y] = 'v';
                            }
                            x = x + 1;
                        }
                        else if (d == direction.LEFT)
                        {
                            if (looping(d, map[x, y])) { return trail; }
                            if (map[x, y] == '^' || map[x, y] == 'v')
                            {
                                map[x, y] = '2';
                            }
                            else
                            {
                                map[x, y] = '<';
                            }
                            y = y - 1;
                        }
                        else if (d == direction.RIGHT)
                        {
                            if (looping(d, map[x, y])) { return trail; }
                            if (map[x, y] == '^' || map[x, y] == 'v')
                            {
                                map[x, y] = '2';
                            }
                            else
                            {
                                map[x, y] = '>';
                            }
                            y = y + 1;
                        }
                        break;
                    }
            }
        }
        return trail;
    }

    static int count(char here, char[,] countHere)
    {
        int count = 0;
        for (int i = 0; i < countHere.GetLength(0); i++)
        {
            for (int j = 0; j < countHere.GetLength(1); j++)
            {
                if (countHere[i, j] == here) { count++; }
            }
        }
        return count;
    }

    static bool looping(direction direction, char item)
    {
        if (direction == direction.LEFT) { return item == '<'; }
        else if (direction == direction.RIGHT) { return item == '>'; }
        else if (direction == direction.UP) { return item == '^'; }
        else if (direction == direction.DOWN) { return item == 'v'; }
        else { return item == 2; }
    }

    static char[,] cleanTrail (int x,int y)
    {
        char[,] returnThis = new char[x,y];
        for (int i = 0; i < returnThis.GetLength(0); i++)
        {
            for (int j = 0;j < returnThis.GetLength(1);j++)
            {
                returnThis[i, j] = '.';
            }
        }
        return returnThis;

    }

    static char[,] getMap(string fileName)
    {

        try
        {
            string[] lines = File.ReadAllLines(fileName);
            int numRows = lines.Length;
            int maxCols = lines[0].Length;
            char[,] map = new char[numRows, maxCols];


            for (int i = 0; i < numRows; i++)
            {
                string line = lines[i];

                for (int j = 0; j < maxCols; j++)
                {
                    if (j < line.Length)
                    {
                        map[i, j] = line[j];
                    }
                    else
                    {
                        map[i, j] = ' ';
                    }
                }
            }
            return map;
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine("File not found. Please provide a valid file path.");
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }
        return new char[10, 10];
    }
}
