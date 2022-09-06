class CalEarn:

  def __init__(self,name):
    """gives name"""
    self.name = name
    self.list1 = [] 

  def inpEarn(self,listNumber):
    """ input how much you earned"""
    self.listNumber = listNumber
    self.list1 += listNumber
    opInp = open("earning.txt","w")
    for x in self.list1:
      opInp.write(str(x)+ "\n")

    opInp.close()
    print(self.list1)

  def calSum(self):
    opInp = open("earning.txt","r")
    sum1 = 0
    for x in opInp:
      sum1 += float(x)

    print(sum1)
    opInp.close()


    
