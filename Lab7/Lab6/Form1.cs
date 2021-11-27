using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var ferma = new Ferma();

            int n = Convert.ToInt32(textBox1.Text);

            string[] res = new string[2];

            Dictionary<int, int> mults = ferma.FermaMethodTest(n, res);

            textBox3.Clear();
            textBox3.Text += res[0];

            textBox4.Clear();
            textBox4.Text += res[1];


            foreach (var i in mults)
            {
                string s = "Множитель: ";
                s += i.Key.ToString();
                s += "   Степень: ";
                s += i.Value.ToString();
                s += "\n";
                richTextBox1.Text += s;
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
