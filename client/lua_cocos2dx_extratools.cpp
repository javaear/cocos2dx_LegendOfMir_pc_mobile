#include "scripting/lua-bindings/auto/lua_cocos2dx_extratools.hpp"
#include "MyTextField.h"
#include "CursorTextField.h"
#include "MirFileLoader.h"
#include "ODClient.h"
#include "MirTileMap.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_cocos2dx_extratools_MyTextField_onTextFieldDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldDeleteBackward'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "MyTextField:onTextFieldDeleteBackward");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyTextField:onTextFieldDeleteBackward"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MyTextField:onTextFieldDeleteBackward");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldDeleteBackward'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldDeleteBackward(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:onTextFieldDeleteBackward",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldDeleteBackward'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_setTextPosition(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_setTextPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MyTextField:setTextPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "MyTextField:setTextPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_setTextPosition'", nullptr);
            return 0;
        }
        cobj->setTextPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:setTextPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_setTextPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_setTextName(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_setTextName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyTextField:setTextName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_setTextName'", nullptr);
            return 0;
        }
        cobj->setTextName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:setTextName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_setTextName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_setText(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_setText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyTextField:setText"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_setText'", nullptr);
            return 0;
        }
        cobj->setText(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:setText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_setText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_getIsTttachIME(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_getIsTttachIME'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_getIsTttachIME'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsTttachIME();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:getIsTttachIME",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_getIsTttachIME'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_getInputText(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_getInputText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_getInputText'", nullptr);
            return 0;
        }
        std::string ret = cobj->getInputText();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:getInputText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_getInputText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_init(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MyTextField:init"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyTextField:init"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2, "MyTextField:init");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:init",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_setMaxLineWidth(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_setMaxLineWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MyTextField:setMaxLineWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_setMaxLineWidth'", nullptr);
            return 0;
        }
        cobj->setMaxLineWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:setMaxLineWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_setMaxLineWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_onTextFieldInsertText(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldInsertText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "MyTextField:onTextFieldInsertText");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyTextField:onTextFieldInsertText"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "MyTextField:onTextFieldInsertText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldInsertText'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldInsertText(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:onTextFieldInsertText",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_onTextFieldInsertText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_setColor(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MyTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MyTextField_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MyTextField:setColor");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MyTextField:setColor");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MyTextField:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:setColor",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MyTextField_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MyTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        cocos2d::Node* arg0;
        const char* arg1;
        const char* arg2;
        double arg3;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "MyTextField:create");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MyTextField:create"); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MyTextField:create"); arg2 = arg2_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 5,&arg3, "MyTextField:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_create'", nullptr);
            return 0;
        }
        MyTextField* ret = MyTextField::create(arg0, arg1, arg2, arg3);
        object_to_luaval<MyTextField>(tolua_S, "MyTextField",(MyTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MyTextField:create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_MyTextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MyTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MyTextField_constructor'", nullptr);
            return 0;
        }
        cobj = new MyTextField();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MyTextField");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MyTextField:MyTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MyTextField_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extratools_MyTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MyTextField)");
    return 0;
}

int lua_register_cocos2dx_extratools_MyTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MyTextField");
    tolua_cclass(tolua_S,"MyTextField","MyTextField","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"MyTextField");
        tolua_function(tolua_S,"new",lua_cocos2dx_extratools_MyTextField_constructor);
        tolua_function(tolua_S,"onTextFieldDeleteBackward",lua_cocos2dx_extratools_MyTextField_onTextFieldDeleteBackward);
        tolua_function(tolua_S,"setTextPosition",lua_cocos2dx_extratools_MyTextField_setTextPosition);
        tolua_function(tolua_S,"setTextName",lua_cocos2dx_extratools_MyTextField_setTextName);
        tolua_function(tolua_S,"setText",lua_cocos2dx_extratools_MyTextField_setText);
        tolua_function(tolua_S,"getIsTttachIME",lua_cocos2dx_extratools_MyTextField_getIsTttachIME);
        tolua_function(tolua_S,"getInputText",lua_cocos2dx_extratools_MyTextField_getInputText);
        tolua_function(tolua_S,"init",lua_cocos2dx_extratools_MyTextField_init);
        tolua_function(tolua_S,"setMaxLineWidth",lua_cocos2dx_extratools_MyTextField_setMaxLineWidth);
        tolua_function(tolua_S,"onTextFieldInsertText",lua_cocos2dx_extratools_MyTextField_onTextFieldInsertText);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_extratools_MyTextField_setColor);
        tolua_function(tolua_S,"create", lua_cocos2dx_extratools_MyTextField_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MyTextField).name();
    g_luaType[typeName] = "MyTextField";
    g_typeCast["MyTextField"] = "MyTextField";
    return 1;
}

