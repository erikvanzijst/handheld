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
