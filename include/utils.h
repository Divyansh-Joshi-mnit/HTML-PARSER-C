#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// Safe allocation wrapper with error checking
void *safe_malloc(size_t size);

// Safe duplication wrapper for strings
char *safe_strdup(const char *s);

#endif // UTILS_H