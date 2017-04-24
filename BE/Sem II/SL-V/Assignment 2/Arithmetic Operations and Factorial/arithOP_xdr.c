/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "arithOP.h"

bool_t
xdr_inputInfo (XDR *xdrs, inputInfo *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num_1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num_2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num_4))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->option))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->num_1);
			IXDR_PUT_LONG(buf, objp->num_2);
			IXDR_PUT_LONG(buf, objp->num_4);
			IXDR_PUT_LONG(buf, objp->option);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num_1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num_2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num_4))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->option))
				 return FALSE;
		} else {
			objp->num_1 = IXDR_GET_LONG(buf);
			objp->num_2 = IXDR_GET_LONG(buf);
			objp->num_4 = IXDR_GET_LONG(buf);
			objp->option = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->num_1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num_2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num_4))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->option))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_outputInfo (XDR *xdrs, outputInfo *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->resultValue))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->floatResultValue))
		 return FALSE;
	return TRUE;
}