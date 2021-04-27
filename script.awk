BEGIN {
	FS=","
	}
$3 <= 3 && NR != 1 {
	sum += $2
	smallCount+=1
}
END {
	print "Avg small orders =", sum / smallCount
	print "Count retail =", (NR - 1)
	}
