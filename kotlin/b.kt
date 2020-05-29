private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
private fun readStrins() = readLn().split("")
private fun readIns() = readStrins().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		var (n, k, l) = readInts()
		var li = readLn()
		var mid = l/2
		var other = l - mid
		if (2*k < l){
			mid = k
			other = k
		}
		var prev = 0
		var total = 0
		for (i in 0 until n){
			if (li[i] == '0') {
				if (prev == 1){
					total += k
				}
				prev = 0
				continue
			}
			if (prev == 0){
				prev = 1
			}
			else {
				total += mid + other
				prev = 0
			}
		}
		if (prev == 1){
			total += k
		}

		println(total)
		t--
	}

}