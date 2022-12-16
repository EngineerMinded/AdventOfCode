
class Program
{
    static void Main (string[] args)
    {
        CPU cpu = new CPU();
        string command;
        int countForArray = 0;
        string fileName = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 10 - Cathode Ray Tube\\Day 10 - Cathode Ray Tube\\Day10Sample.txt";

        string [] commandList = new string[150];
        // Read from the text file
        foreach (string line in File.ReadLines(fileName))
        {
            commandList[countForArray] = line;
            countForArray++;
        }
        ///////////////////////////////////////////////////PART ONE //////////////////////////////////////////////////////////////////
        int total = 0; 
       
        total = total + (cpu.getCountAt(20, commandList, countForArray, true));
        total = total + (cpu.getCountAt(60, commandList, countForArray, true));
        total = total + (cpu.getCountAt(100, commandList, countForArray, true));
        total = total + (cpu.getCountAt(140, commandList, countForArray, true));
        total = total + (cpu.getCountAt(180, commandList, countForArray, true));
        total = total + (cpu.getCountAt(220, commandList, countForArray, true));

        Console.WriteLine("The sum of Part One is : " + total);
        ///////////////////////////////////////////////////PART TWO///////////////////////////////////////////////////////////////////
        string [] image = new string[240];
        Console.WriteLine();
        for (int i = 1; i <= 240; i++)
        {
            int currentRegister =  cpu.getCountAt(i, commandList, countForArray, false);
            Console.WriteLine(i + " " + currentRegister);
            
        }



    }
}