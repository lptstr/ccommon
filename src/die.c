#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "die.h"
#include "types.h"

usize
die(const char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vfprintf(stderr, fmt, ap);
        va_end(ap);

        if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
                fputc(' ', stderr);
                perror(NULL);
        } else {
                fputc('\n', stderr);
        }

        exit(1);

        /* return dummy value so that die() can
         * be used with a boolean expression
         * e.g.: is_ok || die("message")
         */
        return 0;
}
