using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day10
{
    internal class Trail
    {
        int x, y, value, prevX,prevY;
        Trail next;

        public Trail(int x, int y)
        {
            this.x = x; this.y = y; prevX = x; prevY = y; value = 0; next = null;
        }

        public void add (int xx, int yy)
        {
            if (next == null)
            {
                next = new Trail(xx, yy);
                next.value = value + 1;
                next.prevX = x;
                next.prevY = y;
            }
        }
        public int getLastX() 
        {
            if (next == null)
            {
                return x;
            }
            return next.getLastX();
        }
        public int getLastY()
        {
            if (next == null)
            {
                return y;
            }
            return next.getLastY();
        }

        public int getHighestValue()
        {
            if (next == null) { return value; }
            return next.getHighestValue();
        }

        public void printAll()
        {
            Console.WriteLine(x  + "," + y + "->"  + value);
            if (next != null)
            {
                next.printAll();
            }
        }

        public void getNextDirection(char[,] map)
        {
            if (next != null)
            {
                next.getNextDirection(map);
            }
            else
            {
                switch (map[x, y])
                {
                    case '|':
                        {
                            if (prevX == x - 1)
                            {
                                add(x + 1, y);
                            }
                            else
                            {
                                add(x - 1, y);
                            }
                            break;
                        }
                    case 'F':
                        {
                            if (prevX == x + 1)
                            {
                                add(x, y + 1);
                            }
                            else
                            {
                                add(x + 1, y);
                            }
                            break;
                        }
                    case '7':
                        {
                            if (prevX == x + 1)
                            {
                                add(x, y - 1);
                            }
                            else
                            {
                                add(x + 1, y);
                            }
                            break;
                        }
                    case 'L':
                        {
                            if (prevX == x - 1)
                            {
                                add(x, y + 1);
                            }
                            else
                            {
                                add(x - 1, y);
                            }
                            break;
                        }
                    case '-':
                        {
                            if (prevY == y - 1)
                            {
                                add(x, y + 1);
                            }
                            else
                            {
                                add(x, y - 1);
                            }
                            break;
                        }
                    case 'J':
                        {
                            if (prevY == y - 1)
                            {
                                add(x - 1, y);
                            }
                            else
                            {
                                add(x, y - 1);
                            }
                            break;
                        }
                    default:
                        {

                            break;
                        }
                }
            }
        }
    }

}
