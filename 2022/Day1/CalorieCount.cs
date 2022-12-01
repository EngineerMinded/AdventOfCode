/****************************************
 * Wayne Mack                           *
 * Advent of Code 2022                  *
 * Day - 1   Calorie Counting           *
 * Written in :C#                       *
 * Calorie counting linked list with    *
 * functions built in                   *
 ****************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day_1
{
    public class CalorieCount
    {
        private int value;
        private CalorieCount next;


        public CalorieCount(int value)
        {
            this.value = value;
            next = null;
        }
        public void addNext(int nextInput)
        {
            if (next == null)
            {
                next = new CalorieCount(nextInput);
                Console.WriteLine("added ->" + nextInput);
            }
            else { next.addNext(nextInput); }
        }
        // Function to get highest value in part one
        public int getHighestValue(int highest)
        {
            if (value >= highest)
            {
                highest = value;
            }
            if (next == null)
            {
                return highest;
            }
            else
            {
                return next.getHighestValue(highest);
            }
        }
        // Function to get sum of top three in part 2
        public int getTotalOfTopThree (int h1, int h2, int h3)
        {
            if (value > h1 || value > h2 || value > h3)
            {
                if (h1 <= h2 && h1 <= h3)
                {
                    h1 = value;
                }
                else if (h2 <= h1 && h2 <= h3)
                {
                    h2 = value;
                }
                else
                {
                    h3 = value;
                }
            }
            if (next == null)
            {
                return h1 + h2 + h3;
            }
            else
            {
                return next.getTotalOfTopThree(h1, h2, h3);
            }
        }
    }
}
