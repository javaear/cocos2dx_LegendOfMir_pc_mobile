namespace Mir2Server
{
    partial class ItemFrame
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
            if(disposing && (components != null))
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
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.nameText = new System.Windows.Forms.TextBox();
            this.levelText = new System.Windows.Forms.TextBox();
            this.spriteText = new System.Windows.Forms.TextBox();
            this.iconText = new System.Windows.Forms.TextBox();
            this.maxHpText = new System.Windows.Forms.TextBox();
            this.maxMpText = new System.Windows.Forms.TextBox();
            this.phyAtkMinText = new System.Windows.Forms.TextBox();
            this.phyDefText = new System.Windows.Forms.TextBox();
            this.descriText = new System.Windows.Forms.RichTextBox();
            this.confirmBtn = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.needLevelText = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.typeBox = new System.Windows.Forms.ComboBox();
            this.button3 = new System.Windows.Forms.Button();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.phyAtkMaxText = new System.Windows.Forms.TextBox();
            this.label14 = new System.Windows.Forms.Label();
            this.magAtkMaxText = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.magAtkMinText = new System.Windows.Forms.TextBox();
            this.taoAtkMaxText = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.taoAtkMinText = new System.Windows.Forms.TextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.phyLabel = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.magDefText = new System.Windows.Forms.TextBox();
            this.label19 = new System.Windows.Forms.Label();
            this.taoDefText = new System.Windows.Forms.TextBox();
            this.label20 = new System.Windows.Forms.Label();
            this.critRateText = new System.Windows.Forms.TextBox();
            this.defenCritText = new System.Windows.Forms.TextBox();
            this.label21 = new System.Windows.Forms.Label();
            this.preciseText = new System.Windows.Forms.TextBox();
            this.label22 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.dodgeText = new System.Windows.Forms.TextBox();
            this.luckText = new System.Windows.Forms.TextBox();
            this.label24 = new System.Windows.Forms.Label();
            this.slashSpeedText = new System.Windows.Forms.TextBox();
            this.label25 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(2, 9);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(135, 484);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.onSelectedItem);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(182, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "名字";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(182, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "类型";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(182, 78);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "品级";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(161, 107);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(82, 15);
            this.label4.TabIndex = 4;
            this.label4.Text = "大地图标识";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(167, 137);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(67, 15);
            this.label5.TabIndex = 5;
            this.label5.Text = "图标标识";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(167, 166);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(67, 15);
            this.label6.TabIndex = 6;
            this.label6.Text = "最大生命";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(167, 197);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(67, 15);
            this.label7.TabIndex = 7;
            this.label7.Text = "最大魔法";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(167, 230);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(67, 15);
            this.label8.TabIndex = 8;
            this.label8.Text = "攻击属性";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(167, 257);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(67, 15);
            this.label9.TabIndex = 9;
            this.label9.Text = "防御属性";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(182, 318);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(37, 15);
            this.label10.TabIndex = 10;
            this.label10.Text = "描述";
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(236, 13);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(232, 25);
            this.nameText.TabIndex = 11;
            // 
            // levelText
            // 
            this.levelText.Location = new System.Drawing.Point(236, 74);
            this.levelText.Name = "levelText";
            this.levelText.Size = new System.Drawing.Size(232, 25);
            this.levelText.TabIndex = 13;
            // 
            // spriteText
            // 
            this.spriteText.Location = new System.Drawing.Point(249, 104);
            this.spriteText.Name = "spriteText";
            this.spriteText.Size = new System.Drawing.Size(232, 25);
            this.spriteText.TabIndex = 14;
            // 
            // iconText
            // 
            this.iconText.Location = new System.Drawing.Point(249, 134);
            this.iconText.Name = "iconText";
            this.iconText.Size = new System.Drawing.Size(232, 25);
            this.iconText.TabIndex = 15;
            // 
            // maxHpText
            // 
            this.maxHpText.Location = new System.Drawing.Point(249, 163);
            this.maxHpText.Name = "maxHpText";
            this.maxHpText.Size = new System.Drawing.Size(232, 25);
            this.maxHpText.TabIndex = 16;
            // 
            // maxMpText
            // 
            this.maxMpText.Location = new System.Drawing.Point(249, 193);
            this.maxMpText.Name = "maxMpText";
            this.maxMpText.Size = new System.Drawing.Size(232, 25);
            this.maxMpText.TabIndex = 17;
            // 
            // phyAtkMinText
            // 
            this.phyAtkMinText.Location = new System.Drawing.Point(318, 225);
            this.phyAtkMinText.Name = "phyAtkMinText";
            this.phyAtkMinText.Size = new System.Drawing.Size(33, 25);
            this.phyAtkMinText.TabIndex = 18;
            // 
            // phyDefText
            // 
            this.phyDefText.Location = new System.Drawing.Point(317, 254);
            this.phyDefText.Name = "phyDefText";
            this.phyDefText.Size = new System.Drawing.Size(49, 25);
            this.phyDefText.TabIndex = 19;
            this.phyDefText.Text = "123";
            // 
            // descriText
            // 
            this.descriText.Location = new System.Drawing.Point(236, 318);
            this.descriText.Name = "descriText";
            this.descriText.Size = new System.Drawing.Size(332, 125);
            this.descriText.TabIndex = 20;
            this.descriText.Text = "";
            // 
            // confirmBtn
            // 
            this.confirmBtn.Location = new System.Drawing.Point(417, 449);
            this.confirmBtn.Name = "confirmBtn";
            this.confirmBtn.Size = new System.Drawing.Size(75, 39);
            this.confirmBtn.TabIndex = 21;
            this.confirmBtn.Text = "应用";
            this.confirmBtn.UseVisualStyleBackColor = true;
            this.confirmBtn.Click += new System.EventHandler(this.confirmBtn_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(167, 290);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(67, 15);
            this.label11.TabIndex = 22;
            this.label11.Text = "需要等级";
            // 
            // needLevelText
            // 
            this.needLevelText.Location = new System.Drawing.Point(249, 285);
            this.needLevelText.Name = "needLevelText";
            this.needLevelText.Size = new System.Drawing.Size(232, 25);
            this.needLevelText.TabIndex = 23;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(155, 449);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(98, 39);
            this.button1.TabIndex = 24;
            this.button1.Text = "新增道具";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(519, 449);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 39);
            this.button2.TabIndex = 25;
            this.button2.Text = "另存为";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // typeBox
            // 
            this.typeBox.FormattingEnabled = true;
            this.typeBox.Items.AddRange(new object[] {
            "武器",
            "衣服",
            "头盔",
            "手镯",
            "戒指",
            "项链",
            "血瓶"});
            this.typeBox.Location = new System.Drawing.Point(236, 44);
            this.typeBox.Name = "typeBox";
            this.typeBox.Size = new System.Drawing.Size(232, 23);
            this.typeBox.TabIndex = 26;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(285, 449);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(98, 39);
            this.button3.TabIndex = 27;
            this.button3.Text = "删除道具";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(246, 229);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(67, 15);
            this.label12.TabIndex = 29;
            this.label12.Text = "物理攻击";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(353, 229);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(15, 15);
            this.label13.TabIndex = 30;
            this.label13.Text = "-";
            // 
            // phyAtkMaxText
            // 
            this.phyAtkMaxText.Location = new System.Drawing.Point(370, 225);
            this.phyAtkMaxText.Name = "phyAtkMaxText";
            this.phyAtkMaxText.Size = new System.Drawing.Size(31, 25);
            this.phyAtkMaxText.TabIndex = 31;
            this.phyAtkMaxText.Text = "1";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(402, 229);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(67, 15);
            this.label14.TabIndex = 32;
            this.label14.Text = "魔法攻击";
            // 
            // magAtkMaxText
            // 
            this.magAtkMaxText.Location = new System.Drawing.Point(521, 224);
            this.magAtkMaxText.Name = "magAtkMaxText";
            this.magAtkMaxText.Size = new System.Drawing.Size(34, 25);
            this.magAtkMaxText.TabIndex = 35;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(505, 229);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(15, 15);
            this.label15.TabIndex = 34;
            this.label15.Text = "-";
            // 
            // magAtkMinText
            // 
            this.magAtkMinText.Location = new System.Drawing.Point(469, 224);
            this.magAtkMinText.Name = "magAtkMinText";
            this.magAtkMinText.Size = new System.Drawing.Size(34, 25);
            this.magAtkMinText.TabIndex = 33;
            // 
            // taoAtkMaxText
            // 
            this.taoAtkMaxText.Location = new System.Drawing.Point(675, 224);
            this.taoAtkMaxText.Name = "taoAtkMaxText";
            this.taoAtkMaxText.Size = new System.Drawing.Size(32, 25);
            this.taoAtkMaxText.TabIndex = 39;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(658, 229);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(15, 15);
            this.label16.TabIndex = 38;
            this.label16.Text = "-";
            // 
            // taoAtkMinText
            // 
            this.taoAtkMinText.Location = new System.Drawing.Point(623, 224);
            this.taoAtkMinText.Name = "taoAtkMinText";
            this.taoAtkMinText.Size = new System.Drawing.Size(32, 25);
            this.taoAtkMinText.TabIndex = 37;
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(556, 229);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(67, 15);
            this.label17.TabIndex = 36;
            this.label17.Text = "道术攻击";
            // 
            // phyLabel
            // 
            this.phyLabel.AutoSize = true;
            this.phyLabel.Location = new System.Drawing.Point(246, 257);
            this.phyLabel.Name = "phyLabel";
            this.phyLabel.Size = new System.Drawing.Size(67, 15);
            this.phyLabel.TabIndex = 40;
            this.phyLabel.Text = "物理防御";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(369, 258);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(67, 15);
            this.label18.TabIndex = 42;
            this.label18.Text = "魔法防御";
            // 
            // magDefText
            // 
            this.magDefText.Location = new System.Drawing.Point(440, 254);
            this.magDefText.Name = "magDefText";
            this.magDefText.Size = new System.Drawing.Size(45, 25);
            this.magDefText.TabIndex = 41;
            this.magDefText.Text = "123";
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(487, 259);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(67, 15);
            this.label19.TabIndex = 44;
            this.label19.Text = "道术防御";
            // 
            // taoDefText
            // 
            this.taoDefText.Location = new System.Drawing.Point(557, 255);
            this.taoDefText.Name = "taoDefText";
            this.taoDefText.Size = new System.Drawing.Size(45, 25);
            this.taoDefText.TabIndex = 43;
            this.taoDefText.Text = "123";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(505, 19);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(60, 15);
            this.label20.TabIndex = 45;
            this.label20.Text = "暴击率:";
            // 
            // critRateText
            // 
            this.critRateText.Location = new System.Drawing.Point(571, 13);
            this.critRateText.Name = "critRateText";
            this.critRateText.Size = new System.Drawing.Size(71, 25);
            this.critRateText.TabIndex = 46;
            // 
            // defenCritText
            // 
            this.defenCritText.Location = new System.Drawing.Point(571, 42);
            this.defenCritText.Name = "defenCritText";
            this.defenCritText.Size = new System.Drawing.Size(71, 25);
            this.defenCritText.TabIndex = 48;
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(505, 48);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(60, 15);
            this.label21.TabIndex = 47;
            this.label21.Text = "抗暴击:";
            // 
            // preciseText
            // 
            this.preciseText.Location = new System.Drawing.Point(571, 73);
            this.preciseText.Name = "preciseText";
            this.preciseText.Size = new System.Drawing.Size(71, 25);
            this.preciseText.TabIndex = 50;
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(510, 79);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(45, 15);
            this.label22.TabIndex = 49;
            this.label22.Text = "命中:";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(510, 107);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(45, 15);
            this.label23.TabIndex = 51;
            this.label23.Text = "闪避:";
            // 
            // dodgeText
            // 
            this.dodgeText.Location = new System.Drawing.Point(571, 104);
            this.dodgeText.Name = "dodgeText";
            this.dodgeText.Size = new System.Drawing.Size(71, 25);
            this.dodgeText.TabIndex = 52;
            // 
            // luckText
            // 
            this.luckText.Location = new System.Drawing.Point(571, 134);
            this.luckText.Name = "luckText";
            this.luckText.Size = new System.Drawing.Size(71, 25);
            this.luckText.TabIndex = 54;
            // 
            // label24
            // 
            this.label24.AutoSize = true;
            this.label24.Location = new System.Drawing.Point(510, 140);
            this.label24.Name = "label24";
            this.label24.Size = new System.Drawing.Size(45, 15);
            this.label24.TabIndex = 53;
            this.label24.Text = "幸运:";
            // 
            // slashSpeedText
            // 
            this.slashSpeedText.Location = new System.Drawing.Point(571, 163);
            this.slashSpeedText.Name = "slashSpeedText";
            this.slashSpeedText.Size = new System.Drawing.Size(71, 25);
            this.slashSpeedText.TabIndex = 56;
            // 
            // label25
            // 
            this.label25.AutoSize = true;
            this.label25.Location = new System.Drawing.Point(510, 169);
            this.label25.Name = "label25";
            this.label25.Size = new System.Drawing.Size(45, 15);
            this.label25.TabIndex = 55;
            this.label25.Text = "攻速:";
            // 
            // ItemFrame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(769, 500);
            this.Controls.Add(this.slashSpeedText);
            this.Controls.Add(this.label25);
            this.Controls.Add(this.luckText);
            this.Controls.Add(this.label24);
            this.Controls.Add(this.dodgeText);
            this.Controls.Add(this.label23);
            this.Controls.Add(this.preciseText);
            this.Controls.Add(this.label22);
            this.Controls.Add(this.defenCritText);
            this.Controls.Add(this.label21);
            this.Controls.Add(this.critRateText);
            this.Controls.Add(this.label20);
            this.Controls.Add(this.label19);
            this.Controls.Add(this.taoDefText);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.magDefText);
            this.Controls.Add(this.phyLabel);
            this.Controls.Add(this.taoAtkMaxText);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.taoAtkMinText);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.magAtkMaxText);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.magAtkMinText);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.phyAtkMaxText);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.typeBox);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.needLevelText);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.confirmBtn);
            this.Controls.Add(this.descriText);
            this.Controls.Add(this.phyDefText);
            this.Controls.Add(this.phyAtkMinText);
            this.Controls.Add(this.maxMpText);
            this.Controls.Add(this.maxHpText);
            this.Controls.Add(this.iconText);
            this.Controls.Add(this.spriteText);
            this.Controls.Add(this.levelText);
            this.Controls.Add(this.nameText);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox1);
            this.Name = "ItemFrame";
            this.Text = "ItemFrame";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.TextBox levelText;
        private System.Windows.Forms.TextBox spriteText;
        private System.Windows.Forms.TextBox iconText;
        private System.Windows.Forms.TextBox maxHpText;
        private System.Windows.Forms.TextBox maxMpText;
        private System.Windows.Forms.TextBox phyAtkMinText;
        private System.Windows.Forms.TextBox phyDefText;
        private System.Windows.Forms.RichTextBox descriText;
        private System.Windows.Forms.Button confirmBtn;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox needLevelText;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.ComboBox typeBox;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox phyAtkMaxText;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox magAtkMaxText;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox magAtkMinText;
        private System.Windows.Forms.TextBox taoAtkMaxText;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.TextBox taoAtkMinText;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label phyLabel;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.TextBox magDefText;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.TextBox taoDefText;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.TextBox critRateText;
        private System.Windows.Forms.TextBox defenCritText;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.TextBox preciseText;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.TextBox dodgeText;
        private System.Windows.Forms.TextBox luckText;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.TextBox slashSpeedText;
        private System.Windows.Forms.Label label25;
    }
}