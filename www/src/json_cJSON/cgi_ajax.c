#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"
/*
 *  使用 cJSON 构造 json 数据的基本步骤
 */
int method(){
    cJSON *root;
    char *res;
    // 1 创建
    root = cJSON_CreateObject();
    if(root == NULL){

    }
    // 3 添加内容
    cJSON_AddItemToObject(root,"abc",cJSON_CreateString("hello world"));
    // 4 打印
    res = cJSON_Print(root);
    printf("the result is :%s\n",res);

    end:
    // 2 删除
    cJSON_Delete(root);
    return 0;
}
/*
 *  使用 cJSON 构造 json 数据， temp 为温度
 *  {
 *      "temp": "xxx"
 *  }
 */
char *get_rand_temp() {
    cJSON *root;
    char *res = NULL;
    double temp;
    // 0 生成随机数
    srand(time(NULL));
    temp = rand() % 20 + 10;
    // 1 创建
    root = cJSON_CreateObject();
    if (root == NULL) {
        goto end;
    }
    // 3 添加内容
    cJSON_AddItemToObject(root, "temp", cJSON_CreateNumber(temp));
    // 4 存储结果
    res = cJSON_Print(root);

    // 2 销毁
    end:
    cJSON_Delete(root);
    return res;
}

/*
 *  测试get_rand_temp()
 */
int main() {
    char *r1;

    printf("Content-Type:text/html;charset=utf-8\r\n");
    printf("\r\n");

    // 调用生成随机数函数
    r1 = get_rand_temp();
    printf("%s",r1);
    free(r1);

    return 0;
}

