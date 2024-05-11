/*int argc, char * argv[]*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char stateNow;
  struct node *state0;
  struct node *state1;
  struct node *current; /*This points to the current node. Should in only one node*/
}node;

int 
main(int argc, char * argv[])
{
	/*First make a linked list to store the finite state machine. Then have if statements to select perform the required commands.*/
	
	/*Local Variable list*/
      char inputs[3];
      int unreachable[7] = {0,0,0,0,0,0,0}; /*1 if that is unreachable*/
      int garbageOn = 0; /*0 if there is no garbage and 1 if there is*/
      int end = 0; /*end = 0 if its not at the end, else 1*/
      int deleted[7] = {0,0,0,0,0,0,0};
	  struct node *head = (struct node*) malloc(sizeof(struct node));
	  struct node *A = (struct node*) malloc(sizeof(struct node));
	  struct node *B = (struct node*) malloc(sizeof(struct node));
	  struct node *C = (struct node*) malloc(sizeof(struct node));
	  struct node *E = (struct node*) malloc(sizeof(struct node));
	  struct node *F = (struct node*) malloc(sizeof(struct node));
	  struct node *G = (struct node*) malloc(sizeof(struct node));
	  struct node *H = (struct node*) malloc(sizeof(struct node));
	  
	  /*This is the currentState node which will point to the current state.*/
	  struct node *CurrentState = (struct node*) malloc(sizeof(struct node));
	  
	  /*State the values, including state0 and state1 values for the FSM*/
	  head ->stateNow = 'D';
	  head ->state0 = C;
	  head ->state1 = E;
	  
	  A ->stateNow = 'A';
	  A ->state0 = H;
	  A ->state1 = B;
	  
	  
	  B ->stateNow = 'B';
	  B ->state0 = G;
	  B ->state1 = C;
	  
	  C ->stateNow = 'C';
	  C ->state0 = G;
	  C ->state1 = F;
	  
	  E ->stateNow = 'E';
	  E ->state0 = F;
	  E ->state1 = head;
	  
	  F ->stateNow = 'F';
	  F ->state0 = A;
	  F ->state1 = F;
	  
	  G ->stateNow = 'G';
	  G ->state0 = head;
	  G ->state1 = H;
	  
	  H ->stateNow = 'H';
	  H ->state0 = E;
	  H ->state1 = B;
	  
	  /*First print the starting state*/
	  printf("Starting State: %c\n", head ->stateNow);
	  
	  /*Initalize the current state*/
	  CurrentState ->current = head; 
	  
	  /*Seek input from the user*/
	  while(end == 0)
	  {
		scanf("%s", inputs);
	      
	      /*An end command. Just for testing purposes*/
	      if(inputs[0] == 'f')
	      {
	          end = 1;
	      }
	      else
	      if(inputs[0] == '0' || inputs[0] == '1')
	      {
	          /*Zero or one command*/
	          /*Print the 0 or 1 state depending on the input*/
	          if(inputs[0] == '0')
	          {
	            printf("%c\n", CurrentState ->current ->state0 ->stateNow);
	            /*Now change the current state*/
	            CurrentState ->current = CurrentState ->current ->state0;
	          }
	          else
	          {
	              printf("%c\n", CurrentState ->current ->state1 ->stateNow);
	              /*Now change the current state*/
	              CurrentState ->current = CurrentState ->current ->state1;
	          }
	          
	          
	      }
	      else
	      if(inputs[0] == 'c')
	      {
	          /*This is the change command*/
	          if(inputs[1] == '0')
	          {
	              if(inputs[2] == 'A' && deleted[0] == 0)
	                    CurrentState ->current ->state0 = A;
	              else
	              if(inputs[2] == 'B' && deleted[1] == 0)
	                    CurrentState ->current ->state0 = B;
	              else
	              if(inputs[2] == 'C' && deleted[2] == 0)
	                    CurrentState ->current ->state0 = C;
	              else
	              if(inputs[2] == 'D' && deleted[3] == 0)
	                    CurrentState ->current ->state0 = head;
	              else
	              if(inputs[2] == 'E' && deleted[4] == 0)
	                    CurrentState ->current ->state0 = E;
	              else
	              if(inputs[2] == 'F' && deleted[5] == 0)
	                    CurrentState ->current ->state0 = F;
	              else
	              if(inputs[2] == 'G' && deleted[6] == 0)
	                    CurrentState ->current ->state0 = G;
	              else
	              if(inputs[2] == 'H' && deleted[7] == 0)
	                    CurrentState ->current ->state0 = H;     
	               
	          }
	          else
	          if(inputs[1] == '1')
	          {
	              if(inputs[2] == 'A' && deleted[0] == 0)
	                    CurrentState ->current ->state1 = A;
	              else
	              if(inputs[2] == 'B' && deleted[1] == 0)
	                    CurrentState ->current ->state1 = B;
	              else
	              if(inputs[2] == 'C' && deleted[2] == 0)
	                    CurrentState ->current ->state1 = C;
	              else
	              if(inputs[2] == 'D' && deleted[3] == 0)
	                    CurrentState ->current ->state1 = head;
	              else
	              if(inputs[2] == 'E' && deleted[4] == 0)
	                    CurrentState ->current ->state1 = E;
	              else
	              if(inputs[2] == 'F' && deleted[5] == 0)
	                    CurrentState ->current ->state1 = F;
	              else
	              if(inputs[2] == 'G' && deleted[6] == 0)
	                    CurrentState ->current ->state1 = G;
	              else
	              if(inputs[2] == 'H' && deleted[7] == 0)
	                    CurrentState ->current ->state1 = H; 
	          }
	          
	      }
	      else
	      if(inputs[0] == 'p')
	      {
	          /*Print the FSM*/
	          printf("Hello. \n");
	          printf("Your personalized state machine description for Lab 4 (coe428) follows: \n");
	          printf("%c %c %c\n", A->stateNow, A->state0 -> stateNow, A -> state1 -> stateNow);
	          printf("%c %c %c\n", B->stateNow, B->state0 -> stateNow, B -> state1 -> stateNow);
	          printf("%c %c %c\n", C->stateNow, C->state0 -> stateNow, C -> state1 -> stateNow);
	          printf("%c %c %c\n", head->stateNow, head->state0 -> stateNow, head -> state1 -> stateNow);
	          printf("%c %c %c\n", E->stateNow, E->state0 -> stateNow, E -> state1 -> stateNow);
	          printf("%c %c %c\n", F->stateNow, F->state0 -> stateNow, F -> state1 -> stateNow);
	          printf("%c %c %c\n", G->stateNow, G->state0 -> stateNow, G -> state1 -> stateNow);
	          printf("%c %c %c\n", H->stateNow, H->state0 -> stateNow, H -> state1 -> stateNow);
	          
	      }
	      else
	      if(inputs[0] == 'g')
	      {
	          /*The Garbage command. Search for all the states which are unreachable*/
	          int reachable[7] = {0,0,0,0,0,0,0}; /*These will represent the reachable states*/
	          struct node *garbageCollector = (struct node*) malloc(sizeof(struct node));
	          
	          int counter;
	          int switchNum = 0; /*) for 0 and 1 for 1*/
	          garbageOn = 0;
	          
	          garbageCollector -> current = CurrentState ->current;
	          for(counter = 0; counter < 200; counter++)
	          {
    	          /*Test function*/
    	          if(garbageCollector -> current -> stateNow == 'A' || garbageCollector ->current ->state0 -> stateNow == 'A' || garbageCollector ->current ->state1-> stateNow == 'A')
    	          {
    	              reachable[0]++;
    	          }
    	          if(garbageCollector ->current -> stateNow == 'B' || garbageCollector ->current ->state0-> stateNow == 'B' || garbageCollector ->current ->state1-> stateNow == 'B')
    	          {
    	              reachable[1]++;
    	          }
    	          if(garbageCollector ->current -> stateNow == 'C' || garbageCollector ->current ->state0-> stateNow == 'C' || garbageCollector ->current ->state1-> stateNow == 'C')
    	          {
    	              reachable[2]++;
    	          }
    	          if(garbageCollector -> current ->stateNow == 'D' || garbageCollector ->current ->state0-> stateNow == 'D' || garbageCollector ->current ->state1-> stateNow == 'D')
    	          {
    	              reachable[3]++;
    	          }
    	          if(garbageCollector -> current ->stateNow == 'E' || garbageCollector ->current ->state0-> stateNow == 'E' || garbageCollector ->current ->state1-> stateNow == 'E')
    	          {
    	              reachable[4]++;
    	          }
    	          if(garbageCollector ->current -> stateNow == 'F' || garbageCollector ->current ->state0-> stateNow == 'F' || garbageCollector ->current ->state1-> stateNow == 'F')
    	          {
    	              reachable[5]++;
    	          }
    	          if(garbageCollector ->current -> stateNow == 'G' || garbageCollector ->current ->state0-> stateNow == 'G' || garbageCollector ->current ->state1-> stateNow == 'G')
    	          {
    	              reachable[6]++;
    	          }
    	          if(garbageCollector ->current -> stateNow == 'H' || garbageCollector ->current ->state0-> stateNow == 'H' || garbageCollector ->current ->state1-> stateNow == 'H')
    	          {
    	              reachable[7]++;
    	          }
    	          
    	          /*Go deeper in the linked list*/
    	          if(switchNum == 0)
    	          {
    	            garbageCollector -> current = garbageCollector -> current -> state0;
    	          }
    	          else
    	          if(switchNum == 1)
    	          {
    	              garbageCollector -> current = garbageCollector -> current -> state1;
    	          }
    	          
    	          if(counter == 100)
    	          {
    	              switchNum = 1;
    	          }
	          }
	          
	          
	          /*Test to see if there is garbage or not*/
	          if(reachable[0] == 0)
	          {
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'A');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'A');
	              }
	              
	              unreachable[0] = 1;
	              
	          }
	          if(reachable[1] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'B');
	                 garbageOn = 1;
	              } 
	              else
	              {
	                  printf("%c", 'B');
	              }
	              
	              unreachable[1] = 1;
	          }
	          if(reachable[2] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'C');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'C');
	              }
	              
	              unreachable[2] = 1;
	              
	          }
	          if(reachable[3] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'D');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'D');
	              }
	              
	              unreachable[3] = 1;
	          }
	          if(reachable[4] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'E');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'E');
	              }
	              
	              unreachable[4] = 1;
	              
	          }
	          if(reachable[5] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'F');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'F');
	              }
	              
	              unreachable[5] = 1;
	              
	          }
	          if(reachable[6] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'G');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'G');
	              }
	              
	              unreachable[6] = 1;
	          }
	          if(reachable[7] == 0)
	          {
	              
	              if(garbageOn == 0)
	              {
	                 printf("Garbage: <");
	                 printf("%c", 'H');
	                 garbageOn = 1;
	              }
	              else
	              {
	                  printf("%c", 'H');
	              }
	              
	              unreachable[7] = 1;
	              
	          }
	          
	          if(garbageOn == 1)
	          {
	              printf(">\n");
	          }
	          else
	          if(garbageOn == 0)
	          {
	              printf("No garbage \n");
	          }
	          
	         
	          
	      }
	      else
	      if(inputs[0] == 'd')
	      {
	          /*The delete command*/
	          if(inputs != NULL)
	          {
	              /*When there are no optional arguments. Delete all un-deleted states that are unreachable*/
	              if(garbageOn == 0)
	              {
	                  printf("No states deleted\n");
	              }
	              else
	              {
	                  printf("Deleted: <");
	                  if(unreachable[0] == 1)
	                  {
	                      printf("A");
	                      A ->stateNow = ' ';
	                      deleted[0] = 1;
	                  }
	                  if(unreachable[1] == 1)
	                  {
	                      printf("B");
	                      B ->stateNow = ' ';
	                      deleted[1] = 1;
	                  }
	                  if(unreachable[2] == 1)
	                  {
	                      printf("C");
	                      C ->stateNow = ' ';
	                      deleted[2] = 1;
	                  }
	                  if(unreachable[3] == 1)
	                  {
	                      printf("D");
	                      head ->stateNow = ' ';
	                      deleted[3] = 1;
	                  }
	                  if(unreachable[4] == 1)
	                  {
	                      printf("E");
	                      E ->stateNow = ' ';
	                      deleted[4] = 1;
	                  }
	                  if(unreachable[5] == 1)
	                  {
	                      printf("F");
	                      F ->stateNow = ' ';
	                      deleted[5] = 1;
	                  }
	                  if(unreachable[6] == 1)
	                  {
	                      printf("G");
	                      G ->stateNow = ' ';
	                      deleted[6] = 1;
	                  }
	                  if(unreachable[7] == 1)
	                  {
	                      printf("H");
	                      H ->stateNow = ' ';
	                      deleted[7] = 1;
	                  }
	                  
	                  /*The end statement*/
	                  printf(">\n");
	              }
	          }
	          else
	          {
	              if(inputs[1] == 'A' && deleted[0] == 0)
	              {
	                  A ->stateNow = ' ';
	                  deleted[0] = 1;
	                  printf("Deleted\n");
	              }
	              else
	              if(inputs[1] == 'B' && deleted[1] == 0)
	              {
	                  B ->stateNow = ' ';
	                  deleted[1] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'C' && deleted[2] == 0)
	              {
	                  C ->stateNow = ' ';
	                  deleted[2] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'D' && deleted[3] == 0)
	              {
	                  head ->stateNow = ' ';
	                  deleted[3] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'E' && deleted[4] == 0)
	              {
	                  E ->stateNow = ' ';
	                  deleted[4] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'F' && deleted[5] == 0)
	              {
	                  F ->stateNow = ' ';
	                  deleted[5] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'G' && deleted[6] == 0)
	              {
	                  G ->stateNow = ' ';
	                  deleted[6] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              if(inputs[1] == 'H' && deleted[7] == 0)
	              {
	                  H ->stateNow = ' ';
	                  deleted[7] = 1;
	                  printf("Deleted\n");
	                  
	              }
	              else
	              {
	                  printf("Not Deleted\n");
	              }
	              
	          }
	          
	      }
	      
	      
	  }
  
    exit(0);
}




