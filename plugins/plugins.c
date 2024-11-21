
#include "plugins.h"

static const struct luaL_Reg plugin_functions[] = {
    #define X(lua_func, c_func)  \
    { #lua_func, c_func },
    ROOTBEER_PLUGINS
    #undef X
    { NULL, NULL } // protect against empty case
};

void register_rootbeer_plugins(lua_State* L) {
    luaL_newlib(L, plugin_functions);
}

