#include <stdio.h>
#include "cJSON.h"

/*
 *  使用 cJSON 构造 json 数据
 */
int main(){
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