private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		var (n, k, x, y) = readInts()
		var list = readInts()
		var data = ArrayList<Int>()
		var sum = 0L
		var i = 0
		while (i < n){
			data.add(list[i])
			sum += list[i]
			i++
		}
		data.sort()
		var nn: Long = n.toLong()
		var kk: Long = k.toLong()
		var tot: Long = nn*kk
		var cost = 0L
		var j = n-1
		while (sum > tot && j >= 0){
			cost += x
			sum -= data[j]
			j--
		}
		var remcost = 0L
		while (j >= 0 && data[j] > k){
			remcost += x
			j--
		}
		if (remcost < y){
			cost += remcost
		}
		else {
			cost += y
		}
		println(cost)
		t--
	}

}