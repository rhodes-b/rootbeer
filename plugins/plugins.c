
#include "plugins.h"

static const struct luaL_Reg plugin_functions[] = {
    #define X(lua_func, c_func)  \
    { #lua_func, c_func },
    #undef X
};

int get_rootbeer_plugin_count(void) {
    return 0;
};

int get_rootbeer_plugin(const struct luaL_Reg *plugin, int index) {
    (void)plugin;
    (void)index;
    return 0;
}

