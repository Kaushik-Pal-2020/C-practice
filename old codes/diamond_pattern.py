# -*- coding: utf-8 -*-
"""
Created on Sun May 24 06:40:32 2020

@author: kaushik pal
"""

n = int(input("enter no of starts in middle"))

string = '*'*n

for i in range(n):
    print(" ".join(string[0:i+1]).center(2*n-1,' '))

for i in range(n-1,0,-1):
    print(" ".join(string[0:i]).center(2*n-1,' '))
 
print('\n\n')
    
string = [str(x) for x in range(1,n+1)]

for i in range(n):
    print(" ".join(string[0:i+1]).center(2*n-1,' '))

for i in range(n-1,0,-1):
    print(" ".join(string[0:i]).center(2*n-1,' '))
    
  
char = 0
for i in "I love geeksforgeeks":
    char += 1
    
print(char)