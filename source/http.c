/**
 * Powder Toy - HTTP library
 *
 * Powder Toy is the legal property of Stanislaw Skowronek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef MACOSX
#include <malloc.h>
#endif
#include <time.h>
#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
//#include <sys/socket.h>
//#include <netdb.h>
#endif

#include "http.h"
#include "md5.h"

#ifdef WIN32
#define PERROR SOCKET_ERROR
#define PERRNO WSAGetLastError()
#define PEAGAIN WSAEWOULDBLOCK
#define PEINTR WSAEINTR
#define PEINPROGRESS WSAEINPROGRESS
#define PEALREADY WSAEALREADY
#define PCLOSE closesocket
#else
#define PERROR -1
#define PERRNO errno
#define PEAGAIN EAGAIN
#define PEINTR EINTR
#define PEINPROGRESS EINPROGRESS
#define PEALREADY EALREADY
#define PCLOSE close
#endif

static int http_up = 0;
static long http_timeout = 15;
static int http_use_proxy = 0;
static struct sockaddr_in http_proxy;

static char *mystrdup(char *s)
{
    char *x;
    if(s) {
	x = malloc(strlen(s)+1);
	strcpy(x, s);
	return x;
    }
    return s;
}

static int splituri(char *uri, char **host, char **path)
{
    char *p=uri,*q,*x,*y;
    if(!strncmp(p, "http://", 7))
	p += 7;
    q = strchr(p, '/');
    if(!q)
	q = p + strlen(p);
    x = malloc(q-p+1);
    if(*q)
	y = mystrdup(q);
    else
	y = mystrdup("/");
    strncpy(x, p, q-p);
    x[q-p] = 0;
    if(q==p || x[q-p-1]==':') {
	free(x);
	free(y);
	return 1;
    }
    *host = x;
    *path = y;
    return 0;
}

static char *getserv(char *host)
{
    char *q, *x = mystrdup(host);
    q = strchr(x, ':');
    if(q)
	*q = 0;
    return x;
}

static char *getport(char *host)
{
    char *p, *q;
    q = strchr(host, ':');
    if(q)
	p = mystrdup(q+1);
    else
	p = mystrdup("80");
    return p;
}

static int resolve(char *dns, char *srv, struct sockaddr_in *addr)
{
return 1;
}

void http_init(char *proxy)
{

}

void http_done(void)
{
    http_up = 0;
}

#define CHUNK 4096

#define HTS_STRT 0
#define HTS_RSLV 1
#define HTS_CONN 2
#define HTS_IDLE 3
#define HTS_XMIT 4
#define HTS_RECV 5
#define HTS_DONE 6
struct http_ctx {
    int state;
    long last;
    int keep;
    int ret;
    char *host, *path;
    char *thdr;
    int thlen;
    char *txd;
    int txdl;
//    struct sockaddr_in addr;
    char *tbuf;
    int tlen, tptr;
    char *hbuf;
    int hlen, hptr;
    char *rbuf;
    int rlen, rptr;
    int chunked, chunkhdr, rxtogo, contlen, cclose;
    int fd;
    char *fdhost;
};
void *http_async_req_start(void *ctx, char *uri, char *data, int dlen, int keep)
{
    struct http_ctx *cx = ctx;

    return ctx;
}

void http_async_add_header(void *ctx, char *name, char *data)
{

}

static void process_header(struct http_ctx *cx, char *str)
{

}

static void process_byte(struct http_ctx *cx, char ch)
{

}

int http_async_req_status(void *ctx)
{
 
 return 1;
}

char *http_async_req_stop(void *ctx, int *ret, int *len)
{
    struct http_ctx *cx = ctx;
    char *rxd;

    return rxd;
}

void http_async_get_length(void *ctx, int *total, int *done)
{

}

void http_async_req_close(void *ctx)
{

}

char *http_simple_get(char *uri, int *ret, int *len)
{

}

char *http_simple_post(char *uri, char *data, int dlen, int *ret, int *len)
{
return NULL;
}

char *http_ret_text(int ret)
{
  
}

static char hex[] = "0123456789abcdef";
char *http_multipart_post(char *uri, char **names, char **parts, int *plens, char *user, char *pass, int *ret, int *len)
{
    
    return NULL;
}
