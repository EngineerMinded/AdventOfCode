/**************************************************
 * Wayne Mack                                     *
 * Day 12 - Hill Climbing Algorithm               *
 * -----------------------------------------------*
 * Written in C#                                  *
 * (((( UNFINISHED )))))))                        *
 **************************************************/ 
class Program
{
    static bool example = true;
    static int[,]? topography;
    static string? path;
    static List<string> stepList;

    static void Main(string[] args)
    {
        int stepCount = 0;
        path = "Day12Data.txt";
        if (example)
        {
            path = "Day12Example.txt";
        }
        topography = new int[File.ReadAllLines(path).Length, File.ReadAllLines(path)[0].ToCharArray().Length];
        stepList = new List<string>();

        // Populate topography with characters

        int x = 0, y = 0;
        (int x, int y) startingPoint = (0, 0), endingPoint = (0 , 0);
        foreach (string line in File.ReadLines(path))
        {
            y = 0;
            foreach (char c in line.ToCharArray())
            {
                topography[x, y] = (int) c - ( 96);
                if (c == 'S')
                {
                    startingPoint = (x, y);
                    topography[x, y] = 0; 
                }
                if (c == 'E')
                {
                    endingPoint = (x, y);
                    topography[x, y] = 27;
                }

                y++;
            }
            x++;
        }

        

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (topography[i, j] < 10) { Console.Write('0'); }
                Console.Write(topography[i, j] + " ");
            }
            Console.WriteLine("\n");
        }

        Console.WriteLine("The Answer to Part One is: " + getPathOfLeastSteps(startingPoint.x, startingPoint.y, new List<(int, int)>() ));
        stepList.Reverse();
        foreach (String line in stepList)
        {
            Console.WriteLine(line);
        }

        int getPathOfLeastSteps (int xStep, int yStep, List <(int, int)> stepsAlreadyTaken)
        {
            if (topography[xStep,yStep] == 27)
            {
                return 1;
            }
            
            if (deadEnd(xStep, yStep))
            {
                Console.WriteLine("Found Dead End!");
                return 99999999;
            }
            
            List<(int, int)> currentList = stepsAlreadyTaken;
            currentList.Add((xStep, yStep));

            int North, South, East ,West; 
            North = South = East = West = 999999999;

            if (xStep > 0)
            {
                if (!hasBeenFound (xStep - 1, yStep))
                {
                    if (isAcessible(xStep - 1, yStep))
                    {
                        North =  getPathOfLeastSteps(xStep - 1, yStep, currentList);
                    }
                }
            }
            if (xStep < topography.GetLength(0) - 1)
            {
                if (!hasBeenFound(xStep + 1, yStep))
                {
                    if (isAcessible(xStep + 1, yStep))
                    {
                        South = 1 + getPathOfLeastSteps(xStep + 1, yStep, currentList);
                    }
                }
            }
            if (yStep > 0)
            {
                if (!hasBeenFound(xStep , yStep - 1))
                {
                    if (isAcessible(xStep , yStep - 1))
                    {
                        East =  1 + getPathOfLeastSteps(xStep , yStep - 1, currentList);
                    }
                }
            }
            if (yStep < topography.GetLength(1) - 1)
            {
                if (!hasBeenFound(xStep , yStep + 1))
                {
                    if (isAcessible(xStep , yStep + 1))
                    {
                        West =  1 + getPathOfLeastSteps(xStep, yStep + 1, currentList);
                    }
                }
            }
            String gotoHere = "";
            int Answer = North; gotoHere = "North";
            if (South < Answer) { Answer = South;  gotoHere = "South"; }
            if (East < Answer) { Answer = East;  gotoHere = "East"; }
            if (West < Answer) { Answer = West; gotoHere = "West"; }
            if ((xStep, yStep) == endingPoint) { gotoHere = "End"; }
            stepList.Add(xStep + " , " + yStep + " " + gotoHere + " " + stepCount++);
            return  1 + Answer;

            bool hasBeenFound (int xTest, int yTest)
            {
                foreach ((int,int) fn in stepsAlreadyTaken)
                {
                    if (fn == (xTest,yTest))
                    {
                        return true;
                    }
                    
                }
                return false;
            }

            bool isAcessible (int xTest, int yTest)
            {
                return ((topography[xTest,yTest] <= topography[xStep,yStep] + 1) 
                    && ( !hasBeenFound(xTest,yTest))) ;
            }
            bool deadEnd (int xTest, int yTest)
            {
               if (xTest > 0)
                {
                    if (isAcessible (xTest  - 1, yTest))
                    {
                        return false;
                    }
                }
               if (xTest < topography.GetLength(0) - 1)
                {
                    if (isAcessible(xTest + 1, yTest))
                    {
                        return false;
                    }
                }
                if (yTest > 0)
                {
                    if (isAcessible(xTest, yTest - 1))
                    {
                        return false;
                    }
                }
                if (yTest < topography.GetLength(1) - 1)
                {
                    if (isAcessible(xTest, yTest + 1))
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}