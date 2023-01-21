using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day_13___Distress_Signal
{
    internal class Packet
    {
        int leftNumbericValue, rightNumbericValue;
        public List <string> left, right;
        int leftValue, rightValue;
        bool lastWasClosedBracket, lastWasOpenBracket;

        // PACKET CONSTRUCTOR
        public Packet(string metadata)
        {
            left = new List <string> ();
            right = new List <string> ();
            lastWasClosedBracket = lastWasOpenBracket = false;
            foreach (char leftChar in metadata.Split("\n")[0]) {
                fillInformation(true, leftChar);   
            }
            foreach (char rightChar in metadata.Split("\n")[1])
            {
                fillInformation(false, rightChar);
            }
            printVariablesToTest(metadata);
        }

        protected void printVariablesToTest (string metaData)
        {
            Console.WriteLine (metaData);
            foreach (string w in left)
            {
                Console.Write(" " + w);
            }
            Console.WriteLine ();
            foreach (string w in right)
            {
                Console.Write(" " + w);
            }
            Console.WriteLine();
        }
        // INPUT ALL INFORMATION INTO LIST FOR LATER USE
        private void fillInformation (bool LeftTrueRightFalse, char item)
        {
            void addData(bool isLeft, String data)
            {
                if (isLeft)
                {
                    if (data == null) { data = leftValue.ToString(); leftValue = 0; }
                    left.Add(data);
                }
                else
                {
                    if (data == null) { data = rightValue.ToString(); rightValue = 0; }
                    right.Add(data);
                }
            }
            string addThis;
            switch (item)
            {
                case '[':
                    {
                        addData(LeftTrueRightFalse, "[");
                        break;
                    }
                case ']':
                    {
                        if (!lastWasClosedBracket && !lastWasOpenBracket)
                        {
                            addData(LeftTrueRightFalse, null);
                        }
                        
                        addData(LeftTrueRightFalse, "]");
                        break;
                    }
                case ',':
                    {
                        if (lastWasClosedBracket)
                        {
                            lastWasClosedBracket = true;
                        }
                        else
                        {
                            addData(LeftTrueRightFalse, null);
                        }
                        break;
                    }

                default :
                    { 
                        if (LeftTrueRightFalse)
                        {
                            leftValue = leftValue * 10;
                            leftValue = leftValue + (int)item - 48;
                        }
                        else
                        {
                            rightValue = rightValue * 10;
                            rightValue = rightValue + (int)item - 48;
                        }
                        break;
                    }
            }
            lastWasClosedBracket = (item == ']');
            lastWasOpenBracket = (item == '[');
           

        }
        // IS THIS IN THE RIGHT ORDER?
        
        public bool inRightOrder ()
        {
            leftNumbericValue = rightNumbericValue = 0;

            void getNextValueForBoth()
            {

            }

            return true;
        }
        // IS THIS A NUMBER?
        private bool isNumber (string testString)
        {
            foreach (char c in testString.ToCharArray())
            {
                if ((int) c < 48  || (int)c > 58)
                {
                    return false;
                }
            }
            return true;

        }

       
        

    }
}
