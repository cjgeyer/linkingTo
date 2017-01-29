
#include <math.h>
#include "foompter.h"

void foompter(int *n, double *x)
{
    for (int i = 0; i < n[0]; i++)
        x[i] = sin(3.0 * x[i]);
}

// We don't use this function pointer.  It is just here to make
// the compiler complain if the typedef is wrong.
// And we only need the typedef for the benefit of functions in other
// R packages calling foompter via the R_GetCCallable mechanism

#include "foompter-export.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
static foompter_funptr foobarbaz = foompter;
