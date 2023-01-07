/**************************************************
 * Wayne Mack                                     *
 * Day 12 - Hill Climbing Algorithm               *
 * -----------------------------------------------*
 * Written in C#                                  *
 * First Start obtained                           *
 **************************************************/
class Program
{
    static bool example = false;
    static int[,]? Map, Trail;
    static string? path;


    static void Main(string[] args)
    {
        int stepCount = 0;
        path = "Day12Data.txt";
        if (example)
        {
            path = "RedditExample.txt";
        }
        Map = new int[File.ReadAllLines(path).Length, File.ReadAllLines(path)[0].ToCharArray().Length];


        // Populate topography with characters

        int x = 0, y = 0;
        (int x, int y) startingPoint = (0, 0), endingPoint = (0 , 0);
        foreach (string line in File.ReadLines(path))
        {
            y = 0;
            foreach (char c in line.ToCharArray())
            {
                Map[x, y] = (int) c - ( 96);
                if (c == 'S')
                {
                    startingPoint = (x, y);
                    Map[x, y] = 0;
                }
                if (c == 'E')
                {
                    endingPoint = (x, y);
                    Map[x, y] = 26;
                }

                y++;
            }
            x++;
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (Map[i, j] < 100) { Console.Write('0'); }
                if (Map[i, j] < 10) { Console.Write('0'); }
                Console.Write(Map[i, j] + " ");
            }
            Console.WriteLine("\n");
        }


        void displayTrail()
        {
            for (int i = 0; i < Trail.GetLength(0); i++)
            {
                for (int j = 0; j < Trail.GetLength(1); j++)
                {
                    if (Trail[i, j] > 1000) { Console.ForegroundColor = ConsoleColor.DarkRed;  Console.Write("XXX "); }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Blue;
                        if (Trail[i, j] < 100) { Console.Write('0'); }
                        if (Trail[i, j] < 10) { Console.Write('0'); }

                        Console.Write(Trail[i, j] + " ");
                    }


                }
                Console.WriteLine();
            }
        }

        Trail = new int[Map.GetLength(0), Map.GetLength(1)];

        void resetEntireTrail()
        {
            for (int i = 0; i < Trail.GetLength(0); i++)
            {
                for (int j = 0; j < Trail.GetLength(1); j++)
                {
                    Trail[i, j] = Trail.GetLength(0) * Trail.GetLength(1);
                }
            }
        }
        resetEntireTrail();

        Console.ForegroundColor = ConsoleColor.Green;

        void generateSteps(int xHere, int yHere, int Step, bool partOne)
        {
            //Console.Clear();
            //displayTrail();
            //Console.WriteLine("Generating " + xHere + " , " + yHere + " as " + Step );
            bool canAccess(int xAccess, int yAccess)
            {

                return ((Map[xAccess, yAccess] - Map[xHere, yHere] >= -1) && (Trail[xAccess,yAccess] > Trail[xHere, yHere]   + 1));
            }
            if (!partOne)
            {
                if (Trail[xHere,yHere] == 1)
                {
                    Console.WriteLine("point a is :" + xHere + " , " + yHere);
                    startingPoint = (xHere, yHere);
                    return;
                }
            }
            if (xHere > 0)
            {
                if (canAccess (xHere - 1, yHere)) {
                    Trail[xHere - 1, yHere] = Step + 1;
                    generateSteps(xHere - 1, yHere, Step + 1, partOne );

                }
            }
            if (yHere > 0)
            {
                if (canAccess(xHere, yHere - 1))
                {
                    Trail[xHere, yHere - 1] = Step + 1;
                    generateSteps(xHere, yHere - 1, Step + 1, partOne);
                }
            }
            if (yHere < Map.GetLength(1) - 1)
            {
                if (canAccess(xHere, yHere + 1))
                {
                    Trail[xHere, yHere + 1] = Step + 1;
                    generateSteps(xHere, yHere + 1, Step + 1, partOne);
                }
            }
            if (xHere < Map.GetLength(0) - 1)
            {
                if (canAccess(xHere + 1, yHere))
                {
                    Trail[xHere + 1, yHere] = Step + 1;
                    generateSteps(xHere + 1, yHere, Step + 1, partOne);
                }
            }

        }
        Trail[endingPoint.x, endingPoint.y] = 0;
        generateSteps(endingPoint.x, endingPoint.y, 0, true);

        displayTrail();
        ////////////////////////////// PART ONE //////////////////////////////////////////////////////////////

        Console.WriteLine ("The miminum steps on this trail are :" + Trail[startingPoint.x, startingPoint.y]);

        ////////////////////////////// PART TWO //////////////////////////////////////////////////////////////

        resetEntireTrail();

        generateSteps(endingPoint.x, endingPoint.y, 0, false);

        Console.WriteLine("The minimum steps for the new Trail on Part two is " + Trail[startingPoint.x, startingPoint.y]);

    }
}
