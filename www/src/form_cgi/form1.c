#include <stdio.h>
#include <stdlib.h> //  使用 getenv
#include <string.h>
/*
 *  使用 原生方式 CGI 对前端请求 内容进行解析
 */
int main(){
    char *method;
    char *query_str;
    int num;
    int i; // 循环 变量
    int flags = 0; // 默认是 get

    printf("Content-Type:text/html;charset=utf-8\r\n");
    printf("\r\n");
    // getenv 函数 是 CGI 进程 获取 web 服务器进程从前端得到的内容的一个接口(两个进程采用环境变量的方式进行通信)（ TODO web 服务器这里是谁呢？）
    // 可以 通过 man 手册 查看 getenv
    // 常用环境变量——参考
    // http://net.pku.edu.cn/~yhf/tutorial/perlstep/perlstep8.html
    method = getenv("REQUEST_METHOD");
    if(method == NULL ){
        printf("获取 method 失败");
        return 0;
    }
    printf("<h2>form 测试的http 请求形式 %s</h2>",method);

    // 在处理请求的数据之前先判断请求使用的方法
    if(strncmp(method,"GET",3) == 0 ){
        query_str = getenv("QUERY_STRING");
        if(query_str == NULL ){
            printf("获取query string 失败");
            return 0;
        }
        printf("<h2>form 测试的 get 请求的数据 %s</h2>",query_str);
    } else if(strncmp(method,"POST",4) == 0 ){
        // 无法通过环境变量取出，如何取出post 后面拉的货呢?
        num =atoi( getenv("CONTENT_LENGTH"));
        flags = 1;
        query_str = malloc(num + 1);
        for (i = 0; i < num; ++i) {
            query_str[i]= fgetc(stdin);
        }
        query_str[i] = 0;
        printf("<h2>form 测试的 %s请求的数据 %s</h2>",method,query_str);
    } else{
        printf("请求形式未知");
        return 0;
    }
    // TODO 对取出的数据进行 解析 sscanf

    if(flags){
        free(query_str);
    }
    return 0;
}

