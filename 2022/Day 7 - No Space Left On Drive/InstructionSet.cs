/****************************************************************
 * Wayne Mack                                                   *
 * Advent Of Code 2020 - Day 7:                                 *
 * No space Left on Device                                      *
 * ------------------------------------------------------------ *
 * Written in C#                                                *
 * InstructionSet.cs                                            *
 * **************************************************************/
 /***************************************************************
  * InstructionSet as you may guess simple holds the            *
  * instructions. These instructions will be parsed in the      *
  * FileObjects class as an declare variable.                   *
  ***************************************************************/
class InstructionSet
{
    string data;
    InstructionSet Next;
    bool read;
    public InstructionSet ()
    {
        data = null;
        Next = null;
        read = false;
    }
    public void append(string dataInput)
    {
        if (data == null)
        {
            this.data = dataInput;
        }
        else if (Next == null)
        {
            Next = new InstructionSet ();
            Next.data = dataInput;
        }
        else
        {
            Next.append (dataInput);
        }
    }
    public String getNext()
    {
        if (!read)
        {
            read = true;
            return data;
        }
        else if ( Next != null)
        {
            return Next.getNext();
        }
        return "$ end";
    }
    public String peek()
    {
        if (!read)
        {
            return data;
        }
        else if (Next != null)
        {
            return Next.peek();
        }
        return "$ end";
    }
    public void Unread()
    {
        read = true;
        if (Next != null)
        {
            Next.Unread();
        }
    }
    public void PrintAll()
    {
        Console.WriteLine(data);
        if (Next != null)
        {
            Next.PrintAll();
        }
    }
}
