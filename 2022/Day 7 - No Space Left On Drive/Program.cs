


enum Mode { INSERTION_MODE, NONE}
class Program
{
    static DirectoryList workingDirectory;
    static FileObject objectList;

    static void Main(string[] args)
    {

        string path = "C:\\Users\\wamj2\\OneDrive\\Desktop\\Advent Of Code 2022\\Day 7 - No Space Left On Device\\Day 7 - No Space Left On Device\\ShouldBe7.txt";
        objectList = new FileObject();
        FileObject fileList = new FileObject();
        workingDirectory = new DirectoryList();

        foreach (string line in File.ReadLines(path))
        {
            if (line.Contains("$"))
            {
                if (line.Contains("cd"))
                {
                    workingDirectory.cd(line.Split(" ")[2]);
                }
                else if (line.Contains("ls"))
                {

                }
            }
            else
            {
                if (!line.Contains("dir"))
                {
                    fileList.append(workingDirectory.getWorkingDirectory(), line);
                }
                else
                {
                    objectList.append(workingDirectory.getWorkingDirectory(), line);
                }
            }
        }
        objectList.appendFiles(fileList);
        objectList.display();

        DirectoryList summaryDirectoryList = new DirectoryList();
        objectList.resetAll();
        while (!objectList.alreadyRecorded)
        {
            string stringData = objectList.getNextValue();
            string directoryName = stringData.Split(" ")[0];
            int directoryValue = int.Parse(stringData.Split(" ")[1]);
            if (directoryValue == 0)
            {
                if (stringData.Split(" ").Length  > 3)
                {
                    string addressToFind = stringData.Split(" ")[3];
                    summaryDirectoryList.addValue(directoryName, summaryDirectoryList.getValueAtAddress(addressToFind));
                }
            }
            else
            {
                summaryDirectoryList.addValue(directoryName , directoryValue);
            }
        }
        Console.WriteLine();    
        summaryDirectoryList.printAll();

        /////////////////////////////////////// PART ONE ANSWER ///////////////////////////////////////////////////
        Console.WriteLine("\n\nThe sum of the lowest directories are: " + summaryDirectoryList.getSumUnder(100000));
    }
}