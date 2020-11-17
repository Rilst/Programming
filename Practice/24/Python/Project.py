import json
with open("in.json", "r") as read_file:
    Jstr = json.load(read_file)
Buf = []
Res = []
i = 0
while i < len(Jstr):
    UserID = Jstr[i]["userId"]
    TaskComp = Jstr[i]["completed"]
    if TaskComp:
        Buf.append(UserID)
    i += 1
unique = list(set(Buf))
j, n = 0, 0
while j < len(unique):
    Res.append({ 'task_completed': Buf.count(unique[j]) , 'userId': unique[j]})
    j += 1
with open("out.json", "w") as write_file:
    json.dump(Res, write_file, indent=2)