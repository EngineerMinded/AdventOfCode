/*************************************************************************
 * Wayne Mack                                                            *
 * Advent of Code Day 10 - Cathode Ray Tube                              *
 * Written in: C#                                                        *
 * --------------------------------------------------------------------- *
 * CPU.cs                                                                *
 *************************************************************************/

using System;
class CPU
{
    char currentCharacter;
    int arrayCounter, arrayLength;
    bool drawNextOne, changeValue;
    char[] data;
    public int getCountAt(int getCountHere, string [] commandList, int arrayLength, bool partOne)
    {
        int currentValue = 1;
        arrayCounter = 0;
        int nextAccumulator =0;
        bool halfPhase = false;
        changeValue = true;
        data = new char[240];
        for (int o = 0; o < 240; o++ ){
            data[o] = '.';
        }
        
        for (int i = 0; i < getCountHere - 1; i++)
        { 
            // PIXEL DETERMINATION GOES HERE///
            int j = i;
            while (j > 40)
            {
                j = j - 40; 
            }
            j++;
            if ((currentValue == j) || (currentValue + 1  == j) || (currentValue + 2 == j ))
            {
                data[i] = '#';
            }
            //Console.WriteLine(currentValue + " " + j + " " + data[i]);
            if (halfPhase)
            {
                currentValue = currentValue + nextAccumulator;
                halfPhase = false;
            }
            else
            {
                if (!commandList[arrayCounter].Contains("noop"))
                {
                    string currentCharacter = commandList[arrayCounter].Split(" ")[1];
                    nextAccumulator = int.Parse(currentCharacter);
                    halfPhase = true;
                }
                else
                {
                    halfPhase = false;
                }
                arrayCounter++;
                if (arrayCounter >= arrayLength)
                {
                    arrayCounter = 0;
                }
            }
        }
        if (partOne)
        {
            Console.WriteLine(getCountHere + " x " + currentValue + " = " + getCountHere * currentValue);
            return getCountHere * currentValue;
        }
        else
        {
            return currentValue;
        }
    }
    public char[] getData(int getCountHere, string[] commandList, int arrayLength, bool partOne)
    {
        int m = getCountAt(getCountHere, commandList, arrayLength, partOne);
        return data;
    }
};

