#!/usr/bin/env python
# -*- coding:utf-8 -*-
from Queue import Queue

class Task():
	def __init__(self,taskid,coroutine):
		self.taskId = taskid
		self.coroutine = coroutine
		self.sendValue = 1000
		self.beforeFirstYield = True
		self.isFinished = False

	def getTaskId(self):
		return self.taskId

	def run(self):
		if(self.beforeFirstYield):
			self.beforeFirstYield = False
			return self.coroutine.next()
		else:
			try:
				retval = self.coroutine.send(self.sendValue)
				return retval
			except StopIteration:
				self.isFinished = True
				return ""


class Scheduler():

	def __init__(self):
		self.taskQueue = Queue()
		self.maxTaskId = 0
		self.taskMap = dict()

	def scheduler(self,task):
		self.taskQueue.put(task)
	
	def KillTask(self,taskid):
		if  not taskid in self.taskMap:
			return False
		i = 0
		while i < self.taskQueue.qsize():
			tmp = self.taskQueue.get()
			if tmp == self.taskMap[taskid]:
				del self.taskMap[taskid]
				break
			else:
				self.scheduler(tmp)
			i+=1
		return True

	def newTask(self,coroutine):
		self.maxTaskId+=1
		task = Task(self.maxTaskId,coroutine)
		self.taskMap[self.maxTaskId] = task
		self.scheduler(task)
		return self.maxTaskId

	def run(self):
		while not self.taskQueue.empty():
			task = self.taskQueue.get()
			retval = task.run()
			if isinstance(retval,SysCall):
				retval(task,self)
				continue

			if task.isFinished:
				tid = task.getTaskId()
				del self.taskMap[tid]
			else:
				self.scheduler(task)


'''
System Call function
直接调用不能对类型作出控制
所以需要模拟出一个类
'''
class SysCall():
	def __init__(self,callback):
		self.__callback = callback

	def __call__(self,task,scheduler):
		if not isinstance(task,Task):
			raise TypeError(task+" is not instance of Task!")
		if not isinstance(scheduler,Scheduler):
			raise TypeError(scheduler+" is not instance of Scheduler!")
		callback = self.__callback
		return callback(task,scheduler)


"""
系统函数，供用户调用:
"""
def getPID():
	def tmp(task,scheduler):
		task.sendValue = task.getTaskId()
		scheduler.scheduler(task)
	return SysCall(tmp)


def KillTask(taskid):
	def tmp(task,scheduler):
		task.sendValue =  scheduler.KillTask(taskid)
	return SysCall(tmp)

def Fork():
	def tmp(task,scheduler):
		scheduler.newTask(task.coroutine)
		task.sendValue = (task.getTaskId(),0)
	return SysCall(tmp)


"""
用户程序
"""
def task1():
	i = 0
	pid = (yield getPID())
	while i < 100:
		print "This is task pid is %d i is %s"%(pid,i)
		pid = yield Fork()
		i=i+1
		yield
	
"""
def task2():
	i=0
	pid = (yield getPID())
	while i < 10:
		print "This is task pid is %d i is %s"%(pid,i)
		if i == 5:
			re = yield KillTask(1)
			print "KillTask 1 %s"%re
			#re = yield KillTask(2)
			#print "KillTask 1 %s"%re
			pass
		i=i+1
		yield

def task3():
	i=0
	pid = (yield getPID())
	while i < 30:
		print "This is task pid is %d i is %s"%(pid,i)
		i +=1
		yield
"""
schedular = Scheduler()
schedular.newTask(task1())
#schedular.newTask(task2())
#schedular.newTask(task3())

schedular.run()
