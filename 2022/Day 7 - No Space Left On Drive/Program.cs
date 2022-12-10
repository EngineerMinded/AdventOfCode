


enum Mode { INSERTION_MODE, NONE}
class Program
{
    static DirectoryList workingDirectory;
    static FileObject objectList;

    static void Main(string[] args)
    {

        string path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device\\Day 7 - No Space Left On Device\\Day7Sample.txt";
        objectList = new FileObject();
        workingDirectory = new DirectoryList();

        foreach (string line in File.ReadLines(path))
        {
            if (line.Contains("$"))
            {
                if (line.Contains ("cd"))
                {
                    workingDirectory.cd(line.Split(" ")[2]);
                }
                else if (line.Contains("ls"))
                {

                }
            }
            else
            {
                objectList.append(workingDirectory.getWorkingDirectory(), line);
            }
        }
        objectList.display();

        DirectoryList summaryDirectoryList = new DirectoryList();
        summaryDirectoryList.append()

    }
}