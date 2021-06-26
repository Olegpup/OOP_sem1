using System;

namespace lab_8_cs
{
    class Program
    {
        static void Main()
        {
            var list = new List();
            list.AppendToStart('q');
            list.AppendToStart('w');
            list.AppendToStart('e');
            list.AppendToStart('a');
            list.AppendToStart('a');
            list.AppendToStart('!');
            list.AppendToStart('a');
            list.AppendToStart('a');
            
            list.Show();
            Node point = list.GetExclamationPoint();
            list.DeleteA();
            list.Show();
            Console.Write(point.value);
        }
    }
}
