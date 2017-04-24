#!/bin/bash
rpcgen -C arithOP.x
cc -c arithClient.c -o arithClient.o
cc -c arithOP_xdr.c -o arithOP_xdr.o
cc -c arithOP_clnt.c -o arithOP_clnt.o
cc -c arithServer.c -o arithServer.o
cc -c arithOP_svc.c -o arithOP_svc.o
cc -o Client arithClient.o arithOP_clnt.o arithOP_xdr.o -lnsl
cc -o Server arithServer.o arithOP_svc.o arithOP_xdr.o -lnsl
