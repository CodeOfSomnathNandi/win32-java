#include "com_kernel_SimpleFunctions.h"

#ifndef SOMNATH_UTILITY
#define SOMNATH_UTILITY

#ifdef __cplusplus
extern "C" {
#endif

char *jstring_to_cstr(JNIEnv *env, jstring str);

#ifdef __cplusplus
}
#endif

#endif