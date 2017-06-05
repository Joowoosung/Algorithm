#include <stdio.h>

/* ���� ���� (5�� ���� �����͸� ó���ϴ� ����) */
#define MAX 5
int a[MAX], top = -1;
int stack_err = 0;  /* ���� push/pop ���: 0 = ����, 1 = ���� */

/* ���ÿ� �����͸� �ִ� �Լ�  */
/* �Է°� : ����              */
/* ��ȯ��: 0 = ����, 1 = ���� */
int push(int x)
{
  if (top >= MAX - 1) 
    return (stack_err = 1);  /* ���� �� á�� */

  
  stack_err = 0;
  a[++top] = x;
  return 0;
}




/* ���ÿ��� �����͸� ���� �Լ� */
/* ��ȯ��: check_stack_error() ȣ�� ����� 0�� ��, ���� ������  */
int pop( )
{
  if (top < 0) 
    return (stack_err = 1);  /* ���� ������ ���� */


  stack_err = 0;
  return a[top--];
}




/* ���� ����� �۾����� ���� �߻��ߴ��� �˻� */
/* ��ȯ��: 0 = ����, 1 = ����                */
int check_stack_error()
{
  int err = stack_err;
  stack_err = 0;
  return err;
}




/* ���� �ڷᱸ�� �׽�Ʈ ���� */


int main()
{
  int i, data;




  for (i = 1; i <= MAX+2; i++) {  /* 7�� ������ PUSH ó�� */
    if (push(i * 100))
      printf("���� PUSH ����!\n");
    else
      printf("PUSH: %i\n", i * 100);
  }
 
  for (i = 1; i <= MAX+2; i++) {  /* 7�� ������ POP ó�� */
    data = pop();
    if (check_stack_error())
       printf("���� POP ����!\n");
    else
       printf("POP: %i\n", data);
  }

  return 0;
}