using System;

namespace lab_1_cs
{
    class Program
    {
        static int subtract(int A, int B)
        {
            while (B != 0)
            {
                int temp = (~A) & B; // інверсія бітів числа А І біти числа B

                A = A ^ B; // Виключаюче АБО

                B = temp << 1;
            }
            return A;
        }
        static void Inkrement(ref int A)
        {
            A = subtract(0, ~A); // міняємо знак числа A з інвертованим двійковим представленням
        }


        static bool Is_first_bigger(int A, int B)
        {

            int temp_1, temp_2;
            int result = 0;
            for (int i = 31; (i >= 0) && (result == 0); i--) // проходимо кожен біт (цифру) бінарного представлення числа
            {
                temp_1 = (A & (1 << i)) >> i; // виконуємо побітовий зсув вправо на i числа з застосованою бітовою маскою
                temp_2 = (B & (1 << i)) >> i;
                result = subtract(temp_1, temp_2);
            }

            if (result == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        static void Main(string[] args)
        {
            Console.WriteLine("Enter three numbers: ");
            int A = Convert.ToInt32(Console.ReadLine());
            int B = Convert.ToInt32(Console.ReadLine());
            int C = Convert.ToInt32(Console.ReadLine());
            if (Is_first_bigger(A, B))
            {
                Console.WriteLine("{0} is bigger than {1}", A, B);
            }
            else
            {
                Console.WriteLine("{0} isn't bigger than {1}", A, B);
            }
            Inkrement(ref A);
            Inkrement(ref B);
            Inkrement(ref C);
            Console.WriteLine("Incremented first number: {0}", A);
            Console.WriteLine("Incremented second number: {0}", B);
            Console.WriteLine("Incremented third number: {0}", C);
        }
    }
}
