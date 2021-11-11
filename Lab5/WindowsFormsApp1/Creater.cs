using System;
using System.Collections.Generic;
using System.IO;

namespace WindowsFormsApp1
{
    class Creater
    {
        public void Write(string fileName, string[] outw) 
        {
            using (StreamWriter sw = new StreamWriter(fileName))
            {
                foreach (string str in outw)
                    sw.WriteLine(str);
            }
        }

        public string[] Read(string fileName) 
        {
            List<string> list = new List<string>();
            using (StreamReader reader = new StreamReader(fileName))
            {
                while (!reader.EndOfStream)
                {
                    string str = reader.ReadLine();
                    list.Add(str);
                }
            }
            return list.ToArray();
        }

        public string[] Creat_seq(int N, int Q, int F) 
        {
            string[] seq = new string[Q * 2];
            int nx = 0, cu = 0, pr = 0;
            cu = F;
            nx = (cu + pr) % N;
            seq[0] = nx.ToString();
            for (int i = 1; i < Q * 2; i++)
            {
                pr = cu;
                cu = nx;
                nx = (cu + pr) % N;
                seq[i] = nx.ToString();
            }
            return seq;
        }

        public int Peroid(string[] seq) 
        {
            int per = 1;
            int step = 0;
            while(step + per != seq.Length)
            {
                if (seq[step] != seq[per + step])
                {
                    ++per;
                    step = 0;
                }
                else
                    ++step;
            }
            return per;
        }

        public int Max(int[] str) 
        {
            int max = 0;
            max = str[0];
            for (int i = 1; i < str.Length; i++)
            {
                if (max < str[i])
                    max = str[i];
            }
            return max;
        }

        public bool Ver_Pirs(string[] seq, double[] alf) 
        {
            double Sk = 0;
            double S = 0;
            double buf = 0;
            int K = 0;
            double P = 0;
            int b = 0;
            double N = 0;

            int[] s = new int[seq.Length / 2];

            for (int i = 0; i < s.Length; i++)
                s[i] = Convert.ToInt32(seq[i]);

            int M = Max(s);
            if (M < 10)
                N = M;
            else
                N = 5 * Math.Log10(s.Length);

            K = Convert.ToInt32(N);

            P = 1 / K;

            int[] v = new int[K];

            for (int i = 0; i < s.Length; i++)
            {
                v[b] += 1;

                if (i % K == 0)
                    b++;
            }

            for (int i = 0; i < K; i++)
                buf += Math.Pow((v[i] / s.Length - P), 2) / P;

            S = s.Length * buf;

            int r = K - 1;
            Sk = alf[r];

            if (S > Sk)
                return false;
            else
                return true;
        }
    }
}
