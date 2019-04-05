/*
 * computeOperation - read a mathematical expression
   and compute it then write back the result of it
 */

#include "csapp.h"

void computeOperation(int connfd) {
  int bufsize, no1, no2, index = 0, flag = 1;
  int result;
  char buf[MAXLINE];
  char cNo1[10], cNo2[10];
  char op;
  bufsize = read(connfd, buf, MAXLINE);

  for (int i = 0; i < bufsize; i++) {

    if (buf[i] == ' ') {
      continue;
    }
    // get operation if found
    if (buf[i] == '+' || buf[i] == '-' || buf[i] == '/' || buf[i] == '*' ||
        buf[i] == '%') {
      op = buf[i];
      // set flag to 2 to get the second number and reset index to use it in the
      // second no
      flag = 2;
      index = 0;
    }
    // if input is a number
    if ((buf[i] >= '0') && (buf[i] <= '9')) {
      // get first number
      if (flag == 1) {
        cNo1[index++] = buf[i];
      }
      // else get the second number
      else if (flag == 2) {
        cNo2[index++] = buf[i];
      }
    }
    // if you got here means input is not a number or + * / -
  } // end of for loop
  printf("client send %s %c %s\n", cNo1, op, cNo2);
  // convert string to int
  no1 = atoi(cNo1);
  no2 = atoi(cNo2);

  switch (op) {
  case '+':
    result = no1 + no2;
    break;
  case '-':
    result = no1 - no2;
    break;
  case '*':
    result = no1 * no2;
    break;
  case '/':
    result = no1 / no2;
    break;
  case '%':
    result = no1 % no2;
    break;
  default:
    printf("in valid operation");
    write(connfd, "invalid operation", 15);
  }

  printf("send %s %c %s = %d\n", cNo1, op, cNo2, result);
  // conver int to string
  sprintf(buf, "%d", result);
  write(connfd, buf, 15);
}
