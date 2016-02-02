#!/usr/bin/env python
# -*- coding:utf-8 -*-
import select
import socket

http = """HTTP/1.1 200 OK
Cotent-Type:text/html;charset=utf-8
Date: hehehe GMT
Server: epoll module

<!DOCTYPE HTML>
<html>
<head>
<title>这是一首小情歌!</title>
</head>
<body>
这是一首简单小情歌!
</body>
</html>
"""

serv = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serv.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
serv.bind(("",1025))
serv.listen(10)
serv.setblocking(0)

ep = select.epoll()
ep.register(serv.fileno(),select.EPOLLIN)
clients = {}
while True:
	events = ep.poll(1)
	for fileno,event in events:
		if fileno == serv.fileno():
			conn,addr = serv.accept()
			clients.append(conn)
			conn.send(http)
