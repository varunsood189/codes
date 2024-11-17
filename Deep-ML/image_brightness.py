def calculate_brightness(img):
	# Write your code here
	if not img or not img[0]:
		return -1
	rows ,cols = len(img),len(img[0])
	for row in img:
		if len(row)!=cols:
			return -1
		for pixel in row:
			if pixel>255 or pixel<0:
				return -1
	return	sum([v for value in img for v in value])/rows/cols