int lua_cocos2dx_extratools_CursorTextField_onTextFieldAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldAttachWithIME'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextFieldTTF* arg0;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "CursorTextField:onTextFieldAttachWithIME");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldAttachWithIME'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldAttachWithIME(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:onTextFieldAttachWithIME",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldAttachWithIME'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getPosiformPosi(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_getPosiformPosi'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CursorTextField:getPosiformPosi");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "CursorTextField:getPosiformPosi");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getPosiformPosi'", nullptr);
            return 0;
        }
        int ret = cobj->getPosiformPosi(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:getPosiformPosi",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getPosiformPosi'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_BlickSpriteLeft(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteLeft'", nullptr);
            return 0;
        }
        cobj->BlickSpriteLeft();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:BlickSpriteLeft",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setInputWidth(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setInputWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CursorTextField:setInputWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setInputWidth'", nullptr);
            return 0;
        }
        cobj->setInputWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setInputWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setInputWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setInpuntText(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setInpuntText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CursorTextField:setInpuntText"); arg0 = (char*)arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setInpuntText'", nullptr);
            return 0;
        }
        cobj->setInpuntText(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setInpuntText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setInpuntText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getInputText(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_getInputText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getInputText'", nullptr);
            return 0;
        }
        const char* ret = cobj->getInputText();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:getInputText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getInputText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_isInTextField(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_isInTextField'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "CursorTextField:isInTextField");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_isInTextField'", nullptr);
            return 0;
        }
        bool ret = cobj->isInTextField(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:isInTextField",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_isInTextField'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_onTextFieldDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDeleteBackward'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "CursorTextField:onTextFieldDeleteBackward");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CursorTextField:onTextFieldDeleteBackward"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CursorTextField:onTextFieldDeleteBackward");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDeleteBackward'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldDeleteBackward(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:onTextFieldDeleteBackward",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDeleteBackward'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_split_text(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_split_text'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CursorTextField:split_text");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CursorTextField:split_text");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CursorTextField:split_text");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_split_text'", nullptr);
            return 0;
        }
        std::string ret = cobj->split_text(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:split_text",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_split_text'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getRect(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_getRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getRect'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getRect();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:getRect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getRect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setChildName(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setChildName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CursorTextField:setChildName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setChildName'", nullptr);
            return 0;
        }
        cobj->setChildName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setChildName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setChildName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_init(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getPosifromText(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_getPosifromText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CursorTextField:getPosifromText");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CursorTextField:getPosifromText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getPosifromText'", nullptr);
            return 0;
        }
        int ret = cobj->getPosifromText(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:getPosifromText",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getPosifromText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getLabelWidth(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_getLabelWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CursorTextField:getLabelWidth");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CursorTextField:getLabelWidth");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "CursorTextField:getLabelWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getLabelWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getLabelWidth(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:getLabelWidth",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getLabelWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_closeIME(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_closeIME'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_closeIME'", nullptr);
            return 0;
        }
        cobj->closeIME();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:closeIME",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_closeIME'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_MyRemoveFromParent(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_MyRemoveFromParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_MyRemoveFromParent'", nullptr);
            return 0;
        }
        cobj->MyRemoveFromParent();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:MyRemoveFromParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_MyRemoveFromParent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_initCursorSprite(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_initCursorSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CursorTextField:initCursorSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_initCursorSprite'", nullptr);
            return 0;
        }
        cobj->initCursorSprite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:initCursorSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_initCursorSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setPosition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "CursorTextField:setPosition");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "CursorTextField:setPosition");

            if (!ok) { break; }
			float agr0f = (float)arg0;
			float arg1f = (float)arg1;
            cobj->setPosition(agr0f, arg1f);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Point arg0;
            ok &= luaval_to_point(tolua_S, 2, &arg0, "CursorTextField:setPosition");

            if (!ok) { break; }
            cobj->setPosition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CursorTextField:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_onTextFieldInsertText(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldInsertText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "CursorTextField:onTextFieldInsertText");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CursorTextField:onTextFieldInsertText"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CursorTextField:onTextFieldInsertText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldInsertText'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldInsertText(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:onTextFieldInsertText",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldInsertText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_onTextFieldDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDetachWithIME'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextFieldTTF* arg0;

        ok &= luaval_to_object<cocos2d::TextFieldTTF>(tolua_S, 2, "cc.TextFieldTTF",&arg0, "CursorTextField:onTextFieldDetachWithIME");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDetachWithIME'", nullptr);
            return 0;
        }
        bool ret = cobj->onTextFieldDetachWithIME(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:onTextFieldDetachWithIME",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_onTextFieldDetachWithIME'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setPositionX(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setPositionX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CursorTextField:setPositionX");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "CursorTextField:setPositionX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setPositionX'", nullptr);
            return 0;
        }
        cobj->setPositionX(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setPositionX",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setPositionX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_openIME(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_openIME'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_openIME'", nullptr);
            return 0;
        }
        cobj->openIME();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:openIME",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_openIME'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setCursorPositionX(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setCursorPositionX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CursorTextField:setCursorPositionX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setCursorPositionX'", nullptr);
            return 0;
        }
        cobj->setCursorPositionX(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setCursorPositionX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setCursorPositionX'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_KeyDelete(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_KeyDelete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_KeyDelete'", nullptr);
            return 0;
        }
        cobj->KeyDelete();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:KeyDelete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_KeyDelete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_BlickSpriteRight(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteRight'", nullptr);
            return 0;
        }
        cobj->BlickSpriteRight();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:BlickSpriteRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_BlickSpriteRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_AddCursor(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_AddCursor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CursorTextField:AddCursor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_AddCursor'", nullptr);
            return 0;
        }
        cobj->AddCursor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:AddCursor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_AddCursor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_setInputMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CursorTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_CursorTextField_setInputMaxLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CursorTextField:setInputMaxLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_setInputMaxLength'", nullptr);
            return 0;
        }
        cobj->setInputMaxLength(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:setInputMaxLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_setInputMaxLength'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_textFieldWithPlaceHolder(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        cocos2d::Node* arg0;
        const char* arg1;
        const char* arg2;
        double arg3;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CursorTextField:textFieldWithPlaceHolder");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CursorTextField:textFieldWithPlaceHolder"); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "CursorTextField:textFieldWithPlaceHolder"); arg2 = arg2_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 5,&arg3, "CursorTextField:textFieldWithPlaceHolder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_textFieldWithPlaceHolder'", nullptr);
            return 0;
        }
        CursorTextField* ret = CursorTextField::textFieldWithPlaceHolder(arg0, arg1, arg2, arg3);
        object_to_luaval<CursorTextField>(tolua_S, "CursorTextField",(CursorTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CursorTextField:textFieldWithPlaceHolder",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_textFieldWithPlaceHolder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_getinstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CursorTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_getinstance'", nullptr);
            return 0;
        }
        CursorTextField* ret = CursorTextField::getinstance();
        object_to_luaval<CursorTextField>(tolua_S, "CursorTextField",(CursorTextField*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CursorTextField:getinstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_getinstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_CursorTextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CursorTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_CursorTextField_constructor'", nullptr);
            return 0;
        }
        cobj = new CursorTextField();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CursorTextField");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CursorTextField:CursorTextField",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_CursorTextField_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extratools_CursorTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CursorTextField)");
    return 0;
}

int lua_register_cocos2dx_extratools_CursorTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CursorTextField");
    tolua_cclass(tolua_S,"CursorTextField","CursorTextField","cc.TextFieldTTF",nullptr);

    tolua_beginmodule(tolua_S,"CursorTextField");
        tolua_function(tolua_S,"new",lua_cocos2dx_extratools_CursorTextField_constructor);
        tolua_function(tolua_S,"onTextFieldAttachWithIME",lua_cocos2dx_extratools_CursorTextField_onTextFieldAttachWithIME);
        tolua_function(tolua_S,"getPosiformPosi",lua_cocos2dx_extratools_CursorTextField_getPosiformPosi);
        tolua_function(tolua_S,"BlickSpriteLeft",lua_cocos2dx_extratools_CursorTextField_BlickSpriteLeft);
        tolua_function(tolua_S,"setInputWidth",lua_cocos2dx_extratools_CursorTextField_setInputWidth);
        tolua_function(tolua_S,"setInpuntText",lua_cocos2dx_extratools_CursorTextField_setInpuntText);
        tolua_function(tolua_S,"getInputText",lua_cocos2dx_extratools_CursorTextField_getInputText);
        tolua_function(tolua_S,"isInTextField",lua_cocos2dx_extratools_CursorTextField_isInTextField);
        tolua_function(tolua_S,"onTextFieldDeleteBackward",lua_cocos2dx_extratools_CursorTextField_onTextFieldDeleteBackward);
        tolua_function(tolua_S,"split_text",lua_cocos2dx_extratools_CursorTextField_split_text);
        tolua_function(tolua_S,"getRect",lua_cocos2dx_extratools_CursorTextField_getRect);
        tolua_function(tolua_S,"setChildName",lua_cocos2dx_extratools_CursorTextField_setChildName);
        tolua_function(tolua_S,"init",lua_cocos2dx_extratools_CursorTextField_init);
        tolua_function(tolua_S,"getPosifromText",lua_cocos2dx_extratools_CursorTextField_getPosifromText);
        tolua_function(tolua_S,"getLabelWidth",lua_cocos2dx_extratools_CursorTextField_getLabelWidth);
        tolua_function(tolua_S,"closeIME",lua_cocos2dx_extratools_CursorTextField_closeIME);
        tolua_function(tolua_S,"MyRemoveFromParent",lua_cocos2dx_extratools_CursorTextField_MyRemoveFromParent);
        tolua_function(tolua_S,"initCursorSprite",lua_cocos2dx_extratools_CursorTextField_initCursorSprite);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_extratools_CursorTextField_setPosition);
        tolua_function(tolua_S,"onTextFieldInsertText",lua_cocos2dx_extratools_CursorTextField_onTextFieldInsertText);
        tolua_function(tolua_S,"onTextFieldDetachWithIME",lua_cocos2dx_extratools_CursorTextField_onTextFieldDetachWithIME);
        tolua_function(tolua_S,"setPositionX",lua_cocos2dx_extratools_CursorTextField_setPositionX);
        tolua_function(tolua_S,"openIME",lua_cocos2dx_extratools_CursorTextField_openIME);
        tolua_function(tolua_S,"setCursorPositionX",lua_cocos2dx_extratools_CursorTextField_setCursorPositionX);
        tolua_function(tolua_S,"KeyDelete",lua_cocos2dx_extratools_CursorTextField_KeyDelete);
        tolua_function(tolua_S,"BlickSpriteRight",lua_cocos2dx_extratools_CursorTextField_BlickSpriteRight);
        tolua_function(tolua_S,"AddCursor",lua_cocos2dx_extratools_CursorTextField_AddCursor);
        tolua_function(tolua_S,"setInputMaxLength",lua_cocos2dx_extratools_CursorTextField_setInputMaxLength);
        tolua_function(tolua_S,"textFieldWithPlaceHolder", lua_cocos2dx_extratools_CursorTextField_textFieldWithPlaceHolder);
        tolua_function(tolua_S,"getinstance", lua_cocos2dx_extratools_CursorTextField_getinstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CursorTextField).name();
    g_luaType[typeName] = "CursorTextField";
    g_typeCast["CursorTextField"] = "CursorTextField";
    return 1;
}

