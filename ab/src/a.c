#include "a.h"

#include <stddef.h>
#include <stdio.h>

#define ARRAY_SIZE(array)   (sizeof(array)/sizeof(array[0]))

State_t state = STATE_NONE;
int len = 0;
int counter = 0;
char buffer[22];

char* accept_byte(char c)
{
   // if (c == '[') {
   //    state = STATE_CMD;
   //    counter = 0;
   //    len = 0;
   //    return NULL;
   // }

   // if (c >= 'A' && c <= 'Z' && state == STATE_CMD) {
   //    state = STATE_LEN;
   //    return NULL;
   // } else if (c == '[' && state == STATE_CMD) {
   //    state = STATE_CMD;
   //    return NULL;
   // } else if (state == STATE_CMD && c != '[') {
   //    state = STATE_START;
   //    return NULL;
   // }

   // if (c == '0' && state == STATE_LEN) {
   //    state = STATE_END;
   //    return NULL;
   // } else if (c >= 1 && c <= 9 && state == STATE_LEN) {
   //    state = STATE_DATA;
   //    len = c;
   //    return NULL;
   // } else if (c == '[' && state == STATE_LEN) {
   //    state = STATE_CMD;
   //    return NULL;
   // } else if (state == STATE_LEN && c != '[') {
   //    state = STATE_START;
   //    return NULL;
   // }

   // if (counter < len && (c >= '1' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') && state == STATE_DATA) {
   //    counter++;
   //    if (counter == len) {
   //       state = STATE_END;
   //    }
   //    return NULL;
   // }  else if (c == '[' && state == STATE_DATA) {
   //    state = STATE_CMD;
   //    return NULL;
   // } else if (state == STATE_DATA && c != '[') {
   //    state = STATE_START;
   //    return NULL;
   // }

   if (state == STATE_START) {
      if (c == '[') {
         state = STATE_CMD;
         counter = 0;
         len = 0;
      }
      buffer[ARRAY_SIZE(buffer)] = c;
      return buffer;
   }
   if (state == STATE_CMD) {
      if (c >= 'A' && c <= 'Z') {
         state = STATE_LEN;
      } else if (c != '[') {
         state = STATE_START;
      }else if (c == '[') {
         state = STATE_CMD;
      }
      buffer[ARRAY_SIZE(buffer)] = c;
      return buffer;
   }
   if (state == STATE_LEN) {
      if (c == '0') {
         state = STATE_END;
      } else if (c >= 1 && c <= 9) {
         state = STATE_DATA;
         len = c;
      } else if (c == '[') {
         state = STATE_CMD;
      } else if (c != '[') {
         state = STATE_START;
      }
      buffer[ARRAY_SIZE(buffer)] = c;
      return buffer;
   }
   if (state == STATE_DATA) {
      if (counter < len && (c >= '1' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
         counter++;
         if (counter == len) {
            state = STATE_END;
         }
      }  else if (c == '[') {
         state = STATE_CMD;
      } else if (c != '[') {
         state = STATE_START;
      }
      buffer[ARRAY_SIZE(buffer)] = c;
      return buffer;
   }
   if (state == STATE_END) {}

   return NULL;
}
