#!/bin/bash
rpcgen reverse.x
cc -c reverse_server.c -o reverse_server.o
cc -c reverse_client.c -o reverse_client.o
cc -c reverse_clnt.c -o reverse_clnt.o
cc -c reverse_svc.c -o reverse_svc.o
cc -o server reverse_server.o reverse_svc.o
cc -o client reverse_client.o reverse_clnt.o

