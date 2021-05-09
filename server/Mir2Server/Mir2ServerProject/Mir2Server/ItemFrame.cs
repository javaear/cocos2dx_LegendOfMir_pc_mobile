using NLua;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Mir2Server
{
    public partial class ItemFrame : Form
    {
        public TableConf itemConf = new TableConf();
        public int currSelItemIndex = -1;
        private Lua state = new Lua();

        public ItemFrame()
        {
            InitializeComponent();
        }

        public void readConfFile(string txt)
        {
            StreamReader sr = new StreamReader("res/conf/equip/equipment.tab", Encoding.UTF8);
            string result = "";
            String line;
            while ((line = sr.ReadLine()) != null)
            {
                result = result + line + "\n";
            }

            sr.Close();
            readConf(result);
        }

        private int getTypeId(string name)
        {
            if (name == "武器")
            {
                return 2;
            }
            else if (name == "衣服")
            {
                return 1;
            }
            else if (name == "头盔")
            {
                return 3;
            }
            else if (name == "项链")
            {
                return 4;
            }
            else if (name == "手镯")
            {
                return 5;
            }
            else if (name == "戒指")
            {
                return 7;
            }
            else if (name == "血瓶")
            {
                return 11;
            }
            else if (name == "回城卷")
            {
                return 12;
            }
            else if (name == "打包物品")
            {
                return 13;
            }

            return 0;
        }

        private string getTypeName(int id)
        {
            switch (id)
            {
                case 1:
                    return "衣服";
                case 2:
                    return "武器";
                    break;
                case 3:
                    return "头盔";
                case 4:
                    return "项链";
                case 5:
                    return "手镯";
                case 7:
                    return "戒指";
                case 11:
                    return "血瓶";
                case 12:
                    return "回城卷";
                case 13:
                    return "打包物品";
            }

            return "未知";
        }

        public void readConf(string txt)
        {
            itemConf.readTxt(txt);

            updateItem();
        }

        public void updateItem()
        {
            int index = listBox1.SelectedIndex;
            listBox1.Items.Clear();

            for (int i = 0; i < itemConf.Content.Count(); ++i)
            {
                string id = string.Concat(i + 1); //itemConf.Content[i].getValue("id");
                string name = itemConf.Content[i].getValue("sz_name");

                //string utfName = System.Text.Encoding.UTF8.GetString(System.Text.Encoding.Default.GetBytes(name));
                listBox1.Items.Add(id + ":" + name);
            }

            if (index >= itemConf.Content.Count())
                index = itemConf.Content.Count() - 1;

            listBox1.SelectedIndex = index;
        }

        private void onSelectedItem(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (index < 0)
                return;

            int i = index;
            string name = itemConf.Content[i].getValue("sz_name");
            string type = itemConf.Content[i].getValue("type");
            string spriteid = itemConf.Content[i].getValue("spriteid");
            string iconId = itemConf.Content[i].getValue("iconId");
            string needLevel = itemConf.Content[i].getValue("need_level");
            string maxHp = itemConf.Content[i].getValue("maxHp");
            string maxMp = itemConf.Content[i].getValue("maxMp");
            string sz_atk = itemConf.Content[i].getValue("sz_atk");
            string sz_dfs = itemConf.Content[i].getValue("sz_dfs");
            string sz_description = itemConf.Content[i].getValue("sz_description");
            string quality = itemConf.Content[i].getValue("quality");
            string critRate = itemConf.Content[i].getValue("critRate");
            string defenCrit = itemConf.Content[i].getValue("defenCrit");
            string precise = itemConf.Content[i].getValue("precise");
            string dodge = itemConf.Content[i].getValue("dodge");
            string luck = itemConf.Content[i].getValue("luck");
            string slashSpeed = itemConf.Content[i].getValue("slashSpeed");

            critRateText.Text = critRate;
            defenCritText.Text = defenCrit;
            preciseText.Text = precise;
            dodgeText.Text = dodge;
            luckText.Text = luck;
            slashSpeedText.Text = slashSpeed;

            nameText.Text = name;
            typeBox.Text = getTypeName(int.Parse(type));
            spriteText.Text = string.Concat(spriteid);
            iconText.Text = string.Concat(iconId);
            needLevelText.Text = string.Concat(needLevel);
            maxHpText.Text = string.Concat(maxHp);
            maxMpText.Text = string.Concat(maxMp);
            
            descriText.Text = sz_description;
            levelText.Text = quality;

            Table atkTable = parseString(sz_atk);
            Table defTable = parseString(sz_dfs);
            string phyAtkMin = atkTable.getValue("1:1");
            string phyAtkMax = atkTable.getValue("1:2");
            string magAtkMin = atkTable.getValue("2:1");
            string magAtkMax = atkTable.getValue("2:2");
            string taoAtkMin = atkTable.getValue("3:1");
            string taoAtkMax = atkTable.getValue("3:2");
            phyAtkMinText.Text = phyAtkMin;
            phyAtkMaxText.Text = phyAtkMax;
            magAtkMinText.Text = magAtkMin;
            magAtkMaxText.Text = magAtkMax;
            taoAtkMinText.Text = taoAtkMin;
            taoAtkMaxText.Text = taoAtkMax;
            phyDefText.Text = defTable.getValue("1");
            magDefText.Text = defTable.getValue("2");
            taoDefText.Text = defTable.getValue("3");

            currSelItemIndex = index;
        }

        private Table parseString(string str)
        {      
            Table retTable = new Table();
            object[] lt = state.DoString("return " + str);

            if (lt != null && lt.Count() > 0)
            {
                LuaTable o = (LuaTable)lt[0];
                IEnumerator enumra = o.Values.GetEnumerator();

                int index = 1;

                while (enumra.MoveNext())
                {
                    string type = enumra.Current.GetType().ToString();
                    if (type == "NLua.LuaTable")
                    {
                        LuaTable table = enumra.Current as LuaTable;
                        IEnumerator subEnumra = table.GetEnumerator();

                        Console.WriteLine(subEnumra.ToString());
                        //subEnumra.Current.GetType()
                        string key = "";// ob.Key.ToString();

                        while (subEnumra.MoveNext())
                        {
                            KeyValuePair<Object, Object> obj = (KeyValuePair<Object, Object>)subEnumra.Current;

                            retTable.addValue(index + ":" + obj.Key.ToString(), obj.Value.ToString());
                        }
                    }
                    else
                    {
                        retTable.addValue(index + "", enumra.Current.ToString());
                    }

                    index++;
                }
            }
            
            return retTable;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            Table table = null;

            if (index >= 0 && itemConf.Content[index] != null)
            {
                Table currTable = itemConf.Content[index];

                table = currTable.Clone();
                string id = string.Concat(itemConf.Content.Count() + 1);
                table.addValue("id", id);
                //table.addValue("type", "1");
                //table.addValue("quality", "1");
                table.addValue("sz_name", "新增物品" + id);
            }
            else
            {
                table = new Mir2Server.Table();
                string id = string.Concat(itemConf.Content.Count() + 1);
                table.addValue("id", id);
                table.addValue("type", "1");
                table.addValue("quality", "1");
                table.addValue("sz_name", "新增物品" + id);
                
            }

            itemConf.addTable(table);

            updateItem();

            listBox1.SelectedIndex = itemConf.Content.Count() - 1;
        }

        private void confirmBtn_Click(object sender, EventArgs e)
        {
            if (currSelItemIndex < 0 || currSelItemIndex >= itemConf.Content.Count())
            {
                MessageBox.Show(this, "请先选择一个物品进行修改");
                return;
            }

            Table item = itemConf.Content[currSelItemIndex];
            string name = nameText.Text;
            string type = string.Concat(getTypeId(typeBox.Text));
            string spriteid = spriteText.Text;
            string iconId = iconText.Text;
            string needLevel = needLevelText.Text;
            string maxHp = maxHpText.Text;
            string maxMp = maxMpText.Text;
            string sz_description = descriText.Text;
            string quality = levelText.Text;

            string phyAtkMin = format(phyAtkMinText.Text);
            string phyAtkMax = format(phyAtkMaxText.Text);
            string magAtkMin = format(magAtkMinText.Text);
            string magAtkMax = format(magAtkMaxText.Text);
            string taoAtkMin = format(taoAtkMinText.Text);
            string taoAtkMax = format(taoAtkMaxText.Text);
            string phyDef = format(phyDefText.Text);
            string magDef = format(magDefText.Text);
            string taoDef = format(taoDefText.Text);
            string sz_atk = "{{" + phyAtkMin + "," + phyAtkMax + "},{" + magAtkMin + "," 
                + magAtkMax + "},{" + taoAtkMin + "," + taoAtkMax + "}}";
            string sz_dfs = "{" + phyDef + "," + magDef + "," + taoDef + "}";
            string critRate = critRateText.Text;
            string defenCrit = defenCritText.Text;
            string precise = preciseText.Text;
            string dodge = dodgeText.Text;
            string luck = luckText.Text;
            string slashSpeed = slashSpeedText.Text;

            item.addValue("sz_name", name);
            item.addValue("type", type);
            item.addValue("spriteid", spriteid);
            item.addValue("iconId", iconId);
            item.addValue("need_level", needLevel);
            item.addValue("maxHp", maxHp);
            item.addValue("maxMp", maxMp);
            item.addValue("sz_atk", sz_atk);
            item.addValue("sz_dfs", sz_dfs);
            item.addValue("sz_description", sz_description);
            item.addValue("quality", quality);
            item.addValue("critRate", critRate);
            item.addValue("defenCrit", defenCrit);
            item.addValue("precise", precise);
            item.addValue("dodge", dodge);
            item.addValue("luck", luck);
            item.addValue("slashSpeed", slashSpeed);

            updateItem();
            
            MessageBox.Show(this, "应用成功");
        }

        private string format(string str)
        {
            if (str == "")
                str = "0";

            return str;
        }

        private string getClassForType(int type)
        {
            if (type <= 10)
                return "Equipment";

            if (type == 11)
                return "BloodVial";

            if (type == 12)
                return "Ticket";

            if (type == 13)
                return "GoodPack";

            return "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog SaveFile = new SaveFileDialog();
            SaveFile.FileName = "equipment.tab";
            SaveFile.Filter = "装备表|*.xls|所有文件(*.*)|*.*";
            SaveFile.RestoreDirectory = true;
            if (SaveFile.ShowDialog() == DialogResult.OK)
            {
                StreamWriter sw = new StreamWriter(SaveFile.FileName, false);
                sw.WriteLine("id\tsz_name\tsz_name_en\tsz_class\tquality\ttype\tspriteid\ticonId\tneed_level\tmaxHp\tmaxMp\tsz_atk\tsz_dfs\tcritRate\tdefenCrit\tprecise\tdodge\tluck\tslashSpeed\tsz_description");
                for (int i = 0; i < itemConf.Content.Count(); ++i)
                {
                    int id = i + 1;
                    string name = itemConf.Content[i].getValue("sz_name");
                    string type = itemConf.Content[i].getValue("type");
                    string spriteid = itemConf.Content[i].getValue("spriteid");
                    string iconId = itemConf.Content[i].getValue("iconId");
                    string needLevel = itemConf.Content[i].getValue("need_level");
                    string maxHp = itemConf.Content[i].getValue("maxHp");
                    string maxMp = itemConf.Content[i].getValue("maxMp");
                    string sz_atk = itemConf.Content[i].getValue("sz_atk");
                    string sz_dfs = itemConf.Content[i].getValue("sz_dfs");
                    string sz_description = itemConf.Content[i].getValue("sz_description");
                    string quality = itemConf.Content[i].getValue("quality");
                    string critRate = itemConf.Content[i].getValue("critRate");
                    string defenCrit = itemConf.Content[i].getValue("defenCrit");
                    string precise = itemConf.Content[i].getValue("precise");
                    string dodge = itemConf.Content[i].getValue("dodge");
                    string luck = itemConf.Content[i].getValue("luck");
                    string slashSpeed = itemConf.Content[i].getValue("slashSpeed");

                    sw.WriteLine(id+"\t"+name+"\t"+"\t"+ getClassForType(int.Parse(type)) + "\t" + quality
                         + "\t" + type + "\t" + spriteid + "\t" + iconId + "\t" + needLevel + "\t" +maxHp
                          + "\t" + maxMp + "\t" + sz_atk + "\t" + sz_dfs + "\t" + critRate + "\t" + 
                          defenCrit + "\t"+ precise + "\t" + dodge + "\t" + luck + "\t" + slashSpeed + "\t" + sz_description);
                }

                sw.Close();

                MessageBox.Show(this, "保存成功");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (currSelItemIndex < 0 || currSelItemIndex >= itemConf.Content.Count())
            {
                MessageBox.Show("请先选择一个物品");
                return;
            }

            itemConf.Content.RemoveAt(currSelItemIndex);

            updateItem();
        }
    }
}
