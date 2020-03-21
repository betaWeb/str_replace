# Implementation of `str_replace` in C

 This is a very naive implementation of the PHP function `str_replace` in C.
 I wrote it in purpuse to learn C basics.
 
 
 Basically, it search for the index of the searched word in the subject string.
 
 If no index found, then it returns the subject.
 
 Otherwize it splits the subject string into 3 parts :
      - prefix : all chars before the searched word
      - searched word
      - suffix : all chars after the searched word
 and it replaces the searched word by the replace parameter.
 
 Finally, it join prefix with replace and suffix, and returns it as string.
