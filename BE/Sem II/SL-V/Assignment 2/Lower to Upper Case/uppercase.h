/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _UPPERCASE_H_RPCGEN
#define _UPPERCASE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct inputString {
	char *inWord;
	int length;
};
typedef struct inputString inputString;

struct outString {
	char *outWord;
};
typedef struct outString outString;

#define LOWERTOUPPERCASEPROG 463874
#define LOWERTOUPPERCASEPROGVERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define lowertoupper 1
extern  struct outString * lowertoupper_1(struct inputString *, CLIENT *);
extern  struct outString * lowertoupper_1_svc(struct inputString *, struct svc_req *);
extern int lowertouppercaseprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define lowertoupper 1
extern  struct outString * lowertoupper_1();
extern  struct outString * lowertoupper_1_svc();
extern int lowertouppercaseprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_inputString (XDR *, inputString*);
extern  bool_t xdr_outString (XDR *, outString*);

#else /* K&R C */
extern bool_t xdr_inputString ();
extern bool_t xdr_outString ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_UPPERCASE_H_RPCGEN */
