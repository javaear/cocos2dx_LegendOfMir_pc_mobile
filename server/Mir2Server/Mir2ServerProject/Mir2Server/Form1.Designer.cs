namespace Mir2Server
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.服务ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.启动服务ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.暂停服务ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.数据库ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.地图ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.怪物ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.物品ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.button1 = new System.Windows.Forms.Button();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.playerBox = new System.Windows.Forms.ListBox();
            this.button3 = new System.Windows.Forms.Button();
            this.itemBox = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.RichTextBox();
            this.menuStrip1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.服务ToolStripMenuItem,
            this.数据库ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(635, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 服务ToolStripMenuItem
            // 
            this.服务ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.启动服务ToolStripMenuItem,
            this.暂停服务ToolStripMenuItem,
            this.退出ToolStripMenuItem});
            this.服务ToolStripMenuItem.Name = "服务ToolStripMenuItem";
            this.服务ToolStripMenuItem.Size = new System.Drawing.Size(51, 24);
            this.服务ToolStripMenuItem.Text = "服务";
            // 
            // 启动服务ToolStripMenuItem
            // 
            this.启动服务ToolStripMenuItem.Name = "启动服务ToolStripMenuItem";
            this.启动服务ToolStripMenuItem.Size = new System.Drawing.Size(144, 26);
            this.启动服务ToolStripMenuItem.Text = "启动服务";
            this.启动服务ToolStripMenuItem.Click += new System.EventHandler(this.onStart);
            // 
            // 暂停服务ToolStripMenuItem
            // 
            this.暂停服务ToolStripMenuItem.Name = "暂停服务ToolStripMenuItem";
            this.暂停服务ToolStripMenuItem.Size = new System.Drawing.Size(144, 26);
            this.暂停服务ToolStripMenuItem.Text = "暂停服务";
            // 
            // 退出ToolStripMenuItem
            // 
            this.退出ToolStripMenuItem.Name = "退出ToolStripMenuItem";
            this.退出ToolStripMenuItem.Size = new System.Drawing.Size(144, 26);
            this.退出ToolStripMenuItem.Text = "退出";
            this.退出ToolStripMenuItem.Click += new System.EventHandler(this.退出ToolStripMenuItem_Click);
            // 
            // 数据库ToolStripMenuItem
            // 
            this.数据库ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.地图ToolStripMenuItem,
            this.怪物ToolStripMenuItem,
            this.物品ToolStripMenuItem});
            this.数据库ToolStripMenuItem.Name = "数据库ToolStripMenuItem";
            this.数据库ToolStripMenuItem.Size = new System.Drawing.Size(66, 24);
            this.数据库ToolStripMenuItem.Text = "数据库";
            // 
            // 地图ToolStripMenuItem
            // 
            this.地图ToolStripMenuItem.Name = "地图ToolStripMenuItem";
            this.地图ToolStripMenuItem.Size = new System.Drawing.Size(114, 26);
            this.地图ToolStripMenuItem.Text = "地图";
            this.地图ToolStripMenuItem.Click += new System.EventHandler(this.ToolStripMenuItem_Click);
            // 
            // 怪物ToolStripMenuItem
            // 
            this.怪物ToolStripMenuItem.Name = "怪物ToolStripMenuItem";
            this.怪物ToolStripMenuItem.Size = new System.Drawing.Size(114, 26);
            this.怪物ToolStripMenuItem.Text = "怪物";
            this.怪物ToolStripMenuItem.Click += new System.EventHandler(this.怪物ToolStripMenuItem_Click);
            // 
            // 物品ToolStripMenuItem
            // 
            this.物品ToolStripMenuItem.Name = "物品ToolStripMenuItem";
            this.物品ToolStripMenuItem.Size = new System.Drawing.Size(114, 26);
            this.物品ToolStripMenuItem.Text = "物品";
            this.物品ToolStripMenuItem.Click += new System.EventHandler(this.物品ToolStripMenuItem_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 40;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(0, 3);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(600, 385);
            this.richTextBox1.TabIndex = 1;
            this.richTextBox1.Text = "";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Location = new System.Drawing.Point(12, 31);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(611, 420);
            this.tabControl1.TabIndex = 2;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.richTextBox1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(603, 391);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "日志";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.textBox1);
            this.tabPage2.Controls.Add(this.button1);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(603, 391);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "输入";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(515, 357);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 29);
            this.button1.TabIndex = 1;
            this.button1.Text = "发送";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.richTextBox2);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(603, 391);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "错误日志";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(1, 3);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.ReadOnly = true;
            this.richTextBox2.Size = new System.Drawing.Size(600, 385);
            this.richTextBox2.TabIndex = 2;
            this.richTextBox2.Text = "";
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.playerBox);
            this.tabPage4.Controls.Add(this.button3);
            this.tabPage4.Controls.Add(this.itemBox);
            this.tabPage4.Controls.Add(this.label3);
            this.tabPage4.Controls.Add(this.button2);
            this.tabPage4.Controls.Add(this.label2);
            this.tabPage4.Location = new System.Drawing.Point(4, 25);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(603, 391);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "命令";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // playerBox
            // 
            this.playerBox.FormattingEnabled = true;
            this.playerBox.ItemHeight = 15;
            this.playerBox.Location = new System.Drawing.Point(22, 42);
            this.playerBox.Name = "playerBox";
            this.playerBox.Size = new System.Drawing.Size(562, 154);
            this.playerBox.TabIndex = 9;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(441, 319);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(143, 57);
            this.button3.TabIndex = 7;
            this.button3.Text = "更新玩家列表";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // itemBox
            // 
            this.itemBox.FormattingEnabled = true;
            this.itemBox.Location = new System.Drawing.Point(18, 242);
            this.itemBox.Name = "itemBox";
            this.itemBox.Size = new System.Drawing.Size(143, 23);
            this.itemBox.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 214);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "物品id";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(186, 242);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 33);
            this.button2.TabIndex = 4;
            this.button2.Text = "赠送";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(127, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "当前登录玩家列表";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(3, 6);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(506, 367);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(635, 463);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "MirServer";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.onFormClosed);
            this.Load += new System.EventHandler(this.onFormLoad);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 服务ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 启动服务ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 暂停服务ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出ToolStripMenuItem;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ToolStripMenuItem 数据库ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 地图ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 怪物ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 物品ToolStripMenuItem;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox itemBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.ListBox playerBox;
        private System.Windows.Forms.RichTextBox textBox1;
    }
}

