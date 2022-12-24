/****************************************************************
 * Wayne Mack                                                   *
 * Advent Of Code 2020 - Day 7:                                 *
 * No space Left on Device                                      *
 * ------------------------------------------------------------ *
 * Written in C#                                                *
 * FileObject.cs                                                *
 * **************************************************************/

enum Type { FILE, DIRECTORY, UNINITIALIZED}
/****************************************************************
 * FileObjects can either be files or directories               *
 ****************************************************************/
class FileObject
{
    string name;
    bool readInTally;
    Type type;
    FileObject contents; // For Subdirectories and files
    FileObject Next; // for objects in directory as this one
    long fileSize;
    InstructionSet instructions;
    public FileObject ()
    {
        name = "";
        readInTally = false;
        type = Type.UNINITIALIZED;
        Next = null;
        contents = null;
        this.fileSize = 0;
    }
    public FileObject(string name)
    {
        type = Type.DIRECTORY;
        this.name = name;
        readInTally = false;
        Next = null;
        contents = null;
        this.fileSize = 0;
    }
    private FileObject (String name, int size)
    {
        type= Type.FILE;
        readInTally= false;
        this.name = name;
        this.fileSize = size;
        Next = null;
        contents = null; // In this case, CONTENTS is never used
    }
    private void append (String name)
    {
        if (type == Type.UNINITIALIZED)
        {
            this.name = name;
            type = Type.DIRECTORY;
            Next = null;
            contents = null;
        }
        if (Next == null)
        {
            Next = new FileObject(name);
        }
        else
        {
            Next.append (name);
        }
     }
    private void append (String name, int size)
    {
        if (Next == null)
        {
            Next = new FileObject(name, size);
        }
        else
        {
            Next.append(name, size);
        }
    }

    public void command (string targetDirectory, InstructionSet i)
    {
        this.instructions = i;
        if (targetDirectory == this.name)
        {
            bool breakLoop = false;
            while (!breakLoop)
            {
                String nextCommand = instructions.getNext();
                if (nextCommand.Contains("$")) // this is an "ls" or a "cd" command
                {
                    if (nextCommand.Contains("ls"))
                    {
                        while (!instructions.peek().Contains("$"))
                        {
                            nextCommand = instructions.getNext();
                            if (nextCommand.Contains("dir"))
                            {
                                if (contents == null)
                                {
                                    contents = new FileObject(nextCommand.Split(" ")[1]);
                                }
                                else
                                {
                                    contents.append(nextCommand.Split(" ")[1]);
                                }
                            }
                            else
                            {
                                if (contents == null)
                                {
                                    contents = new FileObject(nextCommand.Split(" ")[1], int.Parse(nextCommand.Split(" ")[0]));

                                }
                                else
                                {
                                    contents.append(nextCommand.Split(" ")[1], int.Parse(nextCommand.Split(" ")[0]));
                                }
                            }
                        }
                    }
                    else if (!nextCommand.Contains("end")) // The program assumes that the remaining option is a "cd"
                    {
                        if (nextCommand.Contains(".."))
                        {

                            breakLoop = true;
                        }
                        else
                        {

                            if (contents == null)
                            {
                                contents = new FileObject(nextCommand.Split(" ")[2]);
                            }
                            contents.command(nextCommand.Split(" ")[2], instructions);

                        }
                    }
                    else
                    {
                        breakLoop = true;
                    }
                }
            }
        }
        else if (Next != null)
        {
            Next.command(targetDirectory, instructions);
            instructions = Next.instructions;
        }
        else
        {
            Next = new FileObject(targetDirectory);
            Next.command(targetDirectory, instructions);
            instructions = Next.instructions;
        }
    }

    public long getDirectoryValues()
    {

        if (type == Type.DIRECTORY)
        {
            if (contents != null)
            {
                fileSize = contents.getDirectoryValues();
            }
        }
        if (Next != null)
        {
            return fileSize + Next.getDirectoryValues();

        }
        else
        {
            return fileSize;
        }
    }

    public void printTree()
    {
        fileSize = getDirectoryValues();
        printTree(0);
    }
    private void printTree(int space)
    {
        for (int i = 0; i < space; i++)
        {
            Console.Write("  ");
        }
        if (type == Type.DIRECTORY)
        {
            Console.WriteLine("- " + name + " (dir) " + fileSize);
        }
        else
        {
            Console.WriteLine("- " + name + " (file , size=" + fileSize + ")");
        }
        if (contents != null)
        {
            contents.printTree(space + 2);
        }
        if (Next != null)
        {
            Next.printTree(space);

        }
    }
    public long getAllDirectoriesAtMaxNumber(int maxNumber) // Procedure for Part One
    {
        long total = 0;
        if (contents != null)
        {
            total = total + contents.getAllDirectoriesAtMaxNumber(maxNumber);
        }
        if (type == Type.DIRECTORY )
        {
            if (fileSize <= maxNumber)
            {
                total = total + fileSize;
            }
        }
        if (Next != null)
        {
            total = total + Next.getAllDirectoriesAtMaxNumber(maxNumber);
        }
        return total;
    }

    public long getLargestNumberupTo(long maxNumber)
    {
        long answer = fileSize;
        if (type == Type.DIRECTORY)
        {
            if (contents != null) {
                if (answer > contents.getLargestNumberupTo(maxNumber) &&
                    (contents.getLargestNumberupTo(maxNumber) > maxNumber))
                {
                    answer = contents.getLargestNumberupTo(maxNumber);
                }
            }
            if (Next != null)
            {
                if (answer > Next.getLargestNumberupTo(maxNumber) &&
                    (Next.getLargestNumberupTo(maxNumber) > maxNumber))
                {
                    answer = Next.getLargestNumberupTo(maxNumber);
                }
            }
            return answer;
        }
        else if (Next == null)
        {
            return 999999999999999999; //
        }
        return Next.getLargestNumberupTo(maxNumber);
    }

    public LinkedList<long> allDirectoryNumbers (LinkedList<long> list)
    {
        if (type == Type.DIRECTORY)
        {
            list.AddLast(fileSize);
        }
        if (contents != null)
        {
            list = contents.allDirectoryNumbers(list);
        }
        if (Next != null)
        {
            list = Next.allDirectoryNumbers(list);
        }
        LinkedList<long> sorted = new LinkedList<long>();
        return list;
    }

}
