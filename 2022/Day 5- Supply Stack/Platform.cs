public class Container
{
    private string value;
    private Container next;
    public bool isEmpty;
    private bool alreadyRecorded;

    public Container()
    {
        value = "_";
        next = null;
        isEmpty = true;
    }
    public Container(string v)
    {
        value = v;
        next = null;
    }
    public void push(string v)
    {
        if (value == "_")
        {
            isEmpty = false;
            this.value = v;
        }
        else if (next != null)
        {
            next.push(v);
        }
        else
        {
            next = new Container(v);
        }
    }
    public void push (Container toPush)
    {
        if (next != null)
        {
            next.push(toPush);
        }
        else
        {
            next = toPush;
        }
    }
    public string pop()
    {
        if (next == null)
        {
            string returnThis = value;
            value = "_";
            isEmpty = true;
            return returnThis;
        }
        else if (next.next == null) 
        {
            string returnThis = next.value;
            next = null;
            return returnThis; 
        }
        else
        {
            return next.popBeyondFirst();
        }
    }
    public Container pop(int numbertoget)
    {
        Container subContainer = new Container();
        String[] properOrientation = new String[numbertoget];

        for (int i = 0; i < numbertoget; i++)
        {
            properOrientation[i] = pop();
        }
        for (int i = numbertoget - 1; i >= 0; i--)
        {
            subContainer.push(properOrientation[i]);
        }
        return subContainer;
    }
    private string popBeyondFirst()
    {
        if (next.next == null)
        {
            string returnThis = next.value;
            next = null;
            return returnThis;
        }
        else
        {
            return next.popBeyondFirst();
        }
    }
    public void display ()
    {
        Console.WriteLine(value);
        if (next != null)
        {
            next.display();
        }
    }
    public int getPileSize()
    {
        if (next == null)
        {
            return (value.Split(" ").Length);
        }
        else
        {
            return next.getPileSize();
        }
    }
    public String peek()
    {
        if (next != null)
        {
            return next.peek();
        }
        else
        {
            return value;
        }
    }
    public String record()
    {
        if (!(alreadyRecorded))
        {
            alreadyRecorded = true;
            return value;
        }
        else if (next != null)
        {
            return next.record();
        }
        else
        {
            return ("END");
        }
    }
    public void resetRecord()
    {
        alreadyRecorded = false;
        if (next != null)
        {
            next.resetRecord();
        }
    }
}

public class Platform
{
    int value;
    public Container container;
    Platform next;

    public Platform (int v)
    {
        value = 1;
        container = new Container();
        if (v > 1)
        {
            next = new Platform(value + 1, v);
        }
        else
        {
            next = null;
        }
    }
    private Platform (int v, int limit)
    {
        this.value =v;
        container = new Container();
        if (v < limit)
        {
            next = new Platform (v + 1, limit);
        }
        else
        {
            next = null;
        }
    }
    public String from (int value)
    {
        if (this.value == value)
        {
            return container.pop();
        }
        else if (next != null)
        {
            return next.from(value);
        }
        else
        {
            Console.WriteLine("Value to pull from doesn't exist");
            return "0";
        }
    }
    public void to(int value, string data)
    {
        if (this.value == value)
        {
            container.push(data);
        }
        else if (next != null)
        {
            next.to(value,data);
        }
        else
        {
            Console.WriteLine("Value to go to doesn't exist");
        }
    }
    public Container from (int v, int amount)
    {
        if (v == value)
        {
            Container subcontainer = container.pop(amount);
            return subcontainer;
        } 
        else
        {
            return next.from(v, amount);
        }
    }
    public void to  (int v, Container c)
    {
        if (value == v)
        {
            container.push(c);
        }
        else
        {
            next.to(v, c);
        }
    }
    public void display()
    {
        Console.Write (value + "____\n");
        container.display ();
        if (next != null)
        {
            next.display();
        }
    }
    public String getPartOneAnswer ()
    {
       if (next != null)
        {
            return container.peek() + next.getPartOneAnswer();
        }
       else
        {
            return container.peek();    
        }
    }
    public void reset()
    {
        container.resetRecord();
        if (next != null)
        {
            next.reset();
        }
    }
}