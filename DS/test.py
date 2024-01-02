

from pandas import DataFrame

def printer(arr):
    dataframe = DataFrame(arr[1::],columns=arr[0])
    print(dataframe.to_string(index=False))

length = {
    "D" : 8,
    "A" : 4,
    "H" : 2,
    "C" : 1
}

input_file = open("input.txt")
input_content = input_file.read().split('\n')
input_file.close()

instructions = []

for line in input_content:
    l = line.split(" ")
    try: 
        while(True):
            l.remove('')
    except:
        pass
    instructions.append(l)

current_rel = 0
for i in range(len(instructions)):
    # print(instructions[i])
    instructions[i].insert(0,current_rel)
    if instructions[i][2]=="DC":
        args = instructions[i][-1].split(',')
        for arg in args:
            # print(arg)
            current_rel+=length[arg[0]]

print("Relative Locations")
output = instructions.copy()
output.insert(0,['Rel Ad','Label','Instruction','Arguments'])
printer(output)

esd_card = []

def getRelativeLoc(name):
    for instruction in instructions:
        if(instruction[1]==name):
            return instruction[0]

rel_add = {}

for instruction in instructions:
    if instruction[2]=="START":
        esd_card.append([instruction[1],"SD",1,0,current_rel])
        rel_add[instruction[1]] = 0

    elif instruction[2]=="ENTRY":
        args = instruction[-1].split(',')
        for arg in args:
            esd_card.append([arg,"LD","-",getRelativeLoc(arg),'-'])
            rel_add[arg] = getRelativeLoc(arg)
    elif instruction[2]=="EXTRN":
        args = instruction[-1].split(',')
        temp =2
        for arg in args:
            esd_card.append([arg,"ER",temp,'-','-'])
            temp+=1
            rel_add[arg] = 0

# print(rel_add)

print("\nESD CARD")
output = esd_card.copy()
output.insert(0,['Name','Type','ID','Rel Ad','Length'])
printer(output)

txt_card = []

for instruction in instructions:
    if instruction[2]=="DC":
        temp = instruction[0]
        args = instruction[-1].split(',')
        for arg in args:
            # print(arg)
            content = arg[2:-1]
            for a in rel_add:
                content = content.replace(a,str(rel_add[a]))
            content = eval(content)
            txt_card.append([temp,content])
            temp+=length[arg[0]]

print("\nTXT CARD")
output = txt_card.copy()
output.insert(0,['Rel Ad','Content'])
printer(output)


rld_card = []

def getESDId(name):
    for line in esd_card:
        if(line[0]==name):
            if(line[2]=='-'):
                return 1
            else:
                return line[2]


def isENTRY(name):
    for line in esd_card:
        if(line[0]==name):
            if(line[1]=="ER"):
                return False
            else:
                return True

for instruction in instructions:
    if instruction[2]=="DC":
        temp = instruction[0]
        args = instruction[-1].split(',')
        for arg in args:
            flaggg = False
            content = arg[2:-1]
            for a in rel_add:
                content = content.replace(a,str(rel_add[a]))
            content = eval(content)
            new_content = arg[2:-1]
            for a in rel_add:
                temp3 = rel_add[a]
                if isENTRY(a):
                    temp3+=9999
                elif (not isENTRY(a)) and new_content.count(a)>0:
                    flaggg = True
                new_content = new_content.replace(a,str(temp3))
            new_content = eval(new_content)
            if(content!=new_content or flaggg):
                flag = '+'
                variable = ''
                content = arg[2:-1]
                for character in content:
                    if character!='+' and character!='-':
                        variable+=character
                    else:
                        try:
                            temp2 = int(variable)
                        except:
                            rld_card.append([getESDId(variable),length[arg[0]],flag,temp])
                        variable = ''
                        flag = character
                try:
                    temp2 = int(variable)
                except:
                    rld_card.append([getESDId(variable),length[arg[0]],flag,temp])
                variable = ''
                flag = character

            temp+=length[arg[0]]

print("\nRLD CARD")
output = rld_card.copy()
output.insert(0,['ESD ID','Length','Flag','Rel Ad'])
printer(output)