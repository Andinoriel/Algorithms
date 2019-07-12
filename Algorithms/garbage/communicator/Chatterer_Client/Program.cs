// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
using System;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Chatterer_Client
{
    class Program
    {
        private static string userName;
        private static string host = "";
        private static int port = 0;
        private static TcpClient client;
        private static NetworkStream stream;

        static void Main(string[] args)
        {
            Console.WriteLine("\t\tChatterer_v0.5alpha");
            Console.WriteLine("\t\t Добро пожаловать!\n");
            Console.Write("Введите никнейм: ");
            userName = Console.ReadLine();
            Console.Write("Введите ip-адрес хоста: ");
            host = Console.ReadLine();
            Console.Write("Введите номер порта: ");
            port = int.Parse(Console.ReadLine());
            try
            {
                client = new TcpClient();
                try
                {
                    client.Connect(host, port);
                    stream = client.GetStream();
                    string message = userName;
                    byte[] buf = Encoding.Unicode.GetBytes(message);
                    stream.Write(buf, 0, buf.Length);
                    Thread thread = new Thread(new ThreadStart(ReceiveMessage));
                    thread.Start();
                    Console.WriteLine("\nДобро пожаловать, {" + userName + "}!\n");
                    SendMessage();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        static void SendMessage()
        {
            while (true)
            {
                string message = Console.ReadLine();
                byte[] buf = Encoding.Unicode.GetBytes(message);
                stream.Write(buf, 0, buf.Length);
            }
        }
        static void ReceiveMessage()
        {
            while (true)
            {
                try
                {
                    byte[] buf = new byte[64];
                    StringBuilder builder = new StringBuilder();
                    int bytes = 0;
                    do
                    {
                        bytes = stream.Read(buf, 0, buf.Length);
                        builder.Append(Encoding.Unicode.GetString(buf, 0, bytes));
                    }
                    while (stream.DataAvailable);
                    string message = builder.ToString();
                    Console.WriteLine(message);
                }
                catch
                {
                    Console.WriteLine("Соединение было утеряно!");
                    Disconnect();
                }
            }
        }
        static void Disconnect()
        {
            if (stream != null)
                stream.Close();
            if (client != null)
                client.Close();
            Environment.Exit(0);
        }
    }
}
