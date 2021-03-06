#!/usr/bin/env python
# -*- coding:utf-8 -*-
from Queue import Queue
import copy

class Task():
	def __init__(self,taskid,coroutine):
		self.__taskId = taskid
		self.__coroutine = coroutine
		self.__sendValue = '' 
		self.__beforeFirstYield = True
		self.isFinished = False

	def getTaskId(self):
		return self.__taskId

	def setYield(self):
		self.__beforeFirstYield = False

	def setValue(self,value):
		self.__sendValue = value

	def run(self):
		if(self.__beforeFirstYield):
			self.__beforeFirstYield = False
			return self.__coroutine.next()
		else:
			try:
				retval = self.__coroutine.send(self.__sendValue)
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

	def copy(self,pid):
		if not pid in self.taskMap:
			return False
		newtask = copy.deepcopy(self.taskMap[pid])
		newtaskid = self.maxTaskId + 1
		self.taskMap[newtaskid] = newtask
		self.scheduler(newtask)
		return newtask

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
def getpid():
	def tmp(task,scheduler):
		task.setValue(task.getTaskId())
		scheduler.scheduler(task)
	return SysCall(tmp)


def KillTask(taskid):
	def tmp(task,scheduler):
		task.setValue(scheduler.KillTask(taskid))
	return SysCall(tmp)


"""
fork函数很特别，需要创建任务的一个分支出来
1，创建一个新任务，这个新任务为子任务
2，给这个新任务sendvalue返回0
3，给老任务返回新任务的任务ID
"""
def fork():
	def tmp(task,scheduler):
		taskid = task.getTaskId()
		#克隆一个新任务
		childtask = scheduler.copy(taskid)
		#给父任务设置返回为子任务ID
		task.setValue(scheduler.maxTaskId)
		#给子任务设置返回为0
		childtask.setValue(0)
		print (scheduler.taskMap)
	return SysCall(tmp)

"""
用户程序
"""

"""
def task1():
	i = 0
	#yield 既是中断
	pid = yield getpid()
	while i < 100:
		print "This is task pid is %s i is %s"%(pid,i)
		i=i+1
		yield
"""

"""
def task2():
	i = 0
	pid = yield getpid()
	while i < 100:
		print "This is task pid is %s i is %s"%(pid,i)
		if i == 10:
			yield KillTask(getpid())
		i=i+1
		yield

schedular = Scheduler()
schedular.newTask(task1())
schedular.newTask(task2())
schedular.run()

"""

def task3():
	i=0
	pid = (yield getpid())
	print "This is task pid is %s i is %s"%(pid,i)
	while i < 10:
		if i == 5:
			pid = yield fork()
			if pid > 0:
				print "This is Parent Task, the child Task id is"%(pid)
			else:
				print "This is Child Task"
		i = i + 1
		yield
schedular = Scheduler()
schedular.newTask(task3())
schedular.run()
