/****************************************************************
 * Wayne Mack                                                   *
 * Advent Of Code 2020 - Day 7:                                 *
 * No space Left on Device                                      *
 * ------------------------------------------------------------ *
 * Written in C#                                                *
 * Program.cs                                                   *
 * **************************************************************/
class Program
{
    static bool testMode = false;
    static InstructionSet instructions;
    static FileObject tree;
    static void Main(string[] args)
    {
        String path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device v2.0\\Day 7 - No Space Left On Device v2.0\\Day7Data.txt"; ;
        if (testMode)
        {
           path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device v2.0\\Day 7 - No Space Left On Device v2.0\\Day7Test.txt";
        }
        
        Console.WriteLine("START !");
        instructions = new InstructionSet();
        foreach (string data in File.ReadLines(path))
        {
            instructions.append(data);
        }
        //instructions.PrintAll();
        tree = new FileObject("/");
        tree.command("/",instructions);
        tree.printTree();

        /////////////////////////////////////// PART ONE ///////////////////////////////////////////////////////////////////////////////////
        Console.WriteLine("The total for part One is : " + tree.getAllDirectoriesAtMaxNumber(100000));

        long totalSpace = 70000000;
        long spaceRequired = 30000000;

        ////////////////////////////////////////////////////////////////////////////// PART TWO ////////////////////////////////////////////
        LinkedList<long> fileSizeList = new LinkedList<long>();

        fileSizeList = tree.allDirectoryNumbers(fileSizeList);
        fileSizeList.RemoveFirst();
        long[] fileList = fileSizeList.ToArray();
        Array.Sort(fileList);
        foreach(long variable in fileList)
        {
            Console.WriteLine(variable);
        }

        int arrayRange = fileList.Length;

        long availibleSpace = totalSpace - fileList[fileList.Length - 1];
        Console.WriteLine(" Availible Space : " + availibleSpace);

        int position = 0;

        while (position < arrayRange - 1)
        {
            if (fileList[position] + availibleSpace > spaceRequired)
            {
                break;
            }
            else
            {
                position++;
            }
        }
        Console.WriteLine("The lowest Number that can be deleted is : " + fileList[position]);
    }
}
