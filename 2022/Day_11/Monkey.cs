/*********************************************
 * Wayne Mack                                *
 * Advent Of Code - Day 11                   *
 * ------------------------------------------*
 * Written in C#                             *
 * ONLY FIRST PART COMPLETED!!               *
 * Numbers become too big. Must find a way   *
 * reduce it.                                *
 *********************************************/


﻿using System;
using System.Collections.Generic;
using System.Numerics;

namespace Day_11_Monkey_In_the_Middle
{
    public class Monkey
    {
        public LinkedList<BigInteger> itemList, acquired;
        public bool operationIsAddition, operationNumberIsOld;
        public BigInteger operationNumber;
        public BigInteger divideTestNumber;
        public int trueThrowTo, falseThrowTo;

        public int numberOfInspectionsCarriedOut;

        public Monkey(string[] attributes)
        {
            numberOfInspectionsCarriedOut = 0;
            itemList = new LinkedList<BigInteger>();
            // PARSE FIRST LINE
            foreach (string fg in attributes[1].Substring(18).Split(", "))
            {
                itemList.AddLast(BigInteger.Parse(fg));
            }
            // PARSE SECOND LINE
            operationIsAddition = (attributes[2].Contains("+"));
            if ((attributes[2].Split(" ")[7]) == "old")
            {
                operationNumberIsOld = true; operationNumber = 0;
            }
            else
            {
                operationNumberIsOld = false;
                operationNumber = BigInteger.Parse(attributes[2].Split(" ")[7]);
            }
            // PARSE THIRD LINE
            divideTestNumber = BigInteger.Parse(attributes[3].Split(" ")[5]);
            // PARSE FOURTH LINE
            trueThrowTo = int.Parse(attributes[4].Split(" ")[9]);
            // PARSE FIFTH LINE
            falseThrowTo = int.Parse(attributes[5].Split(" ")[9]);

            displayContents();

        }

        private void displayContents ()
        {
            displayItemList();
            Console.Write("\nOperation: ");
            if (operationIsAddition)
            {
                Console.Write("old + ");
            }
            else
            {
                Console.Write("old * ");
            }
            if (operationNumberIsOld)
            {
                Console.WriteLine("old");
            }
            else
            {
                Console.WriteLine(operationNumber);
            }
            Console.WriteLine("Test: divide by: " + divideTestNumber);
            Console.WriteLine("if true, go to: " + trueThrowTo);
            Console.WriteLine("if false, go to: " + falseThrowTo + "\n");
        }
        public void displayNumberOfInspections()
        {
            Console.WriteLine("-> " + numberOfInspectionsCarriedOut);
        }
        public void displayItemList()
        {
            Console.Write("Item list : ");
            foreach (BigInteger i in itemList)
            {
                //Console.Write(i + " ");
            }
        }

    }
}
