using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Mir2Server
{
    public class Table : ICloneable
    {
        public Dictionary<string, string> m_keyValue = new Dictionary<string, string>();

        object ICloneable.Clone()
        {
            return this.Clone();
        }

        public Table Clone()
        {
            Table newT = new Table();

            foreach (KeyValuePair<string, string> values in m_keyValue)
            {
                newT.addValue(values.Key, values.Value);
            }

            return newT;
        }

        public void addValue(string k, string v)
        {
            m_keyValue[k] = v;
        }

        public string getValue(string k)
        {
            if (m_keyValue.ContainsKey(k) == false)
                return "";

            return m_keyValue[k];
        }

        public void delValue(string k)
        {
            m_keyValue.Remove(k);
        }
    }

    public class TableConf
    {
        private List<string> keyList = new List<string>();
        private List<Table> content = new List<Table>();

        public List<Table> Content
        {
            get
            {
                return content;
            }

            set
            {
                content = value;
            }
        }

        public Table getTable(int index)
        {
            return Content[index];
        }

        public void addTable(Table t)
        {
            Content.Add(t);
        }

        public void readTxt(string txt)
        {
            if (txt == null)
                return;
   
            string[] data = txt.Split('\n');

            int startIndex = 0;
            for (int i = 0; i < data.Count(); ++i)
            {
                if (data[i].Contains("#") == true)
                {
                    startIndex = i + 1;
                }
            }

            string[] keys = data[startIndex].Split('\t');
            for (int i = 0; i < keys.Count(); ++i)
            {
                keyList.Add(keys[i]);
            }

            for (int i = startIndex+1; i < data.Count(); ++i)
            {
                string[] tableData = data[i].Split('\t');
                Table table = new Table();

                if (tableData.Count() > 2)
                {
                    for (int j = 0; j < tableData.Count(); ++j)
                    {
                        table.addValue(keyList[j], tableData[j]);
                    }

                    Content.Add(table);
                }
                else
                {
                }
            }
        }
    }
}
