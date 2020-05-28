private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		val n = readLn()
		var fin = ArrayList<Int>()
		
		for (c in 0 until n.length){
			if (n[c] == '0') continue 
			var num = (n[c].toInt() - '0'.toInt())
			for (dum in 0 until (n.length-1-c)){
				num = num*10
			}
			fin.add(num)
		}	
		println(fin.size)
		for (num in fin){
			print(num.toString() + " ")
		}
		print("\n")
		t--
	}

}