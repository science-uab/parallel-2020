using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace grafica
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            Thread firgalben=new Thread(()=> deseneaza(Color.Yellow, 150,100));
            Thread firgrilight=new Thread(()=> deseneaza(Color.LightGray, 100, 150));
            Thread firrosu=new Thread(()=> deseneaza(Color.Red, 151, 151));
            Thread firroz=new Thread(()=> deseneaza(Color.Pink, 99, 99));

            firgalben.Start();
            firgrilight.Start();
            firrosu.Start();
            firroz.Start();
        }

        private void deseneaza(Color culoare, Int16 Rx, Int16 Ry)
        {
            Graphics g = pictureBox1.CreateGraphics();
            Pen creion = new Pen(culoare);
            Pen guma = new Pen(Color.Navy);
            int x, y;
            double unghi;
            for (unghi = -3.14; unghi <= 3.14; unghi+=0.02)
            {
                x = (int)(225 + Rx * Math.Cos(unghi));
                y = (int)(225 + Ry * Math.Sin(unghi));
                g.DrawRectangle(creion, x, y, 3, 3);
                Thread.Sleep(5);
                //g.DrawRectangle(guma, x, y, 2, 2);
            }
         }
    }
}
