/*!
    \file  
    \brief 
    
    \version 
*/
#include <string.h>
#include "ring.h"

void ring_init(RING *ring, void *buff, uint16_t ring_size, uint16_t ring_qty)
{
    ring->ringbuff = buff;
    ring->ring_index = 0;
    ring->ring_outdex = 0;
    ring->ring_size = ring_size;
    ring->ring_quantity = ring_qty;
}

void ring_clear(RING *ring)
{
    ring->ring_outdex = 0;
    ring->ring_index = 0;
}

int ring_isempty(RING *ring)
{
    return ring->ring_outdex == ring->ring_index ? true : false;
}

int ring_length(RING *ring)
{
    if (ring->ring_outdex > ring->ring_index)
        return (ring->ring_quantity - ring->ring_outdex + ring->ring_index);
    else if (ring->ring_outdex < ring->ring_index)
        return (ring->ring_index - ring->ring_outdex);
    else
        return 0;
}

uint16_t ring_in(RING *ring, void *ring_data)
{
    void *write_index;
    uint16_t ret = 1;
    write_index = ring->ringbuff + ring->ring_index * ring->ring_size;
    memcpy(write_index, ring_data, ring->ring_size);
    ring->ring_index++;
    if (ring->ring_index >= ring->ring_quantity)
        ring->ring_index = 0;
    if (ring->ring_index == ring->ring_outdex)
    {
        ret = 0;
        ring->ring_outdex++;
        if (ring->ring_outdex >= ring->ring_quantity)
        {
            ring->ring_outdex = 0;
        }
    }
    return ret;
}

uint16_t ring_out(RING *ring, void *ring_buff)
{
    void *read_outdex;
    uint8_t ret = 1;
    if (ring->ring_outdex == ring->ring_index)
    {
        ret = 0;
    }
    else
    {
        read_outdex = ring->ringbuff + ring->ring_outdex * ring->ring_size;
        memcpy(ring_buff, read_outdex, ring->ring_size);
        ring->ring_outdex++;
        if (ring->ring_outdex >= ring->ring_quantity)
            ring->ring_outdex = 0;
    }
    return ret;
}
