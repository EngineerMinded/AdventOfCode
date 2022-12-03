/***********************************************
 * Wayne Mack                                  *
 * Advent of Code - Day 3                      *
 * Rucksack Reorganization                     *
 * --------------------------------------------*
 * Written in C#                               *
 ***********************************************/

using System;

class  RuckSack
{
    public int address;   // ADD ON FOR PART TWO
    string first;
    string last;
    char item;
    int itemValue;
    public RuckSack next;
    // NULL CONSTRUCTOR: THIS ADDS UP TO NOTHING
    public RuckSack()
    {
        address = 0;    
        first = "";
        last = "";
        itemValue = 0;
        next = null;
    }
    // CONSTRUCTOR: THIS CONSTRUCTOR TALLIES ALL VALUES FOR PART ONE
    public RuckSack(String input)
    {
        first = input.Substring(0, (int)(input.Length / 2));
        last = input.Substring((int)(input.Length / 2), (int)(input.Length / 2));
        foreach (char f in first)
        {
            foreach (char l in last)
            {
                if (l == f)
                {
                    item = f;
                }
            }
        }
        /* NOTE: ASCII code for a is 97, ACII code for A is 65 */
        int origCharValue = (int)item;
        if (origCharValue > 97)
        {
            itemValue = origCharValue - 96;
        }
        else
        {
            itemValue = origCharValue - 65 + 27;
        }
        next = null;
    }
    // This adds values to rhe linkedlist. This is called after this object is already
    // constructed. 
    public void add(String value)
    {
        if (next == null)
        {
            next = new RuckSack(value);
            next.address = address + 1;
        }
        else
        {
            next.add(value);    
        }
    }
    // The tallyCharacterValues adds up all of the itemvalues and returns them.
    // This is the answer for Part One
    public int tallyCharacterValue ()
    {
        if (next == null) {
            return itemValue;
        }
        else
        {
            return itemValue + next.tallyCharacterValue();
        }
    }
    public string getAtAddress ( int a)  // return the string at this value (For Part 2)
    {
        if (address == a)
        {
            return (first + last);
        }
        else
        {
            return next.getAtAddress(a);
        }
    }
    public int getMaxAddress ()
    {
        if (next != null)
        {
            return next.getMaxAddress();
        }
        else
        {
            return address;
        }
    }
}
class RuckSackGroup
{
    bool startHere = false;
    string sack1, sack2, sack3;
    char commonItem;
    int itemValue;
    RuckSackGroup next;
    int address;
    public RuckSackGroup ()
    {
        sack1 = "";
        sack2 = "";
        sack3 = "";
        itemValue = 0;
        address = 0;
        next = null;   
    }
    public RuckSackGroup(string sack1, string sack2, string sack3)
    {
        startHere = true;
        //Console.WriteLine(sack1 + " " + sack2 + " " + sack3);
        this.sack1 = sack1;
        this.sack2 = sack2;
        this.sack3 = sack3;
        findCommonValue();

    } 
    private void findCommonValue()
    {
        foreach (char x in sack1.ToCharArray())
        {
            foreach (char y in sack2.ToCharArray())
            {
                foreach (char z in sack3.ToCharArray())
                {
                    if (x == y && y == z)
                    {
                        commonItem = x;
                        setItemValue();
                    }
                }
            }
        }
    }
    private void setItemValue () // REFER TO ITEM VALUE CRITERIA
    {                            // IN THE RUCKSACK CONSTRUCTOR ABOVE
    
        if ((int)commonItem > 96)
        {
            itemValue = (int)commonItem - 96;
        }
        else
        {
            itemValue = (int)commonItem - 65 + 27;
        }
    }
    public void add (RuckSack ruckSack )
    {
        if (next != null)
        {
            next.add (ruckSack);
        }
        else 
        {
            int targetAddress1 = ruckSack.address;
            int targetAddress2 = ruckSack.next.address;
            int targetAddress3 = ruckSack.next.next.address;

            next = new RuckSackGroup(ruckSack.getAtAddress(targetAddress1),
                ruckSack.getAtAddress(targetAddress2),
                ruckSack.getAtAddress(targetAddress3));
            next.address = address + 1;
            if (targetAddress3 + 3 <= ruckSack.getMaxAddress())
            {
                next.add(ruckSack.next.next.next);
            }
        }   
    }   
    public int tally()
    {
        if (next != null)
        {
            return itemValue + next.tally();
        }
        else
        {
            return itemValue;
        }
    }
}
// THE MAIN PROGRAM CLASS
class Program
{
    static RuckSack ruckSack;
    static RuckSackGroup ruckSackGroup;

    static string Path = ("C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day3_Rucksack_Reorganization\\Day3_Rucksack_Reorganization\\Day3_Input.txt");
    static void Main(string[] args)
    {
        /////////////////////////////q/////// PART ONE //////////////////////////////////////////
        ruckSack = new RuckSack();    
        // Start gathering information from file
        foreach (string Line in File.ReadAllLines(Path))
        {
            ruckSack.add(Line); 
        }
        Console.WriteLine("The total tally for part one is :" + ruckSack.tallyCharacterValue());
        //////////////////////////////////// PART TWO ///////////////////////////////////////////
        ruckSackGroup = new RuckSackGroup();
        ruckSackGroup.add(ruckSack.next);
        Console.WriteLine("The total tally for part two is :" + ruckSackGroup.tally());
    }
}