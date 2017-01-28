#include <stddef.h>
#include <R_ext/Rdynload.h>
#include "myfoompter.h"
#include "foompter.h"

// Note that foompter.h is not in this package but in the foompter package.
// We can see it because we have foompter in the LinkingTo field of our
// DESCRIPTION file and foompter has it in its inst/include directory.

// The way this function works follows the examples in
// the file Matrix_stubs.c in the R Recommended Package Matrix.
// In any R source tree src/library/Recommended has the tarball.
// After untarring it, the file is inst/include/Matrix_stubs.c.

// The definitive reference is Section 5.4.2 of Writing R Extensions

inline void myfoompter(int *n, double *x)
{
    static foompter_funptr fun = NULL;
    if (fun == NULL)
        fun = (foompter_funptr) R_GetCCallable("foompter", "foompter");
    fun(n, x);
}
