class dir:
	left=False
	right=True
def GetLargestMobileInteger(arr,direction):
        MobileIndex=-1
        LargestMobileNumber=-1
        for i in range(len(arr)):
                if direction[i]==dir.left and i>0:
                        if arr[i-1]<arr[i] and arr[i]>LargestMobileNumber:
                                LargestMobileNumber=arr[i]
                                MobileIndex=i
                if direction[i]==dir.right and i<len(arr)-1:
                        if arr[i+1]<arr[i] and arr[i]>LargestMobileNumber:
                                LargestMobileNumber=arr[i]
                                MobileIndex=i
	return MobileIndex
def john(arr,permlist):
	baselist=[]
	direction={}
	#Initialize the first permutation with <1 <2 ... <n
	for i in range(len(arr)):
		direction[i]=dir.left
	#find largest mobile integer if it exists
	MobileIndex=GetLargestMobileInteger(arr,direction)
	while MobileIndex!=-1:
		#swap k and the adjacent integer it is looking at
		IsAdded=True
#		for i in range(len(permlist)):
#			if permlist[i].count(arr[i])==0 and len(permlist)>0:
#				IsAdded=False
		if(IsAdded==True):
			c=[]
			for i in range(len(arr)):
				c.append(arr[i])
			baselist.append(c)
		mi=MobileIndex
		if direction[mi]==dir.right:
			arr[mi],arr[mi+1]=arr[mi+1],arr[mi]
			direction[mi],direction[mi+1]=direction[mi+1],direction[mi]
			MobileIndex+=1
		elif direction[mi]==dir.left:
                        arr[mi],arr[mi-1]=arr[mi-1],arr[mi]
                        direction[mi],direction[mi-1]=direction[mi-1],direction[mi]
			MobileIndex-=1
		#reverse the direction of all integers larger than k
		for j in range(len(arr)):
			if arr[j]>arr[MobileIndex]:
				if direction[j]==dir.left:
					direction[j]=dir.right
				elif direction[j]==dir.right:
					direction[j]=dir.left
	        MobileIndex=GetLargestMobileInteger(arr,direction)
	IsAdded=True
#        for i in range(len(permlist)):
#                if permlist[i].count(arr[])==0 and len(permlist)>0:
#			IsAdded=False
        if(IsAdded==True):
		c=[]
		for i in range(len(arr)):
                        c.append(arr[i])
		baselist.append(c)
	return baselist
def main():
  arr=[2,3,5]
  permlist=[]
  permlist.append([1,2,3])
  permlist.append([5,6,8])
  permlist.append([3,4,2])
  permlist.append([8,10,9])
  permlist.append([])
  permlist.append([])
  print john(arr,permlist)
  print permlist
main()
