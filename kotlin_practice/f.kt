private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }

fun main(){
	var t = readInt()
	while (t > 0){
		val n = readInt()
		var array = ArrayList< Pair<Int, Int> >()
		for (i in 0 until n){
			var (a, b) = readInts()
			array.add(Pair(a, b))
		}
		t--
	}
}