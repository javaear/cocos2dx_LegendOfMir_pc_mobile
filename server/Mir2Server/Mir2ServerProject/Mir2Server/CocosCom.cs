using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Mir2Server
{
    class CocosCom
    {
        private bool isInit = false;

        public bool init()
        {
            bool b = Cocos2dxCSharp.NativeInterface.Initialize();
            isInit = b;

            return b;
        }

        public bool start()
        {
            return Cocos2dxCSharp.NativeInterface.Start();
        }

        public void mainLoop()
        {
            Cocos2dxCSharp.NativeInterface.MainLoop();
        }

        public string getLogMessage(int type)
        {
            if (isInit == false)
                return "";

            Cocos2dxCSharp.NativeInterface.MainLoop();
            IntPtr ptr = Cocos2dxCSharp.NativeInterface.getLogMessage(type);

            string str = Marshal.PtrToStringAnsi(ptr);
            return str;
        }

        public void excCodes(string codes)
        {
            Cocos2dxCSharp.NativeInterface.ExcStr(codes);
        }

        public string getLuaVariable(string variable)
        {
            if (isInit == false)
                return "";

            IntPtr ptr = Cocos2dxCSharp.NativeInterface.getLuaVariable(variable);

            string str = Marshal.PtrToStringAnsi(ptr);
            return str;
        }

        public string getLuaTable(string table, string field)
        {
            if (isInit == false)
                return "";

            IntPtr ptr = Cocos2dxCSharp.NativeInterface.getLuaTable(table, field);

            string str = Marshal.PtrToStringAnsi(ptr);
            return str;
        }

        public string getLuaFunction(string func, string param)
        {
            if (isInit == false)
                return "";

            IntPtr ptr = Cocos2dxCSharp.NativeInterface.getLuaFunction(func, param);

            string str = Marshal.PtrToStringAnsi(ptr);
            return str;
        }

        public string getLuaFunctionUni(string func, string param)
        {
            if (isInit == false)
                return "";

            IntPtr ptr = Cocos2dxCSharp.NativeInterface.getLuaFunction(func, param);

            string str = Marshal.PtrToStringUni(ptr);
            return str;
        }

        public void debug()
        {
            Cocos2dxCSharp.NativeInterface.Debug();
        }

        public void destroy()
        {
            Cocos2dxCSharp.NativeInterface.Destory();
        }
    }
}
