/*
MIT License

Copyright (c) 2022 Erik van Zijst <erik.van.zijst@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef IRDA_H_INCLUDED
#define IRDA_H_INCLUDED
#include <stdint.h>

#define IRDA_MAXBUF 512

typedef struct {
    uint32_t timeouts;
    uint32_t crc_errors;
    uint32_t bytes_out;
    uint32_t bytes_in;
} link_stats_t;

int8_t irda_init();
void irda_enable(void (*receive_callback)(uint8_t *buf, uint16_t len));

/*
 * Returns the link status.
 */
link_stats_t * irda_stats();

bool irda_write_available();

/*
 * Offers a packet for transmission over IrDA.
 *
 * Only one packet can be enqueued and this function blocks until the previous
 * packet has been transmitted completely.
 *
 * Call `irda_write_available` before calling this function to avoid blocking.
 *
 * On success, the number of bytes written is returned. Any negative value
 * indicates an error.
 */
int irda_write(uint8_t *buf, uint16_t len);

#endif
