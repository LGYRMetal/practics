#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef int ElementType;
#define FatalError(err_msg)  (err(-1, err_msg))
#define Error(err_msg)       (err(-1, err_msg))

#endif
