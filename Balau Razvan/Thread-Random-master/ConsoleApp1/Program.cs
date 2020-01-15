using System;
using System.Threading;

namespace ConsoleApp1
{
    class Program
    {
        public static int sum = 0;
        public static void Proces1()
        {
            
                Random nr = new Random();
                int pr = nr.Next(1, 49);
                sum = sum + pr;
        
                
                    Console.WriteLine("Numar randon este: {0}", pr);     
            
        }
        static void Main(string[] args)
        {

            Console.WriteLine("Incepe primul Thread: ");
            Thread t1 = new Thread(new ThreadStart(Proces1));
            t1.Priority = ThreadPriority.Lowest;
            t1.Start();
            Console.WriteLine("Firul1 este = {0}", t1.ThreadState);
            
            Thread t2 = new Thread(new ThreadStart(Proces1));
            t2.Priority = ThreadPriority.Normal;
            t2.Start();
            Console.WriteLine("Firul1 este= {0}", t1.ThreadState);
            Console.WriteLine("Firul2 este = {0}", t2.ThreadState);

            Thread t3 = new Thread(new ThreadStart(Proces1));
            t3.Priority = ThreadPriority.Normal;
            t3.Start();
            Console.WriteLine("Firul2 este = {0}", t2.ThreadState);
            Console.WriteLine("Firul3 este = {0}", t3.ThreadState);
            t1.Join();
            t2.Join();
            t3.Join();
            Console.WriteLine("Suma numerelor este: {0}", sum);
            Console.WriteLine("Firul3 este = {0}", t3.ThreadState);
            Console.ReadLine();
        }
    }
}
