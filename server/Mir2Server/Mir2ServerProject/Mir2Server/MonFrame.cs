using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mir2Server
{
    public partial class MonFrame : Form
    {
        private TableConf monConf = new TableConf();

        public MonFrame()
        {
            InitializeComponent();
        }

        private void onSelectedItem(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            Table mapTable = monConf.Content[index];

            string name = mapTable.getValue("sz_name");
            string bodyid = mapTable.getValue("bodyid");
            string moveDelta = mapTable.getValue("moveDelta");
            string allowRun = mapTable.getValue("allowRun");
            string slashDelta = mapTable.getValue("slashDelta");
            string castDelta = mapTable.getValue("castDelta");
            string attributeid = mapTable.getValue("attributeid");
            string excConf = mapTable.getValue("sz_excConf");
            string exc = mapTable.getValue("exc");

            nameBox.Text = name;
            bodyIdBox.Text = bodyid;
            moveDeltaBox.Text = moveDelta;
            slashDeltaBox.Text = slashDelta;
            castDeltaBox.Text = castDelta;
            allowRunBox.Text = allowRun;
            attributeIdBox.Text = attributeid;
            excConfBox.Text = excConf;
            excBox.Text = exc;
        }

        public void readConfFile(string txt)
        {
            StreamReader sr = new StreamReader("res/conf/actor/actor.tab", Encoding.UTF8);
            string result = "";
            String line;
            while ((line = sr.ReadLine()) != null)
            {
                if (!line.Contains("#"))
                    result = result + line + "\n";
            }

            sr.Close();
            readConf(result);
        }

        private void readConf(string txt)
        {
            monConf.readTxt(txt);

            for (int i = 0; i < monConf.Content.Count(); ++i)
            {
                string id = monConf.Content[i].getValue("id");
                string name = monConf.Content[i].getValue("sz_name");
                //string utfName = System.Text.Encoding.UTF8.GetString(System.Text.Encoding.Default.GetBytes(name));
                listBox1.Items.Add(id + ":" + name);
            }
        }
    }
}
