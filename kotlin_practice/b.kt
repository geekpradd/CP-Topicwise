private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		var (a, b) = readInts()
		var (c, d) = readInts()
		if (a > b){
			val tem = a
			a = b
			b = tem
		}
		if (c > d){
			val tem = c
			c = d
			d = tem
		}
		var possible: Boolean = true
		if (b != d){
			possible = false
		}
		if (a + c != b){
			possible = false
		}
		if (possible){
			println("YES")
		}
		else {
			println("NO")
		}

		t--
	}

	}