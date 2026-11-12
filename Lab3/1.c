#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct
{
  int top;
  char data[MAXSIZE];
} Stack;

void
init (Stack *stack)
{
  stack->top = -1;
}

bool
isFull (Stack *stack)
{
  return stack->top == MAXSIZE-1;
}

bool
isEmpty (Stack *stack)
{
  return stack->top == -1;
}


bool
push (Stack *stack, char val)
{
  if (isFull (stack))
    {
      printf ("The stack is full--cannot do push operation.\n");
      return false;
    }
  stack->data[++(stack->top)] = val;
  return true;
}

bool
pop (Stack *stack, char *val)
{
  if (isEmpty (stack))
    {
      printf ("The stack is empty--cannot do pop operation\n");
      return false;
    }
  *val = stack->data[(stack->top)--];
  return true;
}

int
currentPos (Stack *stack)
{
  return stack->top;
}

void
byebye (Stack *stack)
{
  stack->top = -1;
}


void
stressTest ()
{
  Stack stack;
  init(&stack);
  char dummy;
  if (pop(&stack, &dummy) == false)
    {
      printf("Pop operatior for empty stack!\n");
    }

  for (int i = 0; i < 105; i++)
    {
      if (push (&stack, '0') == false)
        {
          printf("Push operation for full stack!\n");
          break;
        }
    }
}


// core logic is under this message (i decided not to break down in extra function)


int
main ()
{
  char test_string[] = "(())";
  Stack stack;
  init(&stack);
  int current_depth = 0;
  int max_depth = 0;
  bool is_valid = true;

  for (int i = 0; test_string[i] != '\0'; i++)
    {
      if (test_string[i] == '(')
        {
          if (!push(&stack, '('))
            {
              printf ("Stack overflow. Aborting.\n");
              byebye(&stack);
              return false;
            }
          current_depth++;
          if (current_depth > max_depth)
            {
              max_depth = current_depth;
            }
        }
      else if (test_string[i] == ')')
        {
          char val;
          if (!pop (&stack, &val))
            {
              printf ("The stack is empty (extra parenthesis has been found). Aborting.\n");
              is_valid = false;
              break;
            }
          current_depth--;
        }
    }

  if (!isEmpty(&stack))
    {
      printf ("The stack shall be empty but it is not (unclosed parentheses)\n");
      is_valid = false;
    }

  byebye(&stack);
  if (is_valid)
    {
      printf ("%s is correct, and its maximum depth is %d.\n", test_string, max_depth);
    }
  else
    {
      printf ("%s is incorrect.\n", test_string);
    }
  printf("--- TEST BOUNDARIES --\n");
  stressTest();
  return 0;
}



