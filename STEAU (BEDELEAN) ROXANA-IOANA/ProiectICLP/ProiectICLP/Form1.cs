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

namespace ProiectICLP
{
    public partial class Form1 : Form
    {
        public static ManualResetEvent clientReady = new ManualResetEvent(false);
        public static ManualResetEvent liftReady = new ManualResetEvent(true);
        public static ManualResetEvent sincron = new ManualResetEvent(false);
        public static Desenare client, lift;

        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            client = new Desenare(this, 100, 100, 10, Color.Red);
            lift = new Desenare(this, 200, 0, 10, Color.Red);
            Thread tclient = new Thread(new ThreadStart(client.miscareClient));
            Thread tlift = new Thread(new ThreadStart(lift.miscareLift));
            Thread tsincron = new Thread(new ThreadStart(Desenare.mersSincron));
            tclient.Start();
            tlift.Start();
            tsincron.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            SolidBrush brush = new SolidBrush(client.getColor());
            e.Graphics.FillEllipse(brush, client.getPX(), client.getPY(), client.getSize(), client.getSize());
            e.Graphics.FillRectangle(brush, lift.getPX(), lift.getPY(), lift.getSize(), lift.getSize());
            brush.Dispose();
        }

        public class Desenare
        {
            int px = 0;
            int py = 10;
            int size = 0;
            Color color;
            Form1 parent = null;
            public void paint()
            {
                Thread.Sleep(20);
                parent.Refresh();
            }


            public Desenare(Form1 parent, int px, int py, int size, Color color)
            {
                this.parent = parent;
                this.px = px;
                this.py = py;
                this.size = size;
                this.color = color;
            }
            public int getPX()
            {
                return px;
            }
            public int getPY()
            {
                return py;
            }
            public int getSize()
            {
                return size;
            }
            public Color getColor()
            {
                return color;
            }
            public void miscareClient()
            {
                Form1.liftReady.WaitOne();
              
                while (this.px < 200)
                {
                    px = px + 1;
                    paint();
                }
                Form1.clientReady.Set();
               
            }

            public void miscareLift()
            {
                Form1.clientReady.WaitOne();
               
                while (this.py < 100)
                {
                    py = py + 1;
                    paint();
                }
                Form1.liftReady.Set();
                Form1.sincron.Set();
              

            }

            public static void mersSincron()
            {
                Form1.sincron.WaitOne();
                while (Form1.client.py <= 300)
                {
                    Form1.client.py++;
                    Form1.lift.py++;
                    Form1.client.paint();
                }
            }
        }
    }
}
