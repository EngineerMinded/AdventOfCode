


class Program
{
    static bool testMode = true;
    static InstructionSet instructions;
    static FileObject tree;
    static void Main(string[] args)
    {
        String path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device v2.0\\Day 7 - No Space Left On Device v2.0\\Day7Data.txt"; ;
        if (testMode)
        {
           path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device v2.0\\Day 7 - No Space Left On Device v2.0\\Day7Test.txt";
        }
        
        Console.WriteLine("COMING SOON!");
        instructions = new InstructionSet();
        foreach (string data in File.ReadLines(path))
        {
            instructions.append(data);
        }
        //instructions.PrintAll();
        tree = new FileObject("/");
        tree.command("/",instructions);
        tree.printTree();
        Console.WriteLine("The total for part One is : " + tree.getAllDirectoriesAtMaxNumber(100000));
    }
}
