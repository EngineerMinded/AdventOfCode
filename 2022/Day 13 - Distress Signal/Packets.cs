
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
            Console.WriteLine(inRightOrder());
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
            return _isInRightOrder(0, 0);
        }
        private bool _isInRightOrder (int lPosition, int rPosition)
        {
            Console.WriteLine("Check : " + left.ElementAt(lPosition) + " " + right.ElementAt(rPosition));
            if (left.ElementAt(lPosition) == right.ElementAt(rPosition))
            {
                return _isInRightOrder(lPosition + 1, rPosition + 1);
            }
            else
            {
                if (left.ElementAt(lPosition) == "[")
                {
                    if ((left.ElementAt(rPosition + 1) != "]") && (right.ElementAt(rPosition) != "]")) 
                    {
                        left.Insert(lPosition, "[");
                        left.Insert(lPosition + 2, "]");
                        return _isInRightOrder(lPosition, rPosition);
                    }
                    else
                    {
                        return _isInRightOrder(lPosition + 1, rPosition + 1);
                    }
                }
                else if ((right.ElementAt(rPosition) == "[") && (right.ElementAt(rPosition) != "]")) 
                {
                    if (right.ElementAt(rPosition + 1) != "]")
                    {
                        right.Insert(rPosition, "[");
                        right.Insert(rPosition + 2, "]");
                        return _isInRightOrder(lPosition, rPosition);
                    }
                    else
                    {
                        return _isInRightOrder(lPosition + 1, rPosition + 1);
                    }
                }
                else if (left.ElementAt(lPosition) == "]")
                {
                    return false;
                }
                else if (right.ElementAt(rPosition) == "]")
                {
                    return true;
                }
                else
                {
                    return (int.Parse(left.ElementAt(lPosition)) > (int.Parse(right.ElementAt(rPosition))));
                }
            }
        }
        private void formatNewBrackets ()
        {

        }
        // IS THIS A NUMBER?
        private bool isNumber(string testString)
        {
            foreach (char c in testString.ToCharArray())
            {
                if ((int)c < 48 || (int)c > 58)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
