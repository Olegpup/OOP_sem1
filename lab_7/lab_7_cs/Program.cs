using System;

namespace lab_7_cs
{
    class WrongOperand : Exception          //my own exception class 
    {
        public string Text { private set; get; }

        public WrongOperand(string a)
        {
            Text = a;
        }
    }

    class Foo
    {
        private double _a;

        public double A         //propertys
        {
            get
            {
                return _a;  
            }
            set
            {
                if (value == 4 || value < 0)
                {
                    throw new WrongOperand("Value of a is invalid");        //throwing exception 
                }
                _a = value;
            }
        }
        public double B { get; set; }
        public double C { get; set; }
        public double D { get; set; }

        public Foo()
        {

        }

        public Foo(double a, double b, double c, double d)        //polinom function
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }

        public double GetValue()
        {
            return (2 * C - D + Math.Sqrt(23 * A)) / (A / 4 - 1);
        }
    }

    class Program
    {
        static void Main()
        {
            var polynom1 = new Foo();

            try
            {
                Console.WriteLine("Enter a: ");
                polynom1.A = Convert.ToDouble(Console.ReadLine());

                Console.WriteLine("Enter b: ");
                polynom1.B = Convert.ToDouble(Console.ReadLine());

                Console.WriteLine("Enter c: ");
                polynom1.C = Convert.ToDouble(Console.ReadLine());

                Console.WriteLine("Enter d: ");
                polynom1.D = Convert.ToDouble(Console.ReadLine());

                var polynom2 = new Foo(12, 1, 3, 7);
                
                Console.WriteLine($"a, b, c, d \nF({polynom1.A}, {polynom1.B}, {polynom1.C}, {polynom1.D}) = {polynom1.GetValue()}");
                Console.WriteLine($"a, b, c, d \nF({polynom2.A}, {polynom2.B}, {polynom2.C}, {polynom2.D}) = {polynom2.GetValue()}");
            }
            catch (WrongOperand exc)
            {
                Console.WriteLine(exc.Text);
            }
            Console.ReadKey();
        }
    }
}
