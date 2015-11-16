#!/usr/bin/env python
# -*- coding:utf-8 -*-
# 对于wsgi的理解并对其进行实验
# https://www.python.org/dev/peps/pep-0333/
import socket,re,os

httpre=re.compile(r"^(\w*)\s*([^\s]*)\s*HTTP\/([.\d]*)[\r\n]*([\s\S]+)[\r\n]*[\r\n]*([\s\S]?)$")
headerre=re.compile(r"([^\s]*):\s*([^\r\n]*)[\r\n]")

def recvall(link,buflen):
	buf = link.recv(buflen);
	if len(buf) < buflen:
		return buf
	else:
		return "%s%s"%(buf,recvall(link,buflen))

def headerdic(str):
	mydic = {}
	matches = headerre.findall(str)
	for line in matches:
		mydic[line[0]]=line[1]
	return mydic

#http request return
#method, uri, httpversion, header, body
def httppareser(request):
	try:
		raw_re = httpre.findall(request.strip())[0]
		return raw_re[0], raw_re[1], raw_re[2], raw_re[3], raw_re[4]
	except:
		return None


class WSGIServer:
	def __init__(self,host="127.0.0.1",port=8080,keepalive=5):
		self.host = host
		self.port = port
		self.keepalive = keepalive
		self.environ = os.environ


	def run(self,app):
		sockt = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
		sockt.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
		sockt.bind((self.host,self.port))
		sockt.listen(5)
		while True:
			con,addr = sockt.accept()
			#con.settimeout(self.keepalive)
			raw_request = recvall(con,1024)
			method,uri,httpversion,header,body = httppareser(raw_request)
			environ = header#,**os.environ)
			global response_header

			#start_response
			#gen http response header
			def start_response(status,response_header_list):
				global response_header
				headers = ""
				for header in response_header_list:
					headers = headers+"%s:%s\r\n"%(header[0],header[1])
				response_header = "HTTP/1.1 %s\r\n%s\r\n"%(status,headers)
			response_body = app(environ,start_response)
			con.send(response_header+response_body)
			con.close()

#This is the application
def app(environ,start_response):
	start_response("404 Not Found",[("Content-Type","text/html"),("User-Agent","Mybody")])
	return """<!DOCTYPE HTML>
<html>
<head lang="zh-cn">
	<meta charset="utf-8">
	<title>你好世界</title>
<body>
	<h1>Hello World</h1>
</body>
</html>"""


test = WSGIServer()
test.run(app)
