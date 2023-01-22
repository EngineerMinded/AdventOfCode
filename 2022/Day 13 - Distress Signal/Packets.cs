
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
        int pointOfFailure;

        // PACKET CONSTRUCTOR
        public Packet(string metadata)
        {
            pointOfFailure = -1;
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
            printVariablesToTest(" ");
            Console.WriteLine();
        }

        protected void printVariablesToTest (string metaData)
        {
            int count = 0;
            Console.WriteLine (metaData);
            foreach (string w in left)
            {
                Console.ForegroundColor = ConsoleColor.White;
                if (pointOfFailure == count)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                }
                Console.Write(" " + w);
                count++;
            }
            Console.WriteLine ();
            count = 0;
            foreach (string w in right)
            {
                Console.ForegroundColor = ConsoleColor.White;
                if (pointOfFailure == count)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                }
                Console.Write(" " + w);
                count++;
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
            if ((lPosition == left.Count) || (rPosition == right.Count))
            {
                return true;
            }
            //Console.WriteLine("Check : " + left.ElementAt(lPosition) + " " + right.ElementAt(rPosition));
            if (left.ElementAt(lPosition) == right.ElementAt(rPosition))
            {
                return _isInRightOrder(lPosition + 1, rPosition + 1);
            }
            else
            {
                if (left.ElementAt(lPosition) == "[")
                {
                    if (right.ElementAt(rPosition) == "]")
                    {
                        pointOfFailure = lPosition;
                        return false;
                    }
                    if ((left.ElementAt(rPosition + 1) != "]")) 
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
                else if ((right.ElementAt(rPosition) == "[") )
                {
                    if (left.ElementAt(rPosition) == "]")
                    {
                        return true;
                    }
                    if ((right.ElementAt(rPosition + 1) != "]")) 
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
                else if (left.ElementAt(lPosition) == "]")
                {
                    return true;
                }
                else if (right.ElementAt(rPosition) == "]")
                {
                    pointOfFailure = rPosition;
                    return false;
                }
                else
                {
                    if (int.Parse(left.ElementAt(lPosition)) < (int.Parse(right.ElementAt(rPosition))))
                    {
                        return true;
                    }
                    else
                    {
                        pointOfFailure = lPosition;
                        return false;
                    }
                }
            }
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
