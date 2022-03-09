#ifndef IRDA_H_INCLUDED
#define IRDA_H_INCLUDED
#include <stdint.h>

#define IRDA_MAXBUF 512


int8_t irda_init();
void irda_enable(void (*receive_callback)(uint8_t *buf, int len));
void irda_disable();

bool irda_write_available();

/*
 * Offers a packet for transmission over IrDA.
 *
 * Only one packet can be enqueued and not until the packet has been
 * transmitted completely, can this function be called to enqueue the next
 * packet.
 *
 * Call `irda_is_tx_ready` before calling this function.
 *
 * On success, 0 returned. Any negative value indicates an error.
 */
int irda_write(uint8_t *buf, int len);

#endif
