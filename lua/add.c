/*
* c调用lua 文件 add.lua
*/
#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

lua_State* L;

int luaadd(int x,int y, int z){
    int sum;
    lua_getglobal(L,"add");
    lua_pushnumber(L,x);
    lua_pushnumber(L,y);
    lua_pushnumber(L,z);
    lua_call(L,3,1);
    sum=(int)lua_tonumber(L,-1);
    lua_pop(L,1);
    return sum;
}

int main(){
	int sum;

	L=luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L,"add.lua");
	sum=luaadd(10,15,20);
	printf("The sum is %d\n",sum );
	lua_close(L);
	return 0;
}