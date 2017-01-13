
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include "foompter.h"

static R_NativePrimitiveArgType foompter_types[2] = {INTSXP, REALSXP};

static R_NativeArgStyle foompter_styles[4] = {R_ARG_IN, R_ARG_IN_OUT};

static R_CMethodDef cMethods[] = {
    {"foompter", (DL_FUNC) &foompter, 2, foompter_types, foompter_styles},
    {NULL, NULL, 0, NULL, NULL}
};

static R_CallMethodDef callMethods[]  = {
    {NULL, NULL, 0}
};

void R_init_foompter(DllInfo *info)
{
    R_registerRoutines(info, cMethods, callMethods, NULL, NULL);

    R_RegisterCCallable("foompter", "foompter", (DL_FUNC) foompter);
}


