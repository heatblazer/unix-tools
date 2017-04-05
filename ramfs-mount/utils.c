#include "utils.h"
#include <stdlib.h>

static int aux_strlen(const char* str)
{
    int size = 0;
    while ( *str != '\0') {
        size++;
        str++;
    }
    return size;
}

// bug with the delimiter logic - Fixed it after very big string test!
static char* aux_slice(const char* str, char delimiter, const char** pRet)
{
    int size = 0, i = 0;
    const char* begin = str;
    char  *ret = NULL;
    int match = 0;

    if (!str) {
        return NULL;
    }

    while (*begin != '\0') {
        if (*begin == delimiter) {
            match++;
            break;
        }
        size++;
        begin++;
    }

    ret = (char*)malloc(sizeof(char) * size);

    if(ret == NULL) {
        return NULL;
    }

    if (match) {
        /* we have a delimiter ??? */
        for(i = 0; str[i] != delimiter; ++i) {
            ret[i] = str[i];
        }

        ret[i] = '\0';

        while (*begin == delimiter) {
            begin++;
        }
        (*pRet) = begin;

    } else {
        /* or we just copy the remaining string.... */
        for(i=0; str[i] != '\0'; ++i) {
            ret[i] = str[i];
        }
        ret[i] = '\0';
        (*pRet) = NULL;
    }

    return ret;
}


const char* strchr2(const char* str, char c, int count)
{
    const char* it =  str;
    int i = 0;
    while ( (*it != '\0') && (i < count)) {
        it++;
        if (*it == c) {
            i++;
        }
    }
    return it;
}


char **split(const char *str, char delimiter, int *ret_size)
{
    const char* begin = str;
    const char* end = &str[aux_strlen(str)-1];
    while (*begin == delimiter) begin++;
    while (*end == delimiter) end--;
    int splits = 0;
    int diff = (end - begin)+1;

    int i =0;
    while (i < diff) {
        // avoid cases of adjacent delimiters
        // like "str1,str2,,,,,str3
        if (begin[i] == delimiter) {
            while (begin[i] == delimiter) i++;
            splits++;
        }
        i++;
    }
    splits += 1;
    *ret_size = splits;
    char** split_str = (char**)malloc(sizeof(char**)*splits);

    if (split_str == NULL) {
        return NULL;
    }
    for(int i=0; i < splits; ++i) {
        split_str[i] = aux_slice(begin, delimiter, &begin);
    }
    return split_str;
}
