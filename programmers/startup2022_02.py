# 2022 Summer Coding - 여름방학 스타트업 인턴 프로그램 코딩테스트 
def solution(rooms, target):
    answer = []

    room_num = [0 for i in range(len(rooms))]
    room_member = ["" for i in range(len(rooms))]
    for i in range(len(rooms)):
        rooms[i] = rooms[i].split("[")
        rooms[i] = rooms[i][1].split("]")
        room_num[i] = int(rooms[i][0])
        room_member[i] = rooms[i][1].split(",")
    # print(room_num)
    # print(room_member)

    for i in range(len(room_num)):
        # distance
        room_num[i] = abs(room_num[i] - target)
    # print(room_num)

    # tmp_name = []
    for i in range(len(room_member)):
        if room_num[i] == 0:
            continue
            # tmp_name = room_member[i]
            # for j in range(len(room_member[i])):
            #     room_member[i][j] = ""
        else:
            for j in range(len(room_member[i])):
                if room_member[i][j] not in answer:
                    answer.append(room_member[i][j])
    # print(answer)

    # print(tmp_name)
    # for i in range(len(room_member)):
    #     if tmp_name in room_member[i]:
    #         # print(room_member[i])

    # for i in range(len(room_member)):

    answer = sorted(answer)
    # print(answer)

    return answer
