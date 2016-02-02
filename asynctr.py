#!/usr/bin/env python
# -*- coding:utf-8
# Author Hito
# Async IO Manager
import select

class AsynSocket:
	#Add A Listensocket
	def __init__(self,listensocket,denyhost=[]):
		self.listensock  = listensocket
		self.denyhost =  denyhost
		self.clientsock = list()

	def add_deny(self,denyhost):
		if not denyhost in self.denyhost:
			self.denyhost.append(denyhost)

	def remove_deny(self,denyhost):
		if denyhost in self.denyhost:
			self.denyhost.remove(denyhost)
	
	def add_client(self,clientsock):
		if not clientsock in self.clientsock:
			self.clientsock.append(clientsock)

	def remove_client(self,clientsock):
		if clientsock in self.clientsock:
			self.clientsock.remove(clientsock)

	def __on_select(self):
		while True:
			[]

