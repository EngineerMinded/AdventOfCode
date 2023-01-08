/**************************************************
 * Wayne Mack                                     *
 * Day 12 - Hill Climbing Algorithm               *
 * -----------------------------------------------*
 * Written in C#                                  *
 * Both stars achieved                            *
 **************************************************/
class Program
{
    static bool example = false; // IF RUNNING THE EXAMPLE, MAKE THIS TRUE
    static int[,]? Map, Trail;   // MAP SHOWS ELEVATION DATA, TRAIL IS MATRIX FOR NUMBER OF STEPS
    static string? path;         // PATH IS FOR THE FILENAME

    static void Main(string[] args)
    {
        path = "Day12Data.txt";
        if (example)
        {
            path = "Day12Example.txt";
        }
        Map = new int[File.ReadAllLines(path).Length, File.ReadAllLines(path)[0].ToCharArray().Length];

        // Populate topography with elevation numbers

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
                    // Designate starting point
                    startingPoint = (x, y);
                    Map[x, y] = 0;
                }
                if (c == 'E')
                {
                    // Designate ending point
                    endingPoint = (x, y);
                    Map[x, y] = 26;
                }
                y++;
            }
            x++;
        }

        void displayMap()  // FUNCTION TO DISPLAY MAP IN CONSOLE
        {
            for(int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (Map[i, j] < 100) { Console.Write('0'); }
                    if (Map[i, j] < 10) { Console.Write('0'); }
                    Console.Write(Map[i, j] + " ");
                }
                Console.WriteLine("\n");
            }
        }

        void displayTrail() // FUNCTION TO DISPLAY
        {
            for (int i = 0; i < Trail.GetLength(0); i++)
            {
                for (int j = 0; j < Trail.GetLength(1); j++)
                {
                    if (Trail[i, j] > 1000) { Console.ForegroundColor = ConsoleColor.DarkRed;  Console.Write("XXX "); }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Blue;
                        if (Trail[i, j] < 100) { Console.Write('0'); Console.ForegroundColor = ConsoleColor.DarkCyan; }
                        if (Trail[i, j] < 10) { Console.Write('0'); Console.ForegroundColor = ConsoleColor.Cyan; }

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

        int lowestA = 99999; // For the answer to part 2
        Console.ForegroundColor = ConsoleColor.Green;
        bool foundPartTwo = false;
        void generateSteps(int xHere, int yHere, int Step)
        {


            bool canAccess(int xAccess, int yAccess)
            {

                return ((Map[xAccess, yAccess] - Map[xHere, yHere] >= -1) && (Trail[xAccess,yAccess] > Trail[xHere, yHere]   + 1));
            }

            if (Map[xHere,yHere] == 1)
            {
                if (lowestA > Trail[xHere,yHere]) { lowestA = Trail[xHere,yHere]; }
            }
            if (xHere > 0)
            {
                if (canAccess(xHere - 1, yHere))
                {
                    Trail[xHere - 1, yHere] = Step + 1;
                    generateSteps(xHere - 1, yHere, Step + 1);

                }
            }
            if (yHere > 0)
            {
                if (canAccess(xHere, yHere - 1))
                {
                    Trail[xHere, yHere - 1] = Step + 1;
                    generateSteps(xHere, yHere - 1, Step + 1);
                }
            }
            if (yHere < Map.GetLength(1) - 1)
            {
                if (canAccess(xHere, yHere + 1))
                {
                    Trail[xHere, yHere + 1] = Step + 1;
                    generateSteps(xHere, yHere + 1, Step + 1);
                }
            }
            if (xHere < Map.GetLength(0) - 1)
            {
                if (canAccess(xHere + 1, yHere))
                {
                    Trail[xHere + 1, yHere] = Step + 1;
                    generateSteps(xHere + 1, yHere, Step + 1);
                }
            }


        }
        ////////////////////////////// PART ONE //////////////////////////////////////////////////////////////

        Trail[endingPoint.x, endingPoint.y] = 0;
        generateSteps(endingPoint.x, endingPoint.y, 0);
        //displayTrail();
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.Magenta;
        Console.WriteLine ("The miminum steps on this trail are :" + Trail[startingPoint.x, startingPoint.y]);

        ////////////////////////////// PART TWO //////////////////////////////////////////////////////////////

        Console.WriteLine("Th minimum steps for the hiking trail is: " + lowestA);
    }
}
