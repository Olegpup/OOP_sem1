using System;
namespace lab_8_cs
{
    class Node
    {
        public char value;
        public Node nextNode;

        public Node(char value)
        {
            this.value = value;
            nextNode = null;
        }
    }


    class List
    {
        private int Length = 0;
        public Node Start = null;
        public Node End = null;

        private bool IsEmpty()
        {
            return End == null;
        }

        public void AppendToStart(char value)
        {
            var node = new Node(value);

            if (IsEmpty())
            {
                Start = node;
                End = node;
                Length++;
            }
            else
            {
                Node tempNode = Start;

                Start = node;
                Start.nextNode = tempNode;
                Length++;
            }
        }
        

        public void DeleteA()
        {
            Node currentNode = Start;
            Node node = null;
            int tempLength = Length;
            

            while (tempLength > 0)
            {
                if (currentNode.value == 'a' && node == null)
                {
                    currentNode = Start.nextNode;
                    Start = Start.nextNode;

                    Length--;
                }
                else if (currentNode.value == 'a' && currentNode.nextNode == null)
                {
                    End = node;
                    End.nextNode = null;
                    Length--;
                }
                else if (currentNode.value == 'a')
                {

                    currentNode = currentNode.nextNode;
                    node.nextNode = currentNode;
                    
                    Length--;
                }
                else
                {
                    node = currentNode;
                    currentNode = currentNode.nextNode;
                }
                tempLength--;
            }
        }
        
        public Node GetExclamationPoint()
        {
            int tempLength = Length;
            Node currentNode = Start;
            while (tempLength > 0)
            {
                if (currentNode.value == '!')
                {
                    return currentNode;
                }
                currentNode = currentNode.nextNode;
                tempLength--;
            }
            return null;
        }
        
        public void Show()
        {
            if (Length > 0)
            {
                Node currentNode = Start;
                int tempNode = Length;
                while (tempNode > 0)
                {
                    Console.Write($"{currentNode.value} ");
                    currentNode = currentNode.nextNode;
                    tempNode--;
                }
            }
            Console.WriteLine("\n");
        }
    }
}