#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    char *cur;
    char *last;
    const char *cbig = (const char*) big;
    const char *clittle = (const char*) little;
    	
    if (big_len == 0 || little_len == 0)
		return NULL;

	if (big_len < little_len)
		return NULL;

	
	if (big_len == 1)
		return mx_memchr(big, (int)*clittle, big_len);

	
	last = (char *)cbig + big_len - little_len;

	for (cur = (char *)cbig; cur <= last; cur++)
		if (cur[0] == clittle[0] && mx_memcmp(cur, clittle, little_len) == 0)
			return cur;

	return NULL;
}




