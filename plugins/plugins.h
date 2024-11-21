
#include <lauxlib.h>
#include "example_plugin.h"

// format is Lua exported name, C func name
// X(lua, c)
#define ROOTBEER_PLUGINS         \
    EXAMPLE_PLUGIN

void register_rootbeer_plugins(lua_State* L);

