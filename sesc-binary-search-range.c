#include <stdio.h> 
#include <stdlib.h> 

int K; 

int bi_s_p(int l, int p, int* mass){ 
if(l == p){ 
return l; 
} 
if(mass[l] == K){ 
return l; 
} 
if(mass[p] == K){ 
return p; 
} 
if(mass[(l+p)]/2 >= K){ 
return bi_s_p(l, (l+p)/2,mass); 
}else{ 
return bi_s_p((l+p)/2 + (l+p)%2, p,mass); 
} 
} 

int main() { 
int i; 
int N; 
int min = -1; 
int max = -1; 
int t; 
scanf("%d", &N); 
scanf("%d", &K); 
int* Mass = malloc(N * sizeof(int)); 
for(int i = 0; i < N;i++){ 
scanf("%d", &t); 
Mass[i]=t; 
} 
int k = bi_s_p(0, N-1, Mass); 
min = k; 
max = k; 
while(Mass[min] == K && min>-1){ 
min--; 
} 
min++; 
while(Mass[max] == K && max<N){ 
max++; 
} 
max--; 
if(Mass[k]!=K){ 
printf("-1 -1"); 
}else{ 
printf("%d %d", min, max); 
} 
}
