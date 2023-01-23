/****************************************
 * Wayne Mack                           *
 * Advent of Code 2022                  *
 * Day - 1   Calorie Counting           *
 * Written in :C#                       *
 ****************************************/

using Day_1;
using System;
using System.IO;



CalorieCount calorieCount = new CalorieCount(0);
int total = 0;
foreach (string data in File.ReadAllLines("C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day-1\\Day-1\\Day1Input.txt"))
{
    if (data == "")
    {
        calorieCount.addNext(total);
        total = 0;
    }
    else
    {
        try
        {
            total = total + int.Parse(data);
        }
        catch (FormatException)
        {
            Console.WriteLine("Error ->" + data);
        }
    }
}
// ANSWER FOR PART ONE
Console.WriteLine("The highest calorie count found is: " + calorieCount.getHighestValue(0));
// ANSWER FOR PART TWO
Console.WriteLine("The sum of the highest three however is : " + calorieCount.getTotalOfTopThree(0, 0, 0));



