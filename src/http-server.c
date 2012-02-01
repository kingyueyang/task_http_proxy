/*
 * =====================================================================================
 *
 *       Filename:  http_server.c
 *
 *    Description:  receive POST and RESPONE it
 *
 *        Version:  1.0
 *        Created:  11/29/2011 11:23:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (feinno), yueyang@feinno.com
 *        Company:  FCT
 *
 * =====================================================================================
 */

#include "http-server.h"

int
task_http_proxy(void) {
    struct event_base *base;
    struct evhttp *http;
    struct evhttp_bound_socket *handle;

    unsigned short port = PORT;

    /* As you konw */
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        return (1);

    /* Create a new base evObject */
    base = event_base_new();
    if (!base) {
        fprintf(stderr, "Couldn't create an event_base: exiting\n");
        return 1;
    }

    /* Create a new evhttp object to handle requests. */
    http = evhttp_new(base);
    if (!http) {
        fprintf(stderr, "couldn't create evhttp. Exiting.\n");
        return 1;
    }

    /*
     * The path /post support post method
     * Receive shell command by post body
     */
    evhttp_set_cb(http, "/post", post_command_cb, NULL);

    /* We want to accept arbitrary requests, so we need to set a "generic"
     * cb.  We can also add callbacks for specific paths. */
    evhttp_set_gencb(http, other_cb, NULL);

    /* Now we tell the evhttp what port to listen on */
    handle = evhttp_bind_socket_with_handle(http, "0.0.0.0", port);

    if (!handle) {
        fprintf(stderr, "couldn't bind to port %d. Exiting.\n",
                (int)port);
        return 1;
    }

    event_base_dispatch(base);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

static void
other_cb(struct evhttp_request *req, void *arg) {
    printf("Not Suppost this Path\n");
    evhttp_send_reply(req, 401, "olo", NULL);
    return;
}

static void
post_command_cb(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf;
    char cbuf[4];
    char *buffer = NULL;

    printf("\nArrive /post path\n");
    if (EVHTTP_REQ_POST != evhttp_request_get_command(req)) {
        evhttp_send_reply(req, 500, "not support this method", NULL);
        /*log it*/
        printf("/post not support this method\n");
        return;
    }
    printf("POST Request\n");

    buf = evhttp_request_get_input_buffer(req);
    size_t sz = evbuffer_get_length(buf);

    buffer = malloc(sz + 1);
    if (NULL == buffer) {
        evhttp_send_reply(req, 500, "alloc memroy error", NULL);
        return ;
    }

    /* Init temp buffer */
    memset(buffer, 0, sz + 1);
    while (evbuffer_get_length(buf)) {
        int n;
        n = evbuffer_remove(buf, buffer, sz);
    }
    printf("%s\n", buffer);

    free(buffer);
    buffer = NULL;

    evhttp_send_reply(req, 200, "OK", NULL);
    return ;
}
