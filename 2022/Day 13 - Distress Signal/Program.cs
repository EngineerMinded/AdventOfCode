using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day_13___Distress_Signal
{
    internal class Program
    {
        static List<Packet> packets;
        static string fileName = "Day13Data.txt";
        static bool test = true;

        static void Main (string[] args)
        {
            packets = new List<Packet> ();
            if (test)
            {
                fileName = "Day13Example.txt";
            }
            // GET INFORMATION FROM FILE AND PUT IN PACKET LIST
            foreach (string data in File.ReadAllText(fileName).Split("\r\n\r\n"))
            {
                packets.Add(new Packet(data));
            }   
        }
    }
}