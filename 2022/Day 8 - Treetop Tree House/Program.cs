/*****************************************
 * Wayne Mack                            *
 * Advent Of Code 2022 - Day 8           *
 * Treetop Tree House                    *
 * Written in C#                         *
 *****************************************/

class Program
{
     static int [,] TreeMap;
    static string path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 8- Treetop Tree House\\Day 8- Treetop Tree House\\Day8Data.txt";

    /////////////////////////////////////// MAIN CLASS ///////////////////////////////////////////////////////

    static void Main (string[] args)
    {
        int xRange = File.ReadAllText(path).Split("\n").Length;
        int yRange = File.ReadAllText(path).Split("\n")[0].Length - 1;
        TreeMap = new int[xRange, yRange];
        int x = 0, y = 0;
        foreach (string v in File.ReadLines(path))
        {
            y = 0;
            foreach (char u in v.ToCharArray())
            {
                TreeMap[x, y] = u - '0';
                y++;
            }
            x++;
        }
        /*
        for (int i = 0; i < TreeMap.GetLength(0); i++)
        {
            for (int j = 0; j < TreeMap.GetLength(1); j++)
            {
                Console.Write(TreeMap[i, j]);
            }
            Console.WriteLine();
        }
        */
        // BOOLEAN FUNCTION FOR PART ONE
        bool isVisible (int x, int y) 
        {
            bool a1 = true, a2 = true, a3 = true, a4 = true;
            for (int i = 0; i < x; i++)
            {
                if (TreeMap[i,y] >= TreeMap[x,y])   { a1 = false; }
            }
            for (int i = xRange - 1; i > x; i--)
            {
                if (TreeMap[i,y] >= TreeMap[x,y])  { a2 = false; }
            }
            for (int i = 0; i < y; i++)
            {
                if (TreeMap[x, i] >= TreeMap[x, y])  { a3 = false; }
            }
            for (int i = yRange - 1; i > y; i--)
            {
                if (TreeMap[x, i] >= TreeMap[x, y])  { a4 = false; }
            }
            return a1 || a2 || a3 || a4;
        }
        int count = 0;
        /////////////////////////////// PART ONE ////////////////////////////////////////// 
        for (int i = 0; i < TreeMap.GetLength(0); i++)
        {
            for (int j = 0; j < TreeMap.GetLength(1); j++)
            {
                if (isVisible(i, j))
                {
                    count++;
                } 
            }
        }
        Console.WriteLine("The total number of visible trees is {0} !" , count);
        /////////////////////////////// PART TWO ////////////////////////////////////////////
        int getScenicScore (int x, int y)
        {
            int getUpCount (int v)
            {
                if (v == 0)
                {
                    return 0;
                }
                v--;
                if (TreeMap[v,y] < TreeMap[x,y])
                {
                    return 1 + getUpCount(v);
                }
                else
                {
                    return 1;
                }
            }
            int getDownCount(int v)
            {
                if (v == xRange - 1)
                {
                    return 0;
                }
                v++;
                if (TreeMap[v, y] < TreeMap[x, y])
                {
                    return 1 + getDownCount(v);
                }
                else
                {
                    return 1;
                }
            }
            int getLeftCount(int v)
            {
                if (v == 0)
                {
                    return 0;
                }
                v--;
                if (TreeMap[x, v] < TreeMap[x, y])
                {
                    return 1 + getLeftCount(v);
                }
                else
                {
                    return 1;
                }
            }
            int getRightCount(int v)
            {
                if (v == yRange -1)
                {
                    return 0;
                }
                v++;
                if (TreeMap[x, v] < TreeMap[x, y])
                {
                    return 1 + getRightCount(v);
                }
                else
                {
                    return 1;
                }
            }
            return getUpCount(x) * getDownCount(x) * getRightCount(y) * getLeftCount(y);
        }
        int maxScenicScore = 0;
        for (int i = 0; i < xRange; i++)
        {
            for (int j = 0; j < yRange; j++)
            {
                if (maxScenicScore < getScenicScore(i,j))
                {
                    maxScenicScore = getScenicScore(i,j);
                } 
            }
        }
        Console.WriteLine("The Maximum Scenic Score is: " + maxScenicScore);
    }
}