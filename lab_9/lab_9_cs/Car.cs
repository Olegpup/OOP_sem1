using System;
using System.Collections.Generic;
using System.Text;

namespace lab_9_cs
{
    class Car
    {
        public int[] Array = { 5, 3, 2, 6, 1, 4 };
        
        public delegate void Delegate(object sender, string message);
        public event Delegate Event;
        public string Name { get; set; }
        private int GasLimit { get; set; } 
        private bool onRide = false;

        public Car(string name, int gasLimit)
        {
            Name = name;
            GasLimit = gasLimit;
        }
        
        private void Stop()
        {
            onRide = false;
            Console.WriteLine($"{Name} stopped");
        }
        
        public void Start()
        {
            if (GasLimit > 0)
            {
                onRide = true;
            }
            else
            {
                Stop();
                Event.Invoke(this, $"{Name} needs a gas to start!");
            }
        }
        
        public void Ride()
        {
            if (onRide && GasLimit > 0)
            {
                Console.WriteLine("Car rides");
                GasLimit -= 10;   
            }
            else
            {
                Stop();
                Event.Invoke(this, $"{Name} needs to be on ride and have a gas!");
            }
        }
        
        
        public void FillUp(int gas)
        {
            GasLimit = gas;
            Console.WriteLine("Done!");
        }
        
        public void Show(object obj, string message)
        {
            Console.WriteLine(message);
        }
        
        public void bubbleStaticSort()
        {
            int n = Array.Length;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (Array[j] > Array[j + 1])
                    {
                        int temp = Array[j];
                        Array[j] = Array[j + 1];
                        Array[j + 1] = temp;
                    }
                }
            }
        }
        
        static void bubbleSort(int []array)
        {
            int n = array.Length;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }

        public void ShowArray(int[] arr)
        {
            foreach (int i in arr)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine("\n");
        }
    }
}
