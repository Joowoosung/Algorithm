#include <stdio.h>

/* 스택 구조 (5개 정수 데이터를 처리하는 스택) */
#define MAX 5
int a[MAX], top = -1;
int stack_err = 0;  /* 스택 push/pop 결과: 0 = 정상, 1 = 에러 */

/* 스택에 데이터를 넣는 함수  */
/* 입력값 : 정수              */
/* 반환값: 0 = 정상, 1 = 에러 */
int push(int x)
{
  if (top >= MAX - 1) 
    return (stack_err = 1);  /* 스택 다 찼음 */

  
  stack_err = 0;
  a[++top] = x;
  return 0;
}




/* 스택에서 데이터를 빼는 함수 */
/* 반환값: check_stack_error() 호출 결과가 0일 때, 스택 데이터  */
int pop( )
{
  if (top < 0) 
    return (stack_err = 1);  /* 스택 데이터 없음 */


  stack_err = 0;
  return a[top--];
}




/* 스택 입출력 작업에서 에러 발생했는지 검사 */
/* 반환값: 0 = 정상, 1 = 에러                */
int check_stack_error()
{
  int err = stack_err;
  stack_err = 0;
  return err;
}




/* 스택 자료구조 테스트 예제 */


int main()
{
  int i, data;




  for (i = 1; i <= MAX+2; i++) {  /* 7개 데이터 PUSH 처리 */
    if (push(i * 100))
      printf("스택 PUSH 에러!\n");
    else
      printf("PUSH: %i\n", i * 100);
  }
 
  for (i = 1; i <= MAX+2; i++) {  /* 7개 데이터 POP 처리 */
    data = pop();
    if (check_stack_error())
       printf("스택 POP 에러!\n");
    else
       printf("POP: %i\n", data);
  }

  return 0;
}