/**
 * This is a very naive implementation of the PHP function `str_replace` in C.
 * I wrote it in purpuse to learn C basics.
 * 
 * 
 * Basically, it search for the index of the searched word in the subject string.
 * 
 * If no index found, then it returns the subject.
 * 
 * Otherwize it splits the subject string into 3 parts :
 *      - prefix : all chars before the searched word
 *      - searched word
 *      - suffix : all chars after the searched word
 * and it replaces the searched word by the replace parameter.
 * 
 * Finally, it join prefix with replace and suffix, and returns it as string.
 * 
 * @author BetaWeb / Cyprien GLEPIN
 **/

#include "str_replace.h"

/**
 * Returns the first index of a character or a group of characters on a string
 * 
 * @param str The string in which to look
 * @param c The character or group of characters of which we want to found the index
 * 
 * @return The found index if it exists, -1 otherwise
 **/
int indexOf(char *str, char *c) {
    char *pointer = strlen(c) > 1 
        ? strstr(str, c) 
        : strchr(str, c[0]);

    if (pointer == NULL) {
        return -1;
    }

    return pointer - str;
}

/**
 * Replaces the first occurrence of the searched string in the subject string.
 *
 * @param search The substring to look for
 * @param replace The substring with which to replace the found substring
 * @param subject The string in which to look
 *
 * @return A new string with the search/replacement performed
 **/
char *str_replace(char *search, char *replace, char *subject) {
    int suffix_len, result_len, search_len, replace_len, subject_len, index;
    char *result, *prefix, *suffix;
    
    search_len = strlen(search);
    subject_len = strlen(subject);
    index = indexOf(subject, search);

    if (search_len == 0 || index < 0) {
        result = malloc(subject_len + 1);
        strncpy(result, subject, subject_len + 1);
        
        return result;
    }

    prefix = malloc(index + 1);
    strncpy(prefix, subject, index);
    
    suffix_len = subject_len - (index + search_len);
    suffix = malloc(suffix_len + 1);
    strncat(suffix, subject + index + search_len, suffix_len);

    replace_len = strlen(replace);
    result_len = strlen(prefix) + replace_len + suffix_len + 1;    
    result = malloc(result_len + 1);
    snprintf(result, result_len, "%s%s%s", prefix, replace, suffix);

    free(prefix);
    free(suffix);

    return result;
}

int main(void) {
    char *original_str, *replaced_str;
    
    original_str = "This is a very powerful implementation of str_replace function";
    replaced_str = str_replace("powerful", "naive", original_str);
    
    printf("Original : %s (%d char)\n", original_str, strlen(original_str));
    printf("Replaced : %s (%d char)\n", replaced_str, strlen(replaced_str));

    free(replaced_str);
    original_str = NULL;

    return 1;
}