int lua_cocos2dx_extratools_SpriteX_addStateAni(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_addStateAni'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Animate* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteX:addStateAni"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Animate>(tolua_S, 3, "cc.Animate",&arg1, "SpriteX:addStateAni");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_addStateAni'", nullptr);
            return 0;
        }
        cobj->addStateAni(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:addStateAni",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_addStateAni'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_setEffect(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_setEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteX:setEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_setEffect'", nullptr);
            return 0;
        }
        bool ret = cobj->setEffect(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:setEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_setEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_delStateAni(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_delStateAni'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteX:delStateAni"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_delStateAni'", nullptr);
            return 0;
        }
        cobj->delStateAni(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:delStateAni",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_delStateAni'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_setShaderEnable(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_setShaderEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteX:setShaderEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_setShaderEnable'", nullptr);
            return 0;
        }
        cobj->setShaderEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:setShaderEnable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_setShaderEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_getHue(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_getHue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_getHue'", nullptr);
            return 0;
        }
        double ret = cobj->getHue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:getHue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_getHue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_getAnimateFromIndex(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteX:getAnimateFromIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromIndex'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = cobj->getAnimateFromIndex(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:getAnimateFromIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_draw(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "SpriteX:draw");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "SpriteX:draw");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "SpriteX:draw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_draw'", nullptr);
            return 0;
        }
        cobj->draw(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_merge(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_merge'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpriteX* arg0;

        ok &= luaval_to_object<SpriteX>(tolua_S, 2, "SpriteX",&arg0, "SpriteX:merge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_merge'", nullptr);
            return 0;
        }
        cobj->merge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:merge",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_merge'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_init(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_setEdging(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_setEdging'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Color3B arg1;
        cocos2d::Size arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteX:setEdging");

        ok &= luaval_to_color3b(tolua_S, 3, &arg1, "SpriteX:setEdging");

        ok &= luaval_to_size(tolua_S, 4, &arg2, "SpriteX:setEdging");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_setEdging'", nullptr);
            return 0;
        }
        bool ret = cobj->setEdging(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        cocos2d::Color3B arg1;
        cocos2d::Size arg2;
        cocos2d::Color3B arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteX:setEdging");

        ok &= luaval_to_color3b(tolua_S, 3, &arg1, "SpriteX:setEdging");

        ok &= luaval_to_size(tolua_S, 4, &arg2, "SpriteX:setEdging");

        ok &= luaval_to_color3b(tolua_S, 5, &arg3, "SpriteX:setEdging");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_setEdging'", nullptr);
            return 0;
        }
        bool ret = cobj->setEdging(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:setEdging",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_setEdging'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_stopAllActions(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_stopAllActions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_stopAllActions'", nullptr);
            return 0;
        }
        cobj->stopAllActions();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:stopAllActions",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_stopAllActions'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_release(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_release'", nullptr);
            return 0;
        }
        cobj->release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_isPlayingAction(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_isPlayingAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_isPlayingAction'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlayingAction();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:isPlayingAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_isPlayingAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_runStateAni(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_runStateAni'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteX:runStateAni"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_runStateAni'", nullptr);
            return 0;
        }
        bool ret = cobj->runStateAni(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:runStateAni",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_runStateAni'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_getAnimateFromName(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "SpriteX:getAnimateFromName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromName'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = cobj->getAnimateFromName(arg0);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:getAnimateFromName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_getAnimateFromName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_getAinmateCount(lua_State* tolua_S)
{
    int argc = 0;
    SpriteX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_SpriteX_getAinmateCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_getAinmateCount'", nullptr);
            return 0;
        }
        int ret = cobj->getAinmateCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteX:getAinmateCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_getAinmateCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_SpriteX_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteX:create");
            if (!ok) { break; }
            SpriteX* ret = SpriteX::create(arg0);
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            SpriteX* ret = SpriteX::create();
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteX:create");
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpriteX:create");
            if (!ok) { break; }
            SpriteX* ret = SpriteX::create(arg0, arg1);
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "SpriteX:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_SpriteX_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "SpriteX:createWithTexture");
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpriteX:createWithTexture");
            if (!ok) { break; }
            SpriteX* ret = SpriteX::createWithTexture(arg0, arg1);
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "SpriteX:createWithTexture");
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "SpriteX:createWithTexture");
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SpriteX:createWithTexture");
            if (!ok) { break; }
            SpriteX* ret = SpriteX::createWithTexture(arg0, arg1, arg2);
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "SpriteX:createWithTexture");
            if (!ok) { break; }
            SpriteX* ret = SpriteX::createWithTexture(arg0);
            object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "SpriteX:createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameWithRetain(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SpriteFrame* arg0;
        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0, "SpriteX:createWithSpriteFrameWithRetain");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameWithRetain'", nullptr);
            return 0;
        }
        SpriteX* ret = SpriteX::createWithSpriteFrameWithRetain(arg0);
        object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteX:createWithSpriteFrameWithRetain",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameWithRetain'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteX:createWithSpriteFrameName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameName'", nullptr);
            return 0;
        }
        SpriteX* ret = SpriteX::createWithSpriteFrameName(arg0);
        object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteX:createWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_SpriteX_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SpriteFrame* arg0;
        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0, "SpriteX:createWithSpriteFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrame'", nullptr);
            return 0;
        }
        SpriteX* ret = SpriteX::createWithSpriteFrame(arg0);
        object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteX:createWithSpriteFrame",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_SpriteX_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_extratools_SpriteX_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteX)");
    return 0;
}

