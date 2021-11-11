using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
    
    private void button1_Click(object sender, EventArgs e)
    {
            var CR = new Creater();

            int m = 1;
            double[] r = new double[16] { 3.841, 5.991, 7.815, 9.488, 11.070, 12.592, 14.067, 15.507, 16.919, 18.307, 19.675, 21.026, 22.362, 23.685, 24.996, 26.296 };
            string[] outq = new string[m];
            int F = 0;
            int Q = 0;
            int N = 0;
            int Per = 0;
            int f = 0;
            N = Convert.ToInt32(textBox1.Text);
            F = Convert.ToInt32(textBox3.Text);
            Q = Convert.ToInt32(textBox4.Text);

            outq = CR.Creat_seq(N, Q, F);

            for (int i = 0; i < outq.Length; i++)
            {
                richTextBox2.Text += outq[i] + " ";
            }

            Per = CR.Peroid(outq);

            textBox5.Text = Per.ToString();

            if(CR.Ver_Pirs(outq, r))
                textBox6.Text = "Да";
            else
                textBox6.Text = "Нет";

            for (int i = 0; i < outq.Length; i++)
            {
                richTextBox1.Text += outq[i] + " ";
                f++;
                if (f == Per)
                {
                    richTextBox1.Text += Environment.NewLine;
                    f = 0;
                }
            }
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }      
}
 