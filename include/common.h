#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *msg);
void warn_msg(const char *prefix, const char *msg);
void *safe_malloc(size_t size);

#endif /* COMMON_H */
