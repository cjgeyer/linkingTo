#include <stddef.h>
#include <R_ext/Rdynload.h>
#include "myfoompter.h"
#include "foompter.h"

// the way this function works follows the examples in
// the file Matrix_stubs.c in the R Recommended Package Matrix.
// In any R source tree src/library/Recommended has the tarball.
// After untarring it, the file is inst/include/Matrix_stubs.c.

void myfoompter(int *n, double *x)
{
    static foompter_funptr fun = NULL;
    if (fun == NULL)
        fun = (foompter_funptr) R_GetCCallable("foompter", "foompter");
    fun(n, x);
}
