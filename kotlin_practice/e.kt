private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun main(){
	var t = readInt()
	while (t > 0){
		val n = readInt()
		if (n < 4)
			println(-1)
		else {
			var ceil = (n/2).toInt()
			var v = 2*ceil - 1
			if (n%2 != 0)
				print(n.toString() + " ")
			
			while (v > 0){
				print(v.toString() + " ")
				v -= 2
			}
			
			print("4 2 ")
			v = 2*ceil
			var low = 6
			while (low <= v){
				print(low.toString() + " ")
				low += 2
			}
			print("\n")
		}

		t-- 
	}
}