#include "result.h"

#define RESULT_C(suffix, type)                                                                     \
                                                                                                   \
    Result_##suffix Ok_##suffix(type ok_result) {                                                  \
        Result_##suffix res = {                                                                    \
            .is_err = false,                                                                       \
            .ok     = ok_result,                                                                   \
            .err    = "",                                                                          \
        };                                                                                         \
        return res;                                                                                \
    }                                                                                              \
                                                                                                   \
    Result_##suffix Err_##suffix(char* message) {                                                  \
        Result_##suffix res = {                                                                    \
            .is_err = true,                                                                        \
            .err    = message,                                                                     \
        };                                                                                         \
        return res;                                                                                \
    }

RESULT_C(int, int);
RESULT_C(float, float);
RESULT_C(char_p, char*);