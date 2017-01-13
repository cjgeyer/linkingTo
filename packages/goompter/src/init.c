
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include "goompter.h"

static R_NativePrimitiveArgType goompter_types[2] = {INTSXP, REALSXP};

static R_NativeArgStyle goompter_styles[4] = {R_ARG_IN, R_ARG_IN_OUT};

static R_CMethodDef cMethods[] = {
    {"goompter", (DL_FUNC) &goompter, 2, goompter_types, goompter_styles},
    {NULL, NULL, 0, NULL, NULL}
};

static R_CallMethodDef callMethods[]  = {
    {NULL, NULL, 0}
};

void R_init_goompter(DllInfo *info)
{
    R_registerRoutines(info, cMethods, callMethods, NULL, NULL);
}


