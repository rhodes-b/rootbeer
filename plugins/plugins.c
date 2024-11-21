
#include "plugins.h"

static const struct luaL_Reg plugin_functions[] = {
    #define X(lua_func, c_func)  \
    { #lua_func, c_func },
    ROOTBEER_PLUGINS
    #undef X
    { NULL, NULL } // protect against empty case
};

#define NUM_PLUGINS (sizeof(plugin_functions) / sizeof(plugin_functions[0]) - 1)

int get_rootbeer_plugin_count(void) {
    return NUM_PLUGINS;
};

int get_rootbeer_plugin(const struct luaL_Reg *plugin, int index) {
    if (index >= NUM_PLUGINS) {
        return -1;
    }
    plugin = &plugin_functions[index];
    return 0;
}

