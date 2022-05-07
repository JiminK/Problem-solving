# input examples
# survey: ["AN", "CF", "MJ", "RT", "NA"], choices: [5, 3, 2, 7, 5], result: "TCMA"
# survey: ["TR", "RT", "TR"], choices: [7, 1, 3], result: "RCJA"

def solution(survey, choices):
    answer = ''
    # arr = [[0 for col in range(2)] for row in range(4)]
    myDict = {"R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0}

    for i in range(len(survey)):
        # print(i)  
        # print(survey[i])
        if choices[i] == 4:
            continue
        elif choices[i] == 1:
            myDict[survey[i][0]] += 3
        elif choices[i] == 2:
            myDict[survey[i][0]] += 2
        elif choices[i] == 3:
            myDict[survey[i][0]] += 1
        elif choices[i] == 5:
            myDict[survey[i][1]] += 1
        elif choices[i] == 6:
            myDict[survey[i][1]] += 2
        elif choices[i] == 7:
            myDict[survey[i][1]] += 3

    # for i in range(len(myDict)):
    myKeys = list(myDict.keys())
    # rt = ""
    # cf = ""
    # jm = ""
    # an = ""
    if myDict["R"] >= myDict["T"]:
        answer += "R"
    if myDict["R"] < myDict["T"]:
        answer += "T"

    if myDict["C"] >= myDict["F"]:
        answer += "C"
    if myDict["C"] < myDict["F"]:
        answer += "F"

    if myDict["J"] >= myDict["M"]:
        answer += "J"
    if myDict["J"] < myDict["M"]:
        answer += "M"

    if myDict["A"] >= myDict["N"]:
        answer += "A"
    if myDict["A"] < myDict["N"]:
        answer += "N"            

    # answer = rt + cf + jm + an

    return answer