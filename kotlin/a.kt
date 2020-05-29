private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		val (n, l) = readInts()
		val n1 = n/(1 + l + l*l + l*l*l)
		val n2 = n1*l
		val n3 = n2*l
		val n4  = n3*l
		println(n1.toString() + " " + n2.toString() + " " + n3.toString() + " " + n4.toString())
		t-- 
	}

}