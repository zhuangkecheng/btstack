/*
 * Copyright (C) 2018 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTHIAS
 * RINGWALD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */

#ifndef __MESH_LOWER_TRANSPORT_H
#define __MESH_LOWER_TRANSPORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "ble/mesh/mesh_network.h"

// allocator
mesh_transport_pdu_t * mesh_transport_pdu_get(void);
void mesh_transport_pdu_free(mesh_transport_pdu_t * transport_pdu);

// transport getter/setter
uint16_t mesh_transport_nid(mesh_transport_pdu_t * transport_pdu);
uint16_t mesh_transport_ctl(mesh_transport_pdu_t * transport_pdu);
uint16_t mesh_transport_ttl(mesh_transport_pdu_t * transport_pdu);
uint32_t mesh_transport_seq(mesh_transport_pdu_t * transport_pdu);
uint32_t mesh_transport_seq_zero(mesh_transport_pdu_t * transport_pdu);
uint16_t mesh_transport_src(mesh_transport_pdu_t * transport_pdu);
uint16_t mesh_transport_dst(mesh_transport_pdu_t * transport_pdu);

void mesh_transport_set_nid_ivi(mesh_transport_pdu_t * transport_pdu, uint8_t nid_ivi);
void mesh_transport_set_ctl_ttl(mesh_transport_pdu_t * transport_pdu, uint8_t ctl_ttl);
void mesh_transport_set_seq(mesh_transport_pdu_t * transport_pdu, uint32_t seq);
void mesh_transport_set_src(mesh_transport_pdu_t * transport_pdu, uint16_t src);
void mesh_transport_set_dest(mesh_transport_pdu_t * transport_pdu, uint16_t dest);


void mesh_lower_transport_init();
void mesh_lower_transport_set_higher_layer_handler(void (*pdu_handler)( mesh_pdu_t * pdu));

void     mesh_lower_transport_set_seq(uint32_t seq);
uint32_t mesh_lower_transport_next_seq(void);;
uint32_t mesh_lower_transport_peek_seq(void);

void mesh_lower_transport_message_processed_by_higher_layer(mesh_pdu_t * pdu);

void mesh_lower_transport_send_segmented_pdu(mesh_transport_pdu_t *transport_pdu);

// test
void mesh_lower_transport_received_message(mesh_network_callback_type_t callback_type, mesh_network_pdu_t *network_pdu);
void mesh_lower_transport_dump(void);
void mesh_lower_transport_reset(void);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif