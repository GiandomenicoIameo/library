/* This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY. For more details consult the code.

   This library is free software; you can redistribute it and/or
   modify. ISO C99 Standard: 1.0 Characters      <characters.h>
*/

#ifndef _CHARACTERS_H
#define _CHARACTERS_H

#include <ctype.h>
#include <string.h>

char isvowel( char c );
unsigned int strcd( const char *s );
unsigned int strcsp( const char *s );

#endif
