namespace StarFinder
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.picStarsBitmap = new System.Windows.Forms.PictureBox();
            this.butFindOldStar = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picStarsBitmap)).BeginInit();
            this.SuspendLayout();
            // 
            // picStarsBitmap
            // 
            this.picStarsBitmap.Image = ((System.Drawing.Image)(resources.GetObject("picStarsBitmap.Image")));
            this.picStarsBitmap.Location = new System.Drawing.Point(12, 12);
            this.picStarsBitmap.Name = "picStarsBitmap";
            this.picStarsBitmap.Size = new System.Drawing.Size(776, 387);
            this.picStarsBitmap.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picStarsBitmap.TabIndex = 0;
            this.picStarsBitmap.TabStop = false;
            // 
            // butFindOldStar
            // 
            this.butFindOldStar.Location = new System.Drawing.Point(12, 405);
            this.butFindOldStar.Name = "butFindOldStar";
            this.butFindOldStar.Size = new System.Drawing.Size(75, 33);
            this.butFindOldStar.TabIndex = 1;
            this.butFindOldStar.Text = "Find Star";
            this.butFindOldStar.UseVisualStyleBackColor = true;
            this.butFindOldStar.Click += new System.EventHandler(this.butFindOldStar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.butFindOldStar);
            this.Controls.Add(this.picStarsBitmap);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.picStarsBitmap)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox picStarsBitmap;
        private System.Windows.Forms.Button butFindOldStar;
    }
}

