using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;
using System.Security.Cryptography;
using System.IO;

namespace Lab7
{
    class Ferma
    {
        public Dictionary<int, int> FermaMethodTest(int n, string[] res)
        {
            // счетчик числа итераций
            int count_iter = 0;

            if (n < 0) throw new Exception("Слишком малое значение n! (n > 0)");

            Dictionary<int, int> multipliers = new Dictionary<int, int>();

            // выполняем замер времени
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();

            while (!Test(n, 10) && n > 1)
            {
                count_iter++;
                int a = FermaMethod(n);
                if (multipliers.ContainsKey(a) == false)  multipliers.Add(a, 1);
                else multipliers[a]++; 
                n /= a;
            }
            if (multipliers.ContainsKey(n) == false)  multipliers.Add(n, 1); 
            else  multipliers[n]++; 

            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;

            // вывод множителей и их степеней на консоль
            foreach (KeyValuePair<int, int> keyValue in multipliers)
            {
                Console.WriteLine("Множитель - " + keyValue.Key + "; степень - " + keyValue.Value);
            }

            res[0] = count_iter.ToString();
            res[1] = ts.Milliseconds.ToString();

            return multipliers;
        }

        static int FermaMethod(int n)
        {
            if (n % 2 == 0) return 2;
            if (n % 3 == 0) return 3;
            if (n % 5 == 0) return 5;
            if (n % 7 == 0) return 7;
            if (n % 11 == 0) return 11;
            if (n % 13 == 0) return 13;
            if (n % 17 == 0) return 17;
            if (n % 19 == 0) return 19;

            for (int x = (int)Math.Sqrt(n); x <= n / 2 + 1; x++)
            {
                // t = x^2 - n
                int t = x * x - n;
                if (t >= 0)
                {
                    // if t = y^2
                    int y = (int)Math.Sqrt(t);
                    if (t == y * y) { return x - y; }
                }
            }
            return 1;
        }

        // производится k раундов проверки числа n на простоту
        static bool Test(BigInteger n, int k)
        {
            // если n == 2 или n == 3 - эти числа простые, возвращаем true
            if (n == 2 || n == 3)
                return true;

            // если n < 2 или n четное - возвращаем false
            if (n < 2 || n % 2 == 0)
                return false;

            // представим n − 1 в виде (2^s)·t, где t нечётно, это можно сделать по-следовательным делением n - 1 на 2
            BigInteger t = n - 1;

            int s = 0;

            while (t % 2 == 0)
            {
                t /= 2;
                s += 1;
            }

            // повторить k раз
            for (int i = 0; i < k; i++)
            {
                // выберем случайное целое число a в отрезке [2, n − 2]
                RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();
                byte[] _a = new byte[n.ToByteArray().LongLength];
                BigInteger a;

                do
                {
                    rng.GetBytes(_a);
                    a = new BigInteger(_a);
                }
                while (a < 2 || a >= n - 2);

                // x <- a^t mod n, вычислим с помощью возведения в степень по модулю
                BigInteger x = BigInteger.ModPow(a, t, n);

                // если x == 1 или x == n − 1, то перейти на следующую итерацию цик-ла
                if (x == 1 || x == n - 1) { continue; }

                // повторить s − 1 раз
                for (int r = 1; r < s; r++)
                {
                    // x = x^2 mod n
                    x = BigInteger.ModPow(x, 2, n);
                    // если x == 1, то вернуть "составное"
                    if (x == 1) { return false; }
                    // если x == n − 1, то перейти на следующую итерацию внешнего цикла
                    if (x == n - 1) { break; }
                }
                if (x != n - 1) { return false; }
            }
            // вернуть "вероятно простое"
            return true;
        }
    }
}
