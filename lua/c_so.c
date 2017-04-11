#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static int square(lua_State *L){
	float ret=lua_tonumber(L,-1);
	printf("top of square,%f\n",ret);
	lua_pushnumber(L,ret*ret);
	return 1;
}

static int cube(lua_State *L){
	float ret=lua_tonumber(L,-1);
	printf("top of cube,%f\n",ret );
	lua_pushnumber(L,ret*ret*ret);
	return 1;
}

int luaopen_c_so(lua_State *L){
	lua_register(L,"square",square);
	lua_register(L,"cube",cube);
	return 0;
}