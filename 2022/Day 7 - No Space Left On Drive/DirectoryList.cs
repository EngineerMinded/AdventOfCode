class DirectoryList
{
    string dir;
    int value;
    DirectoryList next;

    public  DirectoryList() 
    {
        dir = "/";
        next = null;
    }

    public DirectoryList (string dir, int value)
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

   
    public void addValue (string directory,int Value )
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
                next = new DirectoryList(dir,value);
            }
        }
    }
    public void addValue (string directory, String fromDirectory ,DirectoryList getInfo)
    {
        if (dir == directory )
        {
            if (getInfo.dir == fromDirectory)
            {
                this.value = this.value + getInfo.value;
            }
            else
            {
                if (getInfo.next != null)
                {
                    addValue(directory,fromDirectory,getInfo.next);
                }
            }
        }
        else
        {
            if (next != null)
            {
                next.addValue (directory,fromDirectory,getInfo);
            }
            else
            {
                next = new DirectoryList(directory, value);
            }
        }
    }
    void printAll()
    {
        Console.WriteLine(dir + " " + value);
        if (next != null)
        {
            next.printAll();
        }
    }
}

