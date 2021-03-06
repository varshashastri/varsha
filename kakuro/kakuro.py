from Tkinter import *
import getSum
import johnson
import eliminate
import FindAllCombinations
#currently Im doing backtracking based on downlist alone. Later see if you can optimize it.
class size:
	rows=9
	columns=8
class BoxType:
	Empty=0
	Filled=1
	Question=2
class KText:
	def __init__(self,r,c,master,text):
		self.row=r
		self.column=c
		self.text=text
		self.text.grid(row=r,column=c)
		self.text.config(state=DISABLED)
		self.type=BoxType.Question
		self.DownValue=0
		self.AcrossValue=0#part of question
		self.downlist=[]
		self.acrosslist=[]
		self.AcrossAnswer=[]
		self.DownAnswer=[]#final assigned value
		self.Value=0#answer value final
		self.index=0
		self.count=0
		self.AllAcrossCombinations=[]
		self.AllDownCombinations=[]
master = Tk()
textboxes={}
puzzle=["0","0","0","23,0","7,0","0","37,0","16,0",
	"0","24,0","34,11","-1","-1","0,13","-1","-1",
	"0,23","-1","-1","-1","-1","3,11","-1","-1",
	"0,27","-1","-1","-1","-1","-1","-1","0",
	"0,14","-1","-1","3,0","0,10","-1","-1","22,0",
	"0","0,10","-1","-1","23,0","6,17","-1","-1",
	"0","16,23","-1","-1","-1","-1","-1","-1",
	"0,11","-1","-1","0,21","-1","-1","-1","-1",
	"0,14","-1","-1","0,9","-1","-1","0","0"]

def sample():
  for i in range(size.rows):
     for j in range(size.columns):
	if puzzle[j+i*size.columns]=="-1":
		textboxes[(i,j)].type=BoxType.Question
	elif puzzle[j+i*size.columns]=="0":
		textboxes[(i,j)].type=BoxType.Empty
                textboxes[(i,j)].text.insert(END,puzzle[j+i*size.columns])
	else:
		textboxes[(i,j)].type=BoxType.Filled
		textboxes[(i,j)].DownValue=int(puzzle[j+i*size.columns].split(',')[0])
		textboxes[(i,j)].AcrossValue=int(puzzle[j+i*size.columns].split(',')[1])
                textboxes[(i,j)].text.insert(END,textboxes[(i,j)].DownValue)
                textboxes[(i,j)].text.insert(END,'\\')
                textboxes[(i,j)].text.insert(END,textboxes[(i,j)].AcrossValue)

def make_puzzle_clicked(event):
 for i in range(size.rows):
  	for j in range(size.columns):
		textboxes[(i,j)].text.config(state=NORMAL)
 sample()

def union(Lists):
	unionlist=[]
	for List in Lists:
		for element in List:
			if((element in unionlist)==False):
				unionlist.append(element)
	return unionlist

def AssignValues():#Returns true if any new value was set
  flag=False
  for i in range(size.rows):
     for j in range(size.columns):
        if (len(textboxes[(i,j)].AllAcrossCombinations)==1 and len(textboxes[(i,j)].AcrossAnswer)==0):
		textboxes[(i,j)].AcrossAnswer=textboxes[(i,j)].AllAcrossCombinations[0]
		k=1
		while k<=len(textboxes[(i,j)].AcrossAnswer):
			textboxes[(i,j+k)].Value=textboxes[(i,j)].AcrossAnswer[k-1]
			k=k+1
                flag=True
        if (len(textboxes[(i,j)].AllDownCombinations)==1 and len(textboxes[(i,j)].DownAnswer)==0):
		textboxes[(i,j)].DownAnswer=textboxes[(i,j)].AllDownCombinations[0]#There is just one answer hence the index 0
		k=1
		while k<=len(textboxes[(i,j)].DownAnswer):
			textboxes[(i+k,j)].Value=textboxes[(i,j)].DownAnswer[k-1]
			k=k+1
		flag=True
  return flag

