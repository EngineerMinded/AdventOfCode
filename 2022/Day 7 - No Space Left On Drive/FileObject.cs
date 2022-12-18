﻿
enum Type { FILE, DIRECTORY }
class FileObject
{
    public string name, directoryValue;
    public int value;
    public FileObject next;
    public Type type;
    public Boolean alreadyRecorded;

    public FileObject()
    {
        directoryValue = "/";
        type = Type.DIRECTORY;
        value = 0;
        name = "";
        next = null;
        alreadyRecorded = false;
    }
    public FileObject(string dir, string name)
    {
        this.name = name;
        this.directoryValue = dir;
        type = Type.DIRECTORY;
        value = 0;
        next = null;
        alreadyRecorded = false;
    }

    public FileObject(string dir, string name, int value)
    {
        this.directoryValue = dir;
        this.name = name;
        this.value = value;
        type = Type.FILE;
        next = null;
        alreadyRecorded = false;
    }
    public void append ( string workingDirectory, string rawData)
    {
        if (next != null)
        {
            next.append ( workingDirectory, rawData);
        }
        else
        {
    
            string passThisLine;
            if (rawData.Contains("dir"))
            {
                passThisLine = "- " + rawData.Split(" ")[1] + " (dir)";
                next = new FileObject(workingDirectory, passThisLine);
            }
            else
            {
                passThisLine = "- " + rawData.Split(" ")[1] +" (file, size=" + rawData.Split(" ")[0] + ")";
                next = new FileObject(workingDirectory, passThisLine, int.Parse(rawData.Split(" ")[0]));
            }
        }
    }

    public void appendFiles (FileObject onlyFiles)
    {
        if (next != null)
        {
            next.appendFiles(onlyFiles);
        }
        else
        {
            next = onlyFiles;
        }
    }
    public void display()
    {
        Console.WriteLine( directoryValue + " " + name);
        if (next != null)
        {
            next.display();
        }
    }

    public void resetAll ()
    {
        alreadyRecorded = false;
        if (next != null)
        {
            next.resetAll();
        }
    }

    public string getNextValue()
    {
        if (next != null)
        {
            if (!next.alreadyRecorded)
            {
                return next.getNextValue();
            }
        }
        alreadyRecorded = true;
        return (directoryValue + " " + value + " " + name);

    }

}


