#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "task.h"

static struct tasks_info *tasks;
static char* tasks_lables[] = {"机房1","机房2","机房3","机房4","机房5"};

/*
 *  模拟生成 机房 和 温度信息
 */
void generate_data(int num){
    tasks->num = num;
    int i;

    for ( i = 0; i < num; ++i) {
        tasks->data[i].temp = ((rand() % 9000) + 1000) /100.0;
        snprintf(tasks->data[i].lable,"%s",tasks_lables[i]);
    }
}

/* 显示数据*/
void show_data(){
    for (int i = 0; i < tasks->num; ++i) {
        printf("the lable is %s , the temp is %.2f\n",tasks->data[i].lable,tasks->data[i].temp);
    }
}
int main(){
    srand(time(NULL));
    // 得到共享内存的起始地址
    tasks = (struct  tasks_info *)init_shm();
    if(tasks == NULL){
        fprintf(stderr,"init share memory!\n");
        return -1;
    }
    /* 不断生成数据*/
    while(1) {
        generate_data(rand()%5 + 1);
        show_data();
        sleep(2);
    }
    return 0;
}

