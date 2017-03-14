#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <bmpd/switch_bmv2/pd/pd.h>
#include <bm/pdfixed/pd_static.h>
#include <bm/pdfixed/thrift-src/pdfixed_rpc_server.h>
#include <bmpd/switch_bmv2/thrift-src/pd_rpc_server.h>

char *of_controller_str = NULL;
int of_ipv6 = 0;

int main() {
    /* Start up the PD RPC server */
    void *pd_server_cookie;
    start_bfn_pd_rpc_server(&pd_server_cookie);
    add_to_rpc_server(pd_server_cookie);

    p4_pd_init();
    p4_pd_switch_bmv2_init();
    p4_pd_switch_bmv2_assign_device(0,
    "ipc:///tmp/bmv2-0-notifications.ipc", 22222);
    p4_pd_switch_bmv2_assign_device(1,
    "ipc:///tmp/bmv2-1-notifications.ipc", 22223);

    #ifdef OPENFLOW_ENABLE
    p4ofagent_init(of_ipv6, of_controller_str);
    #endif

    return 0;
}