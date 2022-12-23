class DirectoryList
{
    string dir;
    long value;
    DirectoryList next;
    
    public  DirectoryList() 
    {
        dir = "/";
        next = null;
    }

    public DirectoryList (string dir, long value)
    {
        this.dir = dir;
        this.value = value;
        next = null; 
    }

    public void cd(string variable)
    {
        if (variable == "/")
        {
            next = null;
        }
        if (variable == "..")
        {
            if (next != null )
            {
                if (next.next == null)
                {
                    next = null;
                }
                else
                {
                    next.cd(variable);
                }
            }
        }
        else if (next != null)
        {
            next.cd(variable);
        }
        else
        {
            dir = variable;
        }
    }
    public string getWorkingDirectory()
    {
        if (next != null)
        {
            return next.getWorkingDirectory();
        }
        else
        {
            return dir;
        }
    }

   
    public void addValue (string directory,long Value )
    {
        if ( dir == directory)
        {
            this.value = this.value + Value;
        }
        else
        {
            if (next != null)
            {
                next.addValue(directory,Value);
            }
            else
            {
             
                next = new DirectoryList(directory,Value);
            }
        }
    }
  
    public void printAll()
    {
        Console.WriteLine(dir + " " + value);
        if (next != null)
        {
            next.printAll();
        }
    }

    public long getValueAtAddress(string inputValue)
    {
        if (inputValue == dir)
        {
            return value;
        }
        if (next != null)
        {
            return next.getValueAtAddress(inputValue);
        }
        return 0;
    }
    public long getSumUnder(int maxValue)
    {
        long sumNow = 0;
        if (value <= maxValue)
        {
            sumNow = value;
            Console.WriteLine("DirectoryList.cs 109 -> " + value);
        }
        if (next == null)
        {
            return sumNow;
        }
        return sumNow + next.getSumUnder(maxValue);  
    }
    

}