int lua_register_cocos2dx_extratools_SpriteX(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteX");
    tolua_cclass(tolua_S,"SpriteX","SpriteX","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"SpriteX");
        tolua_function(tolua_S,"addStateAni",lua_cocos2dx_extratools_SpriteX_addStateAni);
        tolua_function(tolua_S,"setEffect",lua_cocos2dx_extratools_SpriteX_setEffect);
        tolua_function(tolua_S,"delStateAni",lua_cocos2dx_extratools_SpriteX_delStateAni);
        tolua_function(tolua_S,"setShaderEnable",lua_cocos2dx_extratools_SpriteX_setShaderEnable);
        tolua_function(tolua_S,"getHue",lua_cocos2dx_extratools_SpriteX_getHue);
        tolua_function(tolua_S,"getAnimateFromIndex",lua_cocos2dx_extratools_SpriteX_getAnimateFromIndex);
        tolua_function(tolua_S,"draw",lua_cocos2dx_extratools_SpriteX_draw);
        tolua_function(tolua_S,"merge",lua_cocos2dx_extratools_SpriteX_merge);
        tolua_function(tolua_S,"init",lua_cocos2dx_extratools_SpriteX_init);
        tolua_function(tolua_S,"setEdging",lua_cocos2dx_extratools_SpriteX_setEdging);
        tolua_function(tolua_S,"stopAllActions",lua_cocos2dx_extratools_SpriteX_stopAllActions);
        tolua_function(tolua_S,"release",lua_cocos2dx_extratools_SpriteX_release);
        tolua_function(tolua_S,"isPlayingAction",lua_cocos2dx_extratools_SpriteX_isPlayingAction);
        tolua_function(tolua_S,"runStateAni",lua_cocos2dx_extratools_SpriteX_runStateAni);
        tolua_function(tolua_S,"getAnimateFromName",lua_cocos2dx_extratools_SpriteX_getAnimateFromName);
        tolua_function(tolua_S,"getAinmateCount",lua_cocos2dx_extratools_SpriteX_getAinmateCount);
        tolua_function(tolua_S,"create", lua_cocos2dx_extratools_SpriteX_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_extratools_SpriteX_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameWithRetain", lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameWithRetain);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_extratools_SpriteX_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_extratools_SpriteX_createWithSpriteFrame);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteX).name();
    g_luaType[typeName] = "SpriteX";
    g_typeCast["SpriteX"] = "SpriteX";
    return 1;
}

int lua_cocos2dx_extratools_MirFileLoader_launchSchedule(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_launchSchedule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_launchSchedule'", nullptr);
            return 0;
        }
        cobj->launchSchedule();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:launchSchedule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_launchSchedule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_asyncReadMirActionSprite(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_asyncReadMirActionSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:asyncReadMirActionSprite"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:asyncReadMirActionSprite");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:asyncReadMirActionSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_asyncReadMirActionSprite'", nullptr);
            return 0;
        }
        SpriteX* ret = cobj->asyncReadMirActionSprite(arg0, arg1, arg2);
        object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:asyncReadMirActionSprite",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_asyncReadMirActionSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_readMirTexture(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_readMirTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        void* arg1;
        void* arg2;
        void* arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirFileLoader:readMirTexture");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_readMirTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->readMirTexture(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D",(cocos2d::Texture2D*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:readMirTexture",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_readMirTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_insertActionSetting(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_insertActionSetting'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        double arg4;
        bool arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_boolean(tolua_S, 7,&arg5, "MirFileLoader:insertActionSetting");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_insertActionSetting'", nullptr);
            return 0;
        }
        cobj->insertActionSetting(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 7) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        double arg4;
        bool arg5;
        int arg6;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_boolean(tolua_S, 7,&arg5, "MirFileLoader:insertActionSetting");

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "MirFileLoader:insertActionSetting");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_insertActionSetting'", nullptr);
            return 0;
        }
        cobj->insertActionSetting(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:insertActionSetting",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_insertActionSetting'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_readMirActionSprite(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_readMirActionSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:readMirActionSprite"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:readMirActionSprite");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:readMirActionSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_readMirActionSprite'", nullptr);
            return 0;
        }
        SpriteX* ret = cobj->readMirActionSprite(arg0, arg1, arg2);
        object_to_luaval<SpriteX>(tolua_S, "SpriteX",(SpriteX*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:readMirActionSprite",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_readMirActionSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_readMirAnimate(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_readMirAnimate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        const char* arg0;
        int arg1;
        int arg2;
        int arg3;
        double arg4;
        bool arg5;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:readMirAnimate"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:readMirAnimate");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:readMirAnimate");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirFileLoader:readMirAnimate");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "MirFileLoader:readMirAnimate");

        ok &= luaval_to_boolean(tolua_S, 7,&arg5, "MirFileLoader:readMirAnimate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_readMirAnimate'", nullptr);
            return 0;
        }
        cocos2d::Animate* ret = cobj->readMirAnimate(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate",(cocos2d::Animate*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:readMirAnimate",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_readMirAnimate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_setClearNearBlackColor(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_setClearNearBlackColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MirFileLoader:setClearNearBlackColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_setClearNearBlackColor'", nullptr);
            return 0;
        }
        cobj->setClearNearBlackColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:setClearNearBlackColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_setClearNearBlackColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_update(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MirFileLoader:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_readMirSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_readMirSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        const char* arg1;
        const char* arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirFileLoader:readMirSpriteFrame");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MirFileLoader:readMirSpriteFrame"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MirFileLoader:readMirSpriteFrame"); arg2 = arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_readMirSpriteFrame'", nullptr);
            return 0;
        }
        cocos2d::SpriteFrame* ret = cobj->readMirSpriteFrame(arg0, arg1, arg2);
        object_to_luaval<cocos2d::SpriteFrame>(tolua_S, "cc.SpriteFrame",(cocos2d::SpriteFrame*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:readMirSpriteFrame",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_readMirSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_parseCommand(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_parseCommand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        AsyncLoadingCommand* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR AsyncLoadingCommand*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_parseCommand'", nullptr);
            return 0;
        }
        cobj->parseCommand(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:parseCommand",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_parseCommand'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_release(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_release'", nullptr);
            return 0;
        }
        cobj->release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_stopSchedule(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_stopSchedule'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_stopSchedule'", nullptr);
            return 0;
        }
        cobj->stopSchedule();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirFileLoader:stopSchedule",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_stopSchedule'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_readMirAnimation(lua_State* tolua_S)
{
    int argc = 0;
    MirFileLoader* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (MirFileLoader*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirFileLoader_readMirAnimation'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:readMirAnimation"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            AniAction* arg1;
            #pragma warning NO CONVERSION TO NATIVE FOR AniAction*
		ok = false;

            if (!ok) { break; }
            cocos2d::Animation* ret = cobj->readMirAnimation(arg0, arg1);
            object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:readMirAnimation"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            cocos2d::Animation* ret = cobj->readMirAnimation(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 6) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirFileLoader:readMirAnimation"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            bool arg5;
            ok &= luaval_to_boolean(tolua_S, 7,&arg5, "MirFileLoader:readMirAnimation");

            if (!ok) { break; }
            cocos2d::Animation* ret = cobj->readMirAnimation(arg0, arg1, arg2, arg3, arg4, arg5);
            object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MirFileLoader:readMirAnimation",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_readMirAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirFileLoader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirFileLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirFileLoader_getInstance'", nullptr);
            return 0;
        }
        MirFileLoader* ret = MirFileLoader::getInstance();
        object_to_luaval<MirFileLoader>(tolua_S, "MirFileLoader",(MirFileLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirFileLoader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirFileLoader_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_extratools_MirFileLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MirFileLoader)");
    return 0;
}

int lua_register_cocos2dx_extratools_MirFileLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MirFileLoader");
    tolua_cclass(tolua_S,"MirFileLoader","MirFileLoader","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MirFileLoader");
        tolua_function(tolua_S,"launchSchedule",lua_cocos2dx_extratools_MirFileLoader_launchSchedule);
        tolua_function(tolua_S,"asyncReadMirActionSprite",lua_cocos2dx_extratools_MirFileLoader_asyncReadMirActionSprite);
        tolua_function(tolua_S,"readMirTexture",lua_cocos2dx_extratools_MirFileLoader_readMirTexture);
        tolua_function(tolua_S,"insertActionSetting",lua_cocos2dx_extratools_MirFileLoader_insertActionSetting);
        tolua_function(tolua_S,"readMirActionSprite",lua_cocos2dx_extratools_MirFileLoader_readMirActionSprite);
        tolua_function(tolua_S,"readMirAnimate",lua_cocos2dx_extratools_MirFileLoader_readMirAnimate);
        tolua_function(tolua_S,"setClearNearBlackColor",lua_cocos2dx_extratools_MirFileLoader_setClearNearBlackColor);
        tolua_function(tolua_S,"update",lua_cocos2dx_extratools_MirFileLoader_update);
        tolua_function(tolua_S,"readMirSpriteFrame",lua_cocos2dx_extratools_MirFileLoader_readMirSpriteFrame);
        tolua_function(tolua_S,"parseCommand",lua_cocos2dx_extratools_MirFileLoader_parseCommand);
        tolua_function(tolua_S,"release",lua_cocos2dx_extratools_MirFileLoader_release);
        tolua_function(tolua_S,"stopSchedule",lua_cocos2dx_extratools_MirFileLoader_stopSchedule);
        tolua_function(tolua_S,"readMirAnimation",lua_cocos2dx_extratools_MirFileLoader_readMirAnimation);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_extratools_MirFileLoader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MirFileLoader).name();
    g_luaType[typeName] = "MirFileLoader";
    g_typeCast["MirFileLoader"] = "MirFileLoader";
    return 1;
}

