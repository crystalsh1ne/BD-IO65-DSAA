#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
  char data;
  struct Node *next;
} Node;

typedef struct
{
  Node* top;
} Stack;

void
init (Stack *s)
{
  s->top = NULL;
}

bool
isEmpty (Stack *s)
{
  return s->top == NULL;
}

bool
isFull (Stack *s)
{
  return false; // hope you have enough memory
}

bool
push (Stack *s, char val)
{
  Node *newnode = (Node *) malloc (sizeof (Node));
  if (newnode == NULL)
    {
      printf ("Allocating error. Abort.");
      return false;
    }
  newnode->data = val;
  newnode->next = s->top;
  s->top = newnode;
  return true;
}

bool
pop (Stack *s, char *val)
{
  if (isEmpty (s))
    {
      printf ("The stack is empty--cannot do pop operation.\n");
      return false;
    }
  Node *temp = s->top;
  *val = temp->data;
  s->top = temp->next;
  free (temp);
  return true;
}

void
byebye (Stack *s)
{
  char ch;
  while (!isEmpty (s))
    {
      pop(s, &ch); // xd
    }
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


int
main ()
{
  char test_string[] = "((()))"; // max depth is 3, correct
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
  printf("--- TEST BOUNDARIES ---\n");
  stressTest();
  return 0;
}
