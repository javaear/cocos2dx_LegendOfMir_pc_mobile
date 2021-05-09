res文件是配置文件和资源文件，创建cocos 的
lua项目后覆盖即可

runtime-src项目是cocos lua 项目的C++文件，覆盖cocos lua 项目的runtime-src文件夹即可
src是lua文件，包括主要逻辑代码

lua_cocos2dx_extratools的头文件和cpp文件放到cocos项目的luacocos项目下
即cocos2d-x\cocos\scripting\lua-bindings\auto路径下，然后重编译该项目


MirApp.rar包含已经编译好的win32文件,但是不包括res里的资源文件和src的lua逻辑文件
把res和src文件和MirApp解压到同一路径下，即可直接执行程序
注意不要放在中文路径下。