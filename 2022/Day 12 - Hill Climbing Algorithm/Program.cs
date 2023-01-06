/**************************************************
 * Wayne Mack                                     *
 * Day 12 - Hill Climbing Algorithm               *
 * -----------------------------------------------*
 * Written in C#                                  *
 * Gets the right answer for sample but goes      *
 * Forever for practical                          *
 **************************************************/
class Program
{
    static bool example = true;
    static int[,]? Map, Trail;
    static string? path;


    static void Main(string[] args)
    {
        int stepCount = 0;
        path = "Day12Data.txt";
        if (example)
        {
            path = "Day12Example.txt";
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
                    Map[x, y] = 27;
                }

                y++;
            }
            x++;
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
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
                    Console.Write(Trail[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        Trail = new int[Map.GetLength(0), Map.GetLength(1)];
        for (int i = 0; i < Trail.GetLength(0); i++)
        {
            for (int j =0; j < Trail.GetLength(1); j++)
            {
                Trail[i, j] = Trail.GetLength(0) * Trail.GetLength (1);
            }
        }
        Console.ForegroundColor = ConsoleColor.Green;

        void generateSteps(int xHere, int yHere, int Step)
        {
            //Console.Clear();
            //displayTrail();
            Console.WriteLine("Generating " + xHere + " , " + yHere + " of Area" + Map.GetLength(0) +" , " + Map.GetLength(1) +" as " + Step );
            bool canAccess(int xAccess, int yAccess)
            {
                return ((Map[xAccess, yAccess] - Map[xHere, yHere] <= 1) && (Trail[xAccess,yAccess] >= Trail[xHere, yHere]));
            }
            Trail[xHere, yHere] = Step;
            if (xHere > 0)
            {
                if (canAccess (xHere - 1, yHere)) {
                    generateSteps(xHere - 1, yHere, Step + 1) ;
                }
            }
            if (xHere < Map.GetLength(0) - 1)
            {
                if (canAccess(xHere + 1, yHere))
                {
                    generateSteps(xHere + 1, yHere, Step + 1);
                }
            }
            if (yHere > 0)
            {
                if (canAccess(xHere, yHere - 1))
                {
                    generateSteps(xHere, yHere - 1, Step + 1);
                }
            }
            if (yHere < Map.GetLength(1) - 1)
            {
                if (canAccess(xHere, yHere + 1))
                {
                    generateSteps(xHere, yHere + 1, Step + 1);
                }
            }
        }
        generateSteps(startingPoint.x, startingPoint.y, 0);

        displayTrail();

        Console.WriteLine ("The miminum steps on this trail are :" + Trail[endingPoint.x, endingPoint.y]);
    }
}
