func numSteps(s string) int {
	n := len(s)
	ans := n - 1
	carry := 0

	for i := n - 1; i > 0; i-- {
		bit := int(s[i]-'0') + carry

		if bit == 1 {
			ans++
			carry = 1
		}
	}

	return ans + carry
}