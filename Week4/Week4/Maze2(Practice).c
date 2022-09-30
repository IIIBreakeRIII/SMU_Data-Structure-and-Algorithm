//
//  Maze2(Practice).c
//  Week4
//
//  Created by 현소류 on 2022/09/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAZE_SIZE 10



typedef struct
{
    short r;
    short c;
}element;

typedef struct Stack
{
    element data[MAX_SIZE];
    int top;
}Stack;

//스택 초기화 함수
void init(Stack *p)
{
    p->top=-1;
}

//포화 상태 검출 함수
int is_full(Stack *p)
{
    return ( p->top == MAX_SIZE-1);
}

//공백 상태 검출 함수
int is_empty(Stack *p)
{
    return (p->top == -1);
}

//삽입함수
void push(Stack *p, element data)
{
    if(is_full(p))
    {
        printf("스택이 꽉찼습니다\n"); return ;
    }
    else
    {
        p->top++;
        p->data[p->top].r=data.r;
        p->data[p->top].c=data.c;
    }
}

element pop(Stack *p)
{
   if(is_empty(p)){
      fprintf(stderr,"스택 공백 에러\n");
      exit(1);
   }
   else return p->data[(p->top)--];
}

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE]={
    {'1','1','1','1','1','1','1','1','1','1'},
    {'e','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','1','1','0','0','1','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','0','0','0','1','0','x'},
    {'1','1','1','1','1','1','1','1','1','1'}
   };
   
void push_loc(Stack *p,int r, int c)
{
   if(r<0||c<0)return;
   if(maze[r][c] != '1' && maze[r][c] != '.'){
      element tmp;
      tmp.r = r;
      tmp.c = c;
      push(p,tmp);
   }
}


 
// 미로 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
   printf("\n");
   for(int r = 0; r< MAZE_SIZE;r++){
      for(int c=0;c<MAZE_SIZE;c++){
         printf("%c",maze[r][c]);
      }
      printf("\n");
   }
}

int main(void)
{
   int r,c;
   Stack p;
   
   init(&p);
   here = entry;
   while(maze[here.r][here.c]!='x'){
      r = here.r;
      c = here.c;
      maze[r][c]='.';
      maze_print(maze);
      push_loc(&p,r-1,c);
      push_loc(&p,r+1,c);
      push_loc(&p,r,c-1);
      push_loc(&p,r,c+1);
      if(is_empty(&p)){
         printf("실패\n");
         return 0;
      }
      else
         here = pop(&p);
      
   }
   printf("성공\n");
   return 0;
}
