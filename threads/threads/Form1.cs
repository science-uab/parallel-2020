using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.Media;

namespace threads
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Random any;
        public static Thread fir1;
        public static Thread fir2;
        public static SoundPlayer tobe;
        public static int i;
        public static int j;

        private void button1_Click(object sender, EventArgs e)
        {
            fir1 = new Thread(t =>
            {
                for (i = 0; i < 100; i++)
                {
                    int a = any.Next(100, 600);
                    int b = any.Next(150, 400);
                    this.CreateGraphics().FillRectangle(Brushes.Lime, a, b, 10, 10);
                    Thread.Sleep(500);
                }
            }) { IsBackground = true };
            fir1.Start();
            button1.Enabled = false;
            button1.BackColor = Color.LightGray;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            any = new Random();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            fir2 = new Thread(t =>
            {
                for (j = 0; j < 100; j++)
                {
                    int a = any.Next(100, 600);
                    int b = any.Next(150, 400);
                    this.CreateGraphics().FillEllipse(Brushes.Red, a, b, 10, 10);
                    Thread.Sleep(500);
                }
            }) { IsBackground = true };
            fir2.Start();
            button2.Enabled = false;
            button2.BackColor = Color.LightGray;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            tobe = new SoundPlayer("C:/Users/Denis/Desktop/Gabi/toba.wav");//link-ul exact catre fisierul care
            //trebuie obligatoriu sa fie de tip .wav (nu functioneaza mp3 sau alt format)(dupa copierea link-ului, de
            //inlocuit backslash-ul cu slash
            tobe.PlayLooping();
            button3.Enabled = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            fir1.Abort();
            button1.Enabled = true;
            button1.BackColor = Color.Lime;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            fir2.Abort();
            button2.Enabled = true;
            button2.BackColor = Color.Red;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            tobe.Stop();
            button3.Enabled = true;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
