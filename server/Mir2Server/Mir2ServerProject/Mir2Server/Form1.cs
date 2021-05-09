using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mir2Server
{
    public partial class Form1 : Form
    {
        private TableConf playerConf = new TableConf();
        private CocosCom com = new CocosCom();
        private MapFrame mf = null;
        private MonFrame mon = null;
        private ItemFrame item = null;
        private bool isInit = false;

        public Form1()
        {
            InitializeComponent();
            updateUI();

            if (item == null)
            {
                item = new ItemFrame();
                item.readConfFile("");
            }

            com.debug();
        }

        public void startTimer()
        {
            timer1.Start();
        }

        private void onFormLoad(object sender, EventArgs e)
        {
        }

        private void onStart(object sender, EventArgs e)
        {
            bool ret = com.init();

            if (ret == false)
                MessageBox.Show("初始化引擎错误");

            ret = com.start();

            if (ret == false)
                MessageBox.Show("启动引擎错误");

            startTimer();

            isInit = true;

            updateUI();
        }

        private void updateUI()
        {
            if (isInit == true)
            {
                this.启动服务ToolStripMenuItem.Enabled = false;
                this.暂停服务ToolStripMenuItem.Enabled = true;
            }
            else
            {
                this.启动服务ToolStripMenuItem.Enabled = true;
                this.暂停服务ToolStripMenuItem.Enabled = false;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            com.mainLoop();

            string str = "";
            if ((str = com.getLogMessage(1)) != "")
            {
                richTextBox1.AppendText(str);
            }

            string str2 = "";
            if ((str2 = com.getLogMessage(2)) != "")
            {
                string utfName = System.Text.Encoding.UTF8.GetString(System.Text.Encoding.Default.GetBytes(str2));
                richTextBox2.AppendText(utfName);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            com.excCodes(textBox1.Text);
        }

        private void ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string result = com.getLuaFunction("getMapConfTxt", "1");

            if (mf == null)
            {
                mf = new MapFrame();
                mf.readConfFile("");
            }

            mf.Show(); 
        }

        private void onFormClosed(object sender, FormClosedEventArgs e)
        {
            if (mf != null)
            {
                mf.Dispose();
            }

            if (mon != null)
            {
                mon.Dispose();
            }
        }

        private void 怪物ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string result = com.getLuaFunction("getMonConfTxt", "1");

            if (mon == null)
            {
                mon = new MonFrame();
                mon.readConfFile("");
            }

            mon.Show();
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Environment.Exit(0);
        }

        private void 物品ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //string result = com.getLuaFunction("getItemConfTxt", "1");
            item.Show();
        }

        private void onSelectedChange(object sender, EventArgs e)
        {
            string result = com.getLuaFunction("getPlayerList", "1");
            //tarBox.Items.Clear();
            
            string[] user = result.Split('\t');
            for(int i=0;i<user.Count();++i)
            {
               // tarBox.Items.Add(user[i]);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (playerBox.SelectedIndex < 0 || playerBox.SelectedIndex >= playerBox.Items.Count)
            {
                return;
            }

            if  (itemBox.SelectedIndex < 0 || itemBox.SelectedIndex >= item.itemConf.Content.Count)
            {
                Console.WriteLine("invalid itemBox index:" + itemBox.SelectedIndex);
            }

            int index = itemBox.SelectedIndex;
            string id = item.itemConf.Content[index].getValue("id");
            string pid = playerConf.Content[playerBox.SelectedIndex].getValue("pid");
            string code = "Game.addItemWithTypeId(" + pid + "," + id + ")";
            com.excCodes(code);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string result = com.getLuaFunction("getPlayerList", "1");
            string utfResult = System.Text.Encoding.UTF8.GetString(System.Text.Encoding.Default.GetBytes(result));
            string[] user = utfResult.Split('\n');

            playerBox.Items.Clear();
            playerConf.Content.Clear();
            for (int i = 0; i < user.Count(); ++i)
            {
                // tarBox.Items.Add(user[i]);
                string[] playerInfo = user[i].Split(',');

                if (playerInfo.Count() >= 3)
                {
                    playerBox.Items.Add("pid:" + playerInfo[0] + "     name:" + playerInfo[1] + "     level:" + playerInfo[2]);

                    Table p = new Table();
                    p.addValue("pid", playerInfo[0]);
                    p.addValue("name", playerInfo[1]);
                    p.addValue("level", playerInfo[2]);
                    playerConf.Content.Add(p);
                }
            }

            itemBox.Items.Clear();
            for(int i=0;i < item.itemConf.Content.Count();i++)
            {
                string name = item.itemConf.Content[i].getValue("sz_name");
                itemBox.Items.Add(name);
            }
        }
    }
}
