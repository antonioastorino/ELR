#ifndef RESULT
#define RESULT

#include <stdbool.h>

#define RESULT_H(suffix, type)                                                                     \
    typedef struct {                                                                               \
        bool is_err;                                                                               \
        type ok;                                                                                   \
        char* err;                                                                                 \
    } Result_##suffix;                                                                             \
                                                                                                   \
    Result_##suffix Ok_##suffix(type ok_result);                                                   \
                                                                                                   \
    Result_##suffix Err_##suffix(char* message);

RESULT_H(int, int);
RESULT_H(float, float);
RESULT_H(char_p, char*);

#define Err(unused, X) _Generic(unused, int : Err_int, float : Err_float, char* : Err_char_p)(X)
#define Ok(X) _Generic(X, int : Ok_int, float : Ok_float, char* : Ok_char_p)(X)
#endif