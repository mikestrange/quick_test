#include "lua_cocos2dx_screen_helper_auto.hpp"
#include "../../../GLScreenHelper.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_screen_helper_GLScreenHelper_screenFlush(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GLScreenHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_screen_helper_GLScreenHelper_screenFlush'", nullptr);
            return 0;
        }
        GLScreenHelper::screenFlush();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "GLScreenHelper:screenFlush",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_screen_helper_GLScreenHelper_screenFlush'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_screen_helper_GLScreenHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GLScreenHelper)");
    return 0;
}

int lua_register_cocos2dx_screen_helper_GLScreenHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GLScreenHelper");
    tolua_cclass(tolua_S,"GLScreenHelper","GLScreenHelper","",nullptr);

    tolua_beginmodule(tolua_S,"GLScreenHelper");
        tolua_function(tolua_S,"screenFlush", lua_cocos2dx_screen_helper_GLScreenHelper_screenFlush);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GLScreenHelper).name();
    g_luaType[typeName] = "GLScreenHelper";
    g_typeCast["GLScreenHelper"] = "GLScreenHelper";
    return 1;
}
TOLUA_API int register_all_cocos2dx_screen_helper(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_cocos2dx_screen_helper_GLScreenHelper(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

