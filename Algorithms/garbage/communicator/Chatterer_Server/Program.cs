using System;
using System.Threading;

namespace Chatterer_Server
{
    class Program
    {
        static Server _server;
        static Thread _thread;
        static void Main(string[] args)
        {
            Console.WriteLine("\t\tChatterer_server_v0.5alpha");
            Console.WriteLine("\t\t    Добро пожаловать!");
            try
            {
                _server = new Server();
                _thread = new Thread(new ThreadStart(_server.Listen));
                _thread.Start();
            }
            catch(Exception ex)
            {
                _server.Disconnect();
                Console.WriteLine(ex.Message);
            }
        }
    }
}
