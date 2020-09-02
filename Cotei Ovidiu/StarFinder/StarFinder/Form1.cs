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
using System.Drawing.Imaging;

namespace StarFinder
{
    public partial class Form1 : Form
    {
        private int priProcessorCount = Environment.ProcessorCount; // The numbers of processors or cores available in the computer for this application
        private List<Bitmap> prloBitmapList; // The bitmap list
        private List<long> prliOldStarsCount; // The long list with the old star count
        private List<Thread> prloThreadList; //Threads list
        Bitmap proOriginalBitmap; // The original hugeinfrared bitmap portrait

        public Form1()
        {
            InitializeComponent();
        }

        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ __ _ _ _ _ _ _ _ _ _ _
        // NAME: CropBitmap
        // DESC: Ne permite sa obtinem o portiune specifica a unei instante 
        //       Bitmap si sa generam o lista de noi instante Bitmap.
        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        private Bitmap CropBitmap(Bitmap proBitmap, Rectangle proRectangle)
        {
            // Create a new bitmap, copy the portion of the original  defined by proRectangle and keeping its PixelFormat
            Bitmap loCroppedBitmap = proBitmap.Clone(proRectangle, proBitmap.PixelFormat);
            // Return the cropped bitmap
            return loCroppedBitmap;
        }

        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ __ _ _ _ _ _ _ _ _ _ _
        // NAME: IsOldStar
        // DESC: primeste ca parametru o instanta de culaore si returneaza
        //       rezultatele aplicarii regulilor mentionate in nuanta.
        //       Saturatia si luminozitatea acesteia asa cum se evidentiaza
        //       in urmatoarele linii de cod.
        //       Aceasta functie este apelata pentru fiecare pixeldin 
        //       portretul Bitmap si returneaza o valoare booleana.
        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        public bool IsOldStar(Color poPixelColor)
        {
            // Hue between 150 and 258
            // Saturation more than 0.10
            // Brightness more than 0.90
            return ((poPixelColor.GetHue() >= 150) && (poPixelColor.GetHue() <= 258) && (poPixelColor.GetSaturation() >= 0.10) && (poPixelColor.GetBrightness() <= 0.90));
        }

        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ __ _ _ _ _ _ _ _ _ _ _
        // NAME: ThreadOldStarsFinder
        // DESC: Imaginea va fi imaprita in mai multe harti de bit
        //       independente, fiecare portiune va fi atribuita unui thread.
        //       Mai multe threaduri sunt create si pornite asincron,
        //       astfel incat sa stie la ce bitmap apartine.
        //       Threadul rincipal asteapta pana cand toate threadurile
        //       de cautare a stelelor isi termina procesarea, avand un
        //       sleep de 100 milisecunde la fiecare interogare.
        //       Dupa ce toate threadurile isi termina procesarea, threadul
        //       principal reconstruieste bitmapul imaprtit.
        //_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
        private void ThreadOldStarsFinder(object poThreadParameter)
        {
            // Receive the thread number received in poThreadParameter
            int liThreadNumber = (int)poThreadParameter;
            // The pixel matrix (bitmap) row number (Y)
            int liRow;
            // The pixel matrix (bitmap) col number (X)
            int liCol;
            // The pixel color
            Color loPixelColor;
            // Get my bitmap part from the bitmap list
            Bitmap loBitmap = prloBitmapList[liThreadNumber];
            // Reset my old stars counter
            prliOldStarsCount[liThreadNumber] = 0;
            // Interate through each pixel matrix (bitmap) row
            for(liRow = 0; liRow < loBitmap.Height; liRow++)
            {
                // Iterate throucg each pixel matrix (bitmap) cols
                for(liCol = 0; liCol < loBitmap.Width; liCol++)
                {
                    // Get the pixel color for liCol and liRow
                    loPixelColor = loBitmap.GetPixel(liCol, liRow);

                    if(IsOldStar(loPixelColor))
                    {
                        // The color range corresponds to an old star
                        // Change its color to a pure blue
                        loBitmap.SetPixel(liCol, liRow, Color.Blue);
                        // iNCREASE the old stars counter
                        prliOldStarsCount[liThreadNumber]++;
                    }
                }
            }
        }

