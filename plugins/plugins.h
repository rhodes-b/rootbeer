
#include <lauxlib.h>
#include "example_plugin.h"

// format is Lua exported name, C func name
// X(lua, c)
#define ROOTBEER_PLUGINS         \
    EXAMPLE_PLUGIN

int get_rootbeer_plugin_count(void);

// we should make a STATUS enum eventually
int get_rootbeer_plugin(const struct luaL_Reg *plugin, int index);

