#include<stdio.h>
#include "my_time.h"

int main(){
    char *head_title = "hello ,CGI";
    printf("Content-Type:text/html;charset=utf-8\r\n");
    printf("\r\n");
    printf("<h1>%s</h1>",head_title);
    
    printf("<h2>%s</h2>",get_time(0));
    return 0;

}
