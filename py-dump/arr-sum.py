def miniMaxSum(arr):
    arr_sum = [0, 0, 0, 0, 0]
    for i in range (0, len(arr)):
        for j in range (0, len(arr)):
                if i is not j:
                        arr_sum[i] += arr[j]
    print(min(arr_sum), max(arr_sum))
    
if __name__ == '__main__':
        
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
