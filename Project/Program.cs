//Not working code is for remind purpose
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
var parser = new FileIniDataParser();

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                IniData data = parser.ReadFile("Configuration.ini");
                string comPort = data["General"]["COMPort"];
                SerialPort port = new SerialPort("COMPort",
                9600, Parity.None, 8, StopBits.One);
                port.Open();
                port.Write(args[0]);
            }
            else if ([args.object == "mame"])
            {
                IniData data = parser.ReadFile("Configuration.ini");
                string comPort = data["General"]["COMPort"];
                SerialPort port = new SerialPort("COMPort",
                9600, Parity.None, 8, StopBits.One);
                port.Open();
                port.Write("3");
            }
        }
    }
}