int lua_cocos2dx_extratools_ODClient_getOffLine(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_getOffLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_getOffLine'", nullptr);
            return 0;
        }
        bool ret = cobj->getOffLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:getOffLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_getOffLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_getNewMessage(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_getNewMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_getNewMessage'", nullptr);
            return 0;
        }
        char* ret = cobj->getNewMessage();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:getNewMessage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_getNewMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_listenBackFunc(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_listenBackFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_listenBackFunc'", nullptr);
            return 0;
        }
        cobj->listenBackFunc();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:listenBackFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_listenBackFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_hasNewMessage(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_hasNewMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_hasNewMessage'", nullptr);
            return 0;
        }
        bool ret = cobj->hasNewMessage();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:hasNewMessage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_hasNewMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_createSocket(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_createSocket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ODClient:createSocket");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ODClient:createSocket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_createSocket'", nullptr);
            return 0;
        }
        bool ret = cobj->createSocket(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ODClient:createSocket");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ODClient:createSocket");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "ODClient:createSocket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_createSocket'", nullptr);
            return 0;
        }
        bool ret = cobj->createSocket(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:createSocket",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_createSocket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_getID(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_getID'", nullptr);
            return 0;
        }
        int ret = cobj->getID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_setODSocket(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_setODSocket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_setODSocket'", nullptr);
            return 0;
        }
        cobj->setODSocket(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:setODSocket",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_setODSocket'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_init(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_connect(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_connect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        unsigned short arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ODClient:connect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 3, &arg1, "ODClient:connect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_connect'", nullptr);
            return 0;
        }
        bool ret = cobj->connect(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:connect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_connect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_clean(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_clean'", nullptr);
            return 0;
        }
        cobj->clean();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_popMessage(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_popMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_popMessage'", nullptr);
            return 0;
        }
        cobj->popMessage();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:popMessage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_popMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_close(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_close'", nullptr);
            return 0;
        }
        cobj->close();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:close",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_close'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_setID(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_setID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ODClient:setID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_setID'", nullptr);
            return 0;
        }
        cobj->setID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:setID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_setID'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_send(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_send'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ODClient:send"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_send'", nullptr);
            return 0;
        }
        int ret = cobj->send(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "ODClient:send"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ODClient:send");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_send'", nullptr);
            return 0;
        }
        int ret = cobj->send(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:send",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_send'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_listen(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ODClient*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_ODClient_listen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_listen'", nullptr);
            return 0;
        }
        bool ret = cobj->listen();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:listen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_listen'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_ODClient_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ODClient",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_create'", nullptr);
            return 0;
        }
        ODClient* ret = ODClient::create();
        object_to_luaval<ODClient>(tolua_S, "ODClient",(ODClient*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ODClient:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_ODClient_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ODClient* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_ODClient_constructor'", nullptr);
            return 0;
        }
        cobj = new ODClient();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ODClient");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ODClient:ODClient",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_ODClient_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extratools_ODClient_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ODClient)");
    return 0;
}

int lua_register_cocos2dx_extratools_ODClient(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ODClient");
    tolua_cclass(tolua_S,"ODClient","ODClient","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ODClient");
        tolua_function(tolua_S,"new",lua_cocos2dx_extratools_ODClient_constructor);
        tolua_function(tolua_S,"getOffLine",lua_cocos2dx_extratools_ODClient_getOffLine);
        tolua_function(tolua_S,"getNewMessage",lua_cocos2dx_extratools_ODClient_getNewMessage);
        tolua_function(tolua_S,"listenBackFunc",lua_cocos2dx_extratools_ODClient_listenBackFunc);
        tolua_function(tolua_S,"hasNewMessage",lua_cocos2dx_extratools_ODClient_hasNewMessage);
        tolua_function(tolua_S,"createSocket",lua_cocos2dx_extratools_ODClient_createSocket);
        tolua_function(tolua_S,"getID",lua_cocos2dx_extratools_ODClient_getID);
        tolua_function(tolua_S,"setODSocket",lua_cocos2dx_extratools_ODClient_setODSocket);
        tolua_function(tolua_S,"init",lua_cocos2dx_extratools_ODClient_init);
        tolua_function(tolua_S,"connect",lua_cocos2dx_extratools_ODClient_connect);
        tolua_function(tolua_S,"clean",lua_cocos2dx_extratools_ODClient_clean);
        tolua_function(tolua_S,"popMessage",lua_cocos2dx_extratools_ODClient_popMessage);
        tolua_function(tolua_S,"close",lua_cocos2dx_extratools_ODClient_close);
        tolua_function(tolua_S,"setID",lua_cocos2dx_extratools_ODClient_setID);
        tolua_function(tolua_S,"send",lua_cocos2dx_extratools_ODClient_send);
        tolua_function(tolua_S,"listen",lua_cocos2dx_extratools_ODClient_listen);
        tolua_function(tolua_S,"create", lua_cocos2dx_extratools_ODClient_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ODClient).name();
    g_luaType[typeName] = "ODClient";
    g_typeCast["ODClient"] = "ODClient";
    return 1;
}

