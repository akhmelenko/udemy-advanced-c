#include <stdio.h>
#include "debug.h"

void Foo()
{
    DPRINT(DEBUG_LEVEL_MORE_DETAILS, "my debug print %d %s\n", 3, "debug_string");
}

int main()
{
    Foo();

    return 0;
};
