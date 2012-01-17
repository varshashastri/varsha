from Tkinter import *
import getSum
import random
import johnson
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
		self.Acrossvalue=0
		self.downlist=[]
		self.acrosslist=[]
		self.pdown=[]
		self.pacross=[]
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
		print "down-",textboxes[(i,j)].DownValue,count,textboxes[(i,j)].downlist
        if textboxes[(i,j)].type==BoxType.Filled and textboxes[(i,j)].AcrossValue!=0:
                count=0
                for k in range(size.columns-j-1):
                    if textboxes[(i,j+k+1)].type==BoxType.Question:
                        count+=1
                    else:
                        break
                textboxes[(i,j)].acrosslist=getSum.getSubsets(textboxes[(i,j)].AcrossValue,count)
                print "across-",textboxes[(i,j)].AcrossValue,count,textboxes[(i,j)].acrosslist
  for i in range(size.rows):
     for j in range(size.columns):
	if textboxes[(i,j)].DownValue!=0:
		permlist=[]
		for k in range(len(textboxes[(i,j)].downlist)):
			l=1
			while textboxes[(i+k+1,j-l)].type==BoxType.Question:
				l+=1
			permlist.append(textboxes[(i+k+1,j-l)].acrosslist)
		print textboxes[(i,j)].downlist,permlist
                #textboxes[(i,j)].pdown=johnson.john(textboxes[(i,j)].downlist,permlist)
		#print textboxes[(i,j)].pdown
make_puzzle=Button(master, height=3, width=10, text="make puzzle")
make_puzzle.grid(row=size.rows,column=0,columnspan=3)
make_puzzle.bind("<Button-1>",make_puzzle_clicked)
auto_solve=Button(master, height=3, width=10, text="auto solve")
auto_solve.grid(row=size.rows,column=4,columnspan=3)
auto_solve.bind("<Button-1>",auto_solve_clicked)
for i in range(size.rows):
        for j in range(size.columns):
                textboxes[(i,j)]=KText(i,j,master,Text(master,width=6,height=3,font=30))
master.mainloop()
