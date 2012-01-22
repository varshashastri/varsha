import johnson
def FindAllCombinations(ListArr,UnionArr):
    AllComb=[];
    FeasibleComb=[];
    for arr in ListArr:
	AllComb.append(johnson.john(arr));
    for comb in AllComb:
	for arr in comb:
		IsAdded=CheckFeasibility(arr,UnionArr);
		if(IsAdded):
			FeasibleComb.append(arr);
    return FeasibleComb;
def CheckFeasibility(arr,UnionArr):
	for i in range(len(arr)):
		if (arr[i] in UnionArr[i])==False:
			return False
	return True
#def main():
#    acrossListArr=[]
#    acrossListArr.append([1,8]);
#    acrossListArr.append([2,7]);
#    acrossListArr.append([3,6]);
#    acrossListArr.append([4,5]); #These are the various possibilities for elements of an across element to be filled across.
#    downListArr=[]
#    downListArr.append([6,8,9]);
#    downListArr.append([1,2,3]);# these are downLists Corresponding to the acrosslist. Its a union of all different possibilities of the particular downward number.
    #print downListArr
#    print FindAllCombinations(acrossListArr,downListArr);
#main()
