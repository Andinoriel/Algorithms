using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;

namespace Chatterer_Server
{
    public class Server
    {
        static TcpListener listener;
        static string port = "";
        List<Client> clients = new List<Client>();
        public List<string> usernames;

        public Server()
        {
            this.usernames = new List<string>();
        }

        protected internal void AddConnection(Client _Client)
        {
            this.clients.Add(_Client);
        }
        protected internal void RemoveConnection(string id)
        {
            Client client = this.clients.FirstOrDefault(c => c._ClientID == id);
            if (client != null)
                clients.Remove(client);
        }
        protected internal void Listen()
        {
            try
            {
                Console.Write("\nВведите номер порта: ");
                port = Console.ReadLine();
                listener = new TcpListener(IPAddress.Any, int.Parse(port));
                listener.Start();
                Console.WriteLine("\nСервер запущен. Ожидание подключений...\n\n");
                while (true)
                {
                    TcpClient tcpCclient = listener.AcceptTcpClient();
                    Client client = new Client(tcpCclient, this);
                    Thread thread = new Thread(new ThreadStart(client.Run));
                    thread.Start();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Disconnect();
            }
        }
        protected internal void SysMessage(string message, string id)
        {
            byte[] buf = Encoding.Unicode.GetBytes(message);
            for (int i = 0; i < clients.Count(); ++i)
            {
                if (clients[i]._ClientID != id)
                    clients[i]._NWStream.Write(buf, 0, buf.Length);
            }
        }
        protected internal void CallBackMessage(string message, string id)
        {
            byte[] buf = Encoding.Unicode.GetBytes(message);
            for (int i = 0; i < clients.Count(); ++i)
            {
                if (clients[i]._ClientID == id)
                    clients[i]._NWStream.Write(buf, 0, buf.Length);
            }
        }
        protected internal void Disconnect()
        {
            listener.Stop();
            for (int i = 0; i < clients.Count; ++i)
                clients[i].Close();
            Environment.Exit(0);
        }
    }
}