#include <stdio.h>
#include <string.h>

int safe_strcmp(const char *s1, const char *s2, size_t n)
{
    const char *end1 = memchr(s1, '\0', n);	// Find null terminator in s1 or first n characters
    const char *end2 = memchr(s2, '\0', n);	// Find null terminator in s2 or first n characters

    if (end1 == NULL && end2 == NULL)
	return memcmp(s1, s2, n);	// If both strings are null-terminated within the first n characters, compare them with memcmp

    if (end1 == NULL)
	return 1;		// s1 is not null-terminated within the first n characters, so it's considered greater than s2

    if (end2 == NULL)
	return -1;		// s2 is not null-terminated within the first n characters, so it's considered greater than s1

    size_t len1 = end1 - s1;	// Length of s1 within the first n characters
    size_t len2 = end2 - s2;	// Length of s2 within the first n characters

    size_t min_len = (len1 < len2) ? len1 : len2;	// Minimum length between s1 and s2 within the first n characters

    int cmp_result = memcmp(s1, s2, min_len);	// Compare the common part of s1 and s2

    if (cmp_result != 0)
	return cmp_result;	// If the common part is not equal, return the result

    if (len1 < len2)
	return -1;		// If s1 is shorter than s2 within the first n characters, it's considered less than s2

    if (len1 > len2)
	return 1;		// If s1 is longer than s2 within the first n characters, it's considered greater than s2

    return 0;			// If lengths are equal and the common part is equal, return 0
}

int main()
{
    const char *str1 = "hello";
    const char *str2 = "world";
    int result = safe_strcmp(str1, str2, 3);	// Compare only the first 3 characters

    if (result < 0)
	printf("%s is less than %s\n", str1, str2);
    else if (result > 0)
	printf("%s is greater than %s\n", str1, str2);
    else
	printf("%s is equal to %s\n", str1, str2);

    return 0;
}
