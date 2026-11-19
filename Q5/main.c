#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
static int word_count(const char s[]){int count=0,inside=0;for(size_t i=0;s[i]!='\\0';++i){if(isspace((unsigned char)s[i]))inside=0;else if(!inside){++count;inside=1;}}return count;}
static int palindrome(const char s[]){size_t l=0,r=0;while(s[r])++r;if(r==0)return 1;--r;while(l<r){while(l<r&&!isalpha((unsigned char)s[l]))++l;while(l<r&&!isalpha((unsigned char)s[r]))--r;if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r]))return 0;++l;if(r>0)--r;}return 1;}
static void uppercase(char s[]){for(size_t i=0;s[i];++i)s[i]=(char)toupper((unsigned char)s[i]);}
static void reverse(char s[]){size_t n=0;while(s[n])++n;for(size_t i=0;i<n/2;++i){char t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;}}
int main(void){char msg[]=" Meet at the library at 5 PM ";char copy[]="C programming";printf("Words: %d\n",word_count(msg));printf("Palindromes: %d %d\n",palindrome("Madam, I'm Adam"),palindrome("Hello"));uppercase(copy);printf("Upper: %s\n",copy);reverse(copy);printf("Reverse: %s\n",copy);printf("Tab-separated words: %d\n",word_count("one\\ttwo"));return 0;}
