# logs = []

# print("Enter access logs (type END to stop):")

# while True:
#     line = input()
#     if line == "END":
#         break

#     parts = line.split(",")
#     timestamp = parts[0]
#     emp_id = parts[1]
#     access_point = parts[2]
#     result = parts[3]

#     hour = int(timestamp[11:13])
#     logs.append([timestamp, emp_id, access_point, result, hour])

# employees = []
# access_count = []
# fail_count = []
# risk_score = []

# def find_employee(emp_id):
#     for i in range(len(employees)):
#         if employees[i] == emp_id:
#             return i
#     return -1

# for log in logs:
#     emp_id = log[1]
#     result = log[3]
#     hour = log[4]

#     idx = find_employee(emp_id)
#     if idx == -1:
#         employees.append(emp_id)
#         access_count.append(0)
#         fail_count.append(0)
#         risk_score.append(0)
#         idx = len(employees) - 1

#     access_count[idx] += 1

#     if result == "FAIL":
#         fail_count[idx] += 1
#         risk_score[idx] += 10

#     if hour < 9 or hour > 18:
#         risk_score[idx] += 20

# for i in range(len(employees)):
#     if access_count[i] > 5:
#         risk_score[i] += 30
#     if fail_count[i] >= 3:
#         risk_score[i] += 20

# n = len(employees)
# for i in range(n - 1):
#     for j in range(i + 1, n):
#         if risk_score[j] > risk_score[i]:
#             risk_score[i], risk_score[j] = risk_score[j], risk_score[i]
#             employees[i], employees[j] = employees[j], employees[i]

# print("\nSuspicious Employees (Ranked):")
# for i in range(n):
#     print("Employee ID:", employees[i], "| Risk Score:", risk_score[i])


# =================================================================


# devices = []

# print("Enter device logs (type END to stop):")


# while True:
#     line = input()
#     if line == "END":
#         break

#     parts = line.split(",")
#     device_id = parts[0]
#     permissions = parts[1]
#     background_data = int(parts[2])
#     vpn_status = parts[3]

#     devices.append([device_id, permissions, background_data, vpn_status, 0])


# for d in devices:
#     device_id = d[0]
#     permissions = d[1]
#     background_data = d[2]
#     vpn_status = d[3]

#     risk = 0

    
#     if "INTERNET" in permissions and (
#         "READ_CONTACTS" in permissions or
#         "READ_SMS" in permissions or
#         "STORAGE" in permissions
#     ):
#         risk += 30
#     if background_data > 100:
#         risk += 30

#     if vpn_status == "OFF":
#         risk += 40

#     d[4] = risk


# n = len(devices)
# for i in range(n - 1):
#     for j in range(i + 1, n):
#         if devices[j][4] > devices[i][4]:
#             devices[i], devices[j] = devices[j], devices[i]

# print("\nDevice-Level Security Assessment Report:")
# for d in devices:
#     print("\nDevice ID:", d[0])
#     print("Risk Score:", d[4])

#     if d[4] >= 70:
#         print("Risk Level: HIGH")
#     elif d[4] >= 40:
#         print("Risk Level: MEDIUM")
#     else:
#         print("Risk Level: LOW")

#     print("-------------------------")

# =================================================================


physical_logs = []
system_logs = []
timeline = []

print("Enter PHYSICAL access logs (type END):")
while True:
    line = input()
    if line == "END":
        break
    parts = line.split(",")
    time = parts[0]
    person = parts[1]
    result = parts[2]
    physical_logs.append([time, person, result])

print("\nEnter SYSTEM logs (type END):")
while True:
    line = input()
    if line == "END":
        break
    parts = line.split(",")
    time = parts[0]
    event = parts[1]
    system_logs.append([time, event])

for p in physical_logs:
    timeline.append([p[0], "PHYSICAL", p[1], p[2]])

for s in system_logs:
    timeline.append([s[0], "SYSTEM", s[1]])

n = len(timeline)
for i in range(n - 1):
    for j in range(i + 1, n):
        if timeline[j][0] < timeline[i][0]:
            timeline[i], timeline[j] = timeline[j], timeline[i]

weakened_periods = []
breach_window = []

for i in range(len(timeline)):
    # Check system config change
    if timeline[i][1] == "SYSTEM" and timeline[i][2] == "CONFIG_CHANGE":
        # Look for nearby physical access
        for j in range(len(timeline)):
            if timeline[j][1] == "PHYSICAL" and timeline[j][3] == "SUCCESS":
                if timeline[j][0] <= timeline[i][0]:
                    weakened_periods.append((timeline[j][0], timeline[i][0]))
                    breach_window.append(timeline[i][0])

print("\nUnified Suspicious Timeline:")
for t in timeline:
    print(t)

print("\nDetected Weakened Security Periods:")
for w in weakened_periods:
    print("From", w[0], "to", w[1])

if breach_window:
    print("\nMost Probable Breach Window:", breach_window[0])
else:
    print("\nNo clear breach window detected")

