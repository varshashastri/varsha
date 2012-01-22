def NoDuplicates(cl):
	for i in cl:
		if cl.count(i)>1:
			return False
	return True
def AllSum(total,n,cl,baselist):
	end=True
	for i in range(n):
		if cl[n-i-1]==9-i:
			continue
		else:
			end=False
			break
	if sum(cl)==total and NoDuplicates(cl):
		IsRepeated=False
		nl=[]
		for i in range(n):
			nl.append(cl[i])
		nl.sort()
		for l in baselist:
			if l==nl:
				IsRepeated=True
		if IsRepeated==False:
			baselist.append(nl)
        if(end==True):
                return 
	for i in range(n):
		if cl[i]==9:
			cl[i-1]+=1
			for j in range(i,n):
				cl[j]=cl[j-1]+1
				if cl[j]==10:
					cl[j]=1
			AllSum(total,n,cl,baselist)
			break
		elif i==n-1 and cl[i]!=9:
			cl[i]+=1
			AllSum(total,n,cl,baselist)
def getSubsets(total,n):
	ini=[]
	anl=[]
	baselist=[]
	for i in range(n):
		ini.append(i+1)
	AllSum(total,n,ini,baselist)
	return baselist
#def main():
#	print getSubsets(21,4)
#main()
