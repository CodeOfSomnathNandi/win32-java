#include "utility.h"

char *jstring_to_cstr(JNIEnv *env, jstring str)
{
    int length = env->GetStringLength(str);
    char *cstr = new char[length + 1];
    const jchar *charArray = env->GetStringChars(str, nullptr);

    for (int i = 0; i < length; i++)
    {
        cstr[i] = (char)charArray[i];
    }

    cstr[length] = '\0';

    return cstr;
}