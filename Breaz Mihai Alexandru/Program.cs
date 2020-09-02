using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ConsoleApp2
{
    class Program
    {

        public static void Main(string[] args)
        {
            Thread fir1 = new Thread(new ThreadStart(Numara1));
            Thread fir2 = new Thread(new ThreadStart(Numara2));
            Thread fir3 = new Thread(new ThreadStart(Numara3));
            Thread fir4 = new Thread(new ThreadStart(Numara4));
            fir1.Start();
            fir2.Start();
            fir3.Start();
            fir4.Start();

            Console.ReadLine();
        }

        static void Numara1()
        {
            for (int i = 1; i <= 10; i++)
            {
                Thread.Sleep(1001);
                Console.WriteLine("Numar fir1 : " + i);
            }
            Console.WriteLine("Firul 1 a terminat de numarat.");
        }
        static void Numara2()
        {
            for (int i = 1; i <= 15; i++)
            {
                Thread.Sleep(1002);
                Console.WriteLine("Numar fir2 : " + i);
            }
            Console.WriteLine("Firul 2 a terminat de numarat.");
        }
        static void Numara3()
        {
            for (int i = 1; i <= 20; i++)
            {
                Thread.Sleep(1003);
                Console.WriteLine("Numar fir3 : " + i);
            }
            Console.WriteLine("Firul 3 a terminat de numarat.");
        }
        static void Numara4()
        {
            for (int i = 1; i <= 25; i++)
            {
                Thread.Sleep(1005);
                Console.WriteLine("Numar fir4 : " + i);
            }
            Console.WriteLine("Firul 4 a terminat de numarat.");
        }

    }
}
