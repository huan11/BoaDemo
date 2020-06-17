#include <stdio.h>
#include <stdlib.h> //  使用 getenv
#include <string.h>
#include "cJSON.h"  // 使用 json 的解析函数，并将解析后的内容以 json 格式 发到前端
#include "cgic.h"

/*
 *  在下面的代码中，已经 给出了 部分 使用 cJSON 解析 json 格式的代码，但对于前端传过来来的json ,仍未处理完成。TODO
 */
int cgiMain(){
    cJSON *root;
    char *result;

    /*
     *  引入 处理 前端数据的部分
     */
    char *method;
    char *query_str;
    int num;
    int i; // 循环 变量
    int flags = 0; // 默认是 get
    // 存放解析的json
    cJSON *requestJson;


//    char *recevieName = "mx";
//    char *receviePwd ="345";

//    cgiHeaderContentType("text/html;charset=utf-8");
    cgiHeaderContentType("application/json;charset=utf-8");//json格式的数据
    // 第一个参数是 标签的name 属性

    // 我和前端约定好，我们收到的json 的键是统一的 !!!!
    // 解析 json
    // 思考一个问题：你在哪里接收过前端的 数据？直接把所有内容打印出来的那种
    method = getenv("REQUEST_METHOD");
    if(method == NULL ){
//        printf("获取 method 失败");
        return 0;
    }
//    printf("<h2>form 测试的http 请求形式 %s</h2>",method);

    // 在处理请求的数据之前先判断请求使用的方法
    if(strncmp(method,"GET",3) == 0 ){
        query_str = getenv("QUERY_STRING");
        if(query_str == NULL ){
//            printf("获取query string 失败");
            return 0;
        }
//        printf("%s",query_str);
//        printf("<h2>form 测试的 get 请求的数据 %s</h2>",query_str);
    } else if(strncmp(method,"POST",4) == 0 ){
        // 无法通过环境变量取出，如何取出post 后面拉的货呢?
        num =atoi( getenv("CONTENT_LENGTH"));
        flags = 1;
        query_str = malloc(num + 1);
        for (i = 0; i < num; ++i) {
            query_str[i]= fgetc(stdin);
        }
        query_str[i] = 0;
//        printf("%s",query_str);
//        printf("<h2>form 测试的 %s请求的数据 %s</h2>",method,query_str);
    } else{
//        printf("请求形式未知");
//        return 0;
    }

    // 直接对字符串进行解析，以 & 为分隔符 切分数据 ，以 = 为分隔符 切分 json 的 key 和 value
    char *p;
    char *buf;

    buf = query_str;
    p = strsep(&buf,'&');
    while (p!= NULL){
        printf("%s\n", p);
        p = strsep(&buf,'&');
    }



    // 不行，通过 cgi 环境变量得到的是字符串。。不是json 格式。。
    // 从请求的内容中解析 json
    requestJson = cJSON_Parse(query_str);
    // 遍历json 中的数据
    cJSON *recevieName_json = NULL;
    cJSON *receviePwd_json = NULL;
    recevieName_json = cJSON_GetObjectItem(requestJson,"name");
    receviePwd_json = cJSON_GetObjectItem(requestJson,"pwd");

//    TODO 错误写法 ,指针不能直接赋值
//    char *recevieName_string = recevieName_json->valuestring;
//    char *receviePwd_string = receviePwd_json->valuestring;
//    printf("%s + %s",recevieName_string,receviePwd_string);


// 模拟数据
//    char *recevieName_string = "my";
//    char *receviePwd_string = "000";
    // 构造 json
    // 1 创建
    root = cJSON_CreateObject();
    if (root == NULL) {
        goto end;
    }

    // 3 添加内容
//    cJSON_AddItemToObject(root, "name", cJSON_CreateNumber(recevieName));
//    cJSON_AddItemToObject(root, "pwd", cJSON_CreateNumber(receviePwd));

// 模拟数据测试
//    cJSON_AddItemToObject(root, "name",cJSON_CreateString(recevieName_string));
//    cJSON_AddItemToObject(root, "pwd",cJSON_CreateString(receviePwd_string ));
    cJSON_AddItemToObject(root, "name",cJSON_CreateString(recevieName_json->valuestring));
    cJSON_AddItemToObject(root, "pwd",cJSON_CreateString(receviePwd_json->valuestring));
    // 4 存储结果
    result = cJSON_Print(root);
    // 给请求者
    printf("%s",result);
    free(result);

    // 处理前端请求数据用的代码的清理
    if(flags){
        free(query_str);
    }
    // 2 销毁
    end:
    cJSON_Delete(root);

    return 0;
}