        private void WaitForThreadsToDie()
        {
            bool lbContinue = true; // A bool Flag
            int liDeadThreads = 0;
            int liThreadNumber;

            while(lbContinue)
            {
                for (liThreadNumber = 0; liThreadNumber < priProcessorCount;liThreadNumber++)
                {
                    if(prloThreadList[liThreadNumber].IsAlive)
                    {
                        // One of the threads is still alive, exit the for loop and sleep 100 miliseconds
                        break;
                    }
                    else
                    {
                        // Increase the dead threads count
                        liDeadThreads++;
                    }
                }

                if(liDeadThreads == priProcessorCount)
                {
                    // All the threads are dead, exit the while loop
                    break;
                }
                Thread.Sleep(100);
                liDeadThreads = 0;
            }
        }

        private void ShowBitmapWithOldStars()
        {
            int liThreadNumber;
            // Each bitmap portion
            Bitmap loBitmap;
            // The starting row in each iteration
            int liStartRow = 0;
            // Calculate each bitmap`s height
            int liEachBitmapHeight = ((int)(proOriginalBitmap.Height / priProcessorCount)) + 1;
            // Create a new bitmap with the whole width and height
            loBitmap = new Bitmap(proOriginalBitmap.Width, proOriginalBitmap.Height);
            Graphics g = Graphics.FromImage((Image)loBitmap);
            g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;

            for (liThreadNumber = 0; liThreadNumber < priProcessorCount; liThreadNumber++)
            {
                // Draw each portion in its coresponding absolute starting row
                g.DrawImage(prloBitmapList[liThreadNumber], 0, liStartRow);
                // Increase the starting row
                liStartRow += liEachBitmapHeight;
            }

            // Show the bitmap in the pictureBox
            picStarsBitmap.Image = loBitmap;
            g.Dispose();
        }

        private void butFindOldStar_Click(object sender, EventArgs e)
        {
            // obtine o instanta bitmap din textbox.
            proOriginalBitmap = new Bitmap(picStarsBitmap.Image);
            int liThreadNumber; // Thread number
            // Create the thread list, the long list and the bitmap list
            // creaza lista thread-urilor lista de numere si lista de biti pentru a le permite sa creasca dinamic la rulare
            // in functie de numarul de nuclee disponibile pe PC
            prloThreadList = new List<Thread>(priProcessorCount);
            prliOldStarsCount = new List<long>(priProcessorCount);
            prloBitmapList = new List<Bitmap>(priProcessorCount);
            int liStartRow = 0;
            int liEachBitmapHeight = ((int)(proOriginalBitmap.Height / priProcessorCount)) + 1;
            int liHeightToAdd = proOriginalBitmap.Height;
            Bitmap loBitmap;
            // Initialize the threads
            for (liThreadNumber = 0; liThreadNumber < priProcessorCount; liThreadNumber++)
            {
                // Just Copy The number 
                prliOldStarsCount.Add(0);

                if(liEachBitmapHeight > liHeightToAdd)
                {
                    // The last bitmap height perphaps is less than the other bitmaps height
                    liEachBitmapHeight = liHeightToAdd;
                }

                loBitmap = CropBitmap(proOriginalBitmap, new Rectangle(0, liStartRow, proOriginalBitmap.Width, liEachBitmapHeight));
                liHeightToAdd -= liEachBitmapHeight;
                liStartRow += liEachBitmapHeight;
                prloBitmapList.Add(loBitmap);
                // Add the new thread, with a parameterized start (to allow paramaters)
                prloThreadList.Add(new Thread(new ParameterizedThreadStart(ThreadOldStarsFinder)));
            }

            // Now start the threads
            for(liThreadNumber = 0; liThreadNumber < priProcessorCount; liThreadNumber++)
            {
                prloThreadList[liThreadNumber].Start(liThreadNumber);
            }

            WaitForThreadsToDie();
            ShowBitmapWithOldStars();
        }
    }
}
