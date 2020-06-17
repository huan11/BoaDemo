#include <stdio.h>
#include <stdlib.h> //  使用 getenv
#include <string.h>
#include "cgic.h"

/*
 * 使用 cgic 库处理前端的 form 表单提交的数据
 *
 */
int cgiMain(){
    // 保存名字
    char name[16];
    char pwd[16];
    char *method;
    // 1 设置 返回类型
    cgiHeaderContentType("text/html;charset=utf-8");

    // 2 根据 标签名获取 form 表单的数据
    // 第一个参数是 标签的name 属性 ,第二个 参数 是存放数据 的变量， 第三个 是 最大长度
    cgiFormStringNoNewlines("user_name", name,16);
    cgiFormStringNoNewlines("user_pwd",pwd,16);

    //  根据 环境变量 值 获取相应的请求方法
    method = getenv("REQUEST_METHOD");
    fprintf(cgiOut,"<h2>form 测试的 %s 请求的数据 %s+++ %s</h2>",method,name,pwd);
    return 0;
}

