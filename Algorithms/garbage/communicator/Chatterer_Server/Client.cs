// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
using System;
using System.Net.Sockets;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace Chatterer_Server
{
    public class Client
    {
        protected internal string _ClientID { get; private set; }
        protected internal NetworkStream _NWStream { get; private set; }
        string _ClientName;
        TcpClient _Client;
        Server _Server;

        public Client(TcpClient _Client, Server _Server)
        {
            this._ClientID = Guid.NewGuid().ToString();
            this._Client = _Client;
            this._Server = _Server;
            _Server.AddConnection(this);
        }
        public void Run()
        {
            try
            {
                _NWStream = this._Client.GetStream();
                var message = getMessage();
                _ClientName = message;
                if (this._Server.usernames.Contains(_ClientName))
                {
                    this._Server.CallBackMessage("\nПользователь с таким именем уже в сети!", this._ClientID);
                    _Server.RemoveConnection(this._ClientID);
                }
                else
                {
                    this._Server.usernames.Add(_ClientName);
                    message = "\nПользователь {" + this._ClientName + "} в сети.\n";
                    _Server.SysMessage(message, this._ClientID);
                    Console.WriteLine(message);
                    while (true)
                    {
                        try
                        {
                            message = getMessage();
                            message = this._ClientName + ": " + message;
                            Console.WriteLine(message);
                            _Server.SysMessage(message, this._ClientID);
                        }
                        catch
                        {
                            message = "\nПользователь {" + this._ClientName + "} вышел из сети.\n";
                            this._Server.usernames[this._Server.usernames.FindIndex(name => name == _ClientName)] = null;
                            Console.WriteLine(message);
                            _Server.SysMessage(message, this._ClientID);
                            break;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                _Server.RemoveConnection(this._ClientID);
                Close();
            }
        }
        public string getMessage()
        {
            byte[] buf = new byte[64];
            StringBuilder builder = new StringBuilder();
            int bytes = 0;
            do
            {
                bytes = this._NWStream.Read(buf, 0, buf.Length);
                builder.Append(Encoding.Unicode.GetString(buf, 0, bytes));
            }
            while (_NWStream.DataAvailable);
            return builder.ToString();
        }
        protected internal void Close()
        {
            if (this._NWStream != null)
                this._NWStream.Close();
            if (this._Client != null)
                this._Client.Close();
        }
    }
}
