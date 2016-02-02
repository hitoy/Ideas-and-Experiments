#!/usr/bin/env python
from Queue import Queue

class Task():
	def __init__(self,taskid,coroutine):
		self.taskId = taskid
		self.coroutine = coroutine
		self.sendValue = ''
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
				self.sendvalue = False
				return retval
			except StopIteration:
				self.isFinished = True
				return ""


class Scheduler():

	def __init__(self):
		self.taskQueue = Queue()
		self.maxTaskId = 0
		self.taskMap = list()

	def scheduler(self,task):
		self.taskQueue.put(task)

	def newTask(self,coroutine):
		tid = self.maxTaskId+1
		task = Task(tid,coroutine)
		self.taskMap.append([tid,task])
		self.scheduler(task)
		return tid

	def run(self):
		while not self.taskQueue.empty():
			task = self.taskQueue.get()
			task.sendValue = task.getTaskId()
			retval = task.run()
			retval(task,self)
			if task.isFinished:
				tid = task.getTaskId()
				self.taskMap.remove([tid,task])
			else:
				self.scheduler(task)


'''
System Call function
'''
def getTaskId(task,scheduler):
	return task.taskId
	pass


def task1():
	i = 0
	while i < 30:
		print "This is task 1 %s"%i
		i=i+1
		pid = yield getTaskId
		print "ID is %s"%pid
	

def task2():
	i = 0
	while i < 20:
		print "This is task 2 %s"%i
		i=i+1
		yield

schedular = Scheduler()
schedular.newTask(task1())
#schedular.newTask(task2())

schedular.run()
