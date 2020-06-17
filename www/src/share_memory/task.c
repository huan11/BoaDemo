#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "task.h"

/*
 *初始化共享内存空间，返回对应进程的用户空间映射的地址
 */
void* init_shm(void){
    key_t k1;
    int shm_id = 0;
    void *res; // 共享内存的地址

    // 1 获得 key 值
    k1= ftok(KEY_1,KEY_2);
    if(k1 == -1){
        return NULL;
    }
    // 2 获得 id  号
    shm_id = shmget(k1, sizeof(struct tasks_info),  IPC_CREAT  | 0644);
    if(shm_id  == -1 ){
        return NULL;
    }
    // 3 映射地址( 在进程的应用空间  中映射 内核 IPC 对象的地址)
    res = shmat(shm_id,NULL,0);
    return res;
}

/*
 *  释放内存
 */
void detach_shm(void *p){
    shmdt(p);
}
