#include <stdio.h>
#include <ctype.h>
#include "include/characters.h"

char isvowel( char c ) {

  switch( c ) {
    case 'a' :
    case 'A' :

    case 'e' :
    case 'E' :

    case 'i' :
    case 'I' :

    case 'o' :
    case 'O' :

    case 'u' :
    case 'U' :
      return 1;
    default :
      return 0;
  }
}

unsigned int strcd( const char *s ) {

  unsigned int count = 0;

  for( ; *s != '\0'; s++ ) {
    if( isdigit( *s ) ) count++;
  }
  return count;
}

unsigned int strcch( const char *s ) {

  unsigned int count = 0;

  for( ; *s != '\0'; s++ ) {
    count++;
  }
  return count;
}

unsigned int strcsp( const char *s ) {

  unsigned int count = 0;

  for( ; *s != '\0'; s++ ) {
      if( *s == ' ' ) count++;
  }
  return count;
}
