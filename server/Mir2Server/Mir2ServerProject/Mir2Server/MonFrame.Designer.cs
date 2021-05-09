namespace Mir2Server
{
    partial class MonFrame
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
            this.nameBox = new System.Windows.Forms.TextBox();
            this.excBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.excConfBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.attributeIdBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.allowRunBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.bodyIdBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.moveDeltaBox = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.slashDeltaBox = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.castDeltaBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(2, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(127, 409);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.onSelectedItem);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(160, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "名称";
            // 
            // nameBox
            // 
            this.nameBox.Location = new System.Drawing.Point(163, 41);
            this.nameBox.Name = "nameBox";
            this.nameBox.Size = new System.Drawing.Size(166, 25);
            this.nameBox.TabIndex = 2;
            // 
            // excBox
            // 
            this.excBox.Location = new System.Drawing.Point(163, 401);
            this.excBox.Name = "excBox";
            this.excBox.Size = new System.Drawing.Size(219, 25);
            this.excBox.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(160, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 15);
            this.label2.TabIndex = 3;
            this.label2.Text = "bodyid";
            // 
            // excConfBox
            // 
            this.excConfBox.Location = new System.Drawing.Point(163, 355);
            this.excConfBox.Name = "excConfBox";
            this.excConfBox.Size = new System.Drawing.Size(245, 25);
            this.excConfBox.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(163, 128);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "moveDelta";
            // 
            // attributeIdBox
            // 
            this.attributeIdBox.Location = new System.Drawing.Point(163, 304);
            this.attributeIdBox.Name = "attributeIdBox";
            this.attributeIdBox.Size = new System.Drawing.Size(166, 25);
            this.attributeIdBox.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(165, 183);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(87, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "slashDelta";
            // 
            // allowRunBox
            // 
            this.allowRunBox.Location = new System.Drawing.Point(163, 253);
            this.allowRunBox.Name = "allowRunBox";
            this.allowRunBox.Size = new System.Drawing.Size(166, 25);
            this.allowRunBox.TabIndex = 10;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(162, 337);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(87, 15);
            this.label5.TabIndex = 9;
            this.label5.Text = "sz_excConf";
            // 
            // bodyIdBox
            // 
            this.bodyIdBox.Location = new System.Drawing.Point(163, 92);
            this.bodyIdBox.Name = "bodyIdBox";
            this.bodyIdBox.Size = new System.Drawing.Size(166, 25);
            this.bodyIdBox.TabIndex = 12;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(163, 383);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(31, 15);
            this.label6.TabIndex = 11;
            this.label6.Text = "exc";
            // 
            // moveDeltaBox
            // 
            this.moveDeltaBox.Location = new System.Drawing.Point(163, 149);
            this.moveDeltaBox.Name = "moveDeltaBox";
            this.moveDeltaBox.Size = new System.Drawing.Size(166, 25);
            this.moveDeltaBox.TabIndex = 14;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(164, 235);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(71, 15);
            this.label7.TabIndex = 13;
            this.label7.Text = "allowRun";
            // 
            // slashDeltaBox
            // 
            this.slashDeltaBox.Location = new System.Drawing.Point(163, 201);
            this.slashDeltaBox.Name = "slashDeltaBox";
            this.slashDeltaBox.Size = new System.Drawing.Size(166, 25);
            this.slashDeltaBox.TabIndex = 16;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(163, 286);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(95, 15);
            this.label8.TabIndex = 15;
            this.label8.Text = "attributeId";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(364, 23);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(79, 15);
            this.label9.TabIndex = 18;
            this.label9.Text = "castDelta";
            // 
            // castDeltaBox
            // 
            this.castDeltaBox.Location = new System.Drawing.Point(363, 41);
            this.castDeltaBox.Name = "castDeltaBox";
            this.castDeltaBox.Size = new System.Drawing.Size(166, 25);
            this.castDeltaBox.TabIndex = 17;
            // 
            // MonFrame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(601, 437);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.castDeltaBox);
            this.Controls.Add(this.slashDeltaBox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.moveDeltaBox);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.bodyIdBox);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.allowRunBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.attributeIdBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.excConfBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.excBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.nameBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox1);
            this.Name = "MonFrame";
            this.Text = "MonFrame";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox nameBox;
        private System.Windows.Forms.TextBox excBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox excConfBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox attributeIdBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox allowRunBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox bodyIdBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox moveDeltaBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox slashDeltaBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox castDeltaBox;
    }
}