int lua_cocos2dx_extratools_MapTileInfo_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setAnchorPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapTileInfo:setAnchorPoint");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:setAnchorPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setAnchorPoint'", nullptr);
            return 0;
        }
        cobj->setAnchorPoint(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setAnchorPoint",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setAnchorPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setCanWalk(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setCanWalk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setCanWalk");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setCanWalk'", nullptr);
            return 0;
        }
        cobj->setCanWalk(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setCanWalk",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setCanWalk'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getBngIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getBngIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getBngIndex'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getBngIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getBngIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getBngIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setHasObj(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setHasObj'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setHasObj");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setHasObj'", nullptr);
            return 0;
        }
        cobj->setHasObj(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setHasObj",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setHasObj'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setBngIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setBngIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setBngIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setBngIndex'", nullptr);
            return 0;
        }
        cobj->setBngIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setBngIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setBngIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setIsInit(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setIsInit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setIsInit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setIsInit'", nullptr);
            return 0;
        }
        cobj->setIsInit(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setIsInit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setIsInit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setObjFileIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setObjFileIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setObjFileIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setObjFileIndex'", nullptr);
            return 0;
        }
        cobj->setObjFileIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setObjFileIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setObjFileIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setCanFly(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setCanFly'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setCanFly");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setCanFly'", nullptr);
            return 0;
        }
        cobj->setCanFly(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setCanFly",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setCanFly'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setHasDoor(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setHasDoor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setHasDoor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setHasDoor'", nullptr);
            return 0;
        }
        cobj->setHasDoor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setHasDoor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setHasDoor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getObjOffset(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getObjOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getObjOffset'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getObjOffset();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getObjOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getObjOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setLight(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setLight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setLight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setLight'", nullptr);
            return 0;
        }
        cobj->setLight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setLight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setLight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getIsInit(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getIsInit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getIsInit'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsInit();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getIsInit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getIsInit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setDoorOffset(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setDoorOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOffset'", nullptr);
            return 0;
        }
        cobj->setDoorOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setDoorOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setBngImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setBngImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "MapTileInfo:setBngImg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setBngImg'", nullptr);
            return 0;
        }
        cobj->setBngImg(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setBngImg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setBngImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setHasMid(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setHasMid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setHasMid");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setHasMid'", nullptr);
            return 0;
        }
        cobj->setHasMid(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setHasMid",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setHasMid'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getObjFileIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getObjFileIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getObjFileIndex'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getObjFileIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getObjFileIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getObjFileIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getShowDetail(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getShowDetail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getShowDetail'", nullptr);
            return 0;
        }
        bool ret = cobj->getShowDetail();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getShowDetail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getShowDetail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setObjOffset(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setObjOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapTileInfo:setObjOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setObjOffset'", nullptr);
            return 0;
        }
        cobj->setObjOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setObjOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setObjOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getHasMid(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getHasMid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getHasMid'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasMid();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getHasMid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getHasMid'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getAniFrame(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getAniFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getAniFrame'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getAniFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getAniFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getAniFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getBngImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getBngImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getBngImg'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getBngImg();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getBngImg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getBngImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getDoorOffset(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOffset'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getDoorOffset();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getDoorOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getCanFly(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getCanFly'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getCanFly'", nullptr);
            return 0;
        }
        bool ret = cobj->getCanFly();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getCanFly",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getCanFly'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getHasObj(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getHasObj'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getHasObj'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasObj();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getHasObj",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getHasObj'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getRow(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getRow'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getRow();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getRow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getRow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_initSprite(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_initSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_initSprite'", nullptr);
            return 0;
        }
        bool ret = cobj->initSprite();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:initSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_initSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getMidIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getMidIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getMidIndex'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getMidIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getMidIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getMidIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setHasBng(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setHasBng'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setHasBng");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setHasBng'", nullptr);
            return 0;
        }
        cobj->setHasBng(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setHasBng",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setHasBng'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setHasAni(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setHasAni'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setHasAni");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setHasAni'", nullptr);
            return 0;
        }
        cobj->setHasAni(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setHasAni",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setHasAni'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getFilename(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getFilename'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapTileInfo:getFilename");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getFilename'", nullptr);
            return 0;
        }
        std::string ret = cobj->getFilename(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getFilename",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getFilename'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setObjIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setObjIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setObjIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setObjIndex'", nullptr);
            return 0;
        }
        cobj->setObjIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setObjIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setObjIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getObjIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getObjIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getObjIndex'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getObjIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getObjIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getObjIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setObjImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setObjImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "MapTileInfo:setObjImg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setObjImg'", nullptr);
            return 0;
        }
        cobj->setObjImg(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setObjImg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setObjImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getMidImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getMidImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getMidImg'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getMidImg();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getMidImg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getMidImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getLight(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getLight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getLight'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getLight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getLight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getLight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getHasAni(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getHasAni'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getHasAni'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasAni();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getHasAni",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getHasAni'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setAniFrame(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setAniFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setAniFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setAniFrame'", nullptr);
            return 0;
        }
        cobj->setAniFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setAniFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setAniFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_addTileSpriteTo(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_addTileSpriteTo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::Node* arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "MapTileInfo:addTileSpriteTo");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:addTileSpriteTo");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MapTileInfo:addTileSpriteTo");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MapTileInfo:addTileSpriteTo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_addTileSpriteTo'", nullptr);
            return 0;
        }
        bool ret = cobj->addTileSpriteTo(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:addTileSpriteTo",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_addTileSpriteTo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setAniTick(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setAniTick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setAniTick");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setAniTick'", nullptr);
            return 0;
        }
        cobj->setAniTick(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setAniTick",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setAniTick'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setMidIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setMidIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setMidIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setMidIndex'", nullptr);
            return 0;
        }
        cobj->setMidIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setMidIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setMidIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setDoorOpen(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOpen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setDoorOpen");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOpen'", nullptr);
            return 0;
        }
        cobj->setDoorOpen(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setDoorOpen",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorOpen'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getSpriteFromType(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getSpriteFromType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapTileInfo:getSpriteFromType");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:getSpriteFromType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getSpriteFromType'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getSpriteFromType(arg0, arg1);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getSpriteFromType",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getSpriteFromType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getImgPath(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getImgPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        char* arg0;
        int arg1;
        char* arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MapTileInfo:getImgPath"); arg0 = (char*)arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:getImgPath");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "MapTileInfo:getImgPath"); arg2 = (char*)arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getImgPath'", nullptr);
            return 0;
        }
        cobj->getImgPath(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getImgPath",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getImgPath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_removeTileSprite(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_removeTileSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_removeTileSprite'", nullptr);
            return 0;
        }
        cobj->removeTileSprite();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:removeTileSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_removeTileSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setCol(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setCol'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setCol");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setCol'", nullptr);
            return 0;
        }
        cobj->setCol(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setCol",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setCol'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getCanWalk(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getCanWalk'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getCanWalk'", nullptr);
            return 0;
        }
        bool ret = cobj->getCanWalk();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getCanWalk",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getCanWalk'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapTileInfo:setPosition");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setRow(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setRow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setRow'", nullptr);
            return 0;
        }
        cobj->setRow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setRow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setRow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setMidImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setMidImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "MapTileInfo:setMidImg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setMidImg'", nullptr);
            return 0;
        }
        cobj->setMidImg(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setMidImg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setMidImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setShowDetail(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setShowDetail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setShowDetail");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setShowDetail'", nullptr);
            return 0;
        }
        cobj->setShowDetail(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setShowDetail",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setShowDetail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getDoorOpen(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOpen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOpen'", nullptr);
            return 0;
        }
        bool ret = cobj->getDoorOpen();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getDoorOpen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorOpen'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setDoorIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MapTileInfo:setDoorIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorIndex'", nullptr);
            return 0;
        }
        cobj->setDoorIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setDoorIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setDoorIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getDoorIndex(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorIndex'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getDoorIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getDoorIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getDoorIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getAniTick(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getAniTick'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getAniTick'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getAniTick();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getAniTick",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getAniTick'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getCol(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getCol'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getCol'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getCol();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getCol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getCol'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getObjImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getObjImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getObjImg'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getObjImg();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getObjImg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getObjImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getHasBng(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getHasBng'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getHasBng'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasBng();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getHasBng",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getHasBng'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_initTestLabel(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_initTestLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_initTestLabel'", nullptr);
            return 0;
        }
        bool ret = cobj->initTestLabel();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:initTestLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_initTestLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getHasDoor(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getHasDoor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getHasDoor'", nullptr);
            return 0;
        }
        bool ret = cobj->getHasDoor();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getHasDoor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getHasDoor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getCoverImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getCoverImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getCoverImg'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getCoverImg();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getCoverImg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getCoverImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_getOffsetOfObject(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_getOffsetOfObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapTileInfo:getOffsetOfObject");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapTileInfo:getOffsetOfObject");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_getOffsetOfObject'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getOffsetOfObject(arg0, arg1);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:getOffsetOfObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_getOffsetOfObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapTileInfo:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_setCoverImg(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileInfo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileInfo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MapTileInfo_setCoverImg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "MapTileInfo:setCoverImg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_setCoverImg'", nullptr);
            return 0;
        }
        cobj->setCoverImg(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:setCoverImg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_setCoverImg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MapTileInfo_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapTileInfo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MapTileInfo_constructor'", nullptr);
            return 0;
        }
        cobj = new MapTileInfo();
        tolua_pushusertype(tolua_S,(void*)cobj,"MapTileInfo");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileInfo:MapTileInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MapTileInfo_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extratools_MapTileInfo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapTileInfo)");
    return 0;
}

int lua_register_cocos2dx_extratools_MapTileInfo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapTileInfo");
    tolua_cclass(tolua_S,"MapTileInfo","MapTileInfo","",nullptr);

    tolua_beginmodule(tolua_S,"MapTileInfo");
        tolua_function(tolua_S,"new",lua_cocos2dx_extratools_MapTileInfo_constructor);
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_extratools_MapTileInfo_setAnchorPoint);
        tolua_function(tolua_S,"setCanWalk",lua_cocos2dx_extratools_MapTileInfo_setCanWalk);
        tolua_function(tolua_S,"getBngIndex",lua_cocos2dx_extratools_MapTileInfo_getBngIndex);
        tolua_function(tolua_S,"setHasObj",lua_cocos2dx_extratools_MapTileInfo_setHasObj);
        tolua_function(tolua_S,"setBngIndex",lua_cocos2dx_extratools_MapTileInfo_setBngIndex);
        tolua_function(tolua_S,"setIsInit",lua_cocos2dx_extratools_MapTileInfo_setIsInit);
        tolua_function(tolua_S,"setObjFileIndex",lua_cocos2dx_extratools_MapTileInfo_setObjFileIndex);
        tolua_function(tolua_S,"setCanFly",lua_cocos2dx_extratools_MapTileInfo_setCanFly);
        tolua_function(tolua_S,"setHasDoor",lua_cocos2dx_extratools_MapTileInfo_setHasDoor);
        tolua_function(tolua_S,"getObjOffset",lua_cocos2dx_extratools_MapTileInfo_getObjOffset);
        tolua_function(tolua_S,"setLight",lua_cocos2dx_extratools_MapTileInfo_setLight);
        tolua_function(tolua_S,"getIsInit",lua_cocos2dx_extratools_MapTileInfo_getIsInit);
        tolua_function(tolua_S,"setDoorOffset",lua_cocos2dx_extratools_MapTileInfo_setDoorOffset);
        tolua_function(tolua_S,"setBngImg",lua_cocos2dx_extratools_MapTileInfo_setBngImg);
        tolua_function(tolua_S,"setHasMid",lua_cocos2dx_extratools_MapTileInfo_setHasMid);
        tolua_function(tolua_S,"getObjFileIndex",lua_cocos2dx_extratools_MapTileInfo_getObjFileIndex);
        tolua_function(tolua_S,"getShowDetail",lua_cocos2dx_extratools_MapTileInfo_getShowDetail);
        tolua_function(tolua_S,"setObjOffset",lua_cocos2dx_extratools_MapTileInfo_setObjOffset);
        tolua_function(tolua_S,"getHasMid",lua_cocos2dx_extratools_MapTileInfo_getHasMid);
        tolua_function(tolua_S,"getAniFrame",lua_cocos2dx_extratools_MapTileInfo_getAniFrame);
        tolua_function(tolua_S,"getBngImg",lua_cocos2dx_extratools_MapTileInfo_getBngImg);
        tolua_function(tolua_S,"getDoorOffset",lua_cocos2dx_extratools_MapTileInfo_getDoorOffset);
        tolua_function(tolua_S,"getCanFly",lua_cocos2dx_extratools_MapTileInfo_getCanFly);
        tolua_function(tolua_S,"getHasObj",lua_cocos2dx_extratools_MapTileInfo_getHasObj);
        tolua_function(tolua_S,"getRow",lua_cocos2dx_extratools_MapTileInfo_getRow);
        tolua_function(tolua_S,"initSprite",lua_cocos2dx_extratools_MapTileInfo_initSprite);
        tolua_function(tolua_S,"getMidIndex",lua_cocos2dx_extratools_MapTileInfo_getMidIndex);
        tolua_function(tolua_S,"setHasBng",lua_cocos2dx_extratools_MapTileInfo_setHasBng);
        tolua_function(tolua_S,"setHasAni",lua_cocos2dx_extratools_MapTileInfo_setHasAni);
        tolua_function(tolua_S,"getFilename",lua_cocos2dx_extratools_MapTileInfo_getFilename);
        tolua_function(tolua_S,"setObjIndex",lua_cocos2dx_extratools_MapTileInfo_setObjIndex);
        tolua_function(tolua_S,"getObjIndex",lua_cocos2dx_extratools_MapTileInfo_getObjIndex);
        tolua_function(tolua_S,"setObjImg",lua_cocos2dx_extratools_MapTileInfo_setObjImg);
        tolua_function(tolua_S,"getMidImg",lua_cocos2dx_extratools_MapTileInfo_getMidImg);
        tolua_function(tolua_S,"getLight",lua_cocos2dx_extratools_MapTileInfo_getLight);
        tolua_function(tolua_S,"getHasAni",lua_cocos2dx_extratools_MapTileInfo_getHasAni);
        tolua_function(tolua_S,"setAniFrame",lua_cocos2dx_extratools_MapTileInfo_setAniFrame);
        tolua_function(tolua_S,"addTileSpriteTo",lua_cocos2dx_extratools_MapTileInfo_addTileSpriteTo);
        tolua_function(tolua_S,"setAniTick",lua_cocos2dx_extratools_MapTileInfo_setAniTick);
        tolua_function(tolua_S,"setMidIndex",lua_cocos2dx_extratools_MapTileInfo_setMidIndex);
        tolua_function(tolua_S,"setDoorOpen",lua_cocos2dx_extratools_MapTileInfo_setDoorOpen);
        tolua_function(tolua_S,"getSpriteFromType",lua_cocos2dx_extratools_MapTileInfo_getSpriteFromType);
        tolua_function(tolua_S,"getImgPath",lua_cocos2dx_extratools_MapTileInfo_getImgPath);
        tolua_function(tolua_S,"removeTileSprite",lua_cocos2dx_extratools_MapTileInfo_removeTileSprite);
        tolua_function(tolua_S,"setCol",lua_cocos2dx_extratools_MapTileInfo_setCol);
        tolua_function(tolua_S,"getCanWalk",lua_cocos2dx_extratools_MapTileInfo_getCanWalk);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_extratools_MapTileInfo_setPosition);
        tolua_function(tolua_S,"setRow",lua_cocos2dx_extratools_MapTileInfo_setRow);
        tolua_function(tolua_S,"setMidImg",lua_cocos2dx_extratools_MapTileInfo_setMidImg);
        tolua_function(tolua_S,"setShowDetail",lua_cocos2dx_extratools_MapTileInfo_setShowDetail);
        tolua_function(tolua_S,"getDoorOpen",lua_cocos2dx_extratools_MapTileInfo_getDoorOpen);
        tolua_function(tolua_S,"setDoorIndex",lua_cocos2dx_extratools_MapTileInfo_setDoorIndex);
        tolua_function(tolua_S,"getDoorIndex",lua_cocos2dx_extratools_MapTileInfo_getDoorIndex);
        tolua_function(tolua_S,"getAniTick",lua_cocos2dx_extratools_MapTileInfo_getAniTick);
        tolua_function(tolua_S,"getCol",lua_cocos2dx_extratools_MapTileInfo_getCol);
        tolua_function(tolua_S,"getObjImg",lua_cocos2dx_extratools_MapTileInfo_getObjImg);
        tolua_function(tolua_S,"getHasBng",lua_cocos2dx_extratools_MapTileInfo_getHasBng);
        tolua_function(tolua_S,"initTestLabel",lua_cocos2dx_extratools_MapTileInfo_initTestLabel);
        tolua_function(tolua_S,"getHasDoor",lua_cocos2dx_extratools_MapTileInfo_getHasDoor);
        tolua_function(tolua_S,"getCoverImg",lua_cocos2dx_extratools_MapTileInfo_getCoverImg);
        tolua_function(tolua_S,"getOffsetOfObject",lua_cocos2dx_extratools_MapTileInfo_getOffsetOfObject);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_extratools_MapTileInfo_setVisible);
        tolua_function(tolua_S,"setCoverImg",lua_cocos2dx_extratools_MapTileInfo_setCoverImg);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapTileInfo).name();
    g_luaType[typeName] = "MapTileInfo";
    g_typeCast["MapTileInfo"] = "MapTileInfo";
    return 1;
}

