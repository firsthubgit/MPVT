#include "log.h"

#include <stdlib.h>

void die(const char *msg)
{
    ALOGE("%s", msg);
    exit(1);
}

void elog(const char *msg){
    ALOGE("%s", msg);
}