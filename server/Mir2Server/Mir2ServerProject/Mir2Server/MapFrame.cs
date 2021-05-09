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
    public partial class MapFrame : Form
    {
        public TableConf mapConf = new TableConf();

        public MapFrame()
        {
            InitializeComponent();
        }

        public void readConf(string txt)
        {
            mapConf.readTxt(txt);

            for(int i=0;i<mapConf.Content.Count();++i)
            {
                string id = mapConf.Content[i].getValue("id");
                string name = mapConf.Content[i].getValue("sz_name");
                //string utfName = System.Text.Encoding.UTF8.GetString(System.Text.Encoding.Default.GetBytes(name));
                listBox1.Items.Add(id + ":" + name);
            }   
        }

        public void readConfFile(string txt)
        {
            StreamReader sr = new StreamReader("res/conf/map/map.tab", Encoding.UTF8);
            string result = "";
            String line;
            while ((line = sr.ReadLine()) != null)
            {
                result = result + line + "\n";
            }

            sr.Close();
            readConf(result);
        }

        private void onSelectItem(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (index < 0)
                return;

            Table mapTable = mapConf.Content[index];

            string name = mapTable.getValue("sz_name");
            string path = mapTable.getValue("sz_path");
            string monPath = mapTable.getValue("sz_monster_distribute");
            string portalPath = mapTable.getValue("sz_portal_conf");
            string mmapPath = mapTable.getValue("mmapId");

            mapNameBox.Text = name;
            pathBox.Text = path;
            monPathBox.Text = monPath;
            portalPathBox.Text = portalPath;
            mmapPathBox.Text = mmapPath;
        }
    }
}