def Arrange():
  for i in range(size.rows):
     for j in range(size.columns):
	if len(textboxes[(i,j)].acrosslist)>0:
		y=1
		DownLists=[]
		while j+y < size.columns and textboxes[(i,j+y)].type==BoxType.Question:
			x=1
			while textboxes[(i-x,j+y)].type==BoxType.Question:
				x=x+1
			DownLists.append(union(textboxes[(i-x,j+y)].downlist))
			y=y+1
		temp=[]
		temp=FindAllCombinations.FindAllCombinations(textboxes[(i,j)].acrosslist,DownLists)
		textboxes[(i,j)].AllAcrossCombinations=temp
        if len(textboxes[(i,j)].downlist)>0:
                x=1
                AcrossLists=[]
                while i+x < size.rows and textboxes[(i+x,j)].type==BoxType.Question:
                        y=1
                        while j-y>=0 and textboxes[(i+x,j-y)].type==BoxType.Question:
                                y=y+1;
                        AcrossLists.append(union(textboxes[(i+x,j-y)].acrosslist))
			x=x+1;
                temp=[]
		temp=FindAllCombinations.FindAllCombinations(textboxes[(i,j)].downlist,AcrossLists)
		textboxes[(i,j)].AllDownCombinations=temp
		#AllCombinations is the ordered collection for across/down lists i.e it should be placed in specific order on the board.

def RemoveRedundant(AcceptedFormat,ListsToTrim):
	for List in ListsToTrim:
		for i in range(len(AcceptedFormat)):
			if(AcceptedFormat[i]==List[i] or AcceptedFormat[i]==0):
				continue;
			else:
				 ListsToTrim.remove(List)
				 break
	return ListsToTrim

def Rearrange():  #optimization pending and implementation pending.
  for i in range(size.rows):
     for j in range(size.columns):
	AcceptedFormat=[]
	if(len(textboxes[(i,j)].downlist)>0):
		k=1
		while i+k<size.rows and textboxes[(i+k,j)].type==BoxType.Question:
			AcceptedFormat.append(textboxes[(i+k,j)].Value)
			k=k+1
		textboxes[(i,j)].AllDownCombinations=RemoveRedundant(AcceptedFormat,textboxes[(i,j)].AllDownCombinations)
	AcceptedFormat=[]
        if(len(textboxes[(i,j)].acrosslist)>0):
                k=1
                while j+k<size.columns and textboxes[(i,j+k)].type==BoxType.Question:
                        AcceptedFormat.append(textboxes[(i,j+k)].Value)
                        k=k+1
                textboxes[(i,j)].AllAcrossCombinations=RemoveRedundant(AcceptedFormat,textboxes[(i,j)].AllAcrossCombinations)

def GetNextDownijCouple(ijcouple):
	if(ijcouple[1]+1==size.columns and ijcouple[0]+1==size.rows):
		return [-1,-1]
	if(ijcouple==[-1,-1]):
		return [-1,-1]
	elif(ijcouple[1]+1==size.columns):
		ijcouple[0]=ijcouple[0]+1
		ijcouple[1]=0
	else:
		ijcouple[1]=ijcouple[1]+1
	while(ijcouple!=[-1,-1] and textboxes[(ijcouple[0],ijcouple[1])].DownValue==0):
		ijcouple=GetNextDownijCouple(ijcouple)
	return ijcouple

def AssignValuesToSingleList(IsDown,List,i,j):
	if(IsDown):
		k=1
		textboxes[(i,j)].DownAnswer=List
		while k<=len(List):
			textboxes[(i+k,j)].Value=List[k-1]
			k=k+1
	else:
                k=1
		textboxes[(i,j)].AcrossAnswer=List
                while k<=len(List):
                        textboxes[(i,j+k)].Value=List[k-1]
			k=k+1
def Completed():
  for i in range(size.rows):
     for j in range(size.columns):
	if(len(textboxes[(i,j)].DownAnswer)==0):
		return False
  return True

