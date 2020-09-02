using System;
using System.Threading;

namespace Thread_Rendezvous_3
{
    class MainClass
    {
        //clasa Barrier stabileste numarul de thread-uri ce se vor sincroniza
        //constructorul afiseaza dupa fiecare iteratie rand nou si mesajul ***
        public static Barrier barrier = new Barrier(3, barrier => { Console.WriteLine("Thread-uri sincronizate, mergem mai departe."); Console.WriteLine(); });


        //afisam in consola numerele de la 0 la 9
        public static void Munceste()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.Write(i + " ");

                // rendezvous cu celelalte thread-uri
                //semnalizeaza si asteapta sincronizarea cu celelalte thread-uri
                
                barrier.SignalAndWait();
                
            }
            
            
        }

        public static void Main(string[] args)
        {
            // start thread-uri
            new Thread(Munceste).Start();
            new Thread(Munceste).Start();
            new Thread(Munceste).Start();
            Console.Read();
        }
    }
}