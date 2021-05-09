using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Cocos2dxCSharp
{
    class NativeInterface
    {
        const string DLL_NAME = "CocosCom.dll";

        [DllImport("CocosCom.dll", EntryPoint = "Debug", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Debug();

        [DllImport("CocosCom.dll", EntryPoint = "Initialize", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Initialize();

        [DllImport("CocosCom.dll", EntryPoint = "Start", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Start();

        [DllImport("CocosCom.dll", EntryPoint = "MainLoop", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MainLoop();

        //[DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl)]
        [DllImport("CocosCom.dll", EntryPoint = "Destory", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Destory();

        [DllImport("CocosCom.dll", EntryPoint = "ExcStr", CallingConvention = CallingConvention.Cdecl)]
        public extern static void ExcStr(string codes);

        [DllImport("CocosCom.dll", EntryPoint = "getLogMessage", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr getLogMessage(int type);

        [DllImport("CocosCom.dll", EntryPoint = "getLuaVariable", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr getLuaVariable(string variable);

        [DllImport("CocosCom.dll", EntryPoint = "getLuaTable", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr getLuaTable(string table, string field);

        [DllImport("CocosCom.dll", EntryPoint = "getLuaFunction", CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr getLuaFunction(string func, string param);
    }
}