def BackTrack(ijcouple):
	#if(verifyall()):
	#	return true
	#else if(no solution):
		#return false
	#else
	Previjcouple=[-1,-1]
	previ=Previjcouple[0]=ijcouple[0]
	prevj=Previjcouple[1]=ijcouple[1]
	ijcouple=GetNextDownijCouple(ijcouple)
	i=ijcouple[0]
	j=ijcouple[1]
	if (ijcouple==[-1,-1]):
		while(textboxes[(previ,prevj)].index<textboxes[(previ,prevj)].count-1):
			AssignValuesToSingleList(True,textboxes[(previ,prevj)].AllDownCombinations[textboxes[(previ,prevj)].index],previ,prevj)
			textboxes[(previ,prevj)].index+=1
			print textboxes[(previ,prevj)].DownAnswer
		return
	else:
		if(not Completed()):
			AssignValuesToSingleList(True,textboxes[(i,j)].AllDownCombinations[textboxes[(i,j)].index],i,j)
			print textboxes[(i,j)].DownAnswer
			textboxes[(i,j)].index+=1
			BackTrack(ijcouple)
		elif(textboxes[(i,j)].index<textboxes[(i,j)].count-1):
			textboxes[(i,j)].index+=1
			AssignValuesToSingleList(True,textboxes[(i,j)].AllDownCombinations[textboxes[(i,j)].index],i,j)
			print textboxes[(i,j)].DownAnswer
			BackTrack(ijcouple)
		else:
			textboxes[(i,j)].index=0
			BackTrack(Previjcouple)
			
#def verify():
#  flag=False
#  for i in range(size.rows):
#     for j in range(size.columns):
#	        if(len(textboxes[(i,j)].downlist)>0):
#			k=1
#			total=0
#			while k<=len(textboxes[(i,j)].downlist):
#				total=total+textboxes[(i+k,j)].Value
#			if total==textboxes[(i,j)].DownValue:
#			 	flag=True
#			else:
#			 	flag=False
#                if(len(textboxes[(i,j)].acrosslist)>0):
#                        k=1
#                        total=0
#                        while k<=len(textboxes[(i,j)].acrosslist):
#                                total=total+textboxes[(i,j+k)].Value
#                        if total==textboxes[(i,j)].AcrossValue:
#                                flag=True
#                        else:
#                                flag=False
#  return flag

def auto_solve_clicked(event):
  for i in range(size.rows):
     for j in range(size.columns):
	if textboxes[(i,j)].type==BoxType.Filled and textboxes[(i,j)].DownValue!=0:
		count=0
		for k in range(size.rows-i-1):
		    if textboxes[(i+k+1,j)].type==BoxType.Question:
			count+=1
		    else:
			break
		textboxes[(i,j)].downlist=getSum.getSubsets(textboxes[(i,j)].DownValue,count)
        if textboxes[(i,j)].type==BoxType.Filled and textboxes[(i,j)].AcrossValue!=0:
                count=0
                for k in range(size.columns-j-1):
                    if textboxes[(i,j+k+1)].type==BoxType.Question:
                        count+=1
                    else:
                        break
                textboxes[(i,j)].acrosslist=getSum.getSubsets(textboxes[(i,j)].AcrossValue,count)
	if textboxes[(i,j)].type==BoxType.Question:
		x=1
		y=1
		while textboxes[(i,j-y)].type==BoxType.Question:
			y=y+1
		while textboxes[(i-x,j)].type==BoxType.Question:
			x=x+1
		textboxes[(i,j-y)].acrosslist=eliminate.eliminate(textboxes[(i,j-y)].acrosslist,textboxes[(i-x,j)].downlist)
		textboxes[(i-x,j)].downlist=eliminate.eliminate(textboxes[(i-x,j)].downlist,textboxes[(i,j-y)].acrosslist)

  Arrange()#optimize by using fixed numbers from AllCombinations
  while(AssignValues()):
	Rearrange()
  for i in range(size.rows):
    for j in range(size.columns):
	textboxes[(i,j)].count=len(textboxes[(i,j)].AllDownCombinations)
	print textboxes[(i,j)].AllDownCombinations,textboxes[(i,j)].count
  BackTrack([0,0])
make_puzzle=Button(master, height=3, width=10, text="New Puzzle?")
make_puzzle.grid(row=size.rows,column=0,columnspan=3)
make_puzzle.bind("<Button-1>",make_puzzle_clicked)
auto_solve=Button(master, height=3, width=10, text="Solve it!")
auto_solve.grid(row=size.rows,column=4,columnspan=3)
auto_solve.bind("<Button-1>",auto_solve_clicked)
for i in range(size.rows):
        for j in range(size.columns):
                textboxes[(i,j)]=KText(i,j,master,Text(master,width=6,height=3,font=30))
master.mainloop()
