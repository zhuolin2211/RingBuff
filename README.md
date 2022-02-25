# RingBuff
易用的环形缓冲队列

创建环形队列
RING Ring_Buffer;

提供静态的环形队列缓冲空间
#define RING_BUFF_SIZE
TYPE Ring_Buff_Cache[RING_BUFF_SIZE];

初始化环形队列
ring_init(&Ring_Buffer,Ring_Buff_Cache,sizeof(TYPE),RING_BUFF_SIZE);

读取唤醒缓冲队列

TYPE Ring_item;

if(ring_in(&Ring_Buffer,&Ring_item)>0)
{
  printf("write ok\n");
}
else
{
  printf(write error\n);
}

if(ring_out(&Ring_Buffer,&Ring_item)>0)
{
  printf("read ok\n");
}
else
{
  printf(read error\n);
}
