#include "varMap.h"
varMap gvars;

/* The global variable object, gvars, has been tested, works, and is ready to be used by everyone!

Here's a quick overview of how to use them:
--The class varMap is declared and defined in varMap.h and varMap.cpp, respectively, and the object itself is instantiated in varMapDef.cpp. I'm also going to put a copy of these instructions in varMapDef.cpp, since right now that file's feeling kinda lonely~.

--The object gvars is declared in varMap.h, as are a number of const strings CAPITAL_LETTERS = "camelCase".

--To insert something into the gvars object, use gvars.insert(CONST_STRING_, value), where value can be e.g. an int, a float, a double, a string, a char, a bool, and if you need something else I can add it. Note that CONST_STRING_ should be one of the const strings that was declared at the bottom of Common.h (feel free to add to this list!). Please do not simply type in a string yourself--do not type e.g. gvars.insert("myVarName",7). Add the line CONST STRING MY_VAR_NAME = "myVarName" to the bottom of Common.h, and use that instead. If you do not already know why I'm insisting on this, spend some time thinking on it--it's a good thought exercise.

--To fetch something, use the one of the following which seems most appropriate for your needs:
----gvars.getInt(CONST_STRING_)
----gvars.getDouble(CONST_STRING_)
----gvars.getStr(CONST_STRING_)
----gvars.getBool(CONST_STRING_)
----gvars.getChar(CONST_STRING_)
....You get the idea. Again, make sure to be using const strings for the argument!

--Also, you'll need to include the file "Common.h" if it's not being included already.
 Furthermore, do not attempt to redeclare the container--the line "varMap gvars;" will actually cause the container to replace itself and everything inside to fall out.*/