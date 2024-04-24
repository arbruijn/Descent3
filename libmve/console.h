#include <stdio.h>
#define con_printf(lvl, format, ...) fprintf (stderr, format, ## __VA_ARGS__)
