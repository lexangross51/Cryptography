using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;
using System.Security.Cryptography;

namespace Lab6
{
    class RabinMiller
    {
        public string[] RM(int n)
        {
            string[] res = new string[3];

            // счетчик числа итераций
            int count_iter = 0;

            if (n < 3) 
                Console.WriteLine("Слишком малое значение n! (n > 2)");

            // вычисляем верхнюю и нижнюю границу числа
            BigInteger lowerline = (BigInteger)Math.Pow(10, n - 1) + 1;
            BigInteger upperline = lowerline * 2 - 11;

            // выбиираем случаное число из возможного диапозона
            Random rnd = new Random();
            lowerline = rnd.Next((int)lowerline, (int)upperline);

            // выполняем замер времени
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();

            for (BigInteger i = lowerline; i <= upperline; i++)
            {
                count_iter++;
                if (Test(i, 10))
                {
                    res[0] = i.ToString();
                    Console.WriteLine(i);
                    break;
                }
            }

            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;

            Console.WriteLine("Для генерации простого числа потребовалось {0} итераций", count_iter);
            res[1] = count_iter.ToString();
            Console.WriteLine("Затраченное время составляет {0} миллисекунд", ts.Milliseconds);
            res[2] = ts.ToString();

            return res;
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
