
enum Type { FILE, DIRECTORY, UNINITIALIZED} 
class FileObject
{
    string name;
    Type type;
    FileObject contents; // For Subdirectories and files
    FileObject Next; // for objects in directory as this one
    int fileSize;
    InstructionSet instructions;
    public FileObject ()
    {
        name = "";
        type = Type.UNINITIALIZED;
        Next = null;
        contents = null;
        this.fileSize = 0;
    }
    public FileObject(string name)
    {
        type = Type.DIRECTORY;
        this.name = name;
        Next = null;
        contents = null;
        this.fileSize = 0;
    }
    private FileObject (String name, int size)
    {
        type= Type.FILE;
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
        Console.WriteLine(targetDirectory == this.name + " " + targetDirectory + " " + this.name);
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
                                Console.WriteLine (nextCommand);
                                if (contents == null)
                                {
                                    contents = new FileObject(nextCommand.Split(" ")[1], int.Parse(nextCommand.Split(" ")[0]));
                                }
                                else
                                {
                                    contents.append(nextCommand.Split(" ")[1], int.Parse(nextCommand.Split(" ")[0]));
                                }
                                fileSize = fileSize + int.Parse(nextCommand.Split(" ")[0]);
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
                            Console.WriteLine(nextCommand);
                            if (contents == null)
                            {
                                contents = new FileObject(nextCommand.Split(" ")[2]);
                            }
                            contents.command(nextCommand.Split(" ")[2], instructions);
                            fileSize = fileSize + contents.fileSize;
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

    public void printTree()
    {
        printTree(0);
    }
    private void printTree(int space)
    {
        for (int i = 0; i < space; i++)
        {
            Console.Write(" ");
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
    public int getAllDirectoriesAtMaxNumber(int maxNumber)
    {
        int total = 0;
        if (contents != null)
        {
            total = total + contents.getAllDirectoriesAtMaxNumber(maxNumber);
        }
        if (type == Type.DIRECTORY)
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
    
}