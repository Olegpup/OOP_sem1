using System;

namespace lab_9_cs
{
    class Program
    {
        static void Main()
        {
            var Porsche = new Car("Porsche 13348++", 70);
            Porsche.Event += Porsche.Show;
            
            Porsche.Ride();
            Porsche.Start();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.Ride();
            Porsche.FillUp(70);
            Porsche.Start();
            Porsche.Ride();
            Console.WriteLine();
            
            Porsche.ShowArray(Porsche.Array);
            Porsche.bubbleStaticSort();
            Porsche.ShowArray(Porsche.Array);
        }
    }
}

