using System;
class CPU
{

    public int getCountAt(int getCountHere, string [] commandList, int arrayLength, bool partOne)
    {
        int currentValue = 1, arrayCounter = 0, nextAccumulator =0;
        bool halfPhase = false;

        for (int i = 0; i < getCountHere - 1; i++)
        {

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
};

