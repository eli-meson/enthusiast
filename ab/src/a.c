#include "a.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(array)   (sizeof(array)/sizeof(array[0]))

State_t state = STATE_NONE;
int len = 0;
int counter = 0;
int data_counter = 0;
char buffer[23];

char* accept_byte(char c)
{
   if (state == STATE_START) {
      if (c == '[') {
         state = STATE_CMD;
         counter = 0;
         len = 0;
         memset(buffer, 0, sizeof(buffer));
      }
      buffer[counter++] = c;
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
      buffer[counter++] = c;
      return buffer;
   }
   if (state == STATE_LEN) {
      if (c == '0') {
         state = STATE_END;
      } else if (c >= 1 && c <= 9) {
         state = STATE_DATA;
         len = c * 2;
      } else if (c == '[') {
         state = STATE_CMD;
      } else if (c != '[') {
         state = STATE_START;
      }
      buffer[counter++] = c;
      return buffer;
   }
   if (state == STATE_DATA) {
      if (data_counter < len && (c >= '1' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
         data_counter++;
         if (data_counter >= len) {
            state = STATE_END;
         }
      } else if (c == '[') {
         state = STATE_CMD;
      } else if (c != '[') {
         state = STATE_START;
      }
      buffer[counter++] = c;
      return buffer;
   }
   if (state == STATE_END) {
      if (c == ']') {
         state = STATE_START;
      }   else if (c == '[') {
         state = STATE_CMD;
      } else if (c != '[') {
         state = STATE_START;
      }
      buffer[counter++] = c;
      return buffer;
   }

   return NULL;
}
