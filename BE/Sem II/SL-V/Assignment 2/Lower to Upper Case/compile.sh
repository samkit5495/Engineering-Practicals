#!/bin/bash
rpcgen -C uppercase.x
cc -c client.c -o client.o
cc -c server.c -o server.o
cc -c uppercase_xdr.c -o uppercase_xdr.o
cc -c uppercase_clnt.c -o uppercase_clnt.o
cc -c uppercase_svc.c -o uppercase_svc.o
cc -o Server server.o uppercase_svc.o uppercase_xdr.o -lnsl
cc -o Client client.o uppercase_xdr.o uppercase_clnt.o -lnsl
