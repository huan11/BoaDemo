/*
 *  cgi 程序 注意，引用的其他文件中不要出现 printf 原因—— 要给前端回写 json 格式的数据
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "task.h"
#include "cJSON.h"

static struct tasks_info *tasks;

/*
 * 最后发送给前端的形式
 * {
	"num":	4,
	"data":	[
        {
			"lable":	"机房1",
			"temp":	"55.30"
		},
		{
			"lable":	"机房2",
			"temp":	"27.72"
		},
		{
			"lable":	"机房3",
			"temp":	"92.44"
		},
		{
			"lable":	"机房4",
			"temp":	"66.21"
		}
		]
}
 */
void send_json(){
    cJSON *root = cJSON_CreateObject(); // 最外层 的{}
    if(root== NULL){
        goto  end;
    }
    cJSON *infos = NULL;  //  对应 json 中 的 "data"
    cJSON *info;          //  对应 json 中 的 data 的数组的数据项 的{}

    int num;              // 对应 json 中 的 "num"

    char temp[32];
    char *string;  // 用于回写给前端的 字符串

    // 填充 "num"
    num = tasks->num;// TODO 这条信息没有用到
    cJSON_AddItemToObject(root,"num",cJSON_CreateNumber(num));

    // 创建"data" 对应的数组infos( 用来存放 tasks_info 信息 的数组)
    infos = cJSON_CreateArray();
    if(infos == NULL){
        goto end;
    }
    cJSON_AddItemToObject(root,"data",infos);

    // 用内存中的数据填充info ，再将 所有 info 保存到数组infos
    for (int i = 0; i < num; ++i) {
        info = cJSON_CreateObject();
        if(info == NULL){
            goto  end;
        }
        // 用内存中的数据对 info 进行填充
        // 将 机房信息写入 info
        cJSON_AddItemToObject(info,"lable",cJSON_CreateString(tasks->data[i].lable));
        // 将 温度信息写入 info
        snprintf(temp, sizeof(temp),"%.2f",tasks->data[i].temp);
        cJSON_AddItemToObject(info,"temp",cJSON_CreateString(temp));

        //  将 每个 info 保存到 infos 数组中
        cJSON_AddItemToArray(infos,info);
    }
    // 将数据回写给前端
    string = cJSON_Print(root);
    printf("%s",string);
    free(string);

    end:
    cJSON_Delete(root);
    return; //todo
}

/*
 *   测试  send_json();
 */
int main(){
    printf("Content-Type:text/html;charset=utf-8\r\n");
    printf("\r\n");

    tasks = (struct  tasks_info *)init_shm();
    if(tasks == NULL ){
        // TODO 返回给前端一个错误的 json 数据
        return -1;
    }
    send_json();
    return 0;
}