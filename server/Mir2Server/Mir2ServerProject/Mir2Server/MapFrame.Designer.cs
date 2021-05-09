namespace Mir2Server
{
    partial class MapFrame
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

            base.Hide();
            //base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.mapNameBox = new System.Windows.Forms.TextBox();
            this.pathBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.monPathBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.portalPathBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.mmapPathBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(1, 5);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(143, 394);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.onSelectItem);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(165, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "地图名";
            // 
            // mapNameBox
            // 
            this.mapNameBox.Location = new System.Drawing.Point(228, 14);
            this.mapNameBox.Name = "mapNameBox";
            this.mapNameBox.Size = new System.Drawing.Size(116, 25);
            this.mapNameBox.TabIndex = 2;
            // 
            // pathBox
            // 
            this.pathBox.Location = new System.Drawing.Point(228, 56);
            this.pathBox.Name = "pathBox";
            this.pathBox.Size = new System.Drawing.Size(116, 25);
            this.pathBox.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(171, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 15);
            this.label2.TabIndex = 3;
            this.label2.Text = "路径";
            // 
            // monPathBox
            // 
            this.monPathBox.Location = new System.Drawing.Point(253, 99);
            this.monPathBox.Name = "monPathBox";
            this.monPathBox.Size = new System.Drawing.Size(240, 25);
            this.monPathBox.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(165, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "怪物配置表";
            // 
            // portalPathBox
            // 
            this.portalPathBox.Location = new System.Drawing.Point(253, 138);
            this.portalPathBox.Name = "portalPathBox";
            this.portalPathBox.Size = new System.Drawing.Size(240, 25);
            this.portalPathBox.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(150, 142);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "传送点配置表";
            // 
            // mmapPathBox
            // 
            this.mmapPathBox.Location = new System.Drawing.Point(253, 179);
            this.mmapPathBox.Name = "mmapPathBox";
            this.mmapPathBox.Size = new System.Drawing.Size(240, 25);
            this.mmapPathBox.TabIndex = 10;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(150, 183);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(97, 15);
            this.label5.TabIndex = 9;
            this.label5.Text = "小地图配置表";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(371, 343);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(90, 41);
            this.button2.TabIndex = 12;
            this.button2.Text = "删除地图";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(199, 343);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(90, 41);
            this.button1.TabIndex = 13;
            this.button1.Text = "增加地图";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // MapFrame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(533, 411);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.mmapPathBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.portalPathBox);
            this.Controls.Add(this.monPathBox);
            this.Controls.Add(this.pathBox);
            this.Controls.Add(this.mapNameBox);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "MapFrame";
            this.Text = "MapFrame";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox mapNameBox;
        private System.Windows.Forms.TextBox pathBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox monPathBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox portalPathBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox mmapPathBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
    }
}