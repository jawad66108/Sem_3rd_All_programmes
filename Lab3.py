# email = {
#     "From" : " asmknd@saknd-sdcsd",
#     "TO" : "urgent Asdskdfj.edu.pk",
#     "subject" : "Verify Account Now",
#     "Body" : " Dear user , click http: //saknd-sdcsd."
# }


# print("=====Email Received===========")

# for i,j in email.items():
#     print(f"{i}: {j}")

# Warning = []

# if "URGENT" in  email ["subject"].upper():
#     Warning.append("Urgent language -> Red flag")
# if "http:" in email["Body"] and "https://" not in email["Body"]:
#     Warning.append("Contains non-http link")
# if email["From"].split("@")[-1].count("*")>0 or len(email["From"].split("@")[-1].split("."))<2:
#     Warning.append("Suspicious sender!!!!!!!!!")


# print ("\n==============checking=============")

# if Warning:
#     if Warning:
#         for m in Warning:
    
#             print(m)
#     else:
#         print("All good nothing to worry about!")

# import time 
# from queue import Queue

# S_CAPA= 8
# re =Queue()

# for m in range(10):
#     re.put(f"req_{m}")


# pro =0 
# print("Service starting cap: ",S_CAPA)

# while not re.empty():
#     if pro >= S_CAPA:
#         print("Service overloaded!!!!!!!\nincreasing the reponse time ")
#         time.sleep(5)
#     r =re.get()
#     print("Processing ", r)
#     pro +=1
#     time.sleep(0.5)


# u_pas= {"Student" : "letmein"}

# def authen(u_pas, pas):
#     return u_pas.get("Student") == pas 

# word =["1234","password0","letmein","letmein123"]

# for m in word:
#     print("Working: ",m)
#     if authen(u_pas,m):
#         print("Password found!!!: ",m)
#         break
# else:
#     print("Password not found!!!!!!!!!!!!!!!")

# def sender(mag):
#     print("[sender] sending: ",mag)
#     return mag

# def net_path(message):
#     print("Intercepted: ",message)
#     return message

# def rece(msg):
#     print("Received: ",msg)

# m =sender("Password123")
# m2 = net_path(m)
# rece(m2)

# suspicious=["urgent","verify","click here","account"]
# low=0
# med=0
# high=0
# for i in range(1,4):
#     subject=input(f"Enter subject of email {i}: ").lower()
#     body=input(f"Enter body of email {i}: ").lower()
#     text=subject+" "+body
#     found=[]
#     for w in suspicious:
#         if w in text:
#             found.append(w)
#     count=len(found)
#     if count==0:
#         risk="Low Risk"
#         low+=1
#     elif count==1:
#         risk="Medium Risk"
#         med+=1
#     else:
#         risk="High Risk"
#         high+=1
#     print("\nEmail",i)
#     print("Suspicious words:",", ".join(found) if found else "None")
#     print("Total red flags:",count)
#     print("Risk level:",risk)
# print("\nSummary")
# print("Total emails analyzed: 3")
# print("Low Risk:",low)
# print("Medium Risk:",med)
# print("High Risk:",high)

# def sender(msg):
#     checksum=sum(ord(c) for c in msg)
#     packet=f"{msg}|{checksum}"
#     print("Sender sends:",packet)
#     return packet

# def network(packet,tamper=False):
#     if tamper:
#         msg,chk=packet.split("|")
#         msg=msg.replace("jwad_m3","JAWAD.M3")
#         packet=f"{msg}|{chk}"
#         print("Attacker sends:",packet)
#     else:
#         print("Network sends:",packet)
#     return packet

# def receiver(packet):
#     msg,chk=packet.split("|")
#     new=sum(ord(c) for c in msg)
#     if str(new)==chk:
#         print("Receiver: OK")
#     else:
#         print("Receiver: Tampered!")

# p=sender("jawad108")
# p=network(p,tamper=False)
# receiver(p)
# print()
# p=sender("jwad_m3")
# p=network(p,tamper=True)
# receiver(p)

# def sender(msg):
#     checksum=sum(ord(c) for c in msg)
#     packet=f"{msg}|{checksum}"
#     print("Sender sends:",packet)
#     return packet

# def network(packet,tamper=False):
#     if tamper:
#         msg,chk=packet.split("|")
#         msg=msg.replace("jwad_m3","JAWAD.M3")
#         packet=f"{msg}|{chk}"
#         print("Attacker sends:",packet)
#     else:
#         print("Network sends:",packet)
#     return packet

# def receiver(packet):
#     msg,chk=packet.split("|")
#     new=sum(ord(c) for c in msg)
#     if str(new)==chk:
#         print("Receiver: OK")
#     else:
#         print("Receiver: Tampered!")

# p=sender("jawad108")
# p=network(p,tamper=False)
# receiver(p)
# print()
# p=sender("jwad_m3")
# p=network(p,tamper=True)
# receiver(p)

# requests=[("R1","10.0.0.5"),("R2","10.0.0.8"),("R3","10.0.0.5"),("R4","10.0.0.5"),("R5","10.0.0.9"),("R6","10.0.0.8")]
# capacity=5
# per_source_limit=2
# processed=0
# count_by_source={}
# blocked=set()

# for req_id,src in requests:
#     if src in blocked:
#         print("Blocked",req_id,"from",src)
#         continue
#     if processed>=capacity:
#         print("Server overloaded!")
#         break
#     count_by_source[src]=count_by_source.get(src,0)+1
#     if count_by_source[src]>per_source_limit:
#         blocked.add(src)
#         print("Blocked",req_id,"from",src)
#         continue
#     print("Processing",req_id,"from",src)
#     processed+=1

# print()
# print("Summary:")
# print("Processed:",processed)
# if blocked:
#     print("Blocked sources:")
#     for s in blocked:
#         print(s)
# else:
#     print("Blocked sources: None")
