#include <stdio.h>

int memo[100];

int fib(int n){
	if(n <= 1){
		return n;
	}
	else{ 
		if(memo[n] > 0){
			return memo[n];
		}
		memo[n] = fib(n-1)+fib(n-2);
		return memo[n];
	}
}

int d[100];
int fibo(int n){
	d[0] = 0;
	d[1] = 1;
	for(int i = 2; i <= n; i++){
		d[i] = d[i-1]+d[i-2];
	}
	return d[n];
}

int main(){
	int n = 0;
	//fib(n);
	scanf("%d", &n);
	printf("%d\n", fibo(n));

	return 0;
}

