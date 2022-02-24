/*!
    \file  
    \brief 
    
    \version 
*/

#ifndef _RING_H_
#define _RING_H_
#include "stdint.h"
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
#ifndef NULL
#define NULL 0
#endif

typedef struct
{
    unsigned char *ringbuff;
    unsigned int ring_index;
    unsigned int ring_outdex;
    unsigned int ring_size;     //队列大小
    unsigned int ring_quantity; //队列 容量
} RING;

void ring_init(RING *ring, void *buff, uint16_t ring_size, uint16_t ring_qty);
void ring_clear(RING *ring);
int ring_isempty(RING *ring);
uint16_t ring_in(RING *ring, void *ring_data);
uint16_t ring_out(RING *ring, void *ring_buff);
int ring_length(RING *ring);

#endif /* HW_RING_H_ */
