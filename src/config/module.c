#include "lua_module.h"
#include "plugins.h" // Defined from CMake; see the PLUGIN_INCLUDES variable in the main CMakeLists.txt file for more info

// We pack all of the lua functions here into a single struct
// so that they can all be loaded in as a module and called in lua code 
static const struct luaL_Reg functions[] = {
	{"debug_test", rb_lua_debug_test},
	REGISTER // REGISTER is defined from CMake, depends on the plugins included in the build; see the register variable for more info
	{NULL, NULL}
};

// Virtual package entrypoint for the package.preload table
int lua_mod_entrypoint(lua_State *L) {
	luaL_newlib(L, functions);
	return 1;
}

void rb_lua_create_module(lua_State *L) {
	lua_pushcfunction(L, lua_mod_entrypoint);
	lua_setfield(L, LUA_REGISTRYINDEX, "rootbeer");

	// Add it to package.preload now that it's loaded
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "preload");
	lua_pushcfunction(L, lua_mod_entrypoint);
	lua_setfield(L, -2, "rootbeer");
	lua_pop(L, 2);
}