int lua_cocos2dx_extratools_MirTileMap_setTileSize(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_setTileSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int32_t arg0;
        int32_t arg1;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:setTileSize");

        ok &= luaval_to_int32(tolua_S, 3,&arg1, "MirTileMap:setTileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_setTileSize'", nullptr);
            return 0;
        }
        cobj->setTileSize(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:setTileSize",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_setTileSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getWidth(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getWidth'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_showPart(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_showPart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirTileMap:showPart");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTileMap:showPart");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirTileMap:showPart");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirTileMap:showPart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_showPart'", nullptr);
            return 0;
        }
        cobj->showPart(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:showPart",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_showPart'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_setWidth(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_setWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:setWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_setWidth'", nullptr);
            return 0;
        }
        cobj->setWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:setWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_setWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_setShowTileDetail(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_setShowTileDetail'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MirTileMap:setShowTileDetail");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_setShowTileDetail'", nullptr);
            return 0;
        }
        cobj->setShowTileDetail(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:setShowTileDetail",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_setShowTileDetail'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getMapTiles(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getMapTiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getMapTiles'", nullptr);
            return 0;
        }
        MapTileInfo* ret = cobj->getMapTiles();
        object_to_luaval<MapTileInfo>(tolua_S, "MapTileInfo",(MapTileInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getMapTiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getMapTiles'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getImgIdx(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getImgIdx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:getImgIdx");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getImgIdx'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getImgIdx(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getImgIdx",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getImgIdx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_readMapTileData(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_readMapTileData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        MapTileInfo* arg0;
        unsigned char* arg1;
        int arg2;

        ok &= luaval_to_object<MapTileInfo>(tolua_S, 2, "MapTileInfo",&arg0, "MirTileMap:readMapTileData");

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirTileMap:readMapTileData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_readMapTileData'", nullptr);
            return 0;
        }
        MapTileInfo* ret = cobj->readMapTileData(arg0, arg1, arg2);
        object_to_luaval<MapTileInfo>(tolua_S, "MapTileInfo",(MapTileInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:readMapTileData",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_readMapTileData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getPortal(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getPortal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirTileMap:getPortal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getPortal'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getPortal(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getPortal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getPortal'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getMapTile(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getMapTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirTileMap:getMapTile");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTileMap:getMapTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getMapTile'", nullptr);
            return 0;
        }
        MapTileInfo* ret = cobj->getMapTile(arg0, arg1);
        object_to_luaval<MapTileInfo>(tolua_S, "MapTileInfo",(MapTileInfo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getMapTile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getMapTile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getHeight(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getHeight'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_init(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_readMapData(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_readMapData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_readMapData'", nullptr);
            return 0;
        }
        bool ret = cobj->readMapData();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:readMapData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_readMapData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_readShort(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned char* arg0;
        int arg1;
        bool arg2;

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTileMap:readShort");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "MirTileMap:readShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_readShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->readShort(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:readShort",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_initWithMapFile(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_initWithMapFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "MirTileMap:initWithMapFile"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MirTileMap:initWithMapFile"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_initWithMapFile'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithMapFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:initWithMapFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_initWithMapFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_setTileOrder(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_setTileOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int32_t arg0;
        int32_t arg1;
        int32_t arg2;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:setTileOrder");

        ok &= luaval_to_int32(tolua_S, 3,&arg1, "MirTileMap:setTileOrder");

        ok &= luaval_to_int32(tolua_S, 4,&arg2, "MirTileMap:setTileOrder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_setTileOrder'", nullptr);
            return 0;
        }
        cobj->setTileOrder(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:setTileOrder",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_setTileOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_initMapTileSprite(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_initMapTileSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MapTileInfo* arg0;

        ok &= luaval_to_object<MapTileInfo>(tolua_S, 2, "MapTileInfo",&arg0, "MirTileMap:initMapTileSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_initMapTileSprite'", nullptr);
            return 0;
        }
        bool ret = cobj->initMapTileSprite(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:initMapTileSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_initMapTileSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getPortalCount(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getPortalCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getPortalCount'", nullptr);
            return 0;
        }
        int ret = cobj->getPortalCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getPortalCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getPortalCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_setHeight(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_setHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:setHeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_setHeight'", nullptr);
            return 0;
        }
        cobj->setHeight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:setHeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_setHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_is1AtTopDigit(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "MirTileMap:is1AtTopDigit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigit'", nullptr);
            return 0;
        }
        bool ret = cobj->is1AtTopDigit(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:is1AtTopDigit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_hindPart(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_hindPart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirTileMap:hindPart");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTileMap:hindPart");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirTileMap:hindPart");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirTileMap:hindPart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_hindPart'", nullptr);
            return 0;
        }
        cobj->hindPart(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:hindPart",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_hindPart'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_showPartEx(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_showPartEx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MirTileMap:showPartEx");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTileMap:showPartEx");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirTileMap:showPartEx");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "MirTileMap:showPartEx");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_showPartEx'", nullptr);
            return 0;
        }
        cobj->showPartEx(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:showPartEx",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_showPartEx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_getInitComplete(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_getInitComplete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_getInitComplete'", nullptr);
            return 0;
        }
        int ret = cobj->getInitComplete();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:getInitComplete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_getInitComplete'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_release(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_release'", nullptr);
            return 0;
        }
        cobj->release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_updateTile(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_updateTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MirTileMap:updateTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_updateTile'", nullptr);
            return 0;
        }
        cobj->updateTile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:updateTile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_updateTile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_is1AtTopDigitForShort(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTileMap*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigitForShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "MirTileMap:is1AtTopDigitForShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigitForShort'", nullptr);
            return 0;
        }
        bool ret = cobj->is1AtTopDigitForShort(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:is1AtTopDigitForShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_is1AtTopDigitForShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirTileMap",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_create'", nullptr);
            return 0;
        }
        MirTileMap* ret = MirTileMap::create();
        object_to_luaval<MirTileMap>(tolua_S, "MirTileMap",(MirTileMap*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirTileMap:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_extratools_MirTileMap_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MirTileMap* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_extratools_MirTileMap_constructor'", nullptr);
            return 0;
        }
        cobj = new MirTileMap();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MirTileMap");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTileMap:MirTileMap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_extratools_MirTileMap_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_extratools_MirTileMap_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MirTileMap)");
    return 0;
}

int lua_register_cocos2dx_extratools_MirTileMap(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MirTileMap");
    tolua_cclass(tolua_S,"MirTileMap","MirTileMap","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"MirTileMap");
        tolua_function(tolua_S,"new",lua_cocos2dx_extratools_MirTileMap_constructor);
        tolua_function(tolua_S,"setTileSize",lua_cocos2dx_extratools_MirTileMap_setTileSize);
        tolua_function(tolua_S,"getWidth",lua_cocos2dx_extratools_MirTileMap_getWidth);
        tolua_function(tolua_S,"showPart",lua_cocos2dx_extratools_MirTileMap_showPart);
        tolua_function(tolua_S,"setWidth",lua_cocos2dx_extratools_MirTileMap_setWidth);
        tolua_function(tolua_S,"setShowTileDetail",lua_cocos2dx_extratools_MirTileMap_setShowTileDetail);
        tolua_function(tolua_S,"getMapTiles",lua_cocos2dx_extratools_MirTileMap_getMapTiles);
        tolua_function(tolua_S,"getImgIdx",lua_cocos2dx_extratools_MirTileMap_getImgIdx);
        tolua_function(tolua_S,"readMapTileData",lua_cocos2dx_extratools_MirTileMap_readMapTileData);
        tolua_function(tolua_S,"getPortal",lua_cocos2dx_extratools_MirTileMap_getPortal);
        tolua_function(tolua_S,"getMapTile",lua_cocos2dx_extratools_MirTileMap_getMapTile);
        tolua_function(tolua_S,"getHeight",lua_cocos2dx_extratools_MirTileMap_getHeight);
        tolua_function(tolua_S,"init",lua_cocos2dx_extratools_MirTileMap_init);
        tolua_function(tolua_S,"readMapData",lua_cocos2dx_extratools_MirTileMap_readMapData);
        tolua_function(tolua_S,"readShort",lua_cocos2dx_extratools_MirTileMap_readShort);
        tolua_function(tolua_S,"initWithMapFile",lua_cocos2dx_extratools_MirTileMap_initWithMapFile);
        tolua_function(tolua_S,"setTileOrder",lua_cocos2dx_extratools_MirTileMap_setTileOrder);
        tolua_function(tolua_S,"initMapTileSprite",lua_cocos2dx_extratools_MirTileMap_initMapTileSprite);
        tolua_function(tolua_S,"getPortalCount",lua_cocos2dx_extratools_MirTileMap_getPortalCount);
        tolua_function(tolua_S,"setHeight",lua_cocos2dx_extratools_MirTileMap_setHeight);
        tolua_function(tolua_S,"is1AtTopDigit",lua_cocos2dx_extratools_MirTileMap_is1AtTopDigit);
        tolua_function(tolua_S,"hindPart",lua_cocos2dx_extratools_MirTileMap_hindPart);
        tolua_function(tolua_S,"showPartEx",lua_cocos2dx_extratools_MirTileMap_showPartEx);
        tolua_function(tolua_S,"getInitComplete",lua_cocos2dx_extratools_MirTileMap_getInitComplete);
        tolua_function(tolua_S,"release",lua_cocos2dx_extratools_MirTileMap_release);
        tolua_function(tolua_S,"updateTile",lua_cocos2dx_extratools_MirTileMap_updateTile);
        tolua_function(tolua_S,"is1AtTopDigitForShort",lua_cocos2dx_extratools_MirTileMap_is1AtTopDigitForShort);
        tolua_function(tolua_S,"create", lua_cocos2dx_extratools_MirTileMap_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MirTileMap).name();
    g_luaType[typeName] = "MirTileMap";
    g_typeCast["MirTileMap"] = "MirTileMap";
    return 1;
}
TOLUA_API int register_all_cocos2dx_extratools(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"et",0);
	tolua_beginmodule(tolua_S,"et");

	lua_register_cocos2dx_extratools_MirFileLoader(tolua_S);
	lua_register_cocos2dx_extratools_ODClient(tolua_S);
	lua_register_cocos2dx_extratools_MyTextField(tolua_S);
	lua_register_cocos2dx_extratools_MirTileMap(tolua_S);
	lua_register_cocos2dx_extratools_SpriteX(tolua_S);
	lua_register_cocos2dx_extratools_CursorTextField(tolua_S);
	lua_register_cocos2dx_extratools_MapTileInfo(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

