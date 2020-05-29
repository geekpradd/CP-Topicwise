private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t>0){
		var (n, m) = readInts()
		var values = IntArray(n)
		for (i in 0 until n){
			values[i] = 0
		}
		var weights = ArrayList< Pair<Int, Pair<Int, Int> > >()
		for (i in 0 until m){
			var (u, v, w) = readInts()
			weights.add(Pair(w, Pair(u, v)))
		}
		weights.sortBy{it.first}
		var posible = true
		for (i in 0 until m){
			var j = m - 1 - i
			var a = weights[j].second.first
			var b = weights[j].second.second
			a--
			b--
			if (values[a] != 0 && values[b] != 0){
				if (values[a] != weights[j].first && values[b] != weights[j].first){
					posible = false
					break
				}
				
			}
			if (values[a] == 0){
				values[a] = weights[j].first
			}
			if (values[b] == 0){
				values[b] = weights[j].first
			}
		}
		if (posible){
			println("YES")
			for (i in 0 until n){
				print(values[i].toString() + " ")
			}
			print("\n")
		}
		else {
			println("NO")
		}
		t--
	}

}