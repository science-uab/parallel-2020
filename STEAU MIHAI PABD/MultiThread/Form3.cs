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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }
        //Random rdm;
        Random randomblue;
        Random randomgreen;
        Random culoare;
        Thread thgold;

       
         private void Form3_Load(object sender, EventArgs e)
        {
            
                randomblue = new Random();
                randomgreen = new Random();
                culoare = new Random();

            
        }
        private void button10_Click(object sender, EventArgs e)
        {
            Form1 temp1 = new Form1();
            temp1.Region = this.Region;
            temp1.Show();
            this.Hide();
        }



        private void button2_Click(object sender, EventArgs e)
        {
            //Start new thread
            Thread thread = new Thread(t =>
            {
                for (int i = 0; i < 100; i++)
                {
                    int width = randomblue.Next(0, this.Width);
                    int height = randomblue.Next(50, this.Height);
                    this.CreateGraphics().DrawEllipse(new Pen(Brushes.Blue, 7), new Rectangle(width, height, 40, 40));
                    //Delay
                    Thread.Sleep(100);
                }
            })
            { IsBackground = true };
            thread.Start();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //Start new thread
            Thread thread = new Thread(t =>
            {
                for (int i = 0; i < 100; i++)
                {
                    int width = randomgreen.Next(0, this.Width);
                    int height = randomgreen.Next(50, this.Height);
                    this.CreateGraphics().DrawEllipse(new Pen(Brushes.Green, 3), new Rectangle(width, height, 30, 30));
                    //Delay
                    Thread.Sleep(100);
                }
            })
            { IsBackground = true };
            thread.Start();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            thgold = new Thread(thculoare);
            thgold.Start();
        } 
        public void thculoare()
        {
            for (int i = 0; i < 100; i++)
            {
                //desenare patrat
                this.CreateGraphics().DrawRectangle(new Pen(Brushes.Gold, 4), new Rectangle(culoare.Next(0, this.Width), culoare.Next(0, this.Height), 60, 60)); ;
                Thread.Sleep(100);
            }
            MessageBox.Show("Thread-ul a terminat ciclul, complet auriu");

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //buton pentru exit
            if (MessageBox.Show("Se va inchide tot programul. Confirm?", "Inchidere Program", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                MessageBox.Show("Programul se va inchide.", "Program inchis!", MessageBoxButtons.OK);
                System.Windows.Forms.Application.Exit();
            }
            else
            {
                this.Activate();
            }
        }
    }
}
