using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MultiThread
{
    public partial class Form1 : Form
    {
        public Form1()
        {
           // Initializare
            InitializeComponent();
        }
        // Definim Variable pentru Random si pentru treduri

        Random butonrosu;
        Random rdm;
        
        Thread th1;
        Thread th2;
        Thread th3;
        

        private void Form1_Load(object sender, EventArgs e)
        {
              butonrosu = new Random();
             rdm = new Random();

        }

        private void btnThread1_Click(object sender, EventArgs e)
        {
            //Incepe nou thread
            Thread thread = new Thread(t =>
            {
                for (int i = 0; i < 100; i++)
                {
                    //deseneaza cerc
                    int width = butonrosu.Next(0, this.Width);
                    int height = butonrosu.Next(50, this.Height);
                    this.CreateGraphics().DrawEllipse(new Pen(Brushes.Red, 1), new Rectangle(width, height, 20, 20));
                   
                    Thread.Sleep(100);
                }
            })
            { IsBackground = true };
            thread.Start();
        }
 
        private void btnThread2_Click(object sender, EventArgs e)
        {
            //https://docs.microsoft.com/en-us/dotnet/api/system.drawing.graphics.drawellipse?view=netframework-4.8
            //Incepe nou thread
            Thread thread = new Thread(t =>
            {
                for (int i = 0; i < 100; i++)
                {
                    // deseneaza cerc sau elipsa
                    int width = butonrosu.Next(0, this.Width);
                    int height = butonrosu.Next(50, this.Height);
                    this.CreateGraphics().DrawEllipse(new Pen(Brushes.Blue, 1), new Rectangle(width, height, 20, 20));
                    //Delay
                    Thread.Sleep(100);
                }
            })
            { IsBackground = true };
              thread.Start();
          //  MessageBox.Show("Thread-ul a terminat ciclul, complet negru");
 
        }

        private void button1_Click(object sender, EventArgs e)
        {
            th2 = new Thread(thread);
            th2.Start();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            th1 = new Thread(threadb);
            th1.Start();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            th3 = new Thread(threadp);
            th3.Start();
        }
        public void threadp()
        //https://docs.microsoft.com/en-us/dotnet/api/system.drawing.graphics.drawrectangle?view=netframework-4.8
        {
            for (int i = 0; i < 100; i++)
            {
                //deseneaza dreptunghi
                this.CreateGraphics().DrawRectangle(new Pen(Brushes.Pink, 9), new Rectangle(rdm.Next(0, this.Width), rdm.Next(0, this.Height), 15, 40)); ;
                Thread.Sleep(100);

            }
           MessageBox.Show("100 figuri Roz");

        }
        public void thread()
        {
            for (int i = 0; i < 100; i++)
            {
                //desenare patrat
                this.CreateGraphics().DrawRectangle(new Pen(Brushes.Black, 4), new Rectangle(rdm.Next(0, this.Width), rdm.Next(0, this.Height), 20, 20)); ;
                Thread.Sleep(100);
            }
            MessageBox.Show("Thread-ul a terminat ciclul, complet negru");
        }
        public void threadb()
        {
            for (int i = 0; i < 100; i++)
            {
                //patrat
                this.CreateGraphics().DrawRectangle(new Pen(Brushes.Green, 4), new Rectangle(rdm.Next(0, this.Width), rdm.Next(0, this.Height), 20, 20));
                Thread.Sleep(100);
            }
            //mesaj de afisare 
            MessageBox.Show("Thread-ul a terminat ciclul, complet verde");
        }

        private void stop_Click(object sender, EventArgs e)
        {
            //buton pentru exit
            if (MessageBox.Show("Se va inchide tot programul. Confirmi?", "Inchidere Program", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                MessageBox.Show("Programul se va inchide.", "Program inchis!", MessageBoxButtons.OK);
                System.Windows.Forms.Application.Exit();
            }
            else
            {
                this.Activate();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //repornire program
            if (MessageBox.Show("Repornire program. Confirmi?", "REPORNIRE", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                MessageBox.Show("Programul va reporni in cateva momente.", "Program repornit!", MessageBoxButtons.OK);
                System.Windows.Forms.Application.Restart();
            }
            else
            {
                this.Activate();
            }
        }

        public void button5_Click(object sender, EventArgs e)
        {
            //https://www.experts-exchange.com/questions/23839339/Switching-between-Forms-in-C.html schmbare form
            //deschide form 3 si ascude form 1
            Form3 temp = new Form3();
            temp.Region = this.Region;
            temp.Show();
            this.Hide();
        }
    } 
}
//https://www.pluralsight.com/guides/how-to-write-your-first-multi-threaded-application-with-c documentare

//https://www.c-sharpcorner.com/article/understanding-multithreading-and-multitasking-in-c-sharp/ exemplu de thread
//http://marvinproject.sourceforge.net/en/tutorials/03_multithreading/multithreading.html informatii
//https://foxlearn.com/articles/multi-threading-in-csharp.html citire 202
