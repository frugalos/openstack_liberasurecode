/* 
 * <Copyright>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY
 * THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ERASURECODE_H_
#define _ERASURECODE_H_

#include "erasurecode_version.h"
#include "erasurecode_stdinc.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__GNUC__) && __GNUC__ > 3
#define dl_restrict __restrict
#else
#define dl_restrict
#endif

/* liberasurecode API header */

typedef enum {
    EC_BACKEND_NULL             = 0,
    EC_BACKEND_RS_VAND          = 1,
    EC_BACKEND_RS_CAUCHY_ORIG   = 2,
    EC_BACKEND_FLAT_XOR_3       = 3,
    EC_BACKEND_FLAT_XOR_4       = 4,
    EC_BACKENDS_MAX,
} ec_backend_id_t;

typedef void * ec_backend_handle_t;

struct ec_backend_ops {
    int (*init)(TBD);
    int (*exit)(TBD);

    ec_backend_handle_t (*open)(TBD);
    void (*close)(ec_backend_handle_t handle);

    int (*encode)(TBD);
    int (*decode)(TBD);
    int (*reconstruct)(TBD);
    int (*get_fragments_needed)(TBD);
    int (*get_fragment_metadata)(TBD);
    int (*verify_fragment_metadata)(TBD);
    int (*verify_stripe_metadata)(TBD);
};
typedef struct ec_backend_ops ec_backend_ops_t;

struct ec_backend_private {
        uint32_t flags;
        /* other common/private EC backend members go here */
};
typedef struct ec_backend_private ec_backend_private_t;


#define MAX_BASENAMELEN 64
#define MAX_LIBNAMELEN 64
#define MAX_LIBVERLEN 64
struct ec_backend {
    ec_backend_id_t         id;                         /* EC backend id */
    char                    name[MAX_BASENAMELEN];      /* EC backend common name */
    char                    soname[MAX_LIBNAMELEN];     /* EC backend shared library path */
    char                    soversion[MAX_LIBVERLEN];   /* EC backend shared library version */
    ec_backend_handle_t     handle;                     /* EC backend shared library handle */
    uint8_t                 users;                      /* EC backend number of active references */

    ec_backend_ops_t        ops;                        /* EC backend ops table */
    ec_backend_private_t    private;                    /* EC backend private data */

    SLIST_ENTRY(ec_backend) link;
};
typedef struct ec_backend ec_backend_t;

/* Error codes */
typedef enum {
    EBACKENDNOTSUPP = 200,
    EECMETHODNOTIMPL = 201,
} LIBERASURECODE_ERROR_CODES;

/* Backend registration interface */
int liberasurecode_backend_register(ec_backend_t *backend);
int liberasurecode_backend_unregister(ec_backend_t *backend);

/* 

#ifdef __cplusplus
}
#endif

#endif  // _ERASURECODE_H_
