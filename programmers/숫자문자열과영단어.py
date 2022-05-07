def solution(s):
    answer = ""
    # dict = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 
    #         5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}
    num = ["zero", "one", "two", "three", "four", 
           "five", "six", "seven", "eight", "nine"]
    
    # while s is not None:
    word = ""
    for i in s:
        # print(i)
        if i.isdigit():
            answer += str(i)
            continue
        else:
            # print("word ", word)
            word += i
            if word in num:
                print(num.index(word))
                answer += str(num.index(word))
                word = ""
        
        # # 0
        # if i == "z":
        #     s = s[4:]
        #     answer += "0"
        #     i += 1
        # # 1
        # if i == "o":
        #     s = s[3:]
        #     answer += "1"
        #     i += 1
        # # 2, 3
        # if i == "t":
        #     if i + 1 == "w":
        #         s = s[3:]
        #         answer += "2"
        #         i += 1
        #     if i + 1 == "h":
        #         s = s[5:]
        #         answer += "3"
        #         i += 1
        # # 4, 5
        # if i == "f":
        #     if i + 1 == "o":
        #         s = s[4:]
        #         answer += "4"
        #         i += 1
        #     if i + 1 == "i":
        #         s = s[4:]
        #         answer += "5"
        #         i += 1
        # # 6, 7
        # if i == "s":
        #     if i + 1 == "i":
        #         s = s[3:]
        #         answer += "6"
        #         i += 1
        #     if i + 1 == "e":
        #         s = s[5:]
        #         answer += "7"
        #         i += 1
        # # 8
        # if i == "e":
        #     s = s[5:]
        #     answer += "8"
        #     i += 1
        # # 9
        # if i == "n":
        #     s = s[4:]
        #     answer += "9"
        #     i += 1

            
    return int(answer)