/*
 *  通过 共享内存 的方式 实现 两个进程（1 sim_catch 数据采集模拟器  2 temp_cgi  读取数据采集器在内存中生成的数据 并将其回写给 前端请求的程序 ）
 *
 *  此头文件定义   通过 共享内存 通信的 2 个进程 共用的以下内容
 *   1 数据结构
 *   2 通用的代码
 */
#ifndef WORKS_TASK_H
#define WORKS_TASK_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_TASK 5

/*
 *
 */
struct task_msg{
    double temp; // 温度
    char lable[32]; // 机房名称
};
/*
 *
 */
struct tasks_info{
    int num;
    struct task_msg data[MAX_TASK];
};
/* ftok 的 两个 参数*/
#define KEY_1 "/home"
#define KEY_2 10
/*初始化共享内存空间，返回对应进程的用户空间映射的地址*/
extern void* init_shm(void);
/* 释放 */
extern void detach_shm(void *p);

#endif //WORKS_TASK_H
