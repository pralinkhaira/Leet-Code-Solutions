import (
	"sort"
)

func makeLargestSpecial(s string) string {
	count := 0
	i := 0
	var res []string

	for j := 0; j < len(s); j++ {
		if s[j] == '1' {
			count++
		} else {
			count--
		}

		// When balanced
		if count == 0 {
			// Recursively process inner substring
			inner := makeLargestSpecial(s[i+1 : j])
			res = append(res, "1"+inner+"0")
			i = j + 1
		}
	}

	// Sort in descending order
	sort.Slice(res, func(a, b int) bool {
		return res[a] > res[b]
	})

	// Concatenate results
	result := ""
	for _, str := range res {
		result += str
	}

	return result
}