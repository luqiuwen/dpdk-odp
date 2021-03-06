/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2014 Netdp Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Netdp Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef __NETDP_INIT_H__
#define __NETDP_INIT_H__

/**
 *
 *
 */
struct netdp_init_config 
{
    uint32_t max_sock_conn;
    uint32_t max_udp_conn;
    uint32_t max_sock_app;
} __rte_cache_aligned;


typedef int (*netdp_send_packet_cb)(struct rte_mbuf *m, uint8_t port);

/**
 * @param pktmbuf_pool 
 *@param sockets_nb 
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */
int netdp_initialize(int sockets_nb, int lcores_nb, struct rte_mempool **pktmbuf_pool, struct netdp_init_config *user_conf);

/**
 * 
 * @param send_cb     
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */
int netdp_register(netdp_send_packet_cb send_cb);

/**
 * 
 * @param app_name     
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */
int netdp_app_register(char *app_name);


/**
 * 
 *
 * @param m      
 * @param portid   
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */
 uint64_t netdp_packet_handle(struct rte_mbuf *m, uint8_t portid);

#endif /* __NETDP_INIT_H__ */
