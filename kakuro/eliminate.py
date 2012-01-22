def eliminate(retlist,scanlist):
	newlist=[]
	removelist=[]
	for i in range(len(scanlist)):
		newlist=list(set(scanlist[i])|set(newlist))
	for i in range(len(retlist)):
		for j in range(len(retlist[i])):
			n=retlist[i]
			if len(list(set(n)&set(newlist)))==0 and removelist.count(retlist[i])==0:
				removelist.append(retlist[i])
	for i in range(len(removelist)):
		retlist.remove(removelist[i])
	return retlist
#def main():
#	downlist=[]
#	acrosslist=[]
#	downlist.append([6,7,5])
#	downlist.append([3,9,8])
#	acrosslist.append([6,5])
#	acrosslist.append([7,4])
#	acrosslist.append([1,2])
#	downlist=eliminate(downlist,acrosslist)
#	acrosslist=eliminate(acrosslist,downlist)
#	print "downlist=",downlist,"across=",acrosslist
#main()
