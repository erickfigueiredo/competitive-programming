nTests = int(input())

for i in range(nTests):
    num = input()
    nums = []
    for n in num:
        nums.append(int(n))

    total = sum(nums)
    count = 0
    while (True):
        count += 1

        if len(nums) == 1:
            break

        removed = False
        for n in nums:
            if (total - n) % 3 == 0:
                removed = True
                total -= n
                nums.remove(n)
                break

        if not removed:
            count += 1
            break

    print(f"Case {i+1}: {'S' if count%2 else 'T'}")
