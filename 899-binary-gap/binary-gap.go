func binaryGap(n int) int {
	last := -1
	maxGap := 0
	position := 0

	for n > 0 {
		if n&1 == 1 {
			if last != -1 {
				if position-last > maxGap {
					maxGap = position - last
				}
			}
			last = position
		}
		n >>= 1
		position++
	}

	return maxGap
}