if __name__ == "__main__":

    locations = list(map(int, input().split()))
    number = locations[0]
    length = locations[1]
    positions = []
    positions = list(map(int, input().split()))

    positions = list(set(positions))

    positions.sort()

    max_distance_pair = 0
    max_distance = -99999999999

    for i in range(len(positions)-1):
        if positions[i+1] - positions[i] > max_distance:
            max_distance_pair = i+1
            max_distance = positions[i+1] - positions[i]
    ans = max_distance/2
    
    if not(0 in positions):
        if ans < positions[0]:
            ans = positions[0]
    
    if not(length in positions):
        if ans < length - positions[-1]:
            ans = length - positions[-1]

    print('{0:.10f}'.format(ans))



# if __name__ == "__main__":

#     locations = list(map(int, input().split()))
#     number = locations[0]
#     length = locations[1]
#     positions = []
#     positions = list(map(int, input().split()))

#     corner_point_1 = 0 in positions
#     corner_point_2 = length in positions

#     positions.append(0)
#     positions.append(length)

#     positions = list(set(positions))

#     positions.sort()

#     max_distance_pair = 0
#     max_distance = -99999999999

#     for i in range(len(positions)-1):
#         if positions[i+1] - positions[i] > max_distance:
#             max_distance_pair = i+1
#             max_distance = positions[i+1] - positions[i]
#     ans = 0.00
#     if corner_point_1 and corner_point_2:
#         ans = float((positions[max_distance_pair] -
#                      positions[max_distance_pair-1])/2)

#     elif not(corner_point_1) and not(corner_point_2):
#         if positions[1] - positions[0] > max_distance/2:
#             ans = positions[1] - positions[0]
#             max_distance = ans
#         if positions[-1] - positions[-2] > max_distance/2:
#             ans = positions[-1] - positions[-2]

#     elif(corner_point_1):
#         if positions[1] - positions[0] > max_distance/2:
#             ans = positions[1] - positions[0]

#     else:
#          if positions[-1] - positions[-2] > max_distance/2:
#             ans = positions[-1] - positions[-2]
#     print('{0:.10f}'.format(ans))
