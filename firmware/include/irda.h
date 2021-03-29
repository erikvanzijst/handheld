#ifndef IRDA_H_INCLUDED
#define IRDA_H_INCLUDED
#include <stdint.h>

#define IRDA_MAX_PAYLOAD 63
#define ETXBUSY -1      // tx failed, transmission in progress
#define ETXSIZE -2      // tx failed, payload too big

/*
 * Returns true if a peer is present and active, false otherwise.
 *
 * If we're not connected, `irda_is_tx_ready` will return false and calls to
 * `send_irda` will return an error.
 */
bool irda_is_connected();

bool irda_is_tx_ready();

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
int8_t send_irda(uint8_t *data, uint8_t len);

bool irda_is_rx_ready();

/*
 * Receives a packet from IrDA. This will block until an entire packet has
 * been received successfully. To avoid blocking, call `irda_is_rx_ready`
 * first.
 *
 * The data received is copied into `data`. This array must be large enough to
 * hold a full packet (`IRDA_MAX_PAYLOAD`).
 *
 * Returns the number of bytes received. Any negative value indicates an error.
 */
int8_t recv_irda(uint8_t *data);

#endif
