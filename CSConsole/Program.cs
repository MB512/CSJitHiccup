namespace ConsoleApp17
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sum = 0.0;
            for (int i = 0; i < int.MaxValue; i++)
            {
                try
                {
                    sum += ClassLibrary1.Class1.Test(Math.PI);
                } catch {
                    Console.Write("E");
                }
                if (i % 100000 == 0) { Console.Write("."); }
            }

            Console.WriteLine(sum);
        }
    }
}
