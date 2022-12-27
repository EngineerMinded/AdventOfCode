/********************************************
 * Wayne Mack                               *
 * Advent Of Code - Day 11                  *
 * ---------------------------------------- *
 * Written in : C#                          *
 * Hint for Part 2 was found on Reddit      *
 * Program.cs                               *
 ********************************************/
using System;
using System.IO;
using System.Numerics;

namespace Day_11_Monkey_In_the_Middle
{
    class Program
    {
        static string Path = "Day11Data.txt";
        static void Main(string[] args)
        {
            int arrayLength = File.ReadAllText(Path).Split("\n\n").Length;
            Monkey[] MonkeyGroup = new Monkey[arrayLength];
            int monkeyCounter = 0;
            foreach (string line in File.ReadAllText(Path).Split("\n\n")){
                MonkeyGroup[monkeyCounter] = new Monkey(line.Split("\n"));
                monkeyCounter++;
            }
            BigInteger commonModulo;
            void inspectionCycle(bool Part2)
            {
                foreach (Monkey monkey in MonkeyGroup)
                {
                    monkey.numberOfInspectionsCarriedOut = monkey.numberOfInspectionsCarriedOut + monkey.itemList.Count;
                    foreach(BigInteger number in monkey.itemList)
                    {
                        BigInteger m, n = number;
                        if (monkey.operationNumberIsOld)
                        {
                            m = n;
                        }
                        else
                        {
                            m = monkey.operationNumber;
                        }
                        if (monkey.operationIsAddition)
                        {
                            n = n + m;
                        }
                        else
                        {
                            n = n * m;
                        }
                        if (!Part2)
                        {
                            n = n / 3;
                        }
                        else
                        {
                            n = n % commonModulo;
                        }
                        if (n % monkey.divideTestNumber == 0)
                        {
                            MonkeyGroup[monkey.trueThrowTo].itemList.AddLast(n);
                        }
                        else
                        {
                            MonkeyGroup[monkey.falseThrowTo].itemList.AddLast(n);
                        }
                    }
                    monkey.itemList.Clear();
                }
            }
            void getAnswerAtRound (int roundNumber, bool Part2)
            { 
                for (int i = 0; i < roundNumber; i++)
                {
                    Console.WriteLine("\nCycle : " + i);
                    inspectionCycle(Part2);
                    monkeyCounter = 0;
                    foreach (Monkey m in MonkeyGroup)
                    {
                        Console.Write("\nMonkey " + monkeyCounter + " : ");
                        if (!Part2)
                        {
                            m.displayItemList();
                        }
                        else
                        {
                            m.displayItemList();
                            m.displayNumberOfInspections();
                        }
                        monkeyCounter++;
                    }
                    Console.WriteLine();
                }
                long firstNumber = 0, secondNumber = 0;
                foreach (Monkey m in MonkeyGroup)
                {
                    if (m.numberOfInspectionsCarriedOut > firstNumber || m.numberOfInspectionsCarriedOut > secondNumber)
                    {
                        if (firstNumber > secondNumber)
                        {
                            secondNumber = m.numberOfInspectionsCarriedOut;
                        }
                        else
                        {
                            firstNumber = m.numberOfInspectionsCarriedOut;
                        }
                    }
                }
                Console.WriteLine("The total for part One is: " + firstNumber + " * " + secondNumber + " = " + firstNumber * secondNumber);
            }
            BigInteger getCommomModulo ()
            {
                BigInteger answer = 1;
                foreach (Monkey m in MonkeyGroup)
                {
                    answer = answer * m.divideTestNumber;
                }
                return answer;
            }
            commonModulo = getCommomModulo();
            // For Part one: Change 10000 to 20 and true to false
            getAnswerAtRound(10000,true);
        }
    }
}
