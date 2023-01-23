/*********************************************
 * Wayne Mack                                *
 * Advent of Code - Day 5                    *
 * Supply Stacks                             *
 * Written in C#                             *
 * ----------------------------------------- *
 * Container and Platform class              *
 *********************************************/


// The container class is a modified stack used for the data and the containers itself
public class Container
{
    private string value;
    private Container next;
    public bool isEmpty;
    private bool alreadyRecorded;
    
    // Blank Constructor
    public Container()
    {
        value = "_";
        next = null;
        isEmpty = true;
    }
    // New Reference constructor
    public Container(string v)
    {
        value = v;
        next = null;
    }
    // Push data into the stack
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
    // Push multiple Containers into a stack
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
    // Pop data from the stack
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
    // Pop a number of containers from the stack
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
    // Supplemental to popping the stack
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
    // Display values for error cheking
    public void display ()
    {
        Console.WriteLine(value);
        if (next != null)
        {
            next.display();
        }
    }
    // Get the size of the stack
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
    // read the last value of the stack without deleting it (opposite of pop() ).
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
    // This function is used for reading the stack to to bottom. Poppong the stack woul make it read backwards
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
    // Make the stack readable again.
    public void resetRecord()
    {
        alreadyRecorded = false;
        if (next != null)
        {
            next.resetRecord();
        }
    }
}
// Platform is main function that holds all stacks and allows exchhanges of containers between them
public class Platform
{
    int value;
    public Container container;
    Platform next;

    // Initial Constructor
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
    // Supplemental constructor
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
    // Individual data from one stack. to be used with to() function.
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
    // to() function transfering more than one container
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
    // function used in exchange of data from one stack to another
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
    // Transfer more than one container to another stack
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
    // Display all values for error checking
    public void display()
    {
        Console.Write (value + "____\n");
        container.display ();
        if (next != null)
        {
            next.display();
        }
    }
    // Read out top most container from each pile to get answer
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
    // reset all values for the stacks so that they can be used again
    public void reset()
    {
        container.resetRecord();
        if (next != null)
        {
            next.reset();
        }
    }
}