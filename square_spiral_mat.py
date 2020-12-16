def solve(n):
	left = 0
	right = n-1
	top = 0
	bottom = n-1
	num = 1
	target = n*n
	matrix = [[0 for _ in range(n)]for _ in range(n)]
	while num <= target:

		for i in range(left, right+1):
			matrix[top][i] = num
			num += 1
		top += 1

		if num > target:
			break

		for i in range(top, bottom+1):
			matrix[i][right] = num
			num += 1
		right -= 1

		if num > target:
			break

		for i in range(right, left-1, -1):
			matrix[bottom][i] = num
			num += 1
		bottom -= 1

		if num > target:
			break

		for i in range(bottom, top-1, -1):
			matrix[i][left] = num
			num += 1
		left += 1

		if num > target:
			break
	return matrix
n = int(input())

mat = solve(n)
for i in range(n):
	for j in range(n):
		print(mat[i][j],end=' ')
	print()


