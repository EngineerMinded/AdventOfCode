/*******************************************
 * Wayne Mack                              *
 * Advent of Code 2022 - Day 2             *
 * Written in: C#                          *
 * Rock Paper Scissors object class        *
 *******************************************/

using System;
namespace Day2_AOC_2022
{
    public enum SELECTION { A, B, C, X, Y, Z };
    public class RockPaperScissors
    {
        public Node root;
        public void add(SELECTION t, SELECTION u)
        {
            if (root == null)
            {
                root = new Node(u, t);
            }
            else
            {
                root.add(u, t);
            }
        }
        public void printData()
        {
            root.printData();
        }
        public int getTotal()
        {
            return root.getTotal();
        }
    }
    public class Node
    {
        SELECTION you;
        SELECTION them;
        int points;
        Node next;

        public Node(SELECTION t, SELECTION u) 
        {
            this.you = u;
            this.them = t;
            next = null;
            points = assignPoints();
        }
        public void add(SELECTION t, SELECTION u)
        {
            if (next != null)
            {
                next.add(t, u);
            }
            else
            {
                next = new Node(t,u);
            }
        }
        private int assignPoints()
        {
            /* Scoring Criteria:
            * 1 - Rock
            * 2 - Paper
            * 3 - Scissors
            * PLUS:
            * 0 - Lost
            * 3 - Draw
            * 6 - Won
            */
            int score = 0;
            switch (you)
            {
                case SELECTION.X:
                    {
                        score = score + 1;
                        if (them == SELECTION.A)
                        {
                            score = score + 3;
                        }
                        else if (them == SELECTION.C)
                        {
                            score = score + 6;
                        }
                        break;
                    }
                    
                case SELECTION.Y:
                    {
                        score = score + 2;
                        if (them == SELECTION.B)
                        {
                            score = score + 3;
                        }
                        else if (them == SELECTION.A)
                        {
                            score = score + 6;
                        }
                        break;
                    }      
                case SELECTION.Z:
                    {
                        score = score + 3;
                        if (them == SELECTION.C)
                        {
                            score = score + 3;
                        }
                        else if (them == SELECTION.B)
                        {
                            score = score + 6;
                        }
                        break;
                    }       
            }
            return score;
        }
        public int getPoints()
        {
            return points;
        }
        public void printData()
        {
            Console.WriteLine(you + " " + them + " " + points);
            if (!(next == null)) {
                next.printData();
            }
        }
        public int getTotal ()
        {
            if (next != null)
            {
                return points + next.getTotal();
            }
            else
            {
                return points;
            }
        }
        public int secondPredeterminiteValue ()
        {
            int score = 0;
            /* 'Them' value will be substituted as winning determinite
             *
             * X - You must lose at losing value
             * 
             * Y - You must tie at same value
             * 
             * Z - You must win at winning value */

            if (you == SELECTION.X)
            {
                switch (them)
                {
                    case SELECTION.A:
                        {
                            score = score + 3;
                            break;
                        }
                    case SELECTION.B:
                        {
                            score = score + 1;
                            break;
                        }
                    default:
                        {
                            score = score + 2;
                            break;
                        }
                }
            }
            else if (you == SELECTION.Y)
            {
                score = score + 3;
                switch (them)
                {
                    case SELECTION.A:
                        {
                            score = score + 1;
                            break;
                        }
                    case SELECTION.B:
                        {
                            score = score + 2;
                            break;
                        }
                    default:
                        {
                            score = score + 3;
                            break;
                        }
                }
            }
            else if (you == SELECTION.Z)
            {
                score = score + 6;
                switch (them)
                {
                    case SELECTION.A:
                        {
                            score = score + 2;
                            break;
                        }
                    case SELECTION.B:
                        {
                            score = score + 3;
                            break;
                        }
                    default:
                        {
                            score = score + 1;
                            break;
                        }
                }
            }
            if (next == null)
            {
                return score;
            }
            else
            {
                return score + next.secondPredeterminiteValue();
            } 
        }
    }
}
