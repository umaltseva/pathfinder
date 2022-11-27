#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
   unsigned long val = 0;
    while (*hex) {
        char byte = *hex++; 
        if (mx_isalpha(byte)) {
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        val = (val << 4) | (byte & 0xF);
        }
        else {
            return 0;
        }
    }
    return val;
}



