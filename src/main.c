//
//  main.c
//  errors-in-c
//
//  Created by Antonio Astorino on 27/03/2021.
//

#include "result.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // insert code here...
    Result_float d = divide(324.0, 4.3);
    if (d.is_err) {
        printf("Err: %s\n", d.err);
    } else {
        printf("Result: %f\n", d.ok);
    }
    return 0;
